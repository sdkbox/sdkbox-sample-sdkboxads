#ifndef __PluginFyberJS_h__
#define __PluginFyberJS_h__

#include "jsapi.h"
#include "jsfriendapi.h"


#if MOZJS_MAJOR_VERSION >= 33
void js_register_PluginFyberJS_PluginFyber(JSContext *cx, JS::HandleObject global);
void register_all_PluginFyberJS(JSContext* cx, JS::HandleObject obj);
#else
void js_register_PluginFyberJS_PluginFyber(JSContext *cx, JSObject* global);
void register_all_PluginFyberJS(JSContext* cx, JSObject* obj);
#endif
#endif

