
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

    local label1 = cc.Label:createWithSystemFont("play placement 1", "sans", 28)
    local item1 = cc.MenuItemLabel:create(label1)
    item1:onClicked(function()
        print("play placement 1")
        sdkbox.PluginSdkboxAds:placement("placement-1")
    end)
    menu:addChild(item1)

    local label2 = cc.Label:createWithSystemFont("play placement 2", "sans", 28)
    local item2 = cc.MenuItemLabel:create(label2)
    item2:onClicked(function()
        print("play placement 2")
        sdkbox.PluginSdkboxAds:placement("placement-2")
    end)
    menu:addChild(item2)

    menu:alignItemsVerticallyWithPadding(24)
    self:addChild(menu)
end

return MainScene
