//
//  FyberWrapper.h
//  PluginFyber
//
//  Copyright (c) 2015 chukong. All rights reserved.
//

#pragma once

#include "PluginFyber.h"
#include "CocosPlatform.h"
#include "CocosMacros.h"
#include "SdkboxCore.h"
#include "Log.h"
#include "json98.h"
#include "Utils.h"

NS_COCOS_BEGIN

#define TAG "Fyber"
#define VERSION "8.5.2"
#define ANDROID_VERSION "android: 8.1.5"

#define CHK_LIS if(sdkbox::PluginFyber::getListener() == nullptr) return;

class FyberWrapper
{
public:

    static FyberWrapper *instance();

    virtual void setListener(FyberListener* listener) = 0;
    virtual FyberListener* getListener() = 0;
    virtual void removeListener() = 0;
    virtual void init(const std::string& userID = "", const char* jsonconfig = 0) = 0;

    //
    virtual void showOfferWall() = 0;

    //
    virtual void requestInterstitial(const std::string& placementId = "") = 0;
    virtual void showInterstitial() = 0;

    //
    virtual void requestRewardedVideo(const std::string& placementId) = 0;
    virtual void showRewardedVideo() = 0;

    //
    virtual void requestDeltaOfCoins(const std::string& currencyId) = 0;
    virtual void requestLocation() = 0;

    virtual bool isDebugMode() = 0;

    virtual void setAge(int age) = 0;
    virtual void setBirthdate(const std::string& data) = 0;
    virtual void setGender(int gender) = 0;
    virtual void setSexualOrientation(int sexualOrientation) = 0;
    virtual void setEthnicity(int ethnicity) = 0;
    virtual void setLocation(double latitude, double longitude) = 0;
    virtual void cleanLocation() = 0;
    virtual void setMaritalStatus(int status) = 0;
    virtual void setNumberOfChildren(int numberOfChildren) = 0;
    virtual void setAnnualHouseholdIncome(int income) = 0;
    virtual void setEducation(int education) = 0;
    virtual void setZipcode(const std::string& zipcode) = 0;
    virtual void setInterests(const std::vector<std::string>& interests) = 0;
    virtual void setIap(bool flag) = 0;
    virtual void setIapAmount(float amount) = 0;
    virtual void setNumberOfSessions(int numberOfSessions) = 0;
    virtual void setPsTime(double timestamp) = 0;
    virtual void setLastSession(double session) = 0;
    virtual void setConnectionType(int connectionType) = 0;
    virtual void setDevice(const std::string& device) = 0;
    virtual void setVersion(const std::string& version) = 0;
    virtual void cleanCustomParameters() = 0;
    virtual void addCustomParameters(const std::string& key, const std::string& value) = 0;
private:
    static FyberWrapper* _instance;
};

class FyberWrapperDisabled : public FyberWrapper
{
public:
    void setListener(FyberListener* listener) {}
    FyberListener* getListener() { return nullptr; }
    void removeListener() {}
    void init(const std::string& userID = "", const char* jsonconfig = 0) {}

    //
    void showOfferWall() {}

    //
    void requestInterstitial(const std::string& placementId = "") {}
    void showInterstitial() {}

    //
    void requestRewardedVideo(const std::string& placementId) {}
    void showRewardedVideo() {}

    //
    void requestDeltaOfCoins(const std::string& currencyId) {}
    void requestLocation() {}

    bool isDebugMode() { return false; }

    void setAge(int age) {}
    void setBirthdate(const std::string& data) {}
    void setGender(int gender) {}
    void setSexualOrientation(int sexualOrientation) {}
    void setEthnicity(int ethnicity) {}
    void setLocation(double latitude, double longitude) {}
    void cleanLocation() {}
    void setMaritalStatus(int status) {}
    void setNumberOfChildren(int numberOfChildren) {}
    void setAnnualHouseholdIncome(int income) {}
    void setEducation(int education) {}
    void setZipcode(const std::string& zipcode) {}
    void setInterests(const std::vector<std::string>& interests) {}
    void setIap(bool flag) {}
    void setIapAmount(float amount) {}
    void setNumberOfSessions(int numberOfSessions) {}
    void setPsTime(double timestamp) {}
    void setLastSession(double session) {}
    void setConnectionType(int connectionType) {}
    void setDevice(const std::string& device) {}
    void setVersion(const std::string& version) {}
    void cleanCustomParameters() {}
    void addCustomParameters(const std::string& key, const std::string& value) {}
};

class FyberWrapperEnabled : public FyberWrapper
{
public:
    FyberWrapperEnabled();

    void setListener(FyberListener* listener);
    FyberListener* getListener();
    void removeListener();
    void init(const std::string& userID = "", const char* jsonconfig = 0);

    //
    void showOfferWall();

    //
    void requestInterstitial(const std::string& placementId = "");
    void showInterstitial();

    //
    void requestRewardedVideo(const std::string& placementId);
    void showRewardedVideo();

    //
    void requestDeltaOfCoins(const std::string& currencyId);
    void requestLocation();

    bool isDebugMode();

    void setAge(int age);
    void setBirthdate(const std::string& data);
    void setGender(int gender);
    void setSexualOrientation(int sexualOrientation);
    void setEthnicity(int ethnicity);
    void setLocation(double latitude, double longitude);
    void cleanLocation();
    void setMaritalStatus(int status);
    void setNumberOfChildren(int numberOfChildren);
    void setAnnualHouseholdIncome(int income);
    void setEducation(int education);
    void setZipcode(const std::string& zipcode);
    void setInterests(const std::vector<std::string>& interests);
    void setIap(bool flag);
    void setIapAmount(float amount);
    void setNumberOfSessions(int numberOfSessions);
    void setPsTime(double timestamp);
    void setLastSession(double session);
    void setConnectionType(int connectionType);
    void setDevice(const std::string& device);
    void setVersion(const std::string& version);
    void cleanCustomParameters();
    void addCustomParameters(const std::string& key, const std::string& value);
private:
    void nativeConfigure(bool enableDebug,
                         const std::string& appId,
                         const std::string& userId,
                         const std::string& securityToken,
                         bool enableToast = true);
    const char* nativeSDKVersion();

    FyberListener* _listener;
    bool _initialized;
    bool _debugMode;
};

NS_COCOS_END

