#ifndef __ADCOLONYDATA_H_
#define __ADCOLONYDATA_H_

#include "CocosMacros.h"
#include "json98.h"
#include "Utils.h"

NS_COCOS_BEGIN

struct AdColonyData
{
    std::string name;
    std::string zone;
    bool v4vc;
    bool pre_popup;
    bool post_popup;

    static AdColonyData from_json(Json j)
    {
        AdColonyData d;
        d.zone = j["zone"].string_value("");
        d.v4vc = j["v4vc"].bool_value(false);
        d.pre_popup = j["pre_popup"].bool_value(false);
        d.post_popup = j["post_popup"].bool_value(false);
        
        return d;
    }
};
typedef std::map<std::string, AdColonyData>::iterator AdColony_it;


NS_COCOS_END

#endif