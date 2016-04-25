
#include "PluginFyberLuaHelper.h"
#include "PluginFyber/PluginFyber.h"
#include "CCLuaEngine.h"
#include "tolua_fix.h"
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

    return 1;
}

TOLUA_API int register_all_PluginFyberLua_helper(lua_State* L) {
    tolua_module(L,"sdkbox",0);
    tolua_beginmodule(L,"sdkbox");

    extern_PluginFyber(L);

    tolua_endmodule(L);
    return 1;
}


