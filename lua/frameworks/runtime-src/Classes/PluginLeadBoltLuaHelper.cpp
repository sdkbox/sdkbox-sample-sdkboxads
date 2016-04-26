
#include "PluginLeadBoltLuaHelper.h"
#include "PluginLeadBolt/PluginLeadBolt.h"
#include "CCLuaEngine.h"
#include "tolua_fix.h"
#include "SDKBoxLuaHelper.h"

class LeadBoltListenerLua : public sdkbox::LeadBoltListener {
public:
    LeadBoltListenerLua(): mLuaHandler(0) {
    }

    ~LeadBoltListenerLua() {
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


    void onModuleLoaded(const std::string& placement) {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;

        dict.insert(std::make_pair("event", LuaValue::stringValue("onModuleLoaded")));
        dict.insert(std::make_pair("placement", LuaValue::stringValue(placement)));

        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }

    void onModuleClosed(const std::string& placement) {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;

        dict.insert(std::make_pair("event", LuaValue::stringValue("onModuleClosed")));
        dict.insert(std::make_pair("placement", LuaValue::stringValue(placement)));

        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }

    void onModuleClicked(const std::string& placement) {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;

        dict.insert(std::make_pair("event", LuaValue::stringValue("onModuleClicked")));
        dict.insert(std::make_pair("placement", LuaValue::stringValue(placement)));

        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }

    void onModuleCached(const std::string& placement) {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;

        dict.insert(std::make_pair("event", LuaValue::stringValue("onModuleCached")));
        dict.insert(std::make_pair("placement", LuaValue::stringValue(placement)));

        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }

    void onModuleFailed(const std::string& placement, const std::string& error, bool iscached) {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;

        dict.insert(std::make_pair("event", LuaValue::stringValue("onModuleFailed")));
        dict.insert(std::make_pair("placement", LuaValue::stringValue(placement)));
        dict.insert(std::make_pair("error", LuaValue::stringValue(error)));
        dict.insert(std::make_pair("iscached", LuaValue::booleanValue(iscached)));

        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }

    void onMediaFinished(bool viewCompleted) {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;

        dict.insert(std::make_pair("event", LuaValue::stringValue("onMediaFinished")));
        dict.insert(std::make_pair("viewCompleted", LuaValue::booleanValue(viewCompleted)));

        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }

private:
    int mLuaHandler;
};

int lua_PluginLeadBoltLua_PluginLeadBolt_setListener(lua_State* tolua_S) {
    int argc = 0;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginLeadBolt",0,&tolua_err)) goto tolua_lerror;
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
        LeadBoltListenerLua* lis = static_cast<LeadBoltListenerLua*> (sdkbox::PluginLeadBolt::getListener());
        if (NULL == lis) {
            lis = new LeadBoltListenerLua();
        }
        lis->setHandler(handler);
        sdkbox::PluginLeadBolt::setListener(lis);

        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginLeadBolt::setListener",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginLeadBoltLua_PluginLeadBolt_setListener'.",&tolua_err);
#endif
    return 0;
}

static int lua_createTable(lua_State* L, const std::map<std::string, int>& map) {
    lua_newtable(L);

    std::map<std::string, int>::const_iterator it = map.begin();
    while (it != map.end()) {
        lua_pushstring(L, it->first.c_str());
        lua_pushinteger(L, it->second);
        lua_settable(L, -3);
        it++;
    }

    return 1;
}

static int lua_setTable(lua_State* L, int table, const std::string& name, const std::map<std::string, int>& map) {
    if (table < 0) {
        table = lua_gettop(L) + table + 1;
    }
    lua_pushstring(L, name.c_str());
    lua_createTable(L, map);
    lua_rawset(L, table);

    return 0;
}

int lua_PluginLeadBoltLua_constants(lua_State* L) {
    if (NULL == L) {
        return 0;
    }

    lua_pushstring(L, "sdkbox.PluginLeadBolt");
    lua_rawget(L, LUA_REGISTRYINDEX);
    if (lua_istable(L,-1)) {

        std::map<std::string, int> enums;
        enums.clear();
        enums.insert(std::make_pair("AdOrientation_AutoDetect", 0));
        enums.insert(std::make_pair("AdOrientation_Landscape", 1));
        enums.insert(std::make_pair("AdOrientation_Portrait", 2));
        lua_setTable(L, -1, "AdOrientation", enums);
    }
    lua_pop(L, 1);

    return 1;
}

int extern_PluginLeadBolt(lua_State* L) {
    if (NULL == L) {
        return 0;
    }

    lua_pushstring(L, "sdkbox.PluginLeadBolt");
    lua_rawget(L, LUA_REGISTRYINDEX);
    if (lua_istable(L,-1))
    {
        tolua_function(L,"setListener", lua_PluginLeadBoltLua_PluginLeadBolt_setListener);
    }
     lua_pop(L, 1);

    lua_PluginLeadBoltLua_constants(L);

    return 1;
}

TOLUA_API int register_all_PluginLeadBoltLua_helper(lua_State* L) {
    tolua_module(L,"sdkbox",0);
    tolua_beginmodule(L,"sdkbox");

    extern_PluginLeadBolt(L);

    tolua_endmodule(L);
    return 1;
}


