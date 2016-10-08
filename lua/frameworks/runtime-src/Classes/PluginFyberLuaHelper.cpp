
#include "PluginFyberLuaHelper.h"
#include "PluginFyber/PluginFyber.h"
#include "SDKBoxLuaHelper.h"

class FyberListenerLua : public sdkbox::FyberListener {
public:
    FyberListenerLua(): mLuaHandler(0) {

    }
    ~FyberListenerLua() {
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

    void onVirtualCurrencyConnectorFailed(int error,
                                          const std::string& errorCode,
                                          const std::string& errorMsg)
    {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;
        dict.insert(std::make_pair("name", LuaValue::stringValue("onVirtualCurrencyConnectorFailed")));
        dict.insert(std::make_pair("error", LuaValue::intValue(error)));
        dict.insert(std::make_pair("errorcode", LuaValue::stringValue(errorCode)));
        dict.insert(std::make_pair("errormsg", LuaValue::stringValue(errorMsg)));

        dict.insert(std::make_pair("errorCode", LuaValue::stringValue(errorCode)));
        dict.insert(std::make_pair("errorMsg", LuaValue::stringValue(errorMsg)));
        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }
    void onVirtualCurrencyConnectorSuccess(double deltaOfCoins,
                                           const std::string& currencyId,
                                           const std::string& currencyName,
                                           const std::string& transactionId)
    {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;
        dict.insert(std::make_pair("name", LuaValue::stringValue("onVirtualCurrencyConnectorSuccess")));
        dict.insert(std::make_pair("coins", LuaValue::floatValue(deltaOfCoins)));
        dict.insert(std::make_pair("currencyid", LuaValue::stringValue(currencyId)));
        dict.insert(std::make_pair("currencyname", LuaValue::stringValue(currencyName)));
        dict.insert(std::make_pair("transactionid", LuaValue::stringValue(transactionId)));

        dict.insert(std::make_pair("deltaOfCoins", LuaValue::floatValue(deltaOfCoins)));
        dict.insert(std::make_pair("currencyId", LuaValue::stringValue(currencyId)));
        dict.insert(std::make_pair("currencyName", LuaValue::stringValue(currencyName)));
        dict.insert(std::make_pair("transactionId", LuaValue::stringValue(transactionId)));
        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }

    void onCanShowInterstitial(bool canShowInterstitial)
    {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;
        dict.insert(std::make_pair("name", LuaValue::stringValue("onCanShowInterstitial")));
        dict.insert(std::make_pair("available", LuaValue::booleanValue(canShowInterstitial)));

        dict.insert(std::make_pair("canShowInterstitial", LuaValue::booleanValue(canShowInterstitial)));
        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }
    void onInterstitialDidShow()
    {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;
        dict.insert(std::make_pair("name", LuaValue::stringValue("onInterstitialDidShow")));
        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }
    void onInterstitialDismiss(const std::string& reason)
    {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;
        dict.insert(std::make_pair("name", LuaValue::stringValue("onInterstitialDismiss")));
        dict.insert(std::make_pair("reason", LuaValue::stringValue(reason)));
        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }
    void onInterstitialFailed()
    {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;
        dict.insert(std::make_pair("name", LuaValue::stringValue("onInterstitialFailed")));
        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }

    void onBrandEngageClientReceiveOffers(bool areOffersAvailable)
    {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;
        dict.insert(std::make_pair("name", LuaValue::stringValue("onBrandEngageClientReceiveOffers")));
        dict.insert(std::make_pair("available", LuaValue::booleanValue(areOffersAvailable)));

        dict.insert(std::make_pair("areOffersAvailable", LuaValue::booleanValue(areOffersAvailable)));
        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }
    void onBrandEngageClientChangeStatus(int status, const std::string& msg)
    {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;
        dict.insert(std::make_pair("name", LuaValue::stringValue("onBrandEngageClientChangeStatus")));
        dict.insert(std::make_pair("status", LuaValue::intValue(status)));
        dict.insert(std::make_pair("msg", LuaValue::stringValue(msg)));
        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }

    void onOfferWallFinish(int status)
    {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;
        dict.insert(std::make_pair("name", LuaValue::stringValue("onOfferWallFinish")));
        dict.insert(std::make_pair("status", LuaValue::intValue(status)));
        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }

private:
    int mLuaHandler;
};


int lua_PluginFyberLua_PluginFyber_setListener(lua_State* tolua_S) {
    int argc = 0;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginFyber",0,&tolua_err)) goto tolua_lerror;
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
        FyberListenerLua* lis = static_cast<FyberListenerLua*> (sdkbox::PluginFyber::getListener());
        if (nullptr == lis) {
            lis = new FyberListenerLua();
        }
        lis->setHandler(handler);
        sdkbox::PluginFyber::setListener(lis);

        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFyber::setListener",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFyberLua_PluginFyber_setListener'.",&tolua_err);
#endif
    return 0;
}

static int fyber_lua_createTable(lua_State* L, const std::map<std::string, int>& map) {
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
static int fyber_lua_createTable(lua_State* L, const std::map<std::string, std::string>& map) {
    lua_newtable(L);

    std::map<std::string, std::string>::const_iterator it = map.begin();
    while (it != map.end()) {
        lua_pushstring(L, it->first.c_str());
        lua_pushstring(L, it->second.c_str());
        lua_settable(L, -3);
        it++;
    }

    return 1;
}

static int fyber_lua_setTable(lua_State* L, int table, const std::string& name, const std::map<std::string, int>& map) {
    if (table < 0) {
        table = lua_gettop(L) + table + 1;
    }
    lua_pushstring(L, name.c_str());
    fyber_lua_createTable(L, map);
    lua_rawset(L, table);

    return 0;
}
static int fyber_lua_setTable(lua_State* L, int table, const std::string& name, const std::map<std::string, std::string>& map) {
    if (table < 0) {
        table = lua_gettop(L) + table + 1;
    }
    lua_pushstring(L, name.c_str());
    fyber_lua_createTable(L, map);
    lua_rawset(L, table);

    return 0;
}

int lua_PluginFyberLua_constants(lua_State* L) {
    if (NULL == L) {
        return 0;
    }

    lua_pushstring(L, "sdkbox.PluginFyber");
    lua_rawget(L, LUA_REGISTRYINDEX);
    if (lua_istable(L,-1)) {

        //  The device of the user
        {
            std::map<std::string, std::string> enums;
            enums.insert(std::make_pair("Undefined", sdkbox::FYB_UserDeviceUndefined));
            enums.insert(std::make_pair("IPhone", sdkbox::FYB_UserDeviceIPhone));
            enums.insert(std::make_pair("IPad", sdkbox::FYB_UserDeviceIPad));
            enums.insert(std::make_pair("IPod", sdkbox::FYB_UserDeviceIPod));
            enums.insert(std::make_pair("Android", sdkbox::FYB_UserDeviceAndroid));
            fyber_lua_setTable(L, -1, "UserDevice", enums);
        }

        std::map<std::string, int> enums;

        // UserConnectionType
        enums.clear();
        enums.insert(std::make_pair("Undefined", sdkbox::FYB_UserConnectionTypeUndefined));
        enums.insert(std::make_pair("WiFi", sdkbox::FYB_UserConnectionTypeWiFi));
        enums.insert(std::make_pair("3G", sdkbox::FYB_UserConnectionType3G));
        enums.insert(std::make_pair("LTE", sdkbox::FYB_UserConnectionTypeLTE));
        enums.insert(std::make_pair("Edge", sdkbox::FYB_UserConnectionTypeEdge));
        fyber_lua_setTable(L, -1, "UserConnectionType", enums);

        // UserEducation
        enums.clear();
        enums.insert(std::make_pair("Undefined", sdkbox::FYB_UserEducationUndefined));
        enums.insert(std::make_pair("Other", sdkbox::FYB_UserEducationOther));
        enums.insert(std::make_pair("None", sdkbox::FYB_UserEducationNone));
        enums.insert(std::make_pair("HighSchool", sdkbox::FYB_UserEducationHighSchool));
        enums.insert(std::make_pair("InCollege", sdkbox::FYB_UserEducationInCollege));
        enums.insert(std::make_pair("SomeCollege", sdkbox::FYB_UserEducationSomeCollege));
        enums.insert(std::make_pair("Associates", sdkbox::FYB_UserEducationAssociates));
        enums.insert(std::make_pair("Bachelors", sdkbox::FYB_UserEducationBachelors));
        enums.insert(std::make_pair("Masters", sdkbox::FYB_UserEducationMasters));
        enums.insert(std::make_pair("Doctorate", sdkbox::FYB_UserEducationDoctorate));
        fyber_lua_setTable(L, -1, "UserEducation", enums);

        // The marital status of the user
        enums.clear();
        enums.insert(std::make_pair("Undefined", sdkbox::FYB_UserMaritalStatusUndefined));
        enums.insert(std::make_pair("Single", sdkbox::FYB_UserMartialStatusSingle));
        enums.insert(std::make_pair("Relationship", sdkbox::FYB_UserMartialStatusRelationship));
        enums.insert(std::make_pair("Married", sdkbox::FYB_UserMartialStatusMarried));
        enums.insert(std::make_pair("Divorced", sdkbox::FYB_UserMartialStatusDivorced));
        enums.insert(std::make_pair("Engaged", sdkbox::FYB_UserMartialStatusEngaged));
        fyber_lua_setTable(L, -1, "UserMartialStatus", enums);

        // The ethnicity of the user
        enums.clear();
        enums.insert(std::make_pair("Undefined", sdkbox::FYB_UserEthnicityUndefined));
        enums.insert(std::make_pair("Asian", sdkbox::FYB_UserEthnicityAsian));
        enums.insert(std::make_pair("Black", sdkbox::FYB_UserEthnicityBlack));
        enums.insert(std::make_pair("Hispanic", sdkbox::FYB_UserEthnicityHispanic));
        enums.insert(std::make_pair("Indian", sdkbox::FYB_UserEthnicityIndian));
        enums.insert(std::make_pair("MiddleEastern", sdkbox::FYB_UserEthnicityMiddleEastern));
        enums.insert(std::make_pair("NativeAmerican", sdkbox::FYB_UserEthnicityNativeAmerican));
        enums.insert(std::make_pair("PacificIslander", sdkbox::FYB_UserEthnicityPacificIslander));
        enums.insert(std::make_pair("White", sdkbox::FYB_UserEthnicityWhite));
        enums.insert(std::make_pair("Other", sdkbox::FYB_UserEthnicityOther));
        fyber_lua_setTable(L, -1, "UserEthnicity", enums);

        // The gender of the user
        enums.clear();
        enums.insert(std::make_pair("Undefined", sdkbox::FYB_UserGenderUndefined));
        enums.insert(std::make_pair("Male", sdkbox::FYB_UserGenderMale));
        enums.insert(std::make_pair("Female", sdkbox::FYB_UserGenderFemale));
        enums.insert(std::make_pair("Other", sdkbox::FYB_UserGenderOther));
        fyber_lua_setTable(L, -1, "UserGender", enums);

        // The sexual orientation of the user
        enums.clear();
        enums.insert(std::make_pair("Undefined", sdkbox::FYB_UserSexualOrientationUndefined));
        enums.insert(std::make_pair("Straight", sdkbox::FYB_UserSexualOrientationStraight));
        enums.insert(std::make_pair("Bisexual", sdkbox::FYB_UserSexualOrientationBisexual));
        enums.insert(std::make_pair("Gay", sdkbox::FYB_UserSexualOrientationGay));
        enums.insert(std::make_pair("Unknown", sdkbox::FYB_UserSexualOrientationUnknown));
        fyber_lua_setTable(L, -1, "UserSexualOrientation", enums);
    }
    lua_pop(L, 1);

    return 1;
}

int extern_PluginFyber(lua_State* L) {
    if (nullptr == L) {
        return 0;
    }

    lua_pushstring(L, "sdkbox.PluginFyber");
    lua_rawget(L, LUA_REGISTRYINDEX);
    if (lua_istable(L,-1))
    {
        tolua_function(L,"setListener", lua_PluginFyberLua_PluginFyber_setListener);
    }
    lua_pop(L, 1);

    lua_PluginFyberLua_constants(L);

    return 1;
}

TOLUA_API int register_all_PluginFyberLua_helper(lua_State* L) {
    tolua_module(L,"sdkbox",0);
    tolua_beginmodule(L,"sdkbox");

    extern_PluginFyber(L);

    tolua_endmodule(L);
    return 1;
}


