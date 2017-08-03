#include "PluginSdkboxAdsJS.hpp"
#include "PluginSdkboxAds/PluginSdkboxAds.h"
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
JSClass  *jsb_sdkbox_PluginSdkboxAds_class;
#if MOZJS_MAJOR_VERSION < 33
JSObject *jsb_sdkbox_PluginSdkboxAds_prototype;
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginSdkboxAdsJS_PluginSdkboxAds_hideAd(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 2) {
        std::string arg0;
        std::string arg1;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= jsval_to_std_string(cx, args.get(1), &arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginSdkboxAdsJS_PluginSdkboxAds_hideAd : Error processing arguments");
        sdkbox::PluginSdkboxAds::hideAd(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginSdkboxAdsJS_PluginSdkboxAds_hideAd : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginSdkboxAdsJS_PluginSdkboxAds_hideAd(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 2) {
        std::string arg0;
        std::string arg1;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        ok &= jsval_to_std_string(cx, argv[1], &arg1);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginSdkboxAds::hideAd(arg0, arg1);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginSdkboxAdsJS_PluginSdkboxAds_hide(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginSdkboxAdsJS_PluginSdkboxAds_hide : Error processing arguments");
        sdkbox::PluginSdkboxAds::hide(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginSdkboxAdsJS_PluginSdkboxAds_hide : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginSdkboxAdsJS_PluginSdkboxAds_hide(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginSdkboxAds::hide(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginSdkboxAdsJS_PluginSdkboxAds_placement(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginSdkboxAdsJS_PluginSdkboxAds_placement : Error processing arguments");
        sdkbox::PluginSdkboxAds::placement(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginSdkboxAdsJS_PluginSdkboxAds_placement : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginSdkboxAdsJS_PluginSdkboxAds_placement(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginSdkboxAds::placement(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginSdkboxAdsJS_PluginSdkboxAds_init(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        sdkbox::PluginSdkboxAds::init();
        args.rval().setUndefined();
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginSdkboxAdsJS_PluginSdkboxAds_init : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginSdkboxAdsJS_PluginSdkboxAds_init(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        sdkbox::PluginSdkboxAds::init();
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginSdkboxAdsJS_PluginSdkboxAds_isAvailable(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginSdkboxAdsJS_PluginSdkboxAds_isAvailable : Error processing arguments");
        bool ret = sdkbox::PluginSdkboxAds::isAvailable(arg0);
        JS::RootedValue jsret(cx);
        jsret = JS::BooleanValue(ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginSdkboxAdsJS_PluginSdkboxAds_isAvailable : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginSdkboxAdsJS_PluginSdkboxAds_isAvailable(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        bool ret = sdkbox::PluginSdkboxAds::isAvailable(arg0);
        jsval jsret;
        jsret = JS::BooleanValue(ret);
        JS_SET_RVAL(cx, vp, jsret);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif


void js_PluginSdkboxAdsJS_PluginSdkboxAds_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (PluginSdkboxAds)", obj);
}

#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
void js_register_PluginSdkboxAdsJS_PluginSdkboxAds(JSContext *cx, JS::HandleObject global) {
    static JSClass PluginAgeCheq_class = {
        "PluginSdkboxAds",
        JSCLASS_HAS_PRIVATE,
        nullptr
    };
    jsb_sdkbox_PluginSdkboxAds_class = &PluginAgeCheq_class;

#if MOZJS_MAJOR_VERSION < 52
    jsb_sdkbox_PluginSdkboxAds_class->addProperty = JS_PropertyStub;
    jsb_sdkbox_PluginSdkboxAds_class->delProperty = JS_DeletePropertyStub;
    jsb_sdkbox_PluginSdkboxAds_class->getProperty = JS_PropertyStub;
    jsb_sdkbox_PluginSdkboxAds_class->setProperty = JS_StrictPropertyStub;
    jsb_sdkbox_PluginSdkboxAds_class->enumerate = JS_EnumerateStub;
    jsb_sdkbox_PluginSdkboxAds_class->resolve = JS_ResolveStub;
    jsb_sdkbox_PluginSdkboxAds_class->convert = JS_ConvertStub;
    jsb_sdkbox_PluginSdkboxAds_class->finalize = js_PluginSdkboxAdsJS_PluginSdkboxAds_finalize;
    jsb_sdkbox_PluginSdkboxAds_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);
#endif

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("hideAd", js_PluginSdkboxAdsJS_PluginSdkboxAds_hideAd, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("hide", js_PluginSdkboxAdsJS_PluginSdkboxAds_hide, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("placement", js_PluginSdkboxAdsJS_PluginSdkboxAds_placement, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("init", js_PluginSdkboxAdsJS_PluginSdkboxAds_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("isAvailable", js_PluginSdkboxAdsJS_PluginSdkboxAds_isAvailable, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JS::RootedObject parent_proto(cx, nullptr);
    JSObject* objProto = JS_InitClass(
        cx, global,
        parent_proto,
        jsb_sdkbox_PluginSdkboxAds_class,
        dummy_constructor<sdkbox::PluginSdkboxAds>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, objProto);
#if (SDKBOX_COCOS_JSB_VERSION >= 2)
#if MOZJS_MAJOR_VERSION >= 52
    jsb_register_class<sdkbox::PluginSdkboxAds>(cx, jsb_sdkbox_PluginSdkboxAds_class, proto);
#else
    jsb_register_class<sdkbox::PluginSdkboxAds>(cx, jsb_sdkbox_PluginSdkboxAds_class, proto, JS::NullPtr());
#endif
#else
    TypeTest<sdkbox::PluginSdkboxAds> t;
    js_type_class_t *p;
    std::string typeName = t.s_name();
    if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
    {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->jsclass = jsb_sdkbox_PluginSdkboxAds_class;
        p->proto = objProto;
        p->parentProto = NULL;
        _js_global_type_map.insert(std::make_pair(typeName, p));
    }
#endif

    // add the proto and JSClass to the type->js info hash table
    JS::RootedValue className(cx);
    JSString* jsstr = JS_NewStringCopyZ(cx, "PluginSdkboxAds");
    className = JS::StringValue(jsstr);
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
}
#else
void js_register_PluginSdkboxAdsJS_PluginSdkboxAds(JSContext *cx, JSObject *global) {
    jsb_sdkbox_PluginSdkboxAds_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_sdkbox_PluginSdkboxAds_class->name = "PluginSdkboxAds";
    jsb_sdkbox_PluginSdkboxAds_class->addProperty = JS_PropertyStub;
    jsb_sdkbox_PluginSdkboxAds_class->delProperty = JS_DeletePropertyStub;
    jsb_sdkbox_PluginSdkboxAds_class->getProperty = JS_PropertyStub;
    jsb_sdkbox_PluginSdkboxAds_class->setProperty = JS_StrictPropertyStub;
    jsb_sdkbox_PluginSdkboxAds_class->enumerate = JS_EnumerateStub;
    jsb_sdkbox_PluginSdkboxAds_class->resolve = JS_ResolveStub;
    jsb_sdkbox_PluginSdkboxAds_class->convert = JS_ConvertStub;
    jsb_sdkbox_PluginSdkboxAds_class->finalize = js_PluginSdkboxAdsJS_PluginSdkboxAds_finalize;
    jsb_sdkbox_PluginSdkboxAds_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        {"__nativeObj", 0, JSPROP_ENUMERATE | JSPROP_PERMANENT, JSOP_WRAPPER(js_is_native_obj), JSOP_NULLWRAPPER},
        {0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
    };

    static JSFunctionSpec funcs[] = {
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("hideAd", js_PluginSdkboxAdsJS_PluginSdkboxAds_hideAd, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("hide", js_PluginSdkboxAdsJS_PluginSdkboxAds_hide, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("placement", js_PluginSdkboxAdsJS_PluginSdkboxAds_placement, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("init", js_PluginSdkboxAdsJS_PluginSdkboxAds_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("isAvailable", js_PluginSdkboxAdsJS_PluginSdkboxAds_isAvailable, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_sdkbox_PluginSdkboxAds_prototype = JS_InitClass(
        cx, global,
        NULL, // parent proto
        jsb_sdkbox_PluginSdkboxAds_class,
        dummy_constructor<sdkbox::PluginSdkboxAds>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
//  bool found;
//FIXME: Removed in Firefox v27
//  JS_SetPropertyAttributes(cx, global, "PluginSdkboxAds", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
    TypeTest<sdkbox::PluginSdkboxAds> t;
    js_type_class_t *p;
    std::string typeName = t.s_name();
    if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
    {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->jsclass = jsb_sdkbox_PluginSdkboxAds_class;
        p->proto = jsb_sdkbox_PluginSdkboxAds_prototype;
        p->parentProto = NULL;
        _js_global_type_map.insert(std::make_pair(typeName, p));
    }
}
#endif
#elif defined(JS_VERSION)
void js_register_PluginSdkboxAdsJS_PluginSdkboxAds(JSContext *cx, JSObject *global) {
    jsb_sdkbox_PluginSdkboxAds_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_sdkbox_PluginSdkboxAds_class->name = "PluginSdkboxAds";
    jsb_sdkbox_PluginSdkboxAds_class->addProperty = JS_PropertyStub;
    jsb_sdkbox_PluginSdkboxAds_class->delProperty = JS_PropertyStub;
    jsb_sdkbox_PluginSdkboxAds_class->getProperty = JS_PropertyStub;
    jsb_sdkbox_PluginSdkboxAds_class->setProperty = JS_StrictPropertyStub;
    jsb_sdkbox_PluginSdkboxAds_class->enumerate = JS_EnumerateStub;
    jsb_sdkbox_PluginSdkboxAds_class->resolve = JS_ResolveStub;
    jsb_sdkbox_PluginSdkboxAds_class->convert = JS_ConvertStub;
    jsb_sdkbox_PluginSdkboxAds_class->finalize = js_PluginSdkboxAdsJS_PluginSdkboxAds_finalize;
    jsb_sdkbox_PluginSdkboxAds_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    JSPropertySpec *properties = NULL;

    JSFunctionSpec *funcs = NULL;

    static JSFunctionSpec st_funcs[] = {
        JS_FN("hideAd", js_PluginSdkboxAdsJS_PluginSdkboxAds_hideAd, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("hide", js_PluginSdkboxAdsJS_PluginSdkboxAds_hide, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("placement", js_PluginSdkboxAdsJS_PluginSdkboxAds_placement, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("init", js_PluginSdkboxAdsJS_PluginSdkboxAds_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("isAvailable", js_PluginSdkboxAdsJS_PluginSdkboxAds_isAvailable, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_sdkbox_PluginSdkboxAds_prototype = JS_InitClass(
        cx, global,
        NULL, // parent proto
        jsb_sdkbox_PluginSdkboxAds_class,
        dummy_constructor<sdkbox::PluginSdkboxAds>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
    JSBool found;
    JS_SetPropertyAttributes(cx, global, "PluginSdkboxAds", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
    TypeTest<sdkbox::PluginSdkboxAds> t;
    js_type_class_t *p;
    uint32_t typeId = t.s_id();
    HASH_FIND_INT(_js_global_type_ht, &typeId, p);
    if (!p) {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->type = typeId;
        p->jsclass = jsb_sdkbox_PluginSdkboxAds_class;
        p->proto = jsb_sdkbox_PluginSdkboxAds_prototype;
        p->parentProto = NULL;
        HASH_ADD_INT(_js_global_type_ht, type, p);
    }
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
void register_all_PluginSdkboxAdsJS(JSContext* cx, JS::HandleObject obj) {
    // Get the ns
    JS::RootedObject ns(cx);
    get_or_create_js_obj(cx, obj, "sdkbox", &ns);

    js_register_PluginSdkboxAdsJS_PluginSdkboxAds(cx, ns);

    sdkbox::setProjectType("js");
}
#else
void register_all_PluginSdkboxAdsJS(JSContext* cx, JSObject* obj) {
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

    js_register_PluginSdkboxAdsJS_PluginSdkboxAds(cx, obj);

    sdkbox::setProjectType("js");
}
#endif
#elif defined(JS_VERSION)
void register_all_PluginSdkboxAdsJS(JSContext* cx, JSObject* obj) {
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

    js_register_PluginSdkboxAdsJS_PluginSdkboxAds(cx, obj);

    sdkbox::setProjectType("js");
}
#endif