#include "SDKBoxJSHelper.h"
#include "cocos2d_specifics.hpp"
#include "PluginSdkboxAds/PluginSdkboxAds.h"
#include "js_manual_conversions.h"

using namespace sdkbox;

extern JSObject* jsb_sdkbox_PluginSdkboxAds_prototype;

static JSContext* s_cx = nullptr;


class SdkboxAdsListenerWrapper : public sdkbox::PluginSdkboxAdsListener
{
private:

    JSObject* _JSDelegate;

    void invokeDelegate(std::string& fName, jsval dataVal[], int argc) {
        if (!s_cx) {
            return;
        }
        JSContext* cx = s_cx;
        const char* func_name = fName.c_str();
        
        JS::RootedObject obj(cx, _JSDelegate);
        JSAutoCompartment ac(cx, obj);
        
#if MOZJS_MAJOR_VERSION >= 31
        bool hasAction;
        JS::RootedValue retval(cx);
        JS::RootedValue func_handle(cx);
#elif MOZJS_MAJOR_VERSION >= 28
        bool hasAction;
        jsval retval;
        JS::RootedValue func_handle(cx);
#else
        JSBool hasAction;
        jsval retval;
        jsval func_handle;
#endif
        
        if (JS_HasProperty(cx, obj, func_name, &hasAction) && hasAction) {
            if(!JS_GetProperty(cx, obj, func_name, &func_handle)) {
                return;
            }
            if(func_handle == JSVAL_VOID) {
                return;
            }
            
#if MOZJS_MAJOR_VERSION >= 31
            if (0 == argc) {
                JS_CallFunctionName(cx, obj, func_name, JS::HandleValueArray::empty(), &retval);
            } else {
                JS_CallFunctionName(cx, obj, func_name, JS::HandleValueArray::fromMarkedLocation(argc, dataVal), &retval);
            }
#else
            if (0 == argc) {
                JS_CallFunctionName(cx, obj, func_name, 0, nullptr, &retval);
            } else {
                JS_CallFunctionName(cx, obj, func_name, argc, dataVal, &retval);
            }
#endif
        }
    }
    

public:
    void setJSDelegate(JSObject* delegate)
    {
        _JSDelegate = delegate;
    }

    JSObject* getJSDelegate()
    {
        return _JSDelegate;
    }
    
    
    SdkboxAdsListenerWrapper() : _JSDelegate(0)
    {
    }
    
    
    virtual void onAdAction( const std::string& ad_unit_id, const std::string& zone_place_location, sdkbox::AdActionType action_type) {
        std::string name("onAdAction");
        jsval dataVal[3];
        dataVal[0] = std_string_to_jsval(s_cx, ad_unit_id);
        dataVal[1] = std_string_to_jsval(s_cx, zone_place_location);
        dataVal[2] = INT_TO_JSVAL(action_type);
        invokeDelegate(name, dataVal, 3);
    }
    
    virtual void onRewardAction( const std::string& ad_unit_id, const std::string& zone_place_location, float reward_amount, bool reward_succeed) {
        std::string name("onRewardAction");
        jsval dataVal[5];
        dataVal[0] = std_string_to_jsval(s_cx, ad_unit_id);
        dataVal[1] = std_string_to_jsval(s_cx, zone_place_location);
        dataVal[2] = DOUBLE_TO_JSVAL(reward_amount);
        dataVal[3] = int32_to_jsval(s_cx, reward_succeed?1:0);
        invokeDelegate(name, dataVal, 4);
    }
    

};


    sdkbox::JS_BOOL js_PluginSdkboxAdsJS_PluginSdkboxAds_setListener(JSContext *cx, uint32_t argc, jsval *vp)
    {
        s_cx = cx;
        JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
        bool ok = true;

        if (argc == 1) {

            if (!args.get(0).isObject())
            {
                ok = false;
            }
            JSObject *tmpObj = args.get(0).toObjectOrNull();

            JSB_PRECONDITION2(ok, cx, false, "js_PluginSdkboxAdsJS_PluginSdkboxAds_setListener : Error processing arguments");
            SdkboxAdsListenerWrapper* wrapper = new SdkboxAdsListenerWrapper();
            wrapper->setJSDelegate(tmpObj);
            sdkbox::PluginSdkboxAds::setListener(wrapper);

            args.rval().setUndefined();
            return true;
        }
        JS_ReportError(cx, "js_PluginSdkboxAdsJS_PluginSdkboxAds_setListener : wrong number of arguments");
        return false;
    }


    sdkbox::JS_BOOL js_PluginSdkboxAdsJS_PluginSdkboxAds_playAd(JSContext *cx, uint32_t argc, jsval *vp)
    {
        JS_FUNCTION_ARGS args = JS_FUNCTION_GET_ARGS(argc, vp);
        JS_BOOL ok = true;
        
        if (argc == 3) {
            
            std::string ad_unit;
            unsigned int i_ad_type;
            std::string ad_name;
            
            ok &= jsval_to_std_string(cx, JS_FUNCTION_ARGS_GET(args,0), &ad_unit);
            JSB_PRECONDITION2(ok, cx, false, "js_PluginSdkboxAdsJS_PluginSdkboxAds_playAd : Error processing arguments");
            
            ok &= jsval_to_std_string(cx, JS_FUNCTION_ARGS_GET(args,1), &ad_name);
            JSB_PRECONDITION2(ok, cx, false, "js_PluginSdkboxAdsJS_PluginSdkboxAds_playAd : Error processing arguments");
            
            std::map<std::string,std::string> req_args;
            ok &= sdkbox::jsval_to_std_map_string_string(cx, JS_FUNCTION_ARGS_GET(args,2), &req_args );
            JSB_PRECONDITION2(ok, cx, false, "Error processing arguments");
            
            sdkbox::PluginSdkboxAds::playAd( ad_unit, ad_name, req_args );
            
            JS_FUNCTION_RETURN_UNDEFINED(cx, args);
            
        } else if ( argc==2 ) {
            
            std::string ad_name;
            
            ok &= jsval_to_std_string(cx, JS_FUNCTION_ARGS_GET(args,0), &ad_name);
            JSB_PRECONDITION2(ok, cx, false, "js_PluginSdkboxAdsJS_PluginSdkboxAds_playAd : Error processing arguments");
            
            std::map<std::string,std::string> req_args;
            ok &= sdkbox::jsval_to_std_map_string_string(cx, JS_FUNCTION_ARGS_GET(args,1), &req_args );
            JSB_PRECONDITION2(ok, cx, false, "Error processing arguments");
            
            sdkbox::PluginSdkboxAds::playAd( ad_name, req_args );
            
            JS_FUNCTION_RETURN_UNDEFINED(cx, args);
        } else if ( argc==0 ) {
            
            sdkbox::PluginSdkboxAds::playAd( );
            
        } else {
            
            JS_ReportError(cx, "js_PluginFacebookJS_PluginFacebook_inviteFriendsWithInviteIds : wrong number of arguments");
        }
        
        return true;
    }


    sdkbox::JS_BOOL js_PluginSdkboxAdsJS_PluginSdkboxAds_cacheControl(JSContext *cx, uint32_t argc, jsval *vp)
    {
        JS_FUNCTION_ARGS args = JS_FUNCTION_GET_ARGS(argc, vp);
        JS_BOOL ok = true;
        
        std::string ad_unit;
        std::map<std::string,std::string> req_args;
        
        ok &= jsval_to_std_string(cx, JS_FUNCTION_ARGS_GET(args,0), &ad_unit);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginSdkboxAds_cacheControl : Error processing arguments");
                
        ok &= sdkbox::jsval_to_std_map_string_string(cx, JS_FUNCTION_ARGS_GET(args,1), &req_args );
        JSB_PRECONDITION2(ok, cx, false, "js_PluginSdkboxAds_cacheControl : Error processing arguments");
        
        sdkbox::PluginSdkboxAds::cacheControl( ad_unit, req_args );
        
        JS_FUNCTION_RETURN_UNDEFINED(cx, args);
        
        return true;
    }

#define REGISTER_SDKBOXADS_FUNCTIONS \
JS_DefineFunction(cx, pluginObj, "setListener", js_PluginSdkboxAdsJS_PluginSdkboxAds_setListener, 1, JSPROP_READONLY | JSPROP_PERMANENT); \
JS_DefineFunction(cx, pluginObj, "playAd",      js_PluginSdkboxAdsJS_PluginSdkboxAds_playAd,      0, JSPROP_READONLY | JSPROP_PERMANENT);

#if defined(MOZJS_MAJOR_VERSION)
    #if MOZJS_MAJOR_VERSION >= 33
    void register_all_PluginSdkboxAdsJS_helper(JSContext* cx, JS::HandleObject global) {
        // Get the ns
        JS::RootedObject pluginObj(cx);
        sdkbox::getJsObjOrCreat(cx, global, "sdkbox.PluginSdkboxAds", &pluginObj);
        
        REGISTER_SDKBOXADS_FUNCTIONS
    }
    #else
    void register_all_PluginSdkboxAdsJS_helper(JSContext* cx, JSObject* obj) {
        // first, try to get the ns
        JS::RootedValue nsval(cx);
        JS::RootedObject pluginObj(cx);
        
        std::stringstream ss("sdkbox.PluginSdkboxAds");
        std::string sub;
        const char* subChar;
        
        while(getline(ss, sub, '.')) {
            if(sub.empty())continue;
            
            subChar = sub.c_str();
            
            JS_GetProperty(cx, obj, subChar, &nsval);
            if (nsval == JSVAL_VOID) {
                pluginObj = JS_NewObject(cx, NULL, NULL, NULL);
                nsval = OBJECT_TO_JSVAL(pluginObj);
                JS_SetProperty(cx, obj, subChar, nsval);
            } else {
                JS_ValueToObject(cx, nsval, &pluginObj);
            }
            obj = pluginObj;
        }
        
        REGISTE_FACEBOOK_FUNCTIONS
    }
    #endif
#elif defined(JS_VERSION)
    void register_all_PluginSdkboxAdsJS_helper(JSContext* cx, JSObject* global) {
        jsval pluginVal;
        JSObject* pluginObj;
        pluginVal = sdkbox::getJsObjOrCreat(cx, global, "sdkbox.PluginSdkboxAds", &pluginObj);
        
        REGISTE_FACEBOOK_FUNCTIONS
    }
#endif

