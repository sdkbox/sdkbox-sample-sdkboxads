#include "PluginFyberLua.hpp"
#include "PluginFyber/PluginFyber.h"
#include "SDKBoxLuaHelper.h"
#include "sdkbox/Sdkbox.h"



int lua_PluginFyberLua_PluginFyber_setZipcode(lua_State* tolua_S)
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

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginFyber:setZipcode");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFyberLua_PluginFyber_setZipcode'", nullptr);
            return 0;
        }
        sdkbox::PluginFyber::setZipcode(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFyber:setZipcode",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFyberLua_PluginFyber_setZipcode'.",&tolua_err);
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
int lua_PluginFyberLua_PluginFyber_setNumberOfSessions(lua_State* tolua_S)
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

    if (argc == 1)
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "sdkbox.PluginFyber:setNumberOfSessions");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFyberLua_PluginFyber_setNumberOfSessions'", nullptr);
            return 0;
        }
        sdkbox::PluginFyber::setNumberOfSessions(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFyber:setNumberOfSessions",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFyberLua_PluginFyber_setNumberOfSessions'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFyberLua_PluginFyber_setNumberOfChildren(lua_State* tolua_S)
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

    if (argc == 1)
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "sdkbox.PluginFyber:setNumberOfChildren");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFyberLua_PluginFyber_setNumberOfChildren'", nullptr);
            return 0;
        }
        sdkbox::PluginFyber::setNumberOfChildren(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFyber:setNumberOfChildren",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFyberLua_PluginFyber_setNumberOfChildren'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFyberLua_PluginFyber_setLocation(lua_State* tolua_S)
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

    if (argc == 2)
    {
        double arg0;
        double arg1;
        ok &= luaval_to_number(tolua_S, 2,&arg0, "sdkbox.PluginFyber:setLocation");
        ok &= luaval_to_number(tolua_S, 3,&arg1, "sdkbox.PluginFyber:setLocation");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFyberLua_PluginFyber_setLocation'", nullptr);
            return 0;
        }
        sdkbox::PluginFyber::setLocation(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFyber:setLocation",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFyberLua_PluginFyber_setLocation'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFyberLua_PluginFyber_setIap(lua_State* tolua_S)
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

    if (argc == 1)
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "sdkbox.PluginFyber:setIap");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFyberLua_PluginFyber_setIap'", nullptr);
            return 0;
        }
        sdkbox::PluginFyber::setIap(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFyber:setIap",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFyberLua_PluginFyber_setIap'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFyberLua_PluginFyber_setVersion(lua_State* tolua_S)
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

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginFyber:setVersion");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFyberLua_PluginFyber_setVersion'", nullptr);
            return 0;
        }
        sdkbox::PluginFyber::setVersion(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFyber:setVersion",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFyberLua_PluginFyber_setVersion'.",&tolua_err);
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
    if (argc == 2)
    {
        std::string arg0;
        const char* arg1;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginFyber:init");
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "sdkbox.PluginFyber:init"); arg1 = arg1_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFyberLua_PluginFyber_init'", nullptr);
            return 0;
        }
        sdkbox::PluginFyber::init(arg0, arg1);
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
int lua_PluginFyberLua_PluginFyber_setDevice(lua_State* tolua_S)
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

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginFyber:setDevice");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFyberLua_PluginFyber_setDevice'", nullptr);
            return 0;
        }
        sdkbox::PluginFyber::setDevice(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFyber:setDevice",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFyberLua_PluginFyber_setDevice'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFyberLua_PluginFyber_setLastSession(lua_State* tolua_S)
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

    if (argc == 1)
    {
        double arg0;
        ok &= luaval_to_number(tolua_S, 2,&arg0, "sdkbox.PluginFyber:setLastSession");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFyberLua_PluginFyber_setLastSession'", nullptr);
            return 0;
        }
        sdkbox::PluginFyber::setLastSession(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFyber:setLastSession",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFyberLua_PluginFyber_setLastSession'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFyberLua_PluginFyber_setAnnualHouseholdIncome(lua_State* tolua_S)
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

    if (argc == 1)
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "sdkbox.PluginFyber:setAnnualHouseholdIncome");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFyberLua_PluginFyber_setAnnualHouseholdIncome'", nullptr);
            return 0;
        }
        sdkbox::PluginFyber::setAnnualHouseholdIncome(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFyber:setAnnualHouseholdIncome",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFyberLua_PluginFyber_setAnnualHouseholdIncome'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFyberLua_PluginFyber_setMaritalStatus(lua_State* tolua_S)
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

    if (argc == 1)
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "sdkbox.PluginFyber:setMaritalStatus");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFyberLua_PluginFyber_setMaritalStatus'", nullptr);
            return 0;
        }
        sdkbox::PluginFyber::setMaritalStatus(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFyber:setMaritalStatus",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFyberLua_PluginFyber_setMaritalStatus'.",&tolua_err);
#endif
    return 0;
}
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
int lua_PluginFyberLua_PluginFyber_cleanLocation(lua_State* tolua_S)
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFyberLua_PluginFyber_cleanLocation'", nullptr);
            return 0;
        }
        sdkbox::PluginFyber::cleanLocation();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFyber:cleanLocation",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFyberLua_PluginFyber_cleanLocation'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFyberLua_PluginFyber_setSexualOrientation(lua_State* tolua_S)
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

    if (argc == 1)
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "sdkbox.PluginFyber:setSexualOrientation");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFyberLua_PluginFyber_setSexualOrientation'", nullptr);
            return 0;
        }
        sdkbox::PluginFyber::setSexualOrientation(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFyber:setSexualOrientation",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFyberLua_PluginFyber_setSexualOrientation'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFyberLua_PluginFyber_setGender(lua_State* tolua_S)
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

    if (argc == 1)
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "sdkbox.PluginFyber:setGender");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFyberLua_PluginFyber_setGender'", nullptr);
            return 0;
        }
        sdkbox::PluginFyber::setGender(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFyber:setGender",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFyberLua_PluginFyber_setGender'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFyberLua_PluginFyber_setBirthdate(lua_State* tolua_S)
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

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginFyber:setBirthdate");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFyberLua_PluginFyber_setBirthdate'", nullptr);
            return 0;
        }
        sdkbox::PluginFyber::setBirthdate(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFyber:setBirthdate",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFyberLua_PluginFyber_setBirthdate'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFyberLua_PluginFyber_setAge(lua_State* tolua_S)
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

    if (argc == 1)
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "sdkbox.PluginFyber:setAge");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFyberLua_PluginFyber_setAge'", nullptr);
            return 0;
        }
        sdkbox::PluginFyber::setAge(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFyber:setAge",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFyberLua_PluginFyber_setAge'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFyberLua_PluginFyber_setConnectionType(lua_State* tolua_S)
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

    if (argc == 1)
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "sdkbox.PluginFyber:setConnectionType");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFyberLua_PluginFyber_setConnectionType'", nullptr);
            return 0;
        }
        sdkbox::PluginFyber::setConnectionType(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFyber:setConnectionType",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFyberLua_PluginFyber_setConnectionType'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFyberLua_PluginFyber_addCustomParameters(lua_State* tolua_S)
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

    if (argc == 2)
    {
        std::string arg0;
        std::string arg1;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginFyber:addCustomParameters");
        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "sdkbox.PluginFyber:addCustomParameters");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFyberLua_PluginFyber_addCustomParameters'", nullptr);
            return 0;
        }
        sdkbox::PluginFyber::addCustomParameters(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFyber:addCustomParameters",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFyberLua_PluginFyber_addCustomParameters'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFyberLua_PluginFyber_setInterests(lua_State* tolua_S)
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

    if (argc == 1)
    {
        std::vector<std::string> arg0;
        ok &= luaval_to_std_vector_string(tolua_S, 2, &arg0, "sdkbox.PluginFyber:setInterests");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFyberLua_PluginFyber_setInterests'", nullptr);
            return 0;
        }
        sdkbox::PluginFyber::setInterests(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFyber:setInterests",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFyberLua_PluginFyber_setInterests'.",&tolua_err);
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
int lua_PluginFyberLua_PluginFyber_setPsTime(lua_State* tolua_S)
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

    if (argc == 1)
    {
        double arg0;
        ok &= luaval_to_number(tolua_S, 2,&arg0, "sdkbox.PluginFyber:setPsTime");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFyberLua_PluginFyber_setPsTime'", nullptr);
            return 0;
        }
        sdkbox::PluginFyber::setPsTime(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFyber:setPsTime",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFyberLua_PluginFyber_setPsTime'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFyberLua_PluginFyber_cleanCustomParameters(lua_State* tolua_S)
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFyberLua_PluginFyber_cleanCustomParameters'", nullptr);
            return 0;
        }
        sdkbox::PluginFyber::cleanCustomParameters();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFyber:cleanCustomParameters",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFyberLua_PluginFyber_cleanCustomParameters'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFyberLua_PluginFyber_setIapAmount(lua_State* tolua_S)
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

    if (argc == 1)
    {
        double arg0;
        ok &= luaval_to_number(tolua_S, 2,&arg0, "sdkbox.PluginFyber:setIapAmount");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFyberLua_PluginFyber_setIapAmount'", nullptr);
            return 0;
        }
        sdkbox::PluginFyber::setIapAmount(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFyber:setIapAmount",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFyberLua_PluginFyber_setIapAmount'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFyberLua_PluginFyber_setEthnicity(lua_State* tolua_S)
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

    if (argc == 1)
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "sdkbox.PluginFyber:setEthnicity");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFyberLua_PluginFyber_setEthnicity'", nullptr);
            return 0;
        }
        sdkbox::PluginFyber::setEthnicity(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFyber:setEthnicity",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFyberLua_PluginFyber_setEthnicity'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFyberLua_PluginFyber_setEducation(lua_State* tolua_S)
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

    if (argc == 1)
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "sdkbox.PluginFyber:setEducation");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFyberLua_PluginFyber_setEducation'", nullptr);
            return 0;
        }
        sdkbox::PluginFyber::setEducation(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFyber:setEducation",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFyberLua_PluginFyber_setEducation'.",&tolua_err);
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
        tolua_function(tolua_S,"setZipcode", lua_PluginFyberLua_PluginFyber_setZipcode);
        tolua_function(tolua_S,"showInterstitial", lua_PluginFyberLua_PluginFyber_showInterstitial);
        tolua_function(tolua_S,"setNumberOfSessions", lua_PluginFyberLua_PluginFyber_setNumberOfSessions);
        tolua_function(tolua_S,"setNumberOfChildren", lua_PluginFyberLua_PluginFyber_setNumberOfChildren);
        tolua_function(tolua_S,"setLocation", lua_PluginFyberLua_PluginFyber_setLocation);
        tolua_function(tolua_S,"setIap", lua_PluginFyberLua_PluginFyber_setIap);
        tolua_function(tolua_S,"setVersion", lua_PluginFyberLua_PluginFyber_setVersion);
        tolua_function(tolua_S,"requestInterstitial", lua_PluginFyberLua_PluginFyber_requestInterstitial);
        tolua_function(tolua_S,"showOfferWall", lua_PluginFyberLua_PluginFyber_showOfferWall);
        tolua_function(tolua_S,"requestOffers", lua_PluginFyberLua_PluginFyber_requestOffers);
        tolua_function(tolua_S,"init", lua_PluginFyberLua_PluginFyber_init);
        tolua_function(tolua_S,"setDevice", lua_PluginFyberLua_PluginFyber_setDevice);
        tolua_function(tolua_S,"setLastSession", lua_PluginFyberLua_PluginFyber_setLastSession);
        tolua_function(tolua_S,"setAnnualHouseholdIncome", lua_PluginFyberLua_PluginFyber_setAnnualHouseholdIncome);
        tolua_function(tolua_S,"setMaritalStatus", lua_PluginFyberLua_PluginFyber_setMaritalStatus);
        tolua_function(tolua_S,"showOffers", lua_PluginFyberLua_PluginFyber_showOffers);
        tolua_function(tolua_S,"cleanLocation", lua_PluginFyberLua_PluginFyber_cleanLocation);
        tolua_function(tolua_S,"setSexualOrientation", lua_PluginFyberLua_PluginFyber_setSexualOrientation);
        tolua_function(tolua_S,"setGender", lua_PluginFyberLua_PluginFyber_setGender);
        tolua_function(tolua_S,"setBirthdate", lua_PluginFyberLua_PluginFyber_setBirthdate);
        tolua_function(tolua_S,"setAge", lua_PluginFyberLua_PluginFyber_setAge);
        tolua_function(tolua_S,"setConnectionType", lua_PluginFyberLua_PluginFyber_setConnectionType);
        tolua_function(tolua_S,"addCustomParameters", lua_PluginFyberLua_PluginFyber_addCustomParameters);
        tolua_function(tolua_S,"setInterests", lua_PluginFyberLua_PluginFyber_setInterests);
        tolua_function(tolua_S,"requestDeltaOfCoins", lua_PluginFyberLua_PluginFyber_requestDeltaOfCoins);
        tolua_function(tolua_S,"setPsTime", lua_PluginFyberLua_PluginFyber_setPsTime);
        tolua_function(tolua_S,"cleanCustomParameters", lua_PluginFyberLua_PluginFyber_cleanCustomParameters);
        tolua_function(tolua_S,"setIapAmount", lua_PluginFyberLua_PluginFyber_setIapAmount);
        tolua_function(tolua_S,"setEthnicity", lua_PluginFyberLua_PluginFyber_setEthnicity);
        tolua_function(tolua_S,"setEducation", lua_PluginFyberLua_PluginFyber_setEducation);
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

