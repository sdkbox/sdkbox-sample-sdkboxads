
#include "PluginSdkboxAdsLuaHelper.h"
#include "PluginSdkboxAds/PluginSdkboxAds.h"
#include "SDKBoxLuaHelper.h"

class SdkboxAdsListenerLua : public sdkbox::PluginSdkboxAdsListener {
public:
    SdkboxAdsListenerLua(): mLuaHandler(0) {

    }
    ~SdkboxAdsListenerLua() {
        resetHandler();
    }

    void setHandler(int luaHandler) {
        if (mLuaHandler == luaHandler) {
            return;
        }
        resetHandler();
        mLuaHandler = luaHandler;
    }

    void resetHandler() {
        if (0 == mLuaHandler) {
            return;
        }

        LUAENGINE->removeScriptHandler(mLuaHandler);
        mLuaHandler = 0;
    }


    virtual void onAdAction( const std::string& ad_unit_id, const std::string& zone_place_location, sdkbox::AdActionType action_type) {
        LuaStack* stack = LUAENGINE->getLuaStack();

        LuaValueDict dict;
        dict.insert(std::make_pair("name", LuaValue::stringValue("onAdAction")));
        dict.insert(std::make_pair("ad_unit_id", LuaValue::stringValue(ad_unit_id)));
        dict.insert(std::make_pair("ad_name", LuaValue::stringValue(zone_place_location)));
        dict.insert(std::make_pair("ad_action_type", LuaValue::intValue((int)action_type)));
        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }

    virtual void onRewardAction(
        const std::string& ad_unit_id,
        const std::string& zone_place_location,
        float reward_amount,
        bool reward_succeed) {

        LuaStack* stack = LUAENGINE->getLuaStack();

        LuaValueDict dict;
        dict.insert(std::make_pair("name", LuaValue::stringValue("onRewardAction")));
        dict.insert(std::make_pair("ad_unit_id", LuaValue::stringValue(ad_unit_id)));
        dict.insert(std::make_pair("ad_name", LuaValue::stringValue(zone_place_location)));
        dict.insert(std::make_pair("reward_amount", LuaValue::floatValue(reward_amount)));
        dict.insert(std::make_pair("reward_succeed", LuaValue::booleanValue(reward_succeed)));
        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);

    }

private:
    int mLuaHandler;
};

int lua_PluginSdkboxAdsLua_PluginSdkboxAds_setListener(lua_State* tolua_S) {
    int argc = 0;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginSdkboxAds",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
#if COCOS2D_DEBUG >= 1
        if (!toluafix_isfunction(tolua_S, 2 , "LUA_FUNCTION",0,&tolua_err))
        {
            goto tolua_lerror;
        }
#endif
        LUA_FUNCTION handler = (  toluafix_ref_function(tolua_S,2,0));
        SdkboxAdsListenerLua* lis = static_cast<SdkboxAdsListenerLua*> (sdkbox::PluginSdkboxAds::getListener());
        if (nullptr == lis) {
            lis = new SdkboxAdsListenerLua();
        }
        lis->setHandler(handler);
        sdkbox::PluginSdkboxAds::setListener(lis);

        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginSdkboxAds::setListener",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginSdkboxAdsLua_PluginSdkboxAds_setListener'.",&tolua_err);
#endif
    return 0;
}


int lua_PluginSdkboxAdsLua_PluginSdkboxAds_playAd(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginSdkboxAds",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do
    {
        if (argc == 2)
        {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginSdkboxAds:playAd");
            if (!ok) { break; }

            if (lua_isstring(tolua_S, -1)) {
                std::string arg1;
                ok &= luaval_to_std_string(tolua_S, 3, &arg1);
                if (!ok) { break; }
                sdkbox::PluginSdkboxAds::playAd(arg0, arg1);
            } else if (lua_istable(tolua_S, -1)) {
                std::map<std::string,std::string> arg1;
                ok&=luaval_to_std_map_string_string( tolua_S, 3, &arg1, "sdkbox.PluginSdkboxAds:playAd");

                if (!ok) { break; }
                sdkbox::PluginSdkboxAds::playAd(arg0, arg1);
            }

            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);
    ok  = true;
    do
    {
        if (argc == 3)
        {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginSdkboxAds:playAd");
            if (!ok) { break; }
            std::string arg1;
            ok &= luaval_to_std_string(tolua_S, 3,&arg1, "sdkbox.PluginSdkboxAds:playAd");
            if (!ok) { break; }
            std::map<std::string,std::string> arg2;
            ok&=luaval_to_std_map_string_string( tolua_S, 4, &arg2, "sdkbox.PluginSdkboxAds:playAd");
            if (!ok) { break; }
            sdkbox::PluginSdkboxAds::playAd(arg0, arg1, arg2);
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);
    ok  = true;
    do
    {
        if (argc == 0)
        {
            sdkbox::PluginSdkboxAds::playAd();
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d", "sdkbox.PluginSdkboxAds:playAd",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginSdkboxAdsLua_PluginSdkboxAds_playAd'.",&tolua_err);
#endif
    return 0;
}


int lua_PluginSdkboxAdsLua_PluginSdkboxAds_cacheControl(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

    std::string arg0;
    std::map<std::string,std::string> arg2;

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginSdkboxAds",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;


    ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginSdkboxAds:cacheControl");
    ok&=luaval_to_std_map_string_string( tolua_S, 3, &arg2, "sdkbox.PluginSdkboxAds:cacheControl");
    if (ok) {
        sdkbox::PluginSdkboxAds::cacheControl(arg0, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginSdkboxAdsLua_PluginSdkboxAds_cacheControl'.",&tolua_err);
#endif

    return 0;
}

int extern_PluginSdkboxAds(lua_State* L) {
    if (nullptr == L) {
        return 0;
    }

    lua_pushstring(L, "sdkbox.PluginSdkboxAds");
    lua_rawget(L, LUA_REGISTRYINDEX);
    if (lua_istable(L,-1))
    {
        tolua_function(L,"setListener", lua_PluginSdkboxAdsLua_PluginSdkboxAds_setListener);
        tolua_function(L,"playAd", lua_PluginSdkboxAdsLua_PluginSdkboxAds_playAd);
        tolua_function(L, "cacheControl", lua_PluginSdkboxAdsLua_PluginSdkboxAds_cacheControl);
    }
     lua_pop(L, 1);

    return 1;
}

TOLUA_API int register_all_PluginSdkboxAdsLua_helper(lua_State* L) {
    tolua_module(L,"sdkbox",0);
    tolua_beginmodule(L,"sdkbox");

    extern_PluginSdkboxAds(L);

    tolua_endmodule(L);
    return 1;
}


