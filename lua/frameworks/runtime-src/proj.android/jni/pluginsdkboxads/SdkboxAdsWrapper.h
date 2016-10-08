//
//  SdkboxAdsWrapper.hpp
//  PluginSdkboxAds
//
//  Created by hyperandroid on 3/3/16.
//  Copyright © 2016 sdkbox.com. All rights reserved.
//

#ifndef SdkboxAdsWrapper_hpp
#define SdkboxAdsWrapper_hpp

#include "PluginSdkboxAds.h"

#define TAG "SdkboxAds"
#define VERSION "1.0"

namespace sdkbox {
    
    class SdkboxAdsWrapper {
        
    public:
        
        virtual void init()=0;
        virtual void setListener(sdkbox::PluginSdkboxAdsListener *listener)=0;
        virtual PluginSdkboxAdsListener * getListener()=0;
        virtual void playAd(const std::string& ad_unit, const std::string& zone_place_location, const AdUnitParams& params )=0;
        virtual void playAd(const std::string& ad_unit, const std::string& zone_place_location )=0;
        virtual void playAd(const std::string&, const AdUnitParams& params )=0;
        virtual void playAd(const std::string& )=0;
        virtual void playAd()=0;
        virtual void placement(const std::string& placement)=0;
        virtual void cacheControl( const std::string& ad_unit, const std::map<std::string, std::string>& cacheOpts )=0;
        virtual bool isAvailable( const std::string& placement )=0;
        virtual void hide(const std::string& placement)=0;
        virtual void hideAd(const std::string &ad_unit, const std::string &zone_place_location)=0;

        static SdkboxAdsWrapper* getInstance();
    };

    class SdkboxAdsWrapperEnabled : public SdkboxAdsWrapper {
    private:
        
        PluginSdkboxAdsListener * _listener;
        
    public:
        
        SdkboxAdsWrapperEnabled();
        
        virtual void init();
        virtual void setListener(sdkbox::PluginSdkboxAdsListener *listener);
        virtual PluginSdkboxAdsListener * getListener();
        virtual void playAd(const std::string& ad_unit, const std::string& zone_place_location, const AdUnitParams& params );
        virtual void playAd(const std::string& ad_unit, const std::string& zone_place_location );
        virtual void playAd(const std::string&, const AdUnitParams& params );
        virtual void playAd(const std::string& );
        virtual void playAd();
        virtual void placement(const std::string& placement);
        virtual void cacheControl( const std::string& ad_unit, const std::map<std::string, std::string>& cacheOpts );
        virtual bool isAvailable( const std::string& placement );
        virtual void hide(const std::string& placement);
        virtual void hideAd(const std::string &ad_unit, const std::string &zone_place_location);
    };

    class SdkboxAdsWrapperDisabled : public SdkboxAdsWrapper {
        
    public:
        
        virtual void init() {}
        virtual void setListener(sdkbox::PluginSdkboxAdsListener *listener) {}
        virtual PluginSdkboxAdsListener * getListener() { return NULL; }
        virtual void playAd(const std::string& ad_unit, const std::string& zone_place_location, const AdUnitParams& params ) {}
        virtual void playAd(const std::string& ad_unit, const std::string& zone_place_location ) {}
        virtual void playAd(const std::string&, const AdUnitParams& params ) {}
        virtual void playAd(const std::string& ) {}
        virtual void playAd() {}
        virtual void placement(const std::string& placement) {}
        virtual void cacheControl( const std::string& ad_unit, const std::map<std::string, std::string>& cacheOpts ) {}
        virtual bool isAvailable( const std::string& placement ) { return false; }
        virtual void hide(const std::string& ) {}
        virtual void hideAd(const std::string &ad_unit, const std::string &zone_place_location) {}
    };
    
}
#endif /* SdkboxAdsWrapper_hpp */
