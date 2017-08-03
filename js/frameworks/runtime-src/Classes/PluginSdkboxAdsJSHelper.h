

#ifndef __js__PluginSdkboxAdsJSHelper_H_
#define __js__PluginSdkboxAdsJSHelper_H_

#include "jsapi.h"
#include "jsfriendapi.h"
#include "SDKBoxJSHelper.h"

#if MOZJS_MAJOR_VERSION >= 31
    void register_all_PluginSdkboxAdsJS_helper(JSContext* cx, JS::HandleObject global);
#else
    void register_all_PluginSdkboxAdsJS_helper(JSContext* cx, JSObject* global);
#endif

sdkbox::JS_BOOL js_PluginSdkboxAdsJS_PluginSdkboxAds_setListener(JSContext *cx, uint32_t argc, JS::Value *vp);
sdkbox::JS_BOOL js_PluginSdkboxAdsJS_PluginSdkboxAds_playAd(JSContext *cx, uint32_t argc, JS::Value *vp);
sdkbox::JS_BOOL js_PluginSdkboxAdsJS_PluginSdkboxAds_cacheControl(JSContext *cx, uint32_t argc, JS::Value *vp);

#endif /* defined(__js__PluginSdkboxAdsJSHelper_H_) */
