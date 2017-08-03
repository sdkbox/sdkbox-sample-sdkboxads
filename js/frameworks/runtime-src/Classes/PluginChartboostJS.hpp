#ifndef __PluginChartboostJS_h__
#define __PluginChartboostJS_h__

#include "jsapi.h"
#include "jsfriendapi.h"


#if MOZJS_MAJOR_VERSION >= 33
void js_register_PluginChartboostJS_PluginChartboost(JSContext *cx, JS::HandleObject global);
void register_all_PluginChartboostJS(JSContext* cx, JS::HandleObject obj);
#else
void js_register_PluginChartboostJS_PluginChartboost(JSContext *cx, JSObject* global);
void register_all_PluginChartboostJS(JSContext* cx, JSObject* obj);
#endif
#endif

