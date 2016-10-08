/****************************************************************************

 Copyright (c) 2014-2016 SDKBOX Inc

 ****************************************************************************/

#ifndef _PLUGIN_LEADBOLT_WRAPPER_H_
#define _PLUGIN_LEADBOLT_WRAPPER_H_

#include "PluginLeadBolt.h"
#include "json98.h"

#define TAG "LeadBolt"
#define VERSION "6.0b"
#define VERSION_IOS "v6.0b"
#define VERSION_ANDROID "v6.0b"

namespace sdkbox {

    class LeadBoltWrapper {

    public:
        static LeadBoltWrapper* getInstance();

        virtual bool init()=0;
        virtual bool __init( bool asAdUnit )=0;
        virtual void setListener(LeadBoltListener* listener)=0;
        virtual LeadBoltListener* getListener()=0;
        virtual void removeListener()=0;

        /// Start, close, sync
        virtual void startSession(const std::string& apiKey)=0;
        virtual void closeSession()=0;

        virtual void setSyncDataPeriodInSecond(int periodInSecond)=0;
        virtual void sync()=0;

        // Basic Event Functions
        virtual void event(const std::string& name)=0;
        virtual void event(const std::string& name, bool instant)=0;

        // Event with Float Values
        virtual void event(const std::string& name, float floatValue)=0;
        virtual void event(const std::string& name, float floatValue, bool instant)=0;
        virtual void event(const std::string& name, float floatValue, const std::string& ref)=0;
        virtual void event(const std::string& name, float floatValue, const std::string& ref, bool instant)=0;

        /// Event with String Values
        virtual void event(const std::string& name, const std::string& value)=0;
        virtual void event(const std::string& name, const std::string& value, bool instant)=0;
        virtual void event(const std::string& name, const std::string& value, const std::string& ref)=0;
        virtual void event(const std::string& name, const std::string& value, const std::string& ref, bool instant)=0;

        // Event with Float Values
        virtual void event(const std::string& name, int intValue)=0;
        virtual void event(const std::string& name, int intValue, bool instant)=0;
        virtual void event(const std::string& name, int intValue, const std::string& ref)=0;
        virtual void event(const std::string& name, int intValue, const std::string& ref, bool instant)=0;

        // Transaction Events
        virtual void transaction(const std::string& name, float floatValue, const std::string& currencyCode)=0;
        virtual void transaction(const std::string& name, float floatValue, const std::string& currencyCode, bool instant)=0;
        virtual void transaction(const std::string& name, float floatValue, const std::string& currencyCode, const std::string& ref)=0;
        virtual void transaction(const std::string& name, float floatValue, const std::string& currencyCode, const std::string& ref, bool instant)=0;

        // Module functions
        virtual void loadModule()=0;  // for cocos ad unit
        virtual void loadModule(const std::string& placement)=0;
        virtual void loadModule(const std::string& placement, const std::string& userData)=0;
        virtual void loadModuleToCache(const std::string& placement)=0;
        virtual void loadModuleToCache(const std::string& placement, const std::string& userData)=0;
        virtual void destroyModule()=0;

        // Crash Reporting
        virtual void setCrashHandlerStatus(bool enable)=0;
        virtual void crashWithName(const std::string& crashName, const std::string& description)=0;

        // force Ad Orientation
        virtual void fixAdOrientation(PluginLeadBolt::AdOrientation orientation)=0;
        virtual bool isAdReady(const std::string& placement)=0;

        //Demographics function
        virtual void setAgeRange(const std::string& range)=0; // accepted values "13-17", "18-25", "26-35", "36-45", "46+"
        virtual void setGender(const std::string& gender)=0; // accepted valued "Male", "Female"

        virtual void setFramework(const std::string& f)=0;

    };

    class LeadBoltWrapperDisabled : public LeadBoltWrapper {

    public:

        bool init() { return false; }
        bool __init( bool asAdUnit ) { return false; }
        void setListener(LeadBoltListener* listener) {}
        LeadBoltListener* getListener() { return NULL; }
        void removeListener() {}

        /// Start, close, sync
        void startSession(const std::string& apiKey) {}
        void closeSession() {}

        void setSyncDataPeriodInSecond(int periodInSecond) {}
        void sync() {}

        // Basic Event Functions
        void event(const std::string& name) {}
        void event(const std::string& name, bool instant) {}

        // Event with Float Values
        void event(const std::string& name, float floatValue) {}
        void event(const std::string& name, float floatValue, bool instant) {}
        void event(const std::string& name, float floatValue, const std::string& ref) {}
        void event(const std::string& name, float floatValue, const std::string& ref, bool instant) {}

        /// Event with String Values
        void event(const std::string& name, const std::string& value) {}
        void event(const std::string& name, const std::string& value, bool instant) {}
        void event(const std::string& name, const std::string& value, const std::string& ref) {}
        void event(const std::string& name, const std::string& value, const std::string& ref, bool instant) {}

        // Event with Float Values
        void event(const std::string& name, int intValue) {}
        void event(const std::string& name, int intValue, bool instant) {}
        void event(const std::string& name, int intValue, const std::string& ref) {}
        void event(const std::string& name, int intValue, const std::string& ref, bool instant) {}

        // Transaction Events
        void transaction(const std::string& name, float floatValue, const std::string& currencyCode) {}
        void transaction(const std::string& name, float floatValue, const std::string& currencyCode, bool instant) {}
        void transaction(const std::string& name, float floatValue, const std::string& currencyCode, const std::string& ref) {}
        void transaction(const std::string& name, float floatValue, const std::string& currencyCode, const std::string& ref, bool instant) {}

        // Module functions
        void loadModule() {}  // for cocos ad unit
        void loadModule(const std::string& placement) {}
        void loadModule(const std::string& placement, const std::string& userData) {}
        void loadModuleToCache(const std::string& placement) {}
        void loadModuleToCache(const std::string& placement, const std::string& userData) {}
        void destroyModule() {}

        // Crash Reporting
        void setCrashHandlerStatus(bool enable) {}
        void crashWithName(const std::string& crashName, const std::string& description) {}

        // force Ad Orientation
        void fixAdOrientation(PluginLeadBolt::AdOrientation orientation) {}
        bool isAdReady(const std::string& placement) { return false; }

        //Demographics function
        void setAgeRange(const std::string& range) {} // accepted values "13-17", "18-25", "26-35", "36-45", "46+"
        void setGender(const std::string& gender) {} // accepted valued "Male", "Female"

        void setFramework(const std::string& f) {}

    };

    class LeadBoltWrapperEnabled : public LeadBoltWrapper {

    public:
        LeadBoltWrapperEnabled();

        bool init();
        bool __init( bool asAdUnit );
        void setListener(LeadBoltListener* listener);
        LeadBoltListener* getListener();
        void removeListener();


        /// Start, close, sync
        void startSession(const std::string& apiKey);
        void closeSession();

        void setSyncDataPeriodInSecond(int periodInSecond);
        void sync();

        // Basic Event Functions
        void event(const std::string& name);
        void event(const std::string& name, bool instant);

        // Event with Float Values
        void event(const std::string& name, float floatValue);
        void event(const std::string& name, float floatValue, bool instant);
        void event(const std::string& name, float floatValue, const std::string& ref);
        void event(const std::string& name, float floatValue, const std::string& ref, bool instant);

        /// Event with String Values
        void event(const std::string& name, const std::string& value);
        void event(const std::string& name, const std::string& value, bool instant);
        void event(const std::string& name, const std::string& value, const std::string& ref);
        void event(const std::string& name, const std::string& value, const std::string& ref, bool instant);

        // Event with Float Values
        void event(const std::string& name, int intValue);
        void event(const std::string& name, int intValue, bool instant);
        void event(const std::string& name, int intValue, const std::string& ref);
        void event(const std::string& name, int intValue, const std::string& ref, bool instant);

        // Transaction Events
        void transaction(const std::string& name, float floatValue, const std::string& currencyCode);
        void transaction(const std::string& name, float floatValue, const std::string& currencyCode, bool instant);
        void transaction(const std::string& name, float floatValue, const std::string& currencyCode, const std::string& ref);
        void transaction(const std::string& name, float floatValue, const std::string& currencyCode, const std::string& ref, bool instant);

        // Module functions
        void loadModule();  // for cocos ad unit
        void loadModule(const std::string& placement);
        void loadModule(const std::string& placement, const std::string& userData);
        void loadModuleToCache(const std::string& placement);
        void loadModuleToCache(const std::string& placement, const std::string& userData);
        void destroyModule();

        // Crash Reporting
        void setCrashHandlerStatus(bool enable);
        void crashWithName(const std::string& crashName, const std::string& description);

        // force Ad Orientation
        void fixAdOrientation(PluginLeadBolt::AdOrientation orientation);
        bool isAdReady(const std::string& placement);

        //Demographics function
        void setAgeRange(const std::string& range); // accepted values "13-17", "18-25", "26-35", "36-45", "46+"
        void setGender(const std::string& gender); // accepted valued "Male", "Female"

        void setFramework(const std::string& f);


    protected:
        bool nativeInit(const Json& config, bool asAdUnit);
        std::string nativeSDKVersion();

        LeadBoltListener* _listener;
        std::map<std::string, std::string> _ADsMap;
    };

}

#endif
