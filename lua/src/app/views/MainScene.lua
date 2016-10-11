
local MainScene = class("MainScene", cc.load("mvc").ViewBase)

function MainScene:onCreate()
    print("Sample Startup")

    local label = cc.Label:createWithSystemFont("QUIT", "sans", 32)
    local quit = cc.MenuItemLabel:create(label)
    quit:onClicked(function()
        os.exit(0)
    end)
    local size = label:getContentSize()
    local menu = cc.Menu:create(quit)
    menu:setPosition(display.right - size.width / 2 - 16, display.bottom + size.height / 2 + 16)
    self:addChild(menu)

    self:setupTestMenu()
end

function MainScene:setupTestMenu()
    sdkbox.PluginSdkboxAds:init()
    sdkbox.PluginSdkboxAds:setListener(function(args)
        dump(args)
    end)

    local menu = cc.Menu:create()

    local label = cc.Label:createWithSystemFont("play default ad", "sans", 28)
    local item = cc.MenuItemLabel:create(label)
    item:onClicked(function()
        print("play default ad")
        sdkbox.PluginSdkboxAds:playAd()
    end)
    menu:addChild(item)

    local label = cc.Label:createWithSystemFont("play placement 1", "sans", 28)
    local item = cc.MenuItemLabel:create(label)
    item:onClicked(function()
        print("play placement 1")
        sdkbox.PluginSdkboxAds:placement("placement-1")
    end)
    menu:addChild(item)

    local label = cc.Label:createWithSystemFont("play placement 2", "sans", 28)
    local item = cc.MenuItemLabel:create(label)
    item:onClicked(function()
        print("play placement 2")
        sdkbox.PluginSdkboxAds:placement("placement-2")
    end)
    menu:addChild(item)

    local label = cc.Label:createWithSystemFont("------", "sans", 28)
    local item = cc.MenuItemLabel:create(label)
    menu:addChild(item)

    menu:addChild(cc.MenuItemLabel:create(cc.Label:createWithSystemFont("AdColony Interstital", "sans", 24)):onClicked(function()
        print("AdColony Interstital")
        sdkbox.PluginSdkboxAds:playAd("AdColony", "video")
    end))

    menu:addChild(cc.MenuItemLabel:create(cc.Label:createWithSystemFont("AdColony Reward", "sans", 24)):onClicked(function()
        print("AdColony Reward")
        sdkbox.PluginSdkboxAds:playAd("AdColony", "v4vc")
    end))

    menu:addChild(cc.MenuItemLabel:create(cc.Label:createWithSystemFont("Fyber Interstital", "sans", 24)):onClicked(function()
        print("Fyber Interstital")
        sdkbox.PluginSdkboxAds:playAd("Fyber", "INTERSTITIAL")
    end))

    menu:addChild(cc.MenuItemLabel:create(cc.Label:createWithSystemFont("Fyber Reward", "sans", 24)):onClicked(function()
        print("Fyber Reward")
        sdkbox.PluginSdkboxAds:playAd("Fyber", "REWARDED")
    end))


    menu:addChild(cc.MenuItemLabel:create(cc.Label:createWithSystemFont("Chartboost Interstital", "sans", 24)):onClicked(function()
        print("Chartboost Interstital")
        sdkbox.PluginSdkboxAds:playAd("Chartboost", "Default")
    end))

    menu:addChild(cc.MenuItemLabel:create(cc.Label:createWithSystemFont("Chartboost Reward", "sans", 24)):onClicked(function()
        print("Chartboost Reward")
        sdkbox.PluginSdkboxAds:playAd("Chartboost", "Level Complete")
    end))

    menu:addChild(cc.MenuItemLabel:create(cc.Label:createWithSystemFont("Vungle Interstital", "sans", 24)):onClicked(function()
        print("Vungle Interstital")
        sdkbox.PluginSdkboxAds:playAd("Vungle", "video")
    end))

    menu:addChild(cc.MenuItemLabel:create(cc.Label:createWithSystemFont("Vungle Reward", "sans", 24)):onClicked(function()
        print("Vungle Reward")
        sdkbox.PluginSdkboxAds:playAd("Vungle", "reward")
    end))

    menu:addChild(cc.MenuItemLabel:create(cc.Label:createWithSystemFont("Bee7 Interstital", "sans", 24)):onClicked(function()
        print("Bee7 Interstital")
        sdkbox.PluginSdkboxAds:playAd("Fyber", "any")
    end))

    menu:addChild(cc.MenuItemLabel:create(cc.Label:createWithSystemFont("AdMob Interstital", "sans", 24)):onClicked(function()
        print("AdMob Interstital")
        sdkbox.PluginSdkboxAds:playAd("AdMob", "gameover")
    end))

    menu:addChild(cc.MenuItemLabel:create(cc.Label:createWithSystemFont("InMobi Interstital", "sans", 24)):onClicked(function()
        print("InMobi Interstital")
        sdkbox.PluginSdkboxAds:playAd("InMobi", "INTERSTITIAL")
    end))

    menu:addChild(cc.MenuItemLabel:create(cc.Label:createWithSystemFont("Leadbolt Interstital load", "sans", 24)):onClicked(function()
        print("Leadbolt Interstital load")
        sdkbox.PluginSdkboxAds:cacheControl("LeadBolt", {name = "ad1"})
    end))

    menu:addChild(cc.MenuItemLabel:create(cc.Label:createWithSystemFont("Leadbolt Interstital", "sans", 24)):onClicked(function()
        print("Leadbolt Interstital")
        sdkbox.PluginSdkboxAds:playAd("LeadBolt", "ad1")
    end))



    menu:setPosition(display.width * 1 / 4, display.height / 2)
    menu:alignItemsVerticallyWithPadding(24)
    self:addChild(menu)

    -- menu 2

    menu = cc.Menu:create()

    -- show and hide placement
    menu:addChild(cc.MenuItemLabel:create(cc.Label:createWithSystemFont("Play banners", "sans", 24)):onClicked(function()
        sdkbox.PluginSdkboxAds:placement("banners")
    end))
    menu:addChild(cc.MenuItemLabel:create(cc.Label:createWithSystemFont("Hide banners", "sans", 24)):onClicked(function()
        sdkbox.PluginSdkboxAds:hide("banners")
    end))

    -- show and hide Admob banner
    menu:addChild(cc.MenuItemLabel:create(cc.Label:createWithSystemFont("play AdMob home", "sans", 24)):onClicked(function()
        sdkbox.PluginSdkboxAds:playAd("AdMob", "home")
    end))
    menu:addChild(cc.MenuItemLabel:create(cc.Label:createWithSystemFont("Hide InMobi/AdMob banner", "sans", 24)):onClicked(function()
        sdkbox.PluginSdkboxAds:hideAd("AdMob", "home")
        sdkbox.PluginSdkboxAds:hideAd("InMobi", "ad1")
    end))

    menu:setPosition(display.width * 3 / 4, display.height / 2)
    menu:alignItemsVerticallyWithPadding(24)
    self:addChild(menu)
end

return MainScene
