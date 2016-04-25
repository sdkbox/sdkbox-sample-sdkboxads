
#include "HelloWorldScene.h"
#include "PluginSdkboxAds/PluginSdkboxAds.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    CCLOG("Sample Startup");
    
    // add logo
    auto winsize = Director::getInstance()->getWinSize();
    auto logo = Sprite::create("Logo.png");
    auto logoSize = logo->getContentSize();
    logo->setPosition(Vec2(logoSize.width / 2,
                           winsize.height - logoSize.height / 2));
    addChild(logo);
    
    // add quit button
    auto label = Label::createWithSystemFont("QUIT", "sans", 32);
    auto quit = MenuItemLabel::create(label, [](Ref*){
        exit(0);
    });
    auto labelSize = label->getContentSize();
    quit->setPosition(Vec2(winsize.width / 2 - labelSize.width / 2 - 16,
                           -winsize.height / 2 + labelSize.height / 2 + 16));
    addChild(Menu::create(quit, NULL));
    
    // add test menu
    createTestMenu();
    
    return true;
}

void HelloWorld::createTestMenu()
{
    sdkbox::PluginSdkboxAds::setListener(this);
    
    auto menu = Menu::create();
    
    menu->addChild(MenuItemLabel::create(Label::createWithSystemFont("play placement-1", "sans", 24), [](Ref*){
        CCLOG("play placement-1");
        std::string placement("placement-1");
        sdkbox::PluginSdkboxAds::placement(placement);
    }));
    
    menu->addChild(MenuItemLabel::create(Label::createWithSystemFont("play placement-2", "sans", 24), [](Ref*){
        CCLOG("play placement-2");
        std::string placement("placement-2");
        sdkbox::PluginSdkboxAds::placement(placement);
    }));
    
    menu->alignItemsVerticallyWithPadding(10);
    addChild(menu);
}

void HelloWorld::onAdAction(const std::string& ad_unit_id,
                            const std::string& zone_location_place_you_name_it,
                            sdkbox::AdActionType action_type)
{
    std::string action;
    
    switch (action_type)
    {
        case sdkbox::AdActionType::LOADED:
            action = "LOADED";
            break;
            
        case sdkbox::AdActionType::LOAD_FAILED:
            action = "LOAD_FAILED";
            break;
            
        case sdkbox::AdActionType::CLICKED:
            action = "CLICKED";
            break;
            
        case sdkbox::AdActionType::REWARD_STARTED:
            action = "REWARD_STARTED";
            break;
            
        case sdkbox::AdActionType::REWARD_ENDED:
            action = "REWARD_ENDED";
            break;
            
        case sdkbox::AdActionType::REWARD_CANCELED:
            action = "REWARD_CANCELED";
            break;
            
        case sdkbox::AdActionType::AD_STARTED:
            action = "AD_STARTED";
            break;
            
        case sdkbox::AdActionType::AD_CANCELED:
            action = "AD_CANCELED";
            break;
            
        case sdkbox::AdActionType::AD_ENDED:
            action = "AD_ENDED";
            break;
            
        case sdkbox::AdActionType::ADACTIONTYPE_UNKNOWN:
            action = "ADACTIONTYPE_UNKNOWN";
            break;
            
        default:
            action = "null";
    }
    
    CCLOG("onAdAction, ad_unit_id: %s, zone_location_place_you_name_it: %s, action_type: %s",
          ad_unit_id.c_str(),
          zone_location_place_you_name_it.c_str(),
          action.c_str());
}

void HelloWorld::onRewardAction(const std::string& ad_unit_id,
                                const std::string& zone_id,
                                float reward_amount,
                                bool reward_succeed)
{
    CCLOG("onRewardAction, ad_unit_id: %s, zone_id: %s, reward_amount: %0.2f, reward_succeed: %s",
          ad_unit_id.c_str(),
          zone_id.c_str(),
          reward_amount,
          reward_succeed ? "YES" : "NO");
}
