
var HelloWorldLayer = cc.Layer.extend({
    sprite:null,
    ctor:function () {
        //////////////////////////////
        // 1. super init first
        this._super();

        cc.log("Sample Startup")

        this.createTestMenu();

        var winsize = cc.winSize;

        var logo = new cc.Sprite("res/Logo.png");
        var logoSize = logo.getContentSize();
        logo.x = logoSize.width / 2;
        logo.y = winsize.height - logoSize.height / 2;
        this.addChild(logo);

        // var quit = new cc.MenuItemLabel(new cc.LabelTTF("QUIT", "sans", 32), function() {
        //     cc.log("QUIT");
        // });
        // var menu = new cc.Menu(quit);
        // var size = quit.getContentSize();
        // menu.x = winsize.width - size.width / 2 - 16;
        // menu.y = size.height / 2 + 16;
        // this.addChild(menu);

        return true;
    },

    createTestMenu:function() {
        sdkbox.PluginSdkboxAds.init();
        sdkbox.PluginSdkboxAds.setListener({
            onAdAction : function(ad_unit_id, zone_location_place_you_name_it, action_type) {
                cc.log("onAdAction, ad_unit_id: " + String(ad_unit_id) + ", zone_location_place_you_name_it: " + String(zone_location_place_you_name_it) + ", action_type: " + String(action_type));
            },
            onRewardAction : function(ad_unit_id, zone_id, reward_amount, reward_succeed) {
                cc.log("onRewardAction, ad_unit_id: " + String(ad_unit_id) + ", zone_id: " + String(zone_id) + ", reward_amount: " + String(reward_amount) + ", reward_succeed: " + String(reward_succeed));
            }
        });

        var menu = new cc.Menu();

        var item1 = new cc.MenuItemLabel(new cc.LabelTTF("play placement 1", "sans", 28), function() {
            cc.log("play placement 1");
            sdkbox.PluginSdkboxAds.placement("placement-1")
        });
        menu.addChild(item1);

        var item2 = new cc.MenuItemLabel(new cc.LabelTTF("play placement 2", "sans", 28), function() {
            cc.log("play placement 2");
            sdkbox.PluginSdkboxAds.placement("placement-2")
        });
        menu.addChild(item2);

        var winsize = cc.winSize;
        menu.x = winsize.width / 2;
        menu.y = winsize.height / 2;
        menu.alignItemsVerticallyWithPadding(20);
        this.addChild(menu);
    }
});

var HelloWorldScene = cc.Scene.extend({
    onEnter:function () {
        this._super();
        var layer = new HelloWorldLayer();
        this.addChild(layer);
    }
});

