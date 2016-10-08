#ifndef _VUNGLE_DATA_H_
#define _VUNGLE_DATA_H_

#include "CocosMacros.h"
#include "json98.h"
#include "Utils.h"

NS_COCOS_BEGIN

struct VungleAd
{
    bool soundEnabled;
    bool backButton;
    bool incentivized;
    std::string userID;
    std::string placement;
    std::string name;
    
    VungleAd() : name(""), soundEnabled(false), backButton(false), incentivized(false), userID(""), placement("")
    {}

    static VungleAd from_json( std::string name, Json j)
    {
        VungleAd ad;
        ad.name = name;
        ad.soundEnabled = j["sound"].bool_value(true);
        ad.backButton = j["backbutton"].bool_value(true);
        ad.incentivized = j["incentivized"].bool_value(false);
        ad.placement = j["placement"].string_value("");
        
        return ad;
    }
};

typedef std::map<std::string, Json>::iterator Json_it;
typedef std::map<std::string, VungleAd>::iterator VungleAd_it;

NS_COCOS_END

#endif
