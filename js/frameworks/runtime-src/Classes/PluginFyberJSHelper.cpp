
#include "PluginFyberJSHelper.h"
#include "cocos2d_specifics.hpp"
#include "SDKBoxJSHelper.h"
#include "PluginFyber/PluginFyber.h"

static JSContext* s_cx = nullptr;

class FyberListenerJsHelper : public sdkbox::FyberListener
{

public:
    void setJSDelegate(JSObject* delegate)
    {
        mJsDelegate = delegate;
    }

    JSObject* getJSDelegate()
    {
        return mJsDelegate;
    }

    void onVirtualCurrencyConnectorFailed(int error,
                                          const std::string& errorCode,
                                          const std::string& errorMsg)
    {
        std::string name("onVirtualCurrencyConnectorFailed");
        jsval dataVal[4];
        dataVal[0] = INT_TO_JSVAL(error);
        dataVal[1] = c_string_to_jsval(s_cx, errorCode.c_str());
        dataVal[2] = c_string_to_jsval(s_cx, errorMsg.c_str());

        invokeDelegate(name, dataVal, 3);
    }
    void onVirtualCurrencyConnectorSuccess(double deltaOfCoins,
                                           const std::string& currencyId,
                                           const std::string& currencyName,
                                           const std::string& transactionId)
    {
        std::string name("onVirtualCurrencyConnectorSuccess");
        jsval dataVal[4];
        dataVal[0] = DOUBLE_TO_JSVAL(deltaOfCoins);
        dataVal[1] = c_string_to_jsval(s_cx, currencyId.c_str());
        dataVal[2] = c_string_to_jsval(s_cx, currencyName.c_str());
        dataVal[3] = c_string_to_jsval(s_cx, transactionId.c_str());

        invokeDelegate(name, dataVal, 4);
    }
    void onCanShowInterstitial(bool canShowInterstitial)
    {
        std::string name("onCanShowInterstitial");
        jsval dataVal[1];
        dataVal[0] = BOOLEAN_TO_JSVAL(canShowInterstitial);
        invokeDelegate(name, dataVal, 1);
    }
    void onInterstitialDidShow()
    {
        std::string name("onInterstitialDidShow");
        jsval dataVal[0];
        invokeDelegate(name, dataVal, 0);
    }
    void onInterstitialDismiss(const std::string& reason)
    {
        std::string name("onInterstitialDismiss");
        jsval dataVal[1];
        dataVal[0] = c_string_to_jsval(s_cx, reason.c_str());
        invokeDelegate(name, dataVal, 1);
    }
    void onInterstitialFailed()
    {
        std::string name("onInterstitialFailed");
        jsval dataVal[0];
        invokeDelegate(name, dataVal, 0);
    }

    void onBrandEngageClientReceiveOffers(bool areOffersAvailable)
    {
        std::string name("onBrandEngageClientReceiveOffers");
        jsval dataVal[1];
        dataVal[0] = BOOLEAN_TO_JSVAL(areOffersAvailable);
        invokeDelegate(name, dataVal, 1);
    }
    void onBrandEngageClientChangeStatus(int status, const std::string& msg)
    {
        std::string name("onBrandEngageClientChangeStatus");
        jsval dataVal[2];
        dataVal[0] = INT_TO_JSVAL(status);
        dataVal[1] = c_string_to_jsval(s_cx, msg.c_str());
        invokeDelegate(name, dataVal, 2);
    }

    void onOfferWallFinish(int status)
    {
        std::string name("onOfferWallFinish");
        jsval dataVal[1];
        dataVal[0] = INT_TO_JSVAL(status);
        invokeDelegate(name, dataVal, 1);
    }
private:
    void invokeDelegate(std::string& fName, jsval dataVal[], int argc) {
        if (!s_cx) {
            return;
        }
        JSContext* cx = s_cx;
        const char* func_name = fName.c_str();

        JS::RootedObject obj(cx, mJsDelegate);
        JSAutoCompartment ac(cx, obj);

#if MOZJS_MAJOR_VERSION >= 31
        bool hasAction;
        JS::RootedValue retval(cx);
        JS::RootedValue func_handle(cx);
#elif MOZJS_MAJOR_VERSION >= 28
        bool hasAction;
        jsval retval;
        JS::RootedValue func_handle(cx);
#else
        JSBool hasAction;
        jsval retval;
        jsval func_handle;
#endif

        if (JS_HasProperty(cx, obj, func_name, &hasAction) && hasAction) {
            if(!JS_GetProperty(cx, obj, func_name, &func_handle)) {
                return;
            }
            if(func_handle == JSVAL_VOID) {
                return;
            }

#if MOZJS_MAJOR_VERSION >= 31
            if (0 == argc) {
                JS_CallFunctionName(cx, obj, func_name, JS::HandleValueArray::empty(), &retval);
            } else {
                JS_CallFunctionName(cx, obj, func_name, JS::HandleValueArray::fromMarkedLocation(argc, dataVal), &retval);
            }
#else
            if (0 == argc) {
                JS_CallFunctionName(cx, obj, func_name, 0, nullptr, &retval);
            } else {
                JS_CallFunctionName(cx, obj, func_name, argc, dataVal, &retval);
            }
#endif
        }
    }

private:
    JSObject* mJsDelegate;

};

#if MOZJS_MAJOR_VERSION >= 28
bool js_PluginFyberJS_PluginFyber_setListener(JSContext *cx, uint32_t argc, jsval *vp)
#else
JSBool js_PluginFyberJS_PluginFyber_setListener(JSContext *cx, unsigned argc, JS::Value *vp)
#endif
{
    s_cx = cx;
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;

    if (argc == 1) {

        if (!args.get(0).isObject())
        {
            ok = false;
        }
        JSObject *tmpObj = args.get(0).toObjectOrNull();

        JSB_PRECONDITION2(ok, cx, false, "js_PluginFyberJS_PluginFyber_setListener : Error processing arguments");
        FyberListenerJsHelper* lis = new FyberListenerJsHelper();
        lis->setJSDelegate(tmpObj);
        sdkbox::PluginFyber::setListener(lis);

        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginFyberJS_PluginFyber_setListener : wrong number of arguments");
    return false;
}

#define REGISTE_FYBER_FUNCTIONS \
JS_DefineFunction(cx, pluginObj, "setListener", js_PluginFyberJS_PluginFyber_setListener, 1, JSPROP_READONLY | JSPROP_PERMANENT);

#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
void register_all_PluginFyberJS_helper(JSContext* cx, JS::HandleObject global) {
    // Get the ns
    JS::RootedObject pluginObj(cx);
    sdkbox::getJsObjOrCreat(cx, global, "sdkbox.PluginFyber", &pluginObj);

    REGISTE_FYBER_FUNCTIONS
}
#else
void register_all_PluginFyberJS_helper(JSContext* cx, JSObject* obj) {
    // first, try to get the ns
    JS::RootedValue nsval(cx);
    JS::RootedObject pluginObj(cx);

    std::stringstream ss("sdkbox.PluginFyber");
    std::string sub;
    const char* subChar;

    while(getline(ss, sub, '.')) {
        if(sub.empty())continue;

        subChar = sub.c_str();

        JS_GetProperty(cx, obj, subChar, &nsval);
        if (nsval == JSVAL_VOID) {
            pluginObj = JS_NewObject(cx, NULL, NULL, NULL);
            nsval = OBJECT_TO_JSVAL(pluginObj);
            JS_SetProperty(cx, obj, subChar, nsval);
        } else {
            JS_ValueToObject(cx, nsval, &pluginObj);
        }
        obj = pluginObj;
    }

    REGISTE_FYBER_FUNCTIONS
}
#endif
#elif defined(JS_VERSION)
void register_all_PluginFyberJS_helper(JSContext* cx, JSObject* global) {
    jsval pluginVal;
    JSObject* pluginObj;
    pluginVal = sdkbox::getJsObjOrCreat(cx, global, "sdkbox.PluginFyber", &pluginObj);

    REGISTE_FYBER_FUNCTIONS
}
#endif

