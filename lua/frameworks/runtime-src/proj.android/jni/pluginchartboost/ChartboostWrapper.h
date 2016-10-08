
#ifndef _PLUGIN_CHARTBOOST_WRAPPER_H_
#define _PLUGIN_CHARTBOOST_WRAPPER_H_

#include "PluginChartboost.h"
#include "ChartboostData.h"

#define TAG  "Chartboost"
#define VERSION "5.5.3"
#define IOS_VERSION     "ios: 6.5.1"
#define ANDROID_VERSION "android: 5.5.3"

namespace sdkbox {


    enum CB_AdType {
        Interstitial = 0,
        RewardedVideo,
        MoreApp
    };

    typedef std::map<std::string, CB_AdType> ChartboostAds;
    typedef ChartboostAds::const_iterator ChartboostAds_i;

class ChartboostWrapper
{
public:
    static ChartboostWrapper* getInstance();

    virtual void init(const char* jsonconfig = 0) = 0;
    virtual void show(const std::string& name) = 0;
    virtual void setListener(ChartboostListener* listener) = 0;
    virtual ChartboostListener* getListener() = 0;
    virtual void removeListener() = 0;
    virtual bool isAnyViewVisible() = 0;
    virtual bool isAvailable(const std::string& name) = 0;
    virtual void cache(const std::string& name) = 0;
    virtual void setAutoCacheAds(bool shouldCache) = 0;
    virtual bool getAutoCacheAds() = 0;
    virtual void closeImpression() = 0;
    virtual void setStatusBarBehavior(CB_StatusBarBehavior behavior) = 0;
    virtual void didPassAgeGate(bool pass) = 0;
    virtual void setShouldPauseClickForConfirmation(bool shouldPause) = 0;
    virtual bool handleOpenURL(const std::string& url, const std::string& sourceApp) = 0;
    virtual void setCustomID(const std::string& customID) = 0;
    virtual std::string getCustomID() = 0;
    virtual void setShouldRequestInterstitialsInFirstSession(bool shouldRequest) = 0;
    virtual void setShouldDisplayLoadingViewForMoreApps(bool shouldDisplay) = 0;
    virtual void setShouldPrefetchVideoContent(bool shouldPrefetch) = 0;
    virtual bool nativeConfigure(const std::string appID, const std::string appSignature, bool asAdUnit, const void* unitPtr ) = 0;
    virtual void __init( bool asAdUnit, const void* UnitPtr ) = 0;
    virtual std::string adType(const std::string& name) = 0;
};

    class ChartboostWrapperEnabled : public ChartboostWrapper
    {
    public:
        ChartboostWrapperEnabled();
        void init(const char* jsonconfig = 0);
        void show(const std::string& name);
        void setListener(ChartboostListener* listener);
        ChartboostListener* getListener();
        void removeListener();
        bool isAnyViewVisible();
        bool isAvailable(const std::string& name);
        void cache(const std::string& name);
        void setAutoCacheAds(bool shouldCache);
        bool getAutoCacheAds();
        void closeImpression();
        void setStatusBarBehavior(CB_StatusBarBehavior behavior);
        void didPassAgeGate(bool pass);
        void setShouldPauseClickForConfirmation(bool shouldPause);
        bool handleOpenURL(const std::string& url, const std::string& sourceApp);
        void setCustomID(const std::string& customID);
        std::string getCustomID();
        void setShouldRequestInterstitialsInFirstSession(bool shouldRequest);
        void setShouldDisplayLoadingViewForMoreApps(bool shouldDisplay);
        void setShouldPrefetchVideoContent(bool shouldPrefetch);
        bool nativeConfigure(const std::string appID, const std::string appSignature, bool asAdUnit, const void* unitPtr );
        void __init( bool asAdUnit, const void* UnitPtr );
        std::string adType(const std::string& name);

    protected:

        const char* nativeSDKVersion();
        void nativeShowInterstitial(std::string name, int type);
        void nativeShowRewardedVideo(std::string name, int type);
        void nativeShowMoreApps(std::string name, int type);


        bool _initialized;
        ChartboostListener* _listener;
        ChartboostAds ads;

    };


    class ChartboostWrapperDisabled : public ChartboostWrapper
    {
    public:

        void init(const char* jsonconfig = 0) {}
        void show(const std::string& name) {}
        void setListener(ChartboostListener* listener) {}
        ChartboostListener* getListener() { return NULL; }
        void removeListener() {}
        bool isAnyViewVisible() { return false; }
        bool isAvailable(const std::string& name) { return false; };
        void cache(const std::string& name) {}
        void setAutoCacheAds(bool shouldCache) {}
        bool getAutoCacheAds() { return false; }
        void closeImpression() {}
        void setStatusBarBehavior(CB_StatusBarBehavior behavior) {}
        void didPassAgeGate(bool pass) {}
        void setShouldPauseClickForConfirmation(bool shouldPause) {}
        bool handleOpenURL(const std::string& url, const std::string& sourceApp) { return false; }
        void setCustomID(const std::string& customID) {}
        std::string getCustomID() { return ""; }
        void setShouldRequestInterstitialsInFirstSession(bool shouldRequest) {}
        void setShouldDisplayLoadingViewForMoreApps(bool shouldDisplay) {}
        void setShouldPrefetchVideoContent(bool shouldPrefetch) {}

        bool nativeConfigure(const std::string appID, const std::string appSignature, bool asAdUnit, const void* unitPtr ) { return false;}
        void __init( bool asAdUnit, const void* UnitPtr ) {}
        virtual std::string adType(const std::string& name) { return ""; }

    protected:

        const char* nativeSDKVersion();
        void nativeShowInterstitial(std::string name, int type);
        void nativeShowRewardedVideo(std::string name, int type);
        void nativeShowMoreApps(std::string name, int type);


        bool _initialized;
        ChartboostListener* _listener;
        ChartboostAds ads;
    };


}

#endif
