#include "PluginAdColonyJSHelper.h"
#include "PluginAdColony/PluginAdColony.h"
#include "SDKBoxJSHelper.h"

extern JSObject* jsb_sdkbox_PluginAdColony_prototype;

static JSContext* s_cx = nullptr;

JSObject* adinfo_to_obj(JSContext* cx, const sdkbox::AdColonyAdInfo& info)
{
#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
#if MOZJS_MAJOR_VERSION >= 52
    JS::RootedObject jsobj(cx, JS_NewObject(cx, NULL));
#else
    JS::RootedObject jsobj(cx, JS_NewObject(cx, NULL, JS::NullPtr(), JS::NullPtr()));
#endif
    JS::RootedValue name(cx);
    name = SB_STR_TO_JSVAL(cx, info.name);

    JS_SetProperty(cx, jsobj, "name", name);

    JS::RootedValue zoneID(cx);
    zoneID = SB_STR_TO_JSVAL(cx, info.zoneID);

    JS_SetProperty(cx, jsobj, "zoneID", zoneID);

    JS::RootedValue shown(cx);
    shown = JS::BooleanValue(info.shown);

    JS_SetProperty(cx, jsobj, "shown", shown);

    JS::RootedValue iapEnabled(cx);
    iapEnabled = JS::BooleanValue(info.iapEnabled);

    JS_SetProperty(cx, jsobj, "iapEnabled", iapEnabled);

    JS::RootedValue iapProductID(cx);
    iapProductID = SB_STR_TO_JSVAL(cx, info.iapProductID);

    JS_SetProperty(cx, jsobj, "iapProductID", iapProductID);

    JS::RootedValue iapQuantity(cx);
    iapQuantity = JS::Int32Value(info.iapQuantity);

    JS_SetProperty(cx, jsobj, "iapQuantity", iapQuantity);

    JS::RootedValue iapEngagementType(cx);
    iapEngagementType = JS::Int32Value(info.iapEngagementType);

    JS_SetProperty(cx, jsobj, "iapEngagementType", iapEngagementType);
#else
    JSObject* jsobj = JS_NewObject(cx, NULL, NULL, NULL);

    JS::RootedValue name(cx);
    name = SB_STR_TO_JSVAL(cx, info.name);
    JS_SetProperty(cx, jsobj, "name", name);

    JS::RootedValue zoneID(cx);
    zoneID = SB_STR_TO_JSVAL(cx, info.zoneID);
    JS_SetProperty(cx, jsobj, "zoneID", zoneID);

    JS::RootedValue shown(cx);
    shown = BOOLEAN_TO_JSVAL(info.shown);
    JS_SetProperty(cx, jsobj, "shown", shown);

    JS::RootedValue iapEnabled(cx);
    iapEnabled = BOOLEAN_TO_JSVAL(info.iapEnabled);
    JS_SetProperty(cx, jsobj, "iapEnabled", iapEnabled);

    JS::RootedValue iapProductID(cx);
    iapProductID = SB_STR_TO_JSVAL(cx, info.iapProductID);
    JS_SetProperty(cx, jsobj, "iapProductID", iapProductID);

    JS::RootedValue iapQuantity(cx);
    iapQuantity = INT_TO_JSVAL(info.iapQuantity);
    JS_SetProperty(cx, jsobj, "iapQuantity", iapQuantity);

    JS::RootedValue iapEngagementType(cx);
    iapEngagementType = INT_TO_JSVAL(info.iapEngagementType);
    JS_SetProperty(cx, jsobj, "iapEngagementType", iapEngagementType);
#endif
#elif defined(JS_VERSION)
    JSObject* jsobj = JS_NewObject(cx, NULL, NULL, NULL);
    jsval name;
    name = SB_STR_TO_JSVAL(cx, info.name);

    JS_SetProperty(cx, jsobj, "name", &name);

    jsval zoneID;
    zoneID = SB_STR_TO_JSVAL(cx, info.zoneID);

    JS_SetProperty(cx, jsobj, "zoneID", &zoneID);

    jsval shown;
    shown = BOOLEAN_TO_JSVAL(info.shown);

    JS_SetProperty(cx, jsobj, "shown", &shown);

    jsval iapEnabled;
    iapEnabled = BOOLEAN_TO_JSVAL(info.iapEnabled);

    JS_SetProperty(cx, jsobj, "iapEnabled", &iapEnabled);

    jsval iapProductID;
    iapProductID = SB_STR_TO_JSVAL(cx, info.iapProductID);

    JS_SetProperty(cx, jsobj, "iapProductID", &iapProductID);

    jsval iapQuantity;
    iapQuantity = INT_TO_JSVAL(info.iapQuantity);

    JS_SetProperty(cx, jsobj, "iapQuantity", &iapQuantity);

    jsval iapEngagementType;
    iapEngagementType = INT_TO_JSVAL(info.iapEngagementType);

    JS_SetProperty(cx, jsobj, "iapEngagementType", &iapEngagementType);
#endif

    return jsobj;
}

class AdColonyListenerWrapper : public sdkbox::AdColonyListener, public sdkbox::JSListenerBase
{
public:
    AdColonyListenerWrapper():sdkbox::JSListenerBase() {
    }

    void onAdColonyChange(const sdkbox::AdColonyAdInfo& info, bool available)
    {
        if (!s_cx)
        {
            return;
        }
#if (COCOS2D_VERSION >= 0x00030000)
        cocos2d::Director::getInstance()->getScheduler()->performFunctionInCocosThread([=](){
#endif
        JSContext* cx = s_cx;
        const char* func_name = "onAdColonyChange";

        JS::RootedObject obj(cx, getJSDelegate());
        JSAutoCompartment ac(cx, obj);

#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
        bool hasAction;
        JS::RootedValue retval(cx);
        JS::RootedValue func_handle(cx);
#else
        bool hasAction;
        jsval retval;
        JS::RootedValue func_handle(cx);
#endif
#elif defined(JS_VERSION)
        JSBool hasAction;
        jsval retval;
        jsval func_handle;
#endif

        JS::Value dataVal[2];
        dataVal[0] = JS::ObjectValue(*adinfo_to_obj(s_cx, info));
        dataVal[1] = JS::BooleanValue(available);

        if (JS_HasProperty(cx, obj, func_name, &hasAction) && hasAction) {
            if(!JS_GetProperty(cx, obj, func_name, &func_handle)) {
                return;
            }
            if(func_handle == JS::NullValue()) {
                return;
            }

#if MOZJS_MAJOR_VERSION >= 31
            JS_CallFunctionName(cx, obj, func_name, JS::HandleValueArray::fromMarkedLocation(sizeof(dataVal)/sizeof(*dataVal), dataVal), &retval);
#else
            JS_CallFunctionName(cx, obj, func_name, sizeof(dataVal)/sizeof(*dataVal), dataVal, &retval);
#endif
        }
#if (COCOS2D_VERSION >= 0x00030000)
        });
#endif
    }

    void onAdColonyReward(const sdkbox::AdColonyAdInfo& info, const std::string& currencyName, int amount, bool success)
    {
        if (!s_cx)
        {
            return;
        }
#if (COCOS2D_VERSION >= 0x00030000)
        cocos2d::Director::getInstance()->getScheduler()->performFunctionInCocosThread([=](){
#endif
        JSContext* cx = s_cx;
        const char* func_name = "onAdColonyReward";

        JS::RootedObject obj(cx, getJSDelegate());
        JSAutoCompartment ac(cx, obj);

#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
        bool hasAction;
        JS::RootedValue retval(cx);
        JS::RootedValue func_handle(cx);
#else
        bool hasAction;
        jsval retval;
        JS::RootedValue func_handle(cx);
#endif
#elif defined(JS_VERSION)
        JSBool hasAction;
        jsval retval;
        jsval func_handle;
#endif
        JS::Value dataVal[4];
        dataVal[0] = JS::ObjectValue(*adinfo_to_obj(s_cx, info));
        dataVal[1] = SB_STR_TO_JSVAL(s_cx, currencyName);
        dataVal[2] = JS::Int32Value(amount);
        dataVal[3] = JS::BooleanValue(success);

        if (JS_HasProperty(cx, obj, func_name, &hasAction) && hasAction) {
            if(!JS_GetProperty(cx, obj, func_name, &func_handle)) {
                return;
            }
            if(func_handle == JS::NullValue()) {
                return;
            }

#if MOZJS_MAJOR_VERSION >= 31
            JS_CallFunctionName(cx, obj, func_name, JS::HandleValueArray::fromMarkedLocation(sizeof(dataVal)/sizeof(*dataVal), dataVal), &retval);
#else
            JS_CallFunctionName(cx, obj, func_name, sizeof(dataVal)/sizeof(*dataVal), dataVal, &retval);
#endif
        }
#if (COCOS2D_VERSION >= 0x00030000)
        });
#endif
    }

    void onAdColonyStarted(const sdkbox::AdColonyAdInfo& info)
    {
        if (!s_cx)
        {
            return;
        }
#if (COCOS2D_VERSION >= 0x00030000)
        cocos2d::Director::getInstance()->getScheduler()->performFunctionInCocosThread([=](){
#endif
        JSContext* cx = s_cx;
        const char* func_name = "onAdColonyStarted";

        JS::RootedObject obj(cx, getJSDelegate());
        JSAutoCompartment ac(cx, obj);

#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
        bool hasAction;
        JS::RootedValue retval(cx);
        JS::RootedValue func_handle(cx);
#else
        bool hasAction;
        jsval retval;
        JS::RootedValue func_handle(cx);
#endif
#elif defined(JS_VERSION)
        JSBool hasAction;
        jsval retval;
        jsval func_handle;
#endif
        JS::Value dataVal[1];
        dataVal[0] = JS::ObjectValue(*adinfo_to_obj(s_cx, info));

        if (JS_HasProperty(cx, obj, func_name, &hasAction) && hasAction) {
            if(!JS_GetProperty(cx, obj, func_name, &func_handle)) {
                return;
            }
            if(func_handle == JS::NullValue()) {
                return;
            }

#if MOZJS_MAJOR_VERSION >= 31
            JS_CallFunctionName(cx, obj, func_name, JS::HandleValueArray::fromMarkedLocation(sizeof(dataVal)/sizeof(*dataVal), dataVal), &retval);
#else
            JS_CallFunctionName(cx, obj, func_name, sizeof(dataVal)/sizeof(*dataVal), dataVal, &retval);
#endif
        }
#if (COCOS2D_VERSION >= 0x00030000)
        });
#endif
    }

    void onAdColonyFinished(const sdkbox::AdColonyAdInfo& info)
    {
        if (!s_cx)
        {
            return;
        }
#if (COCOS2D_VERSION >= 0x00030000)
        cocos2d::Director::getInstance()->getScheduler()->performFunctionInCocosThread([=](){
#endif
        JSContext* cx = s_cx;
        const char* func_name = "onAdColonyFinished";

        JS::RootedObject obj(cx, getJSDelegate());
        JSAutoCompartment ac(cx, obj);

#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
        bool hasAction;
        JS::RootedValue retval(cx);
        JS::RootedValue func_handle(cx);
#else
        bool hasAction;
        jsval retval;
        JS::RootedValue func_handle(cx);
#endif
#elif defined(JS_VERSION)
        JSBool hasAction;
        jsval retval;
        jsval func_handle;
#endif
        JS::Value dataVal[1];
        dataVal[0] = JS::ObjectValue(*adinfo_to_obj(s_cx, info));

        if (JS_HasProperty(cx, obj, func_name, &hasAction) && hasAction) {
            if(!JS_GetProperty(cx, obj, func_name, &func_handle)) {
                return;
            }
            if(func_handle == JS::NullValue()) {
                return;
            }

#if MOZJS_MAJOR_VERSION >= 31
            JS_CallFunctionName(cx, obj, func_name, JS::HandleValueArray::fromMarkedLocation(sizeof(dataVal)/sizeof(*dataVal), dataVal), &retval);
#else
            JS_CallFunctionName(cx, obj, func_name, sizeof(dataVal)/sizeof(*dataVal), dataVal, &retval);
#endif
        }
#if (COCOS2D_VERSION >= 0x00030000)
        });
#endif
    }

};

#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
bool js_PluginAdColonyJS_PluginAdColony_setListener(JSContext *cx, uint32_t argc, JS::Value *vp)
#else
bool js_PluginAdColonyJS_PluginAdColony_setListener(JSContext *cx, uint32_t argc, jsval *vp)
#endif
#elif defined(JS_VERSION)
JSBool js_PluginAdColonyJS_PluginAdColony_setListener(JSContext *cx, uint32_t argc, jsval *vp)
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

        JSB_PRECONDITION2(ok, cx, false, "js_PluginAdColonyJS_PluginAdColony_setIAPListener : Error processing arguments");
        AdColonyListenerWrapper* wrapper = new AdColonyListenerWrapper();
        wrapper->setJSDelegate(cx, args.get(0));
        sdkbox::PluginAdColony::setListener(wrapper);

        args.rval().setUndefined();
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginAdColonyJS_PluginAdColony_setIAPListener : wrong number of arguments");
    return false;
}

#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
void register_all_PluginAdColonyJS_helper(JSContext* cx, JS::HandleObject global) {
    JS::RootedObject pluginObj(cx);
    sdkbox::getJsObjOrCreat(cx, global, "sdkbox.PluginAdColony", &pluginObj);

    JS_DefineFunction(cx, pluginObj, "setListener", js_PluginAdColonyJS_PluginAdColony_setListener, 1, JSPROP_READONLY | JSPROP_PERMANENT);
}
#else
void register_all_PluginAdColonyJS_helper(JSContext* cx, JSObject* global) {
    JS::RootedObject pluginObj(cx);
    sdkbox::getJsObjOrCreat(cx, JS::RootedObject(cx, global), "sdkbox.PluginAdColony", &pluginObj);

    JS_DefineFunction(cx, pluginObj, "setListener", js_PluginAdColonyJS_PluginAdColony_setListener, 1, JSPROP_READONLY | JSPROP_PERMANENT);
}
#endif
#elif defined(JS_VERSION)
void register_all_PluginAdColonyJS_helper(JSContext* cx, JSObject* global) {
    jsval pluginVal;
    JSObject* pluginObj;
    pluginVal = sdkbox::getJsObjOrCreat(cx, global, "sdkbox.PluginAdColony", &pluginObj);

    JS_DefineFunction(cx, pluginObj, "setListener", js_PluginAdColonyJS_PluginAdColony_setListener, 1, JSPROP_READONLY | JSPROP_PERMANENT);
}
#endif

