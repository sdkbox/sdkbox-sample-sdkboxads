#ifndef __PluginSdkboxAdsJS_h__
#define __PluginSdkboxAdsJS_h__

#include "jsapi.h"
#include "jsfriendapi.h"


extern JSClass  *jsb_sdkbox_PluginSdkboxAds_class;
extern JSObject *jsb_sdkbox_PluginSdkboxAds_prototype;

#if MOZJS_MAJOR_VERSION >= 33
void js_register_PluginSdkboxAdsJS_PluginSdkboxAds(JSContext *cx, JS::HandleObject global);
void register_all_PluginSdkboxAdsJS(JSContext* cx, JS::HandleObject obj);
#else
void js_register_PluginSdkboxAdsJS_PluginSdkboxAds(JSContext *cx, JSObject* global);
void register_all_PluginSdkboxAdsJS(JSContext* cx, JSObject* obj);
#endif

bool js_PluginSdkboxAdsJS_PluginSdkboxAds_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_PluginSdkboxAdsJS_PluginSdkboxAds_finalize(JSContext *cx, JSObject *obj);
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginSdkboxAdsJS_PluginSdkboxAds_placement(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginSdkboxAdsJS_PluginSdkboxAds_placement(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginSdkboxAdsJS_PluginSdkboxAds_init(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginSdkboxAdsJS_PluginSdkboxAds_init(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#endif

