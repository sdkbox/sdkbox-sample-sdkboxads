#include "PluginLeadBoltJS.hpp"
#include "PluginLeadBolt/PluginLeadBolt.h"
#include "SDKBoxJSHelper.h"
#include "sdkbox/Sdkbox.h"


#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 52
#elif MOZJS_MAJOR_VERSION >= 33
template<class T>
static bool dummy_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    JS_ReportErrorUTF8(cx, "Constructor for the requested class is not available, please refer to the API reference.");
    return false;
}

static bool js_is_native_obj(JSContext *cx, uint32_t argc, jsval *vp) {
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    args.rval().setBoolean(true);
    return true;
}
#else
template<class T>
static bool dummy_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    JS::RootedValue initializing(cx);
    bool isNewValid = true;
    if (isNewValid)
    {
        TypeTest<T> t;
        js_type_class_t *typeClass = nullptr;
        std::string typeName = t.s_name();
        auto typeMapIter = _js_global_type_map.find(typeName);
        CCASSERT(typeMapIter != _js_global_type_map.end(), "Can't find the class type!");
        typeClass = typeMapIter->second;
        CCASSERT(typeClass, "The value is null.");

        JSObject *_tmp = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
        T* cobj = new T();
        js_proxy_t *pp = jsb_new_proxy(cobj, _tmp);
        JS_AddObjectRoot(cx, &pp->obj);
        JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(_tmp));
        return true;
    }

    return false;
}

static bool empty_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    return false;
}

static bool js_is_native_obj(JSContext *cx, JS::HandleObject obj, JS::HandleId id, JS::MutableHandleValue vp)
{
    vp.set(BOOLEAN_TO_JSVAL(true));
    return true;
}
#endif
#elif defined(JS_VERSION)
template<class T>
static JSBool dummy_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    TypeTest<T> t;
    T* cobj = new T();
    js_type_class_t *p;
    uint32_t typeId = t.s_id();
    HASH_FIND_INT(_js_global_type_ht, &typeId, p);
    assert(p);
    JSObject *_tmp = JS_NewObject(cx, p->jsclass, p->proto, p->parentProto);
    js_proxy_t *pp = jsb_new_proxy(cobj, _tmp);
    JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(_tmp));

    return JS_TRUE;
}

static JSBool empty_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    return JS_FALSE;
}
#endif
JSClass  *jsb_sdkbox_PluginLeadBolt_class;
#if MOZJS_MAJOR_VERSION < 33
JSObject *jsb_sdkbox_PluginLeadBolt_prototype;
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginLeadBoltJS_PluginLeadBolt_setCrashHandlerStatus(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= sdkbox::js_to_bool(cx, args.get(0), (bool *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginLeadBoltJS_PluginLeadBolt_setCrashHandlerStatus : Error processing arguments");
        sdkbox::PluginLeadBolt::setCrashHandlerStatus(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginLeadBoltJS_PluginLeadBolt_setCrashHandlerStatus : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginLeadBoltJS_PluginLeadBolt_setCrashHandlerStatus(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        bool arg0;
        ok &= sdkbox::js_to_bool(cx, argv[0], (bool *)&arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginLeadBolt::setCrashHandlerStatus(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginLeadBoltJS_PluginLeadBolt_transaction(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 3) {
        std::string arg0;
        double arg1;
        std::string arg2;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= sdkbox::js_to_number(cx, args.get(1), &arg1);
        ok &= jsval_to_std_string(cx, args.get(2), &arg2);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginLeadBoltJS_PluginLeadBolt_transaction : Error processing arguments");
        sdkbox::PluginLeadBolt::transaction(arg0, arg1, arg2);
        args.rval().setUndefined();
        return true;
    }
    if (argc == 4) {
        std::string arg0;
        double arg1;
        std::string arg2;
        std::string arg3;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= sdkbox::js_to_number(cx, args.get(1), &arg1);
        ok &= jsval_to_std_string(cx, args.get(2), &arg2);
        ok &= jsval_to_std_string(cx, args.get(3), &arg3);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginLeadBoltJS_PluginLeadBolt_transaction : Error processing arguments");
        sdkbox::PluginLeadBolt::transaction(arg0, arg1, arg2, arg3);
        args.rval().setUndefined();
        return true;
    }
    if (argc == 5) {
        std::string arg0;
        double arg1;
        std::string arg2;
        std::string arg3;
        bool arg4;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= sdkbox::js_to_number(cx, args.get(1), &arg1);
        ok &= jsval_to_std_string(cx, args.get(2), &arg2);
        ok &= jsval_to_std_string(cx, args.get(3), &arg3);
        ok &= sdkbox::js_to_bool(cx, args.get(4), (bool *)&arg4);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginLeadBoltJS_PluginLeadBolt_transaction : Error processing arguments");
        sdkbox::PluginLeadBolt::transaction(arg0, arg1, arg2, arg3, arg4);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginLeadBoltJS_PluginLeadBolt_transaction : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginLeadBoltJS_PluginLeadBolt_transaction(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 3) {
        std::string arg0;
        double arg1;
        std::string arg2;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        ok &= sdkbox::js_to_number(cx, argv[1], &arg1);
        ok &= jsval_to_std_string(cx, argv[2], &arg2);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginLeadBolt::transaction(arg0, arg1, arg2);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    if (argc == 4) {
        std::string arg0;
        double arg1;
        std::string arg2;
        std::string arg3;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        ok &= sdkbox::js_to_number(cx, argv[1], &arg1);
        ok &= jsval_to_std_string(cx, argv[2], &arg2);
        ok &= jsval_to_std_string(cx, argv[3], &arg3);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginLeadBolt::transaction(arg0, arg1, arg2, arg3);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    if (argc == 5) {
        std::string arg0;
        double arg1;
        std::string arg2;
        std::string arg3;
        bool arg4;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        ok &= sdkbox::js_to_number(cx, argv[1], &arg1);
        ok &= jsval_to_std_string(cx, argv[2], &arg2);
        ok &= jsval_to_std_string(cx, argv[3], &arg3);
        ok &= sdkbox::js_to_bool(cx, argv[4], (bool *)&arg4);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginLeadBolt::transaction(arg0, arg1, arg2, arg3, arg4);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginLeadBoltJS_PluginLeadBolt_setGender(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginLeadBoltJS_PluginLeadBolt_setGender : Error processing arguments");
        sdkbox::PluginLeadBolt::setGender(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginLeadBoltJS_PluginLeadBolt_setGender : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginLeadBoltJS_PluginLeadBolt_setGender(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginLeadBolt::setGender(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginLeadBoltJS_PluginLeadBolt_setSyncDataPeriodInSecond(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        int arg0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginLeadBoltJS_PluginLeadBolt_setSyncDataPeriodInSecond : Error processing arguments");
        sdkbox::PluginLeadBolt::setSyncDataPeriodInSecond(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginLeadBoltJS_PluginLeadBolt_setSyncDataPeriodInSecond : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginLeadBoltJS_PluginLeadBolt_setSyncDataPeriodInSecond(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        int arg0;
        ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginLeadBolt::setSyncDataPeriodInSecond(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginLeadBoltJS_PluginLeadBolt_crashWithName(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 2) {
        std::string arg0;
        std::string arg1;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= jsval_to_std_string(cx, args.get(1), &arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginLeadBoltJS_PluginLeadBolt_crashWithName : Error processing arguments");
        sdkbox::PluginLeadBolt::crashWithName(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginLeadBoltJS_PluginLeadBolt_crashWithName : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginLeadBoltJS_PluginLeadBolt_crashWithName(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 2) {
        std::string arg0;
        std::string arg1;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        ok &= jsval_to_std_string(cx, argv[1], &arg1);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginLeadBolt::crashWithName(arg0, arg1);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginLeadBoltJS_PluginLeadBolt_closeSession(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        sdkbox::PluginLeadBolt::closeSession();
        args.rval().setUndefined();
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginLeadBoltJS_PluginLeadBolt_closeSession : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginLeadBoltJS_PluginLeadBolt_closeSession(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        sdkbox::PluginLeadBolt::closeSession();
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginLeadBoltJS_PluginLeadBolt_isAdReady(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginLeadBoltJS_PluginLeadBolt_isAdReady : Error processing arguments");
        bool ret = sdkbox::PluginLeadBolt::isAdReady(arg0);
        JS::RootedValue jsret(cx);
        jsret = JS::BooleanValue(ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginLeadBoltJS_PluginLeadBolt_isAdReady : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginLeadBoltJS_PluginLeadBolt_isAdReady(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        bool ret = sdkbox::PluginLeadBolt::isAdReady(arg0);
        jsval jsret;
        jsret = JS::BooleanValue(ret);
        JS_SET_RVAL(cx, vp, jsret);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginLeadBoltJS_PluginLeadBolt_sync(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        sdkbox::PluginLeadBolt::sync();
        args.rval().setUndefined();
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginLeadBoltJS_PluginLeadBolt_sync : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginLeadBoltJS_PluginLeadBolt_sync(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        sdkbox::PluginLeadBolt::sync();
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginLeadBoltJS_PluginLeadBolt_fixAdOrientation(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        sdkbox::PluginLeadBolt::AdOrientation arg0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginLeadBoltJS_PluginLeadBolt_fixAdOrientation : Error processing arguments");
        sdkbox::PluginLeadBolt::fixAdOrientation(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginLeadBoltJS_PluginLeadBolt_fixAdOrientation : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginLeadBoltJS_PluginLeadBolt_fixAdOrientation(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        sdkbox::PluginLeadBolt::AdOrientation arg0;
        ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginLeadBolt::fixAdOrientation(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginLeadBoltJS_PluginLeadBolt_init(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        bool ret = sdkbox::PluginLeadBolt::init();
        JS::RootedValue jsret(cx);
        jsret = JS::BooleanValue(ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginLeadBoltJS_PluginLeadBolt_init : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginLeadBoltJS_PluginLeadBolt_init(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        bool ret = sdkbox::PluginLeadBolt::init();
        jsval jsret;
        jsret = JS::BooleanValue(ret);
        JS_SET_RVAL(cx, vp, jsret);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginLeadBoltJS_PluginLeadBolt_startSession(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginLeadBoltJS_PluginLeadBolt_startSession : Error processing arguments");
        sdkbox::PluginLeadBolt::startSession(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginLeadBoltJS_PluginLeadBolt_startSession : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginLeadBoltJS_PluginLeadBolt_startSession(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginLeadBolt::startSession(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginLeadBoltJS_PluginLeadBolt_loadModule(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginLeadBoltJS_PluginLeadBolt_loadModule : Error processing arguments");
        sdkbox::PluginLeadBolt::loadModule(arg0);
        args.rval().setUndefined();
        return true;
    }
    if (argc == 2) {
        std::string arg0;
        std::string arg1;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= jsval_to_std_string(cx, args.get(1), &arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginLeadBoltJS_PluginLeadBolt_loadModule : Error processing arguments");
        sdkbox::PluginLeadBolt::loadModule(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginLeadBoltJS_PluginLeadBolt_loadModule : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginLeadBoltJS_PluginLeadBolt_loadModule(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginLeadBolt::loadModule(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    if (argc == 2) {
        std::string arg0;
        std::string arg1;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        ok &= jsval_to_std_string(cx, argv[1], &arg1);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginLeadBolt::loadModule(arg0, arg1);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginLeadBoltJS_PluginLeadBolt_setFramework(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginLeadBoltJS_PluginLeadBolt_setFramework : Error processing arguments");
        sdkbox::PluginLeadBolt::setFramework(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginLeadBoltJS_PluginLeadBolt_setFramework : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginLeadBoltJS_PluginLeadBolt_setFramework(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginLeadBolt::setFramework(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginLeadBoltJS_PluginLeadBolt_destroyModule(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        sdkbox::PluginLeadBolt::destroyModule();
        args.rval().setUndefined();
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginLeadBoltJS_PluginLeadBolt_destroyModule : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginLeadBoltJS_PluginLeadBolt_destroyModule(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        sdkbox::PluginLeadBolt::destroyModule();
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginLeadBoltJS_PluginLeadBolt_setAgeRange(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginLeadBoltJS_PluginLeadBolt_setAgeRange : Error processing arguments");
        sdkbox::PluginLeadBolt::setAgeRange(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginLeadBoltJS_PluginLeadBolt_setAgeRange : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginLeadBoltJS_PluginLeadBolt_setAgeRange(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginLeadBolt::setAgeRange(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginLeadBoltJS_PluginLeadBolt_loadModuleToCache(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginLeadBoltJS_PluginLeadBolt_loadModuleToCache : Error processing arguments");
        sdkbox::PluginLeadBolt::loadModuleToCache(arg0);
        args.rval().setUndefined();
        return true;
    }
    if (argc == 2) {
        std::string arg0;
        std::string arg1;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= jsval_to_std_string(cx, args.get(1), &arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginLeadBoltJS_PluginLeadBolt_loadModuleToCache : Error processing arguments");
        sdkbox::PluginLeadBolt::loadModuleToCache(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginLeadBoltJS_PluginLeadBolt_loadModuleToCache : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginLeadBoltJS_PluginLeadBolt_loadModuleToCache(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginLeadBolt::loadModuleToCache(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    if (argc == 2) {
        std::string arg0;
        std::string arg1;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        ok &= jsval_to_std_string(cx, argv[1], &arg1);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginLeadBolt::loadModuleToCache(arg0, arg1);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif


void js_PluginLeadBoltJS_PluginLeadBolt_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (PluginLeadBolt)", obj);
}

#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
void js_register_PluginLeadBoltJS_PluginLeadBolt(JSContext *cx, JS::HandleObject global) {
    static JSClass PluginAgeCheq_class = {
        "PluginLeadBolt",
        JSCLASS_HAS_PRIVATE,
        nullptr
    };
    jsb_sdkbox_PluginLeadBolt_class = &PluginAgeCheq_class;

#if MOZJS_MAJOR_VERSION < 52
    jsb_sdkbox_PluginLeadBolt_class->addProperty = JS_PropertyStub;
    jsb_sdkbox_PluginLeadBolt_class->delProperty = JS_DeletePropertyStub;
    jsb_sdkbox_PluginLeadBolt_class->getProperty = JS_PropertyStub;
    jsb_sdkbox_PluginLeadBolt_class->setProperty = JS_StrictPropertyStub;
    jsb_sdkbox_PluginLeadBolt_class->enumerate = JS_EnumerateStub;
    jsb_sdkbox_PluginLeadBolt_class->resolve = JS_ResolveStub;
    jsb_sdkbox_PluginLeadBolt_class->convert = JS_ConvertStub;
    jsb_sdkbox_PluginLeadBolt_class->finalize = js_PluginLeadBoltJS_PluginLeadBolt_finalize;
    jsb_sdkbox_PluginLeadBolt_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);
#endif

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("setCrashHandlerStatus", js_PluginLeadBoltJS_PluginLeadBolt_setCrashHandlerStatus, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("transaction", js_PluginLeadBoltJS_PluginLeadBolt_transaction, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setGender", js_PluginLeadBoltJS_PluginLeadBolt_setGender, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setSyncDataPeriodInSecond", js_PluginLeadBoltJS_PluginLeadBolt_setSyncDataPeriodInSecond, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("crashWithName", js_PluginLeadBoltJS_PluginLeadBolt_crashWithName, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("closeSession", js_PluginLeadBoltJS_PluginLeadBolt_closeSession, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("isAdReady", js_PluginLeadBoltJS_PluginLeadBolt_isAdReady, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("sync", js_PluginLeadBoltJS_PluginLeadBolt_sync, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("fixAdOrientation", js_PluginLeadBoltJS_PluginLeadBolt_fixAdOrientation, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("init", js_PluginLeadBoltJS_PluginLeadBolt_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("startSession", js_PluginLeadBoltJS_PluginLeadBolt_startSession, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("loadModule", js_PluginLeadBoltJS_PluginLeadBolt_loadModule, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setFramework", js_PluginLeadBoltJS_PluginLeadBolt_setFramework, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("destroyModule", js_PluginLeadBoltJS_PluginLeadBolt_destroyModule, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setAgeRange", js_PluginLeadBoltJS_PluginLeadBolt_setAgeRange, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("loadModuleToCache", js_PluginLeadBoltJS_PluginLeadBolt_loadModuleToCache, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JS::RootedObject parent_proto(cx, nullptr);
    JSObject* objProto = JS_InitClass(
        cx, global,
        parent_proto,
        jsb_sdkbox_PluginLeadBolt_class,
        dummy_constructor<sdkbox::PluginLeadBolt>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, objProto);
#if (SDKBOX_COCOS_JSB_VERSION >= 2)
#if MOZJS_MAJOR_VERSION >= 52
    jsb_register_class<sdkbox::PluginLeadBolt>(cx, jsb_sdkbox_PluginLeadBolt_class, proto);
#else
    jsb_register_class<sdkbox::PluginLeadBolt>(cx, jsb_sdkbox_PluginLeadBolt_class, proto, JS::NullPtr());
#endif
#else
    TypeTest<sdkbox::PluginLeadBolt> t;
    js_type_class_t *p;
    std::string typeName = t.s_name();
    if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
    {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->jsclass = jsb_sdkbox_PluginLeadBolt_class;
        p->proto = objProto;
        p->parentProto = NULL;
        _js_global_type_map.insert(std::make_pair(typeName, p));
    }
#endif

    // add the proto and JSClass to the type->js info hash table
    JS::RootedValue className(cx);
    JSString* jsstr = JS_NewStringCopyZ(cx, "PluginLeadBolt");
    className = JS::StringValue(jsstr);
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
}
#else
void js_register_PluginLeadBoltJS_PluginLeadBolt(JSContext *cx, JSObject *global) {
    jsb_sdkbox_PluginLeadBolt_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_sdkbox_PluginLeadBolt_class->name = "PluginLeadBolt";
    jsb_sdkbox_PluginLeadBolt_class->addProperty = JS_PropertyStub;
    jsb_sdkbox_PluginLeadBolt_class->delProperty = JS_DeletePropertyStub;
    jsb_sdkbox_PluginLeadBolt_class->getProperty = JS_PropertyStub;
    jsb_sdkbox_PluginLeadBolt_class->setProperty = JS_StrictPropertyStub;
    jsb_sdkbox_PluginLeadBolt_class->enumerate = JS_EnumerateStub;
    jsb_sdkbox_PluginLeadBolt_class->resolve = JS_ResolveStub;
    jsb_sdkbox_PluginLeadBolt_class->convert = JS_ConvertStub;
    jsb_sdkbox_PluginLeadBolt_class->finalize = js_PluginLeadBoltJS_PluginLeadBolt_finalize;
    jsb_sdkbox_PluginLeadBolt_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        {"__nativeObj", 0, JSPROP_ENUMERATE | JSPROP_PERMANENT, JSOP_WRAPPER(js_is_native_obj), JSOP_NULLWRAPPER},
        {0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
    };

    static JSFunctionSpec funcs[] = {
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("setCrashHandlerStatus", js_PluginLeadBoltJS_PluginLeadBolt_setCrashHandlerStatus, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("transaction", js_PluginLeadBoltJS_PluginLeadBolt_transaction, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setGender", js_PluginLeadBoltJS_PluginLeadBolt_setGender, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setSyncDataPeriodInSecond", js_PluginLeadBoltJS_PluginLeadBolt_setSyncDataPeriodInSecond, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("crashWithName", js_PluginLeadBoltJS_PluginLeadBolt_crashWithName, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("closeSession", js_PluginLeadBoltJS_PluginLeadBolt_closeSession, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("isAdReady", js_PluginLeadBoltJS_PluginLeadBolt_isAdReady, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("sync", js_PluginLeadBoltJS_PluginLeadBolt_sync, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("fixAdOrientation", js_PluginLeadBoltJS_PluginLeadBolt_fixAdOrientation, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("init", js_PluginLeadBoltJS_PluginLeadBolt_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("startSession", js_PluginLeadBoltJS_PluginLeadBolt_startSession, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("loadModule", js_PluginLeadBoltJS_PluginLeadBolt_loadModule, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setFramework", js_PluginLeadBoltJS_PluginLeadBolt_setFramework, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("destroyModule", js_PluginLeadBoltJS_PluginLeadBolt_destroyModule, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setAgeRange", js_PluginLeadBoltJS_PluginLeadBolt_setAgeRange, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("loadModuleToCache", js_PluginLeadBoltJS_PluginLeadBolt_loadModuleToCache, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_sdkbox_PluginLeadBolt_prototype = JS_InitClass(
        cx, global,
        NULL, // parent proto
        jsb_sdkbox_PluginLeadBolt_class,
        dummy_constructor<sdkbox::PluginLeadBolt>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
//  bool found;
//FIXME: Removed in Firefox v27
//  JS_SetPropertyAttributes(cx, global, "PluginLeadBolt", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
    TypeTest<sdkbox::PluginLeadBolt> t;
    js_type_class_t *p;
    std::string typeName = t.s_name();
    if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
    {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->jsclass = jsb_sdkbox_PluginLeadBolt_class;
        p->proto = jsb_sdkbox_PluginLeadBolt_prototype;
        p->parentProto = NULL;
        _js_global_type_map.insert(std::make_pair(typeName, p));
    }
}
#endif
#elif defined(JS_VERSION)
void js_register_PluginLeadBoltJS_PluginLeadBolt(JSContext *cx, JSObject *global) {
    jsb_sdkbox_PluginLeadBolt_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_sdkbox_PluginLeadBolt_class->name = "PluginLeadBolt";
    jsb_sdkbox_PluginLeadBolt_class->addProperty = JS_PropertyStub;
    jsb_sdkbox_PluginLeadBolt_class->delProperty = JS_PropertyStub;
    jsb_sdkbox_PluginLeadBolt_class->getProperty = JS_PropertyStub;
    jsb_sdkbox_PluginLeadBolt_class->setProperty = JS_StrictPropertyStub;
    jsb_sdkbox_PluginLeadBolt_class->enumerate = JS_EnumerateStub;
    jsb_sdkbox_PluginLeadBolt_class->resolve = JS_ResolveStub;
    jsb_sdkbox_PluginLeadBolt_class->convert = JS_ConvertStub;
    jsb_sdkbox_PluginLeadBolt_class->finalize = js_PluginLeadBoltJS_PluginLeadBolt_finalize;
    jsb_sdkbox_PluginLeadBolt_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    JSPropertySpec *properties = NULL;

    JSFunctionSpec *funcs = NULL;

    static JSFunctionSpec st_funcs[] = {
        JS_FN("setCrashHandlerStatus", js_PluginLeadBoltJS_PluginLeadBolt_setCrashHandlerStatus, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("transaction", js_PluginLeadBoltJS_PluginLeadBolt_transaction, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setGender", js_PluginLeadBoltJS_PluginLeadBolt_setGender, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setSyncDataPeriodInSecond", js_PluginLeadBoltJS_PluginLeadBolt_setSyncDataPeriodInSecond, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("crashWithName", js_PluginLeadBoltJS_PluginLeadBolt_crashWithName, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("closeSession", js_PluginLeadBoltJS_PluginLeadBolt_closeSession, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("isAdReady", js_PluginLeadBoltJS_PluginLeadBolt_isAdReady, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("sync", js_PluginLeadBoltJS_PluginLeadBolt_sync, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("fixAdOrientation", js_PluginLeadBoltJS_PluginLeadBolt_fixAdOrientation, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("init", js_PluginLeadBoltJS_PluginLeadBolt_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("startSession", js_PluginLeadBoltJS_PluginLeadBolt_startSession, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("loadModule", js_PluginLeadBoltJS_PluginLeadBolt_loadModule, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setFramework", js_PluginLeadBoltJS_PluginLeadBolt_setFramework, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("destroyModule", js_PluginLeadBoltJS_PluginLeadBolt_destroyModule, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setAgeRange", js_PluginLeadBoltJS_PluginLeadBolt_setAgeRange, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("loadModuleToCache", js_PluginLeadBoltJS_PluginLeadBolt_loadModuleToCache, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_sdkbox_PluginLeadBolt_prototype = JS_InitClass(
        cx, global,
        NULL, // parent proto
        jsb_sdkbox_PluginLeadBolt_class,
        dummy_constructor<sdkbox::PluginLeadBolt>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
    JSBool found;
    JS_SetPropertyAttributes(cx, global, "PluginLeadBolt", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
    TypeTest<sdkbox::PluginLeadBolt> t;
    js_type_class_t *p;
    uint32_t typeId = t.s_id();
    HASH_FIND_INT(_js_global_type_ht, &typeId, p);
    if (!p) {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->type = typeId;
        p->jsclass = jsb_sdkbox_PluginLeadBolt_class;
        p->proto = jsb_sdkbox_PluginLeadBolt_prototype;
        p->parentProto = NULL;
        HASH_ADD_INT(_js_global_type_ht, type, p);
    }
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
void register_all_PluginLeadBoltJS(JSContext* cx, JS::HandleObject obj) {
    // Get the ns
    JS::RootedObject ns(cx);
    get_or_create_js_obj(cx, obj, "sdkbox", &ns);

    js_register_PluginLeadBoltJS_PluginLeadBolt(cx, ns);

    sdkbox::setProjectType("js");
}
#else
void register_all_PluginLeadBoltJS(JSContext* cx, JSObject* obj) {
    // first, try to get the ns
    JS::RootedValue nsval(cx);
    JS::RootedObject ns(cx);
    JS_GetProperty(cx, obj, "sdkbox", &nsval);
    if (nsval == JSVAL_VOID) {
        ns = JS_NewObject(cx, NULL, NULL, NULL);
        nsval = OBJECT_TO_JSVAL(ns);
        JS_SetProperty(cx, obj, "sdkbox", nsval);
    } else {
        JS_ValueToObject(cx, nsval, &ns);
    }
    obj = ns;

    js_register_PluginLeadBoltJS_PluginLeadBolt(cx, obj);

    sdkbox::setProjectType("js");
}
#endif
#elif defined(JS_VERSION)
void register_all_PluginLeadBoltJS(JSContext* cx, JSObject* obj) {
    // first, try to get the ns
    jsval nsval;
    JSObject *ns;
    JS_GetProperty(cx, obj, "sdkbox", &nsval);
    if (nsval == JSVAL_VOID) {
        ns = JS_NewObject(cx, NULL, NULL, NULL);
        nsval = OBJECT_TO_JSVAL(ns);
        JS_SetProperty(cx, obj, "sdkbox", &nsval);
    } else {
        JS_ValueToObject(cx, nsval, &ns);
    }
    obj = ns;

    js_register_PluginLeadBoltJS_PluginLeadBolt(cx, obj);

    sdkbox::setProjectType("js");
}
#endif