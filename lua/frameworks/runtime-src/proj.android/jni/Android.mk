LOCAL_PATH := $(call \
my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := cocos2dlua_shared

LOCAL_MODULE_FILENAME := libcocos2dlua

LOCAL_SRC_FILES := ../../Classes/AppDelegate.cpp \
../../Classes/ide-support/SimpleConfigParser.cpp \
../../Classes/ide-support/RuntimeLuaImpl.cpp \
../../Classes/ide-support/lua_debugger.c \
hellolua/main.cpp \
../../Classes/PluginSdkboxAdsLua.hpp \
../../Classes/PluginSdkboxAdsLua.cpp \
../../Classes/PluginSdkboxAdsLuaHelper.cpp \
../../Classes/PluginSdkboxAdsLuaHelper.h \
../../Classes/SDKBoxLuaHelper.h \
../../Classes/SDKBoxLuaHelper.cpp \
../../Classes/PluginFyberLua.hpp \
../../Classes/PluginFyberLua.cpp \
../../Classes/PluginFyberLuaHelper.cpp \
../../Classes/PluginFyberLuaHelper.h \
../../Classes/PluginChartboostLua.cpp \
../../Classes/PluginChartboostLua.hpp \
../../Classes/PluginChartboostLuaHelper.cpp \
../../Classes/PluginChartboostLuaHelper.h \
../../Classes/PluginVungleLua.hpp \
../../Classes/PluginVungleLua.cpp \
../../Classes/PluginVungleLuaHelper.cpp \
../../Classes/PluginVungleLuaHelper.h \
../../Classes/PluginAdMobLua.cpp \
../../Classes/PluginAdMobLuaHelper.cpp \
../../Classes/PluginInMobiLua.cpp \
../../Classes/PluginInMobiLuaHelper.cpp \
../../Classes/PluginLeadBoltLua.cpp \
../../Classes/PluginLeadBoltLuaHelper.cpp \
../../Classes/PluginAdColonyLua.cpp \
../../Classes/PluginAdcolonyLuaHelper.cpp

LOCAL_CPPFLAGS := -DSDKBOX_ENABLED
LOCAL_LDLIBS := -landroid \
-llog
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes
LOCAL_WHOLE_STATIC_LIBRARIES := PluginSdkboxAds \
sdkbox \
PluginFyber \
PluginChartboost \
PluginVungle \
PluginAdMob \
PluginInMobi \
PluginLeadBolt \
PluginAdColony

# _COCOS_HEADER_ANDROID_BEGIN
# _COCOS_HEADER_ANDROID_END

LOCAL_STATIC_LIBRARIES := cocos2d_lua_static
LOCAL_STATIC_LIBRARIES += cocos2d_simulator_static

# _COCOS_LIB_ANDROID_BEGIN
# _COCOS_LIB_ANDROID_END

include $(BUILD_SHARED_LIBRARY)
$(call import-add-path, $(LOCAL_PATH))

$(call import-module,scripting/lua-bindings/proj.android/prebuilt-mk)
$(call import-module,tools/simulator/libsimulator/proj.android/prebuilt-mk)
$(call import-module, ./sdkbox)
$(call import-module, ./pluginsdkboxads)
$(call import-module, ./pluginfyber)
$(call import-module, ./pluginchartboost)
$(call import-module, ./pluginvungle)
$(call import-module, ./pluginadmob)
$(call import-module, ./plugininmobi)
$(call import-module, ./pluginleadbolt)
$(call import-module, ./pluginadcolony)

# _COCOS_LIB_IMPORT_ANDROID_BEGIN
# _COCOS_LIB_IMPORT_ANDROID_END
