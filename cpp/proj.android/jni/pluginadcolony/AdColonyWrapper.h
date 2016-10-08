/****************************************************************************

 Copyright (c) 2014-2016 SDKBOX Inc

 ****************************************************************************/

#ifndef __PluginAdColony__AdColonyWrapper__
#define __PluginAdColony__AdColonyWrapper__

#include <string>
#include <map>

#include "CocosMacros.h"
#include "AdColonyData.h"
#include "PluginAdColony.h"
#include "CocosPlatform.h"

#define IOS_VERSION     "ios: 2.6.2.1"
#define ANDROID_VERSION "android: 2.3.6"
#define TAG        "AdColony"
#define VERSION    "2.6.1"


namespace sdkbox {

    class AdColonyWrapper
    {
    public:
        AdColonyWrapper();

        static AdColonyWrapper *getInstance();

        virtual void init()= 0;
        virtual void show(const std::string& name)=0;

        virtual void setListener(AdColonyListener* listener)=0;
        virtual AdColonyListener* getListener()=0;
        virtual void removeListener()=0;

        virtual AdColonyData findData(const std::string& name)=0;
        virtual AdColonyData findDataByZone(const std::string& zoneID)=0;

        virtual int zoneStatusForZone(const std::string& zoneID)=0;
        virtual AdColonyAdStatus getStatus(const std::string& name)=0;

        /** @name Device and User Identifiers */
        virtual void setCustomID(const std::string& customID)=0;
        virtual std::string getCustomID()=0;
        virtual std::string getUniqueDeviceID()=0;
        virtual std::string getAdvertisingIdentifier()=0;
        virtual std::string getVendorIdentifier()=0;

        /** @name V4VC Multiple Videos per Reward Info */
        virtual int getVideosPerReward(const std::string& currencyName)=0;
        virtual int getVideoCreditBalance(const std::string& currencyName)=0;

        /** @name Options and Other Functionality */
        virtual void cancelAd()=0;
        virtual bool videoAdCurrentlyRunning()=0;
        virtual void turnAllAdsOff()=0;

        /** @name Optional User Metadata */
        virtual void setUserMetadata(const std::string& metadataType, const std::string& value)=0;
        virtual void userInterestedIn(const std::string& topic)=0;

        virtual void notifyIAPComplete(const std::string& transactionID, const std::string& productID, int quantity, float price, const std::string& currencyCode)=0;

    private:
        static AdColonyWrapper *_instance;

    };


    class AdColonyWrapperEnabled : public AdColonyWrapper {
    public:
        AdColonyWrapperEnabled();

        virtual ~AdColonyWrapperEnabled();

        void init();

        void show(const std::string &name);

        void setListener(AdColonyListener *listener);

        AdColonyListener *getListener();

        void removeListener();

        AdColonyData findData(const std::string &name);

        AdColonyData findDataByZone(const std::string &zoneID);

        int zoneStatusForZone(const std::string &zoneID);

        AdColonyAdStatus getStatus(const std::string &name);

        /** @name Device and User Identifiers */
        void setCustomID(const std::string &customID);

        std::string getCustomID();

        std::string getUniqueDeviceID();

        std::string getAdvertisingIdentifier();

        std::string getVendorIdentifier();

        /** @name V4VC Multiple Videos per Reward Info */
        int getVideosPerReward(const std::string &currencyName);

        int getVideoCreditBalance(const std::string &currencyName);

        /** @name Options and Other Functionality */
        void cancelAd();

        bool videoAdCurrentlyRunning();

        void turnAllAdsOff();

        /** @name Optional User Metadata */
        void setUserMetadata(const std::string &metadataType, const std::string &value);

        void userInterestedIn(const std::string &topic);

        void notifyIAPComplete(const std::string &transactionID, const std::string &productID,
                               int quantity, float price, const std::string &currencyCode);

    protected:
        void nativeConfigure(const Json &config);

        void nativePlayVideoAdForZone(AdColonyData *ad);

        const char *nativeSDKVersion();

        void __trackInit(Json &json);

    protected:
        bool _initialized;
        AdColonyListener *_listener;
        std::map<std::string, AdColonyData> ads;
    };

}

#endif /* defined(__PluginAdColony__AdColonyWrapper__) */
