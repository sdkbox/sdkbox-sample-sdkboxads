#include "PluginLeadBoltLua.hpp"
#include "PluginLeadBolt/PluginLeadBolt.h"
#include "SDKBoxLuaHelper.h"
#include "sdkbox/Sdkbox.h"



int lua_PluginLeadBoltLua_PluginLeadBolt_setCrashHandlerStatus(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginLeadBolt",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "sdkbox.PluginLeadBolt:setCrashHandlerStatus");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginLeadBoltLua_PluginLeadBolt_setCrashHandlerStatus'", nullptr);
            return 0;
        }
        sdkbox::PluginLeadBolt::setCrashHandlerStatus(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginLeadBolt:setCrashHandlerStatus",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginLeadBoltLua_PluginLeadBolt_setCrashHandlerStatus'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginLeadBoltLua_PluginLeadBolt_transaction(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginLeadBolt",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 3)
    {
        std::string arg0;
        double arg1;
        std::string arg2;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginLeadBolt:transaction");
        ok &= luaval_to_number(tolua_S, 3,&arg1, "sdkbox.PluginLeadBolt:transaction");
        ok &= luaval_to_std_string(tolua_S, 4,&arg2, "sdkbox.PluginLeadBolt:transaction");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginLeadBoltLua_PluginLeadBolt_transaction'", nullptr);
            return 0;
        }
        sdkbox::PluginLeadBolt::transaction(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 4)
    {
        std::string arg0;
        double arg1;
        std::string arg2;
        std::string arg3;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginLeadBolt:transaction");
        ok &= luaval_to_number(tolua_S, 3,&arg1, "sdkbox.PluginLeadBolt:transaction");
        ok &= luaval_to_std_string(tolua_S, 4,&arg2, "sdkbox.PluginLeadBolt:transaction");
        ok &= luaval_to_std_string(tolua_S, 5,&arg3, "sdkbox.PluginLeadBolt:transaction");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginLeadBoltLua_PluginLeadBolt_transaction'", nullptr);
            return 0;
        }
        sdkbox::PluginLeadBolt::transaction(arg0, arg1, arg2, arg3);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 5)
    {
        std::string arg0;
        double arg1;
        std::string arg2;
        std::string arg3;
        bool arg4;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginLeadBolt:transaction");
        ok &= luaval_to_number(tolua_S, 3,&arg1, "sdkbox.PluginLeadBolt:transaction");
        ok &= luaval_to_std_string(tolua_S, 4,&arg2, "sdkbox.PluginLeadBolt:transaction");
        ok &= luaval_to_std_string(tolua_S, 5,&arg3, "sdkbox.PluginLeadBolt:transaction");
        ok &= luaval_to_boolean(tolua_S, 6,&arg4, "sdkbox.PluginLeadBolt:transaction");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginLeadBoltLua_PluginLeadBolt_transaction'", nullptr);
            return 0;
        }
        sdkbox::PluginLeadBolt::transaction(arg0, arg1, arg2, arg3, arg4);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginLeadBolt:transaction",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginLeadBoltLua_PluginLeadBolt_transaction'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginLeadBoltLua_PluginLeadBolt_setGender(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginLeadBolt",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginLeadBolt:setGender");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginLeadBoltLua_PluginLeadBolt_setGender'", nullptr);
            return 0;
        }
        sdkbox::PluginLeadBolt::setGender(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginLeadBolt:setGender",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginLeadBoltLua_PluginLeadBolt_setGender'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginLeadBoltLua_PluginLeadBolt_setSyncDataPeriodInSecond(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginLeadBolt",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "sdkbox.PluginLeadBolt:setSyncDataPeriodInSecond");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginLeadBoltLua_PluginLeadBolt_setSyncDataPeriodInSecond'", nullptr);
            return 0;
        }
        sdkbox::PluginLeadBolt::setSyncDataPeriodInSecond(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginLeadBolt:setSyncDataPeriodInSecond",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginLeadBoltLua_PluginLeadBolt_setSyncDataPeriodInSecond'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginLeadBoltLua_PluginLeadBolt_crashWithName(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginLeadBolt",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        std::string arg0;
        std::string arg1;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginLeadBolt:crashWithName");
        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "sdkbox.PluginLeadBolt:crashWithName");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginLeadBoltLua_PluginLeadBolt_crashWithName'", nullptr);
            return 0;
        }
        sdkbox::PluginLeadBolt::crashWithName(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginLeadBolt:crashWithName",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginLeadBoltLua_PluginLeadBolt_crashWithName'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginLeadBoltLua_PluginLeadBolt_closeSession(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginLeadBolt",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginLeadBoltLua_PluginLeadBolt_closeSession'", nullptr);
            return 0;
        }
        sdkbox::PluginLeadBolt::closeSession();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginLeadBolt:closeSession",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginLeadBoltLua_PluginLeadBolt_closeSession'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginLeadBoltLua_PluginLeadBolt_isAdReady(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginLeadBolt",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginLeadBolt:isAdReady");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginLeadBoltLua_PluginLeadBolt_isAdReady'", nullptr);
            return 0;
        }
        bool ret = sdkbox::PluginLeadBolt::isAdReady(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginLeadBolt:isAdReady",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginLeadBoltLua_PluginLeadBolt_isAdReady'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginLeadBoltLua_PluginLeadBolt_sync(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginLeadBolt",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginLeadBoltLua_PluginLeadBolt_sync'", nullptr);
            return 0;
        }
        sdkbox::PluginLeadBolt::sync();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginLeadBolt:sync",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginLeadBoltLua_PluginLeadBolt_sync'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginLeadBoltLua_PluginLeadBolt_fixAdOrientation(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginLeadBolt",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        sdkbox::PluginLeadBolt::AdOrientation arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "sdkbox.PluginLeadBolt:fixAdOrientation");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginLeadBoltLua_PluginLeadBolt_fixAdOrientation'", nullptr);
            return 0;
        }
        sdkbox::PluginLeadBolt::fixAdOrientation(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginLeadBolt:fixAdOrientation",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginLeadBoltLua_PluginLeadBolt_fixAdOrientation'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginLeadBoltLua_PluginLeadBolt_init(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginLeadBolt",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginLeadBoltLua_PluginLeadBolt_init'", nullptr);
            return 0;
        }
        bool ret = sdkbox::PluginLeadBolt::init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginLeadBolt:init",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginLeadBoltLua_PluginLeadBolt_init'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginLeadBoltLua_PluginLeadBolt_startSession(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginLeadBolt",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginLeadBolt:startSession");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginLeadBoltLua_PluginLeadBolt_startSession'", nullptr);
            return 0;
        }
        sdkbox::PluginLeadBolt::startSession(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginLeadBolt:startSession",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginLeadBoltLua_PluginLeadBolt_startSession'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginLeadBoltLua_PluginLeadBolt_loadModule(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginLeadBolt",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginLeadBolt:loadModule");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginLeadBoltLua_PluginLeadBolt_loadModule'", nullptr);
            return 0;
        }
        sdkbox::PluginLeadBolt::loadModule(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 2)
    {
        std::string arg0;
        std::string arg1;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginLeadBolt:loadModule");
        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "sdkbox.PluginLeadBolt:loadModule");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginLeadBoltLua_PluginLeadBolt_loadModule'", nullptr);
            return 0;
        }
        sdkbox::PluginLeadBolt::loadModule(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginLeadBolt:loadModule",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginLeadBoltLua_PluginLeadBolt_loadModule'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginLeadBoltLua_PluginLeadBolt_setFramework(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginLeadBolt",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginLeadBolt:setFramework");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginLeadBoltLua_PluginLeadBolt_setFramework'", nullptr);
            return 0;
        }
        sdkbox::PluginLeadBolt::setFramework(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginLeadBolt:setFramework",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginLeadBoltLua_PluginLeadBolt_setFramework'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginLeadBoltLua_PluginLeadBolt_destroyModule(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginLeadBolt",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginLeadBoltLua_PluginLeadBolt_destroyModule'", nullptr);
            return 0;
        }
        sdkbox::PluginLeadBolt::destroyModule();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginLeadBolt:destroyModule",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginLeadBoltLua_PluginLeadBolt_destroyModule'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginLeadBoltLua_PluginLeadBolt_setAgeRange(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginLeadBolt",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginLeadBolt:setAgeRange");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginLeadBoltLua_PluginLeadBolt_setAgeRange'", nullptr);
            return 0;
        }
        sdkbox::PluginLeadBolt::setAgeRange(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginLeadBolt:setAgeRange",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginLeadBoltLua_PluginLeadBolt_setAgeRange'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginLeadBoltLua_PluginLeadBolt_event(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginLeadBolt",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 2)
        {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginLeadBolt:event");
            if (!ok) { break; }
            double arg1;
            ok &= luaval_to_number(tolua_S, 3,&arg1, "sdkbox.PluginLeadBolt:event");
            if (!ok) { break; }
            sdkbox::PluginLeadBolt::event(arg0, arg1);
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 1)
        {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginLeadBolt:event");
            if (!ok) { break; }
            sdkbox::PluginLeadBolt::event(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d", "sdkbox.PluginLeadBolt:event",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginLeadBoltLua_PluginLeadBolt_event'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginLeadBoltLua_PluginLeadBolt_loadModuleToCache(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginLeadBolt",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginLeadBolt:loadModuleToCache");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginLeadBoltLua_PluginLeadBolt_loadModuleToCache'", nullptr);
            return 0;
        }
        sdkbox::PluginLeadBolt::loadModuleToCache(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 2)
    {
        std::string arg0;
        std::string arg1;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginLeadBolt:loadModuleToCache");
        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "sdkbox.PluginLeadBolt:loadModuleToCache");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginLeadBoltLua_PluginLeadBolt_loadModuleToCache'", nullptr);
            return 0;
        }
        sdkbox::PluginLeadBolt::loadModuleToCache(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginLeadBolt:loadModuleToCache",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginLeadBoltLua_PluginLeadBolt_loadModuleToCache'.",&tolua_err);
#endif
    return 0;
}
static int lua_PluginLeadBoltLua_PluginLeadBolt_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (PluginLeadBolt)");
    return 0;
}

int lua_register_PluginLeadBoltLua_PluginLeadBolt(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"sdkbox.PluginLeadBolt");
    tolua_cclass(tolua_S,"PluginLeadBolt","sdkbox.PluginLeadBolt","",nullptr);

    tolua_beginmodule(tolua_S,"PluginLeadBolt");
        tolua_function(tolua_S,"setCrashHandlerStatus", lua_PluginLeadBoltLua_PluginLeadBolt_setCrashHandlerStatus);
        tolua_function(tolua_S,"transaction", lua_PluginLeadBoltLua_PluginLeadBolt_transaction);
        tolua_function(tolua_S,"setGender", lua_PluginLeadBoltLua_PluginLeadBolt_setGender);
        tolua_function(tolua_S,"setSyncDataPeriodInSecond", lua_PluginLeadBoltLua_PluginLeadBolt_setSyncDataPeriodInSecond);
        tolua_function(tolua_S,"crashWithName", lua_PluginLeadBoltLua_PluginLeadBolt_crashWithName);
        tolua_function(tolua_S,"closeSession", lua_PluginLeadBoltLua_PluginLeadBolt_closeSession);
        tolua_function(tolua_S,"isAdReady", lua_PluginLeadBoltLua_PluginLeadBolt_isAdReady);
        tolua_function(tolua_S,"sync", lua_PluginLeadBoltLua_PluginLeadBolt_sync);
        tolua_function(tolua_S,"fixAdOrientation", lua_PluginLeadBoltLua_PluginLeadBolt_fixAdOrientation);
        tolua_function(tolua_S,"init", lua_PluginLeadBoltLua_PluginLeadBolt_init);
        tolua_function(tolua_S,"startSession", lua_PluginLeadBoltLua_PluginLeadBolt_startSession);
        tolua_function(tolua_S,"loadModule", lua_PluginLeadBoltLua_PluginLeadBolt_loadModule);
        tolua_function(tolua_S,"setFramework", lua_PluginLeadBoltLua_PluginLeadBolt_setFramework);
        tolua_function(tolua_S,"destroyModule", lua_PluginLeadBoltLua_PluginLeadBolt_destroyModule);
        tolua_function(tolua_S,"setAgeRange", lua_PluginLeadBoltLua_PluginLeadBolt_setAgeRange);
        tolua_function(tolua_S,"event", lua_PluginLeadBoltLua_PluginLeadBolt_event);
        tolua_function(tolua_S,"loadModuleToCache", lua_PluginLeadBoltLua_PluginLeadBolt_loadModuleToCache);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(sdkbox::PluginLeadBolt).name();
    g_luaType[typeName] = "sdkbox.PluginLeadBolt";
    g_typeCast["PluginLeadBolt"] = "sdkbox.PluginLeadBolt";
    return 1;
}
TOLUA_API int register_all_PluginLeadBoltLua(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"sdkbox",0);
	tolua_beginmodule(tolua_S,"sdkbox");

	lua_register_PluginLeadBoltLua_PluginLeadBolt(tolua_S);

	tolua_endmodule(tolua_S);

	sdkbox::setProjectType("lua");
	return 1;
}

