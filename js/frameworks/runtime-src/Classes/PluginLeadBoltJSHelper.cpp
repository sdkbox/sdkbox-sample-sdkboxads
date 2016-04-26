#include "PluginLeadBoltJSHelper.h"
#include "cocos2d_specifics.hpp"
#include "PluginLeadBolt/PluginLeadBolt.h"
#include "SDKBoxJSHelper.h"

#include "js_manual_conversions.h"

extern JSObject* jsb_sdkbox_PluginLeadBolt_prototype;
static JSContext* s_cx = nullptr;

class LBCallbackJS: public cocos2d::CCObject {
public:
    LBCallbackJS();
    void schedule();
    void notityJs(float dt);
    int transParams(jsval** pp);

    std::string _name;

    jsval _paramVal[3];
    int _paramLen;

    std::string _placement;
    std::string _error;
    bool _bool;
};

class LeadBoltListenerJS : public sdkbox::LeadBoltListener {
private:
    JSObject* _JSDelegate;
public:
    void setJSDelegate(JSObject* delegate) {
        _JSDelegate = delegate;
    }

    JSObject* getJSDelegate() {
        return _JSDelegate;
    }

    virtual void onModuleLoaded(const std::string& placement) {
        LBCallbackJS* cb = new LBCallbackJS();
        cb->_name = "onModuleLoaded";
        cb->_placement = placement;
        cb->schedule();
    }

    virtual void onModuleClosed(const std::string& placement) {
        LBCallbackJS* cb = new LBCallbackJS();
        cb->_name = "onModuleClosed";
        cb->_placement = placement;
        cb->schedule();
    }

    virtual void onModuleClicked(const std::string& placement) {
        LBCallbackJS* cb = new LBCallbackJS();
        cb->_name = "onModuleClicked";
        cb->_placement = placement;
        cb->schedule();
    }

    virtual void onModuleCached(const std::string& placement) {
        LBCallbackJS* cb = new LBCallbackJS();
        cb->_name = "onModuleCached";
        cb->_placement = placement;
        cb->schedule();
    }

    virtual void onModuleFailed(const std::string& placement, const std::string& error, bool iscached) {
        LBCallbackJS* cb = new LBCallbackJS();
        cb->_name = "onModuleFailed";
        cb->_placement = placement;
        cb->_error = error;
        cb->_bool = iscached;
        cb->schedule();
    }

    virtual void onMediaFinished(bool viewCompleted) {
        LBCallbackJS* cb = new LBCallbackJS();
        cb->_name = "onMediaFinished";
        cb->_bool = viewCompleted;
        cb->schedule();
    }

    void invokeJS(const char* func, LBCallbackJS* cb) {
        if (!s_cx) {
            return;
        }
        JSContext* cx = s_cx;
        const char* func_name = func;
        JS::RootedObject obj(cx, _JSDelegate);
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
        int valueSize = 0;
        jsval* pVals = nullptr;
        valueSize = cb->transParams(&pVals);

        if (JS_HasProperty(cx, obj, func_name, &hasAction) && hasAction) {
            if(!JS_GetProperty(cx, obj, func_name, &func_handle)) {
                return;
            }
            if(func_handle == JSVAL_VOID) {
                return;
            }

#if MOZJS_MAJOR_VERSION >= 31
            if (0 == valueSize) {
                JS_CallFunctionName(cx, obj, func_name, JS::HandleValueArray::empty(), &retval);
            } else {
                JS_CallFunctionName(cx, obj, func_name, JS::HandleValueArray::fromMarkedLocation(valueSize, pVals), &retval);
            }
#else
            if (0 == valueSize) {
                JS_CallFunctionName(cx, obj, func_name, 0, nullptr, &retval);
            } else {
                JS_CallFunctionName(cx, obj, func_name, valueSize, pVals, &retval);
            }
#endif
        }
    }

};


LBCallbackJS::LBCallbackJS():
_paramLen(0) {
}

void LBCallbackJS::schedule() {
    retain();
    cocos2d::CCDirector::sharedDirector()->getScheduler()->scheduleSelector(schedule_selector(LBCallbackJS::notityJs), this, 0.1, false);
    autorelease();
}

void LBCallbackJS::notityJs(float dt) {
    sdkbox::LeadBoltListener* lis = sdkbox::PluginLeadBolt::getListener();
    LeadBoltListenerJS* l = dynamic_cast<LeadBoltListenerJS*>(lis);
    if (l) {
        l->invokeJS(_name.c_str(), this);
    }
    cocos2d::CCDirector::sharedDirector()->getScheduler()->unscheduleAllForTarget(this);
    release();
}

int LBCallbackJS::transParams(jsval** pp) {
    JSContext* cx = s_cx;
    if (0 == _name.compare("onMediaFinished")) {
        _paramVal[0] = BOOLEAN_TO_JSVAL(_bool);
        _paramLen = 1;
    } else if(0 == _name.compare("onModuleFailed")) {
        _paramVal[0] = std_string_to_jsval(cx, _placement);
        _paramVal[1] = std_string_to_jsval(cx, _error);
        _paramVal[2] = BOOLEAN_TO_JSVAL(_bool);
        _paramLen = 3;
    } else {
        _paramVal[0] = std_string_to_jsval(cx, _placement);
        _paramLen = 1;
    }

    *pp = _paramVal;
    return _paramLen;
}


#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
bool js_PluginLeadBoltJS_PluginLeadBolt_setListener(JSContext *cx, uint32_t argc, jsval *vp)
#else
bool js_PluginLeadBoltJS_PluginLeadBolt_setListener(JSContext *cx, uint32_t argc, jsval *vp)
#endif
#elif defined(JS_VERSION)
JSBool js_PluginLeadBoltJS_PluginLeadBolt_setListener(JSContext *cx, uint32_t argc, jsval *vp)
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

        JSB_PRECONDITION2(ok, cx, false, "js_PluginLeadBoltJS_PluginLeadBolt_setIAPListener : Error processing arguments");
        LeadBoltListenerJS* wrapper = new LeadBoltListenerJS();
        wrapper->setJSDelegate(tmpObj);
        sdkbox::PluginLeadBolt::setListener(wrapper);

        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginLeadBoltJS_PluginLeadBolt_setIAPListener : wrong number of arguments");
    return false;
}

#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
bool js_PluginLeadBoltJS_PluginLeadBolt_event(JSContext *cx, uint32_t argc, jsval *vp)
#else
bool js_PluginLeadBoltJS_PluginLeadBolt_event(JSContext *cx, uint32_t argc, jsval *vp)
#endif
#elif defined(JS_VERSION)
JSBool js_PluginLeadBoltJS_PluginLeadBolt_event(JSContext *cx, uint32_t argc, jsval *vp)
#endif
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;

    do {
        if (argc == 2) {
            std::string arg0;
            ok &= jsval_to_std_string(cx, args.get(0), &arg0);
            if (!ok) { ok = true; break; }
            double arg1;
            ok &= sdkbox::js_to_number(cx, args.get(1), &arg1);
            if (!ok) { ok = true; break; }
            sdkbox::PluginLeadBolt::event(arg0, arg1);
            return true;
        }
    } while (0);

    do {
        if (argc == 1) {
            std::string arg0;
            ok &= jsval_to_std_string(cx, args.get(0), &arg0);
            if (!ok) { ok = true; break; }
            sdkbox::PluginLeadBolt::event(arg0);
            return true;
        }
    } while (0);
    JS_ReportError(cx, "js_PluginLeadBoltJS_PluginLeadBolt_event : wrong number of arguments");
    return false;
}


#if defined(MOZJS_MAJOR_VERSION) and MOZJS_MAJOR_VERSION >= 26
void leadbolt_set_constants(JSContext* cx, const JS::RootedObject& obj, const std::string& name, const std::map<std::string, int>& params)
#else
void leadbolt_set_constants(JSContext* cx, JSObject* obj, const std::string& name, const std::map<std::string, int>& params)
#endif
{
    jsval val = sdkbox::std_map_string_int_to_jsval(cx, params);

    JS::RootedValue rv(cx);
    rv = val;
#if defined(MOZJS_MAJOR_VERSION) and MOZJS_MAJOR_VERSION >= 26
    JS_SetProperty(cx, obj, name.c_str(), rv);
#else
    JS_SetProperty(cx, obj, name.c_str(), rv.address());
#endif
}

#if defined(MOZJS_MAJOR_VERSION) and MOZJS_MAJOR_VERSION >= 26
void leadbolt_register_constants(JSContext* cx, const JS::RootedObject& obj)
#else
void leadbolt_register_constants(JSContext* cx, JSObject* obj)
#endif
{
    std::map<std::string, int> enums;
    enums.clear();
    enums.insert(std::make_pair("AdOrientation_AutoDetect", 0));
    enums.insert(std::make_pair("AdOrientation_Landscape", 1));
    enums.insert(std::make_pair("AdOrientation_Portrait", 2));
    leadbolt_set_constants(cx, obj, "AdOrientation", enums);
}

#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
void register_all_PluginLeadBoltJS_helper(JSContext* cx, JS::HandleObject global) {
    JS::RootedObject pluginObj(cx);
    sdkbox::getJsObjOrCreat(cx, global, "sdkbox.PluginLeadBolt", &pluginObj);

    JS_DefineFunction(cx, pluginObj, "setListener", js_PluginLeadBoltJS_PluginLeadBolt_setListener, 1, JSPROP_READONLY | JSPROP_PERMANENT);
    JS_DefineFunction(cx, pluginObj, "event", js_PluginLeadBoltJS_PluginLeadBolt_event, 1, JSPROP_READONLY | JSPROP_PERMANENT);

    leadbolt_register_constants(cx, pluginObj);
}
#else
void register_all_PluginLeadBoltJS_helper(JSContext* cx, JSObject* global) {
    JS::RootedObject pluginObj(cx);
    sdkbox::getJsObjOrCreat(cx, JS::RootedObject(cx, global), "sdkbox.PluginLeadBolt", &pluginObj);

    JS_DefineFunction(cx, pluginObj, "setListener", js_PluginLeadBoltJS_PluginLeadBolt_setListener, 1, JSPROP_READONLY | JSPROP_PERMANENT);
    JS_DefineFunction(cx, pluginObj, "event", js_PluginLeadBoltJS_PluginLeadBolt_event, 1, JSPROP_READONLY | JSPROP_PERMANENT);

    leadbolt_register_constants(cx, pluginObj);
}
#endif
#elif defined(JS_VERSION)
void register_all_PluginLeadBoltJS_helper(JSContext* cx, JSObject* global) {
    jsval pluginVal;
    JSObject* pluginObj;
    pluginVal = sdkbox::getJsObjOrCreat(cx, global, "sdkbox.PluginLeadBolt", &pluginObj);

    JS_DefineFunction(cx, pluginObj, "setListener", js_PluginLeadBoltJS_PluginLeadBolt_setListener, 1, JSPROP_READONLY | JSPROP_PERMANENT);
    JS_DefineFunction(cx, pluginObj, "event", js_PluginLeadBoltJS_PluginLeadBolt_event, 1, JSPROP_READONLY | JSPROP_PERMANENT);

    leadbolt_register_constants(cx, pluginObj);
}
#endif
