#include "PluginSdkboxAdsLua.hpp"
#include "PluginSdkboxAds/PluginSdkboxAds.h"
#include "tolua_fix.h"
#include "SDKBoxLuaHelper.h"
#include "sdkbox/Sdkbox.h"



int lua_PluginSdkboxAdsLua_PluginSdkboxAds_placement(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginSdkboxAds",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginSdkboxAds:placement");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginSdkboxAdsLua_PluginSdkboxAds_placement'", nullptr);
            return 0;
        }
        sdkbox::PluginSdkboxAds::placement(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginSdkboxAds:placement",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginSdkboxAdsLua_PluginSdkboxAds_placement'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginSdkboxAdsLua_PluginSdkboxAds_init(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginSdkboxAds",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginSdkboxAdsLua_PluginSdkboxAds_init'", nullptr);
            return 0;
        }
        sdkbox::PluginSdkboxAds::init();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginSdkboxAds:init",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginSdkboxAdsLua_PluginSdkboxAds_init'.",&tolua_err);
#endif
    return 0;
}
static int lua_PluginSdkboxAdsLua_PluginSdkboxAds_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (PluginSdkboxAds)");
    return 0;
}

int lua_register_PluginSdkboxAdsLua_PluginSdkboxAds(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"sdkbox.PluginSdkboxAds");
    tolua_cclass(tolua_S,"PluginSdkboxAds","sdkbox.PluginSdkboxAds","",nullptr);

    tolua_beginmodule(tolua_S,"PluginSdkboxAds");
        tolua_function(tolua_S,"placement", lua_PluginSdkboxAdsLua_PluginSdkboxAds_placement);
        tolua_function(tolua_S,"init", lua_PluginSdkboxAdsLua_PluginSdkboxAds_init);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(sdkbox::PluginSdkboxAds).name();
    g_luaType[typeName] = "sdkbox.PluginSdkboxAds";
    g_typeCast["PluginSdkboxAds"] = "sdkbox.PluginSdkboxAds";
    return 1;
}
TOLUA_API int register_all_PluginSdkboxAdsLua(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"sdkbox",0);
	tolua_beginmodule(tolua_S,"sdkbox");

	lua_register_PluginSdkboxAdsLua_PluginSdkboxAds(tolua_S);

	tolua_endmodule(tolua_S);

	sdkbox::setProjectType("lua");
	return 1;
}

