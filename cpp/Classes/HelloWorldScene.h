#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "PluginSdkboxAds/PluginSdkboxAds.h"

class HelloWorld : public cocos2d::Layer, public sdkbox::PluginSdkboxAdsListener
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
    
private:
    void createTestMenu();
    
    void onAdAction(const std::string& ad_unit_id,
                    const std::string& zone_location_place_you_name_it,
                    sdkbox::AdActionType action_type);
    
    void onRewardAction(const std::string& ad_unit_id,
                        const std::string& zone_id,
                        float reward_amount,
                        bool reward_succeed);
};

#endif // __HELLOWORLD_SCENE_H__
