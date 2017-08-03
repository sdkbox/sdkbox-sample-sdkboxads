
#include "PluginFyberJSHelper.h"
#include "SDKBoxJSHelper.h"
#include "PluginFyber/PluginFyber.h"

static JSContext* s_cx = nullptr;

class FyberListenerJsHelper : public sdkbox::FyberListener, public sdkbox::JSListenerBase
{
public:
    FyberListenerJsHelper():sdkbox::JSListenerBase() {
    }

    void onVirtualCurrencyConnectorFailed(int error,
                                          const std::string& errorCode,
                                          const std::string& errorMsg)
    {
        std::string name("onVirtualCurrencyConnectorFailed");
        JS::Value dataVal[4];
        dataVal[0] = JS::Int32Value(error);
        dataVal[1] = SB_STR_TO_JSVAL(s_cx, errorCode);
        dataVal[2] = SB_STR_TO_JSVAL(s_cx, errorMsg);

        invokeDelegate(name, dataVal, 3);
    }
    void onVirtualCurrencyConnectorSuccess(double deltaOfCoins,
                                           const std::string& currencyId,
                                           const std::string& currencyName,
                                           const std::string& transactionId)
    {
        std::string name("onVirtualCurrencyConnectorSuccess");
        JS::Value dataVal[4];
        dataVal[0] = JS::DoubleValue(deltaOfCoins);
        dataVal[1] = SB_STR_TO_JSVAL(s_cx, currencyId);
        dataVal[2] = SB_STR_TO_JSVAL(s_cx, currencyName);
        dataVal[3] = SB_STR_TO_JSVAL(s_cx, transactionId);

        invokeDelegate(name, dataVal, 4);
    }
    void onCanShowInterstitial(bool canShowInterstitial)
    {
        std::string name("onCanShowInterstitial");
        JS::Value dataVal[1];
        dataVal[0] = JS::BooleanValue(canShowInterstitial);
        invokeDelegate(name, dataVal, 1);
    }
    void onInterstitialDidShow()
    {
        std::string name("onInterstitialDidShow");
        JS::Value dataVal[0];
        invokeDelegate(name, dataVal, 0);
    }
    void onInterstitialDismiss(const std::string& reason)
    {
        std::string name("onInterstitialDismiss");
        JS::Value dataVal[1];
        dataVal[0] = SB_STR_TO_JSVAL(s_cx, reason);
        invokeDelegate(name, dataVal, 1);
    }
    void onInterstitialFailed()
    {
        std::string name("onInterstitialFailed");
        JS::Value dataVal[0];
        invokeDelegate(name, dataVal, 0);
    }

    void onBrandEngageClientReceiveOffers(bool areOffersAvailable)
    {
        std::string name("onBrandEngageClientReceiveOffers");
        JS::Value dataVal[1];
        dataVal[0] = JS::BooleanValue(areOffersAvailable);
        invokeDelegate(name, dataVal, 1);
    }
    void onBrandEngageClientChangeStatus(int status, const std::string& msg)
    {
        std::string name("onBrandEngageClientChangeStatus");
        JS::Value dataVal[2];
        dataVal[0] = JS::Int32Value(status);
        dataVal[1] = SB_STR_TO_JSVAL(s_cx, msg);
        invokeDelegate(name, dataVal, 2);
    }

    void onOfferWallFinish(int status)
    {
        std::string name("onOfferWallFinish");
        JS::Value dataVal[1];
        dataVal[0] = JS::Int32Value(status);
        invokeDelegate(name, dataVal, 1);
    }
private:
    void invokeDelegate(std::string& fName, JS::Value dataVal[], int argc) {
        if (!s_cx) {
            return;
        }
        JSContext* cx = s_cx;
        const char* func_name = fName.c_str();

        JS::RootedObject obj(cx, getJSDelegate());
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
            if(func_handle == JS::NullValue()) {
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
};

#if MOZJS_MAJOR_VERSION >= 28
bool js_PluginFyberJS_PluginFyber_setListener(JSContext *cx, uint32_t argc, JS::Value *vp)
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

        JSB_PRECONDITION2(ok, cx, false, "js_PluginFyberJS_PluginFyber_setListener : Error processing arguments");
        FyberListenerJsHelper* lis = new FyberListenerJsHelper();
        lis->setJSDelegate(cx, args.get(0));
        sdkbox::PluginFyber::setListener(lis);

        args.rval().setUndefined();
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginFyberJS_PluginFyber_setListener : wrong number of arguments");
    return false;
}

#if defined(MOZJS_MAJOR_VERSION) and MOZJS_MAJOR_VERSION >= 26
void fyber_set_constants(JSContext* cx, const JS::RootedObject& obj, const std::string& name, const std::map<std::string, int>& params)
#else
void fyber_set_constants(JSContext* cx, JSObject* obj, const std::string& name, const std::map<std::string, int>& params)
#endif
{
    JS::RootedValue val(cx);
    sdkbox::std_map_string_int_to_jsval(cx, params, &val);

    JS::RootedValue rv(cx);
    rv = val;
#if defined(MOZJS_MAJOR_VERSION) and MOZJS_MAJOR_VERSION >= 26
    JS_SetProperty(cx, obj, name.c_str(), rv);
#else
    JS_SetProperty(cx, obj, name.c_str(), rv.address());
#endif
}
#if defined(MOZJS_MAJOR_VERSION) and MOZJS_MAJOR_VERSION >= 26
void fyber_set_constants(JSContext* cx, const JS::RootedObject& obj, const std::string& name, const std::map<std::string, std::string>& params)
#else
void fyber_set_constants(JSContext* cx, JSObject* obj, const std::string& name, const std::map<std::string, std::string>& params)
#endif
{
    JS::RootedValue val(cx);
    sdkbox::std_map_string_string_to_jsval(cx, params, &val);

    JS::RootedValue rv(cx);
    rv = val;
#if defined(MOZJS_MAJOR_VERSION) and MOZJS_MAJOR_VERSION >= 26
    JS_SetProperty(cx, obj, name.c_str(), rv);
#else
    JS_SetProperty(cx, obj, name.c_str(), rv.address());
#endif
}

#if defined(MOZJS_MAJOR_VERSION) and MOZJS_MAJOR_VERSION >= 26
void fyber_register_constants(JSContext* cx, const JS::RootedObject& obj)
#else
void fyber_register_constants(JSContext* cx, JSObject* obj)
#endif
{
    //  The device of the user
    {
        std::map<std::string, std::string> enums;
        enums.insert(std::make_pair("Undefined", sdkbox::FYB_UserDeviceUndefined));
        enums.insert(std::make_pair("IPhone", sdkbox::FYB_UserDeviceIPhone));
        enums.insert(std::make_pair("IPad", sdkbox::FYB_UserDeviceIPad));
        enums.insert(std::make_pair("IPod", sdkbox::FYB_UserDeviceIPod));
        enums.insert(std::make_pair("Android", sdkbox::FYB_UserDeviceAndroid));
        fyber_set_constants(cx, obj, "UserDevice", enums);
    }

    std::map<std::string, int> enums;

    // UserConnectionType
    enums.clear();
    enums.insert(std::make_pair("Undefined", sdkbox::FYB_UserConnectionTypeUndefined));
    enums.insert(std::make_pair("WiFi", sdkbox::FYB_UserConnectionTypeWiFi));
    enums.insert(std::make_pair("3G", sdkbox::FYB_UserConnectionType3G));
    enums.insert(std::make_pair("LTE", sdkbox::FYB_UserConnectionTypeLTE));
    enums.insert(std::make_pair("Edge", sdkbox::FYB_UserConnectionTypeEdge));
    fyber_set_constants(cx, obj, "UserConnectionType", enums);

    // UserEducation
    enums.clear();
    enums.insert(std::make_pair("Undefined", sdkbox::FYB_UserEducationUndefined));
    enums.insert(std::make_pair("Other", sdkbox::FYB_UserEducationOther));
    enums.insert(std::make_pair("None", sdkbox::FYB_UserEducationNone));
    enums.insert(std::make_pair("HighSchool", sdkbox::FYB_UserEducationHighSchool));
    enums.insert(std::make_pair("InCollege", sdkbox::FYB_UserEducationInCollege));
    enums.insert(std::make_pair("SomeCollege", sdkbox::FYB_UserEducationSomeCollege));
    enums.insert(std::make_pair("Associates", sdkbox::FYB_UserEducationAssociates));
    enums.insert(std::make_pair("Bachelors", sdkbox::FYB_UserEducationBachelors));
    enums.insert(std::make_pair("Masters", sdkbox::FYB_UserEducationMasters));
    enums.insert(std::make_pair("Doctorate", sdkbox::FYB_UserEducationDoctorate));
    fyber_set_constants(cx, obj, "UserEducation", enums);

    // The marital status of the user
    enums.clear();
    enums.insert(std::make_pair("Undefined", sdkbox::FYB_UserMaritalStatusUndefined));
    enums.insert(std::make_pair("Single", sdkbox::FYB_UserMartialStatusSingle));
    enums.insert(std::make_pair("Relationship", sdkbox::FYB_UserMartialStatusRelationship));
    enums.insert(std::make_pair("Married", sdkbox::FYB_UserMartialStatusMarried));
    enums.insert(std::make_pair("Divorced", sdkbox::FYB_UserMartialStatusDivorced));
    enums.insert(std::make_pair("Engaged", sdkbox::FYB_UserMartialStatusEngaged));
    fyber_set_constants(cx, obj, "UserMartialStatus", enums);

    // The ethnicity of the user
    enums.clear();
    enums.insert(std::make_pair("Undefined", sdkbox::FYB_UserEthnicityUndefined));
    enums.insert(std::make_pair("Asian", sdkbox::FYB_UserEthnicityAsian));
    enums.insert(std::make_pair("Black", sdkbox::FYB_UserEthnicityBlack));
    enums.insert(std::make_pair("Hispanic", sdkbox::FYB_UserEthnicityHispanic));
    enums.insert(std::make_pair("Indian", sdkbox::FYB_UserEthnicityIndian));
    enums.insert(std::make_pair("MiddleEastern", sdkbox::FYB_UserEthnicityMiddleEastern));
    enums.insert(std::make_pair("NativeAmerican", sdkbox::FYB_UserEthnicityNativeAmerican));
    enums.insert(std::make_pair("PacificIslander", sdkbox::FYB_UserEthnicityPacificIslander));
    enums.insert(std::make_pair("White", sdkbox::FYB_UserEthnicityWhite));
    enums.insert(std::make_pair("Other", sdkbox::FYB_UserEthnicityOther));
    fyber_set_constants(cx, obj, "UserEthnicity", enums);

    // The gender of the user
    enums.clear();
    enums.insert(std::make_pair("Undefined", sdkbox::FYB_UserGenderUndefined));
    enums.insert(std::make_pair("Male", sdkbox::FYB_UserGenderMale));
    enums.insert(std::make_pair("Female", sdkbox::FYB_UserGenderFemale));
    enums.insert(std::make_pair("Other", sdkbox::FYB_UserGenderOther));
    fyber_set_constants(cx, obj, "UserGender", enums);

    // The sexual orientation of the user
    enums.clear();
    enums.insert(std::make_pair("Undefined", sdkbox::FYB_UserSexualOrientationUndefined));
    enums.insert(std::make_pair("Straight", sdkbox::FYB_UserSexualOrientationStraight));
    enums.insert(std::make_pair("Bisexual", sdkbox::FYB_UserSexualOrientationBisexual));
    enums.insert(std::make_pair("Gay", sdkbox::FYB_UserSexualOrientationGay));
    enums.insert(std::make_pair("Unknown", sdkbox::FYB_UserSexualOrientationUnknown));
    fyber_set_constants(cx, obj, "UserSexualOrientation", enums);
}

#define REGISTE_FYBER_FUNCTIONS \
JS_DefineFunction(cx, pluginObj, "setListener", js_PluginFyberJS_PluginFyber_setListener, 1, JSPROP_READONLY | JSPROP_PERMANENT); \
fyber_register_constants(cx, pluginObj);

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
        if (nsval == JS::NullValue()) {
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

