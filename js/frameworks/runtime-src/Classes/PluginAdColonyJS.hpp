#ifndef __PluginAdColonyJS_h__
#define __PluginAdColonyJS_h__

#include "jsapi.h"
#include "jsfriendapi.h"


#if MOZJS_MAJOR_VERSION >= 33
void js_register_PluginAdColonyJS_PluginAdColony(JSContext *cx, JS::HandleObject global);
void register_all_PluginAdColonyJS(JSContext* cx, JS::HandleObject obj);
#else
void js_register_PluginAdColonyJS_PluginAdColony(JSContext *cx, JSObject* global);
void register_all_PluginAdColonyJS(JSContext* cx, JSObject* obj);
#endif
#endif

