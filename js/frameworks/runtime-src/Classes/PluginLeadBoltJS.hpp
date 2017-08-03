#ifndef __PluginLeadBoltJS_h__
#define __PluginLeadBoltJS_h__

#include "jsapi.h"
#include "jsfriendapi.h"


#if MOZJS_MAJOR_VERSION >= 33
void js_register_PluginLeadBoltJS_PluginLeadBolt(JSContext *cx, JS::HandleObject global);
void register_all_PluginLeadBoltJS(JSContext* cx, JS::HandleObject obj);
#else
void js_register_PluginLeadBoltJS_PluginLeadBolt(JSContext *cx, JSObject* global);
void register_all_PluginLeadBoltJS(JSContext* cx, JSObject* obj);
#endif
#endif

