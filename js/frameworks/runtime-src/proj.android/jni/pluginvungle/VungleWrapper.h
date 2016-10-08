#ifndef __VUNGLE_WRAPPER_H__
#define __VUNGLE_WRAPPER_H__

#include "CocosMacros.h"
#include "json98.h"
#include "PluginVungle.h"
#include "VungleData.h"

NS_COCOS_BEGIN

// watch out with the plugins tag. AdUnit TAG must the same as this.
#define TAG "Vungle"
#define VERSION "3.2.0"
#define IOS_VERSION     "ios: 3.2.1"

class VungleWrapper {
public:
    static VungleWrapper* getInstance();

    virtual void init() = 0;
    virtual void __init( bool asAdUnit ) = 0;
    virtual void show(const std::string& name) = 0;
    virtual void setListener(VungleListener* listener) = 0;
    virtual VungleListener* getListener() = 0;
    virtual void removeListener() = 0;
    virtual void setDebug(bool enable) = 0;
    virtual bool isCacheAvailable() = 0;
    virtual void setUserID(const std::string& userID) = 0;
    virtual VungleAd getCurrentAd() = 0;
    virtual std::string getCurrentAdName() = 0;
    virtual std::string setCurrentAdName(const std::string& adName) = 0;
    virtual bool isIncentivized( const std::string& name ) = 0;

    std::string _currentAd;     //current play ad nam = 0;
private:
    static VungleWrapper* _instance;
};


class VungleWrapperDisabled : public VungleWrapper
{
public:
    void init() {}
    void __init( bool asAdUnit ) {}
    void show(const std::string& name) {}
    void setListener(VungleListener* listener) {}
    VungleListener* getListener() { return nullptr; }
    void removeListener() {}
    void setDebug(bool enable) {}
    bool isCacheAvailable() { return false; }
    void setUserID(const std::string& userID) {}
    VungleAd getCurrentAd() { return VungleAd(); }
    std::string getCurrentAdName() { return ""; }
    std::string setCurrentAdName(const std::string& adName) { return ""; }
    bool isIncentivized( const std::string& name ) { return false; }
};

class VungleWrapperEnabled : public VungleWrapper
{
public:
    VungleWrapperEnabled();
    ~VungleWrapperEnabled();
    static VungleWrapper* getInstance();

    void init();
    void __init( bool asAdUnit );
    void show(const std::string& name);
    void setListener(VungleListener* listener);
    VungleListener* getListener();
    void removeListener();
    void setDebug(bool enable);
    bool isCacheAvailable();
    void setUserID(const std::string& userID);

    VungleAd getCurrentAd();
    std::string getCurrentAdName();
    std::string setCurrentAdName(const std::string& adName);

    std::string _currentAd;     //current play ad name
    bool isIncentivized( const std::string& name );

protected:

    bool nativeInit(const std::string& appId, bool asAdUnit );
    const char* nativeSDKVersion();

    VungleListener* _listener;
    bool _initialized;
    std::string _userID;
    std::map<std::string, VungleAd> _ads;
};

NS_COCOS_END

#endif
