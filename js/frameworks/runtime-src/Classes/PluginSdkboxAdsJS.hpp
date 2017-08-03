#ifndef __PluginSdkboxAdsJS_h__
#define __PluginSdkboxAdsJS_h__

#include "jsapi.h"
#include "jsfriendapi.h"


#if MOZJS_MAJOR_VERSION >= 33
void js_register_PluginSdkboxAdsJS_PluginSdkboxAds(JSContext *cx, JS::HandleObject global);
void register_all_PluginSdkboxAdsJS(JSContext* cx, JS::HandleObject obj);
#else
void js_register_PluginSdkboxAdsJS_PluginSdkboxAds(JSContext *cx, JSObject* global);
void register_all_PluginSdkboxAdsJS(JSContext* cx, JSObject* obj);
#endif
#endif

