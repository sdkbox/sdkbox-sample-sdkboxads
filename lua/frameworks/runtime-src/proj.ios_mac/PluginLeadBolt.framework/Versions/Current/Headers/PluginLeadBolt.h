/****************************************************************************

 Copyright (c) 2014-2016 SDKBOX Inc

 ****************************************************************************/

#ifndef _PLUGIN_LEADBOLT_H_
#define _PLUGIN_LEADBOLT_H_

#include <string>
#include <map>

namespace sdkbox {

    class LeadBoltListener;
    class PluginLeadBolt {
    public:

        enum AdOrientation {
            AdOrientation_AutoDetect = 0,
            AdOrientation_Landscape,
            AdOrientation_Portrait
        };

        /**
         *  initialize the plugin instance.
         */
        static bool init();

        /**
         * Set listener to listen for leadbolt events
         */
        static void setListener(LeadBoltListener* listener);

        /**
         * Get the listener
         */
        static LeadBoltListener* getListener();

        /**
         * Remove the listener, and can't listen to events anymore
         */
        static void removeListener();

        /**
         * Cache Ad with name @placement (referenced from your json config file)
         */
        static void loadModuleToCache(const std::string& placement, const std::string& userData = "");

        /**
         * Check if Ad with name @placement (referenced from your json config file) is available for display
         */
        static bool isAdReady(const std::string& placement);

        /**
         * Load/Display Ad with name @placement (referenced from your json config file)
         */
        static void loadModule(const std::string& placement, const std::string& userData = "");

        /**
         * start session
         */
        static void startSession(const std::string& apiKey);

        /**
         * close session
         */
        static void closeSession();

        /**
         * sync data second, just valid on ios
         */
        static void setSyncDataPeriodInSecond(int periodInSecond);

        /**
         * sync data
         */
        static void sync();

        /**
         * event
         */
        static void event(const std::string& name);

        /**
         * event with float value
         */
        static void event(const std::string& name, float floatValue);

        /**
         * Transaction Events
         */
        static void transaction(const std::string& name, float floatValue, const std::string& currencyCode, const std::string& ref = "", bool instant = false);

        /**
         * destroy module
         */
        static void destroyModule();

        /**
         * Crash Reporting
         */
        static void setCrashHandlerStatus(bool enable);

        /**
         * Crash Reporting
         */
        static void crashWithName(const std::string& crashName, const std::string& description);

        /**
         * force Ad Orientation
         */
        static void fixAdOrientation(AdOrientation orientation);

        /**
         * setAgeRange
         * You can increase your App’s performance by optionally including the additional information above. This allows selected premium advertisers to display their Ads to your users. To pass this additional information, use the following methods BEFORE calling loadModuleToCache.
         * accepted values "13-17", "18-25", "26-35", "36-45", "46+"
         */
        static void setAgeRange(const std::string& range); // accepted values "13-17", "18-25", "26-35", "36-45", "46+"

        /**
         * setGender
         * You can increase your App’s performance by optionally including the additional information above. This allows selected premium advertisers to display their Ads to your users. To pass this additional information, use the following methods BEFORE calling loadModuleToCache.
         * accepted valued "Male", "Female"
         */
        static void setGender(const std::string& gender); // accepted valued "Male", "Female"

        /**
         * setFramework
         */
        static void setFramework(const std::string& f);
        };

    class LeadBoltListener {
    public:

        /**
         * Notifies the delegate that the module has finished loading
         */
        virtual void onModuleLoaded(const std::string& placement) {};

        /**
         * Notifies the delegate that the module has closed
         */
        virtual void onModuleClosed(const std::string& placement) {};

        /**
         * Notifies the delegate that the module has clicked
         */
        virtual void onModuleClicked(const std::string& placement) {};

        /**
         * Notifies the delegate that the module has cached
         */
        virtual void onModuleCached(const std::string& placement) {};

        /**
         * Notifies the delegate that the module has fail
         */
        virtual void onModuleFailed(const std::string& placement, const std::string& error, bool iscached) {};

        /**
         * Notifies the delegate that the rewarded video has finished playing.
         */
        virtual void onMediaFinished(bool viewCompleted) {};

    };
}

#endif
