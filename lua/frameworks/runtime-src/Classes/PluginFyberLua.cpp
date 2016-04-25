#include "PluginFyberLua.hpp"
#include "PluginFyber/PluginFyber.h"
#include "tolua_fix.h"
#include "SDKBoxLuaHelper.h"
#include "sdkbox/Sdkbox.h"



int lua_PluginFyberLua_PluginFyber_showOffers(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginFyber",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFyberLua_PluginFyber_showOffers'", nullptr);
            return 0;
        }
        sdkbox::PluginFyber::showOffers();
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginFyber:showOffers");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFyberLua_PluginFyber_showOffers'", nullptr);
            return 0;
        }
        sdkbox::PluginFyber::showOffers(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFyber:showOffers",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFyberLua_PluginFyber_showOffers'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFyberLua_PluginFyber_requestInterstitial(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginFyber",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFyberLua_PluginFyber_requestInterstitial'", nullptr);
            return 0;
        }
        sdkbox::PluginFyber::requestInterstitial();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFyber:requestInterstitial",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFyberLua_PluginFyber_requestInterstitial'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFyberLua_PluginFyber_showOfferWall(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginFyber",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFyberLua_PluginFyber_showOfferWall'", nullptr);
            return 0;
        }
        sdkbox::PluginFyber::showOfferWall();
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginFyber:showOfferWall");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFyberLua_PluginFyber_showOfferWall'", nullptr);
            return 0;
        }
        sdkbox::PluginFyber::showOfferWall(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFyber:showOfferWall",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFyberLua_PluginFyber_showOfferWall'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFyberLua_PluginFyber_requestDeltaOfCoins(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginFyber",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFyberLua_PluginFyber_requestDeltaOfCoins'", nullptr);
            return 0;
        }
        sdkbox::PluginFyber::requestDeltaOfCoins();
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginFyber:requestDeltaOfCoins");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFyberLua_PluginFyber_requestDeltaOfCoins'", nullptr);
            return 0;
        }
        sdkbox::PluginFyber::requestDeltaOfCoins(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFyber:requestDeltaOfCoins",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFyberLua_PluginFyber_requestDeltaOfCoins'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFyberLua_PluginFyber_showInterstitial(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginFyber",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFyberLua_PluginFyber_showInterstitial'", nullptr);
            return 0;
        }
        sdkbox::PluginFyber::showInterstitial();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFyber:showInterstitial",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFyberLua_PluginFyber_showInterstitial'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFyberLua_PluginFyber_requestOffers(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginFyber",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFyberLua_PluginFyber_requestOffers'", nullptr);
            return 0;
        }
        sdkbox::PluginFyber::requestOffers();
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginFyber:requestOffers");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFyberLua_PluginFyber_requestOffers'", nullptr);
            return 0;
        }
        sdkbox::PluginFyber::requestOffers(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFyber:requestOffers",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFyberLua_PluginFyber_requestOffers'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFyberLua_PluginFyber_init(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginFyber",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFyberLua_PluginFyber_init'", nullptr);
            return 0;
        }
        sdkbox::PluginFyber::init();
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginFyber:init");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFyberLua_PluginFyber_init'", nullptr);
            return 0;
        }
        sdkbox::PluginFyber::init(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFyber:init",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFyberLua_PluginFyber_init'.",&tolua_err);
#endif
    return 0;
}
static int lua_PluginFyberLua_PluginFyber_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (PluginFyber)");
    return 0;
}

int lua_register_PluginFyberLua_PluginFyber(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"sdkbox.PluginFyber");
    tolua_cclass(tolua_S,"PluginFyber","sdkbox.PluginFyber","",nullptr);

    tolua_beginmodule(tolua_S,"PluginFyber");
        tolua_function(tolua_S,"showOffers", lua_PluginFyberLua_PluginFyber_showOffers);
        tolua_function(tolua_S,"requestInterstitial", lua_PluginFyberLua_PluginFyber_requestInterstitial);
        tolua_function(tolua_S,"showOfferWall", lua_PluginFyberLua_PluginFyber_showOfferWall);
        tolua_function(tolua_S,"requestDeltaOfCoins", lua_PluginFyberLua_PluginFyber_requestDeltaOfCoins);
        tolua_function(tolua_S,"showInterstitial", lua_PluginFyberLua_PluginFyber_showInterstitial);
        tolua_function(tolua_S,"requestOffers", lua_PluginFyberLua_PluginFyber_requestOffers);
        tolua_function(tolua_S,"init", lua_PluginFyberLua_PluginFyber_init);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(sdkbox::PluginFyber).name();
    g_luaType[typeName] = "sdkbox.PluginFyber";
    g_typeCast["PluginFyber"] = "sdkbox.PluginFyber";
    return 1;
}
TOLUA_API int register_all_PluginFyberLua(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"sdkbox",0);
	tolua_beginmodule(tolua_S,"sdkbox");

	lua_register_PluginFyberLua_PluginFyber(tolua_S);

	tolua_endmodule(tolua_S);

	sdkbox::setProjectType("lua");
	return 1;
}

