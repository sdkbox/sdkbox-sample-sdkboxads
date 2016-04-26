#ifndef __PluginLeadBoltJS_h__
#define __PluginLeadBoltJS_h__

#include "jsapi.h"
#include "jsfriendapi.h"


extern JSClass  *jsb_sdkbox_PluginLeadBolt_class;
extern JSObject *jsb_sdkbox_PluginLeadBolt_prototype;

#if MOZJS_MAJOR_VERSION >= 33
void js_register_PluginLeadBoltJS_PluginLeadBolt(JSContext *cx, JS::HandleObject global);
void register_all_PluginLeadBoltJS(JSContext* cx, JS::HandleObject obj);
#else
void js_register_PluginLeadBoltJS_PluginLeadBolt(JSContext *cx, JSObject* global);
void register_all_PluginLeadBoltJS(JSContext* cx, JSObject* obj);
#endif

bool js_PluginLeadBoltJS_PluginLeadBolt_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_PluginLeadBoltJS_PluginLeadBolt_finalize(JSContext *cx, JSObject *obj);
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginLeadBoltJS_PluginLeadBolt_setCrashHandlerStatus(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginLeadBoltJS_PluginLeadBolt_setCrashHandlerStatus(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginLeadBoltJS_PluginLeadBolt_transaction(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginLeadBoltJS_PluginLeadBolt_transaction(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginLeadBoltJS_PluginLeadBolt_setGender(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginLeadBoltJS_PluginLeadBolt_setGender(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginLeadBoltJS_PluginLeadBolt_setSyncDataPeriodInSecond(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginLeadBoltJS_PluginLeadBolt_setSyncDataPeriodInSecond(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginLeadBoltJS_PluginLeadBolt_crashWithName(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginLeadBoltJS_PluginLeadBolt_crashWithName(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginLeadBoltJS_PluginLeadBolt_closeSession(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginLeadBoltJS_PluginLeadBolt_closeSession(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginLeadBoltJS_PluginLeadBolt_isAdReady(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginLeadBoltJS_PluginLeadBolt_isAdReady(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginLeadBoltJS_PluginLeadBolt_sync(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginLeadBoltJS_PluginLeadBolt_sync(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginLeadBoltJS_PluginLeadBolt_fixAdOrientation(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginLeadBoltJS_PluginLeadBolt_fixAdOrientation(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginLeadBoltJS_PluginLeadBolt_init(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginLeadBoltJS_PluginLeadBolt_init(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginLeadBoltJS_PluginLeadBolt_startSession(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginLeadBoltJS_PluginLeadBolt_startSession(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginLeadBoltJS_PluginLeadBolt_loadModule(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginLeadBoltJS_PluginLeadBolt_loadModule(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginLeadBoltJS_PluginLeadBolt_setFramework(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginLeadBoltJS_PluginLeadBolt_setFramework(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginLeadBoltJS_PluginLeadBolt_destroyModule(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginLeadBoltJS_PluginLeadBolt_destroyModule(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginLeadBoltJS_PluginLeadBolt_setAgeRange(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginLeadBoltJS_PluginLeadBolt_setAgeRange(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginLeadBoltJS_PluginLeadBolt_loadModuleToCache(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginLeadBoltJS_PluginLeadBolt_loadModuleToCache(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#endif

