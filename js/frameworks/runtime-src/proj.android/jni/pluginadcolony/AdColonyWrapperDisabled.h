//
//  AdColonyWrapperDisabled.cpp
//  PluginAdColony
//
//  Created by hyperandroid on 2/24/16.
//  Copyright © 2016 chukong. All rights reserved.
//

#ifndef __AdColonyWrapperDisabled
#define __AdColonyWrapperDisabled

#include "Log.h"
#include "AdColonyWrapper.h"
#include "PluginAdColony.h"
#include "AdColonyData.h"
#include "json98.h"

using namespace sdkbox;

namespace sdkbox {
    
    class AdColonyWrapperDisabled : public AdColonyWrapper {
    public:
        AdColonyWrapperDisabled();
        
        virtual ~AdColonyWrapperDisabled();
        
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
    };
    
    
}

#endif