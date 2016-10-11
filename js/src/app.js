
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

        menu.addChild(new cc.MenuItemLabel(new cc.LabelTTF("play default ad", "sans", 28), function() {
            cc.log("play default ad");
            sdkbox.PluginSdkboxAds.playAd();
        }));

        menu.addChild(new cc.MenuItemLabel(new cc.LabelTTF("play placement 1", "sans", 28), function() {
            cc.log("play placement 1");
            sdkbox.PluginSdkboxAds.placement("placement-1");
        }));

        menu.addChild(new cc.MenuItemLabel(new cc.LabelTTF("play placement 2", "sans", 28), function() {
            cc.log("play placement 2");
            sdkbox.PluginSdkboxAds.placement("placement-2");
        }));

        menu.addChild(new cc.MenuItemLabel(new cc.LabelTTF("------", "sans", 28), function() {
        }));


        menu.addChild(new cc.MenuItemLabel(new cc.LabelTTF("AdColony Interstital", "sans", 24), function() {
            cc.log("AdColony Interstital");
            sdkbox.PluginSdkboxAds.playAd("AdColony", "video");
        }));

        menu.addChild(new cc.MenuItemLabel(new cc.LabelTTF("AdColony Reward", "sans", 24), function() {
            cc.log("AdColony Reward");
            sdkbox.PluginSdkboxAds.playAd("AdColony", "v4vc");
        }));

        menu.addChild(new cc.MenuItemLabel(new cc.LabelTTF("Fyber Interstital", "sans", 24), function() {
            cc.log("Fyber Interstital");
            sdkbox.PluginSdkboxAds.playAd("Fyber", "INTERSTITIAL");
        }));

        menu.addChild(new cc.MenuItemLabel(new cc.LabelTTF("Fyber Reward", "sans", 24), function() {
            cc.log("Fyber Reward");
            sdkbox.PluginSdkboxAds.playAd("Fyber", "REWARDED");
        }));

        menu.addChild(new cc.MenuItemLabel(new cc.LabelTTF("Chartboost Interstital", "sans", 24), function() {
            cc.log("Chartboost Interstital");
            sdkbox.PluginSdkboxAds.playAd("Chartboost", "Default");
        }));

        menu.addChild(new cc.MenuItemLabel(new cc.LabelTTF("Chartboost Reward", "sans", 24), function() {
            cc.log("Chartboost Reward");
            sdkbox.PluginSdkboxAds.playAd("Chartboost", "Level Complete");
        }));

        menu.addChild(new cc.MenuItemLabel(new cc.LabelTTF("Vungle Interstital", "sans", 24), function() {
            cc.log("Vungle Interstital");
            sdkbox.PluginSdkboxAds.playAd("Vungle", "video");
        }));

        menu.addChild(new cc.MenuItemLabel(new cc.LabelTTF("Vungle Reward", "sans", 24), function() {
            cc.log("Vungle Reward");
            sdkbox.PluginSdkboxAds.playAd("Vungle", "reward");
        }));

        menu.addChild(new cc.MenuItemLabel(new cc.LabelTTF("Bee7 Interstital", "sans", 24), function() {
            cc.log("Bee7 Interstital");
            sdkbox.PluginSdkboxAds.playAd("Fyber", "any");
        }));

        menu.addChild(new cc.MenuItemLabel(new cc.LabelTTF("AdMob Interstital", "sans", 24), function() {
            cc.log("AdMob Interstital");
            sdkbox.PluginSdkboxAds.playAd("AdMob", "gameover");
        }));

        menu.addChild(new cc.MenuItemLabel(new cc.LabelTTF("InMobi Interstital", "sans", 24), function() {
            cc.log("InMobi Interstital");
            sdkbox.PluginSdkboxAds.playAd("InMobi", "INTERSTITIAL");
        }));

        menu.addChild(new cc.MenuItemLabel(new cc.LabelTTF("Leadbolt Interstital load", "sans", 24), function() {
            cc.log("Leadbolt Interstital load");
            sdkbox.PluginSdkboxAds.cacheControl("LeadBolt", {"name": "ad1"});
        }));

        menu.addChild(new cc.MenuItemLabel(new cc.LabelTTF("Leadbolt Interstital", "sans", 24), function() {
            cc.log("Leadbolt Interstital");
            sdkbox.PluginSdkboxAds.playAd("LeadBolt", "ad1");
        }));

        var winsize = cc.winSize;
        menu.x = winsize.width / 4;
        menu.y = winsize.height / 2;
        menu.alignItemsVerticallyWithPadding(20);
        this.addChild(menu);

        // menu 2

        menu = new cc.Menu();
        // show and hide placement
        menu.addChild(new cc.MenuItemLabel(new cc.LabelTTF("Play banners", "sans", 24), function() {
            sdkbox.PluginSdkboxAds.placement("banners");
        }));
        menu.addChild(new cc.MenuItemLabel(new cc.LabelTTF("Hide banners", "sans", 24), function() {
            sdkbox.PluginSdkboxAds.hide("banners");
        }));

        // show and hide Admob banner
        menu.addChild(new cc.MenuItemLabel(new cc.LabelTTF("play AdMob home", "sans", 24), function() {
            sdkbox.PluginSdkboxAds.playAd("AdMob", "home");
        }));
        menu.addChild(new cc.MenuItemLabel(new cc.LabelTTF("Hide InMobi/AdMob banner", "sans", 24), function() {
            sdkbox.PluginSdkboxAds.hideAd("AdMob", "home");
            sdkbox.PluginSdkboxAds.hideAd("InMobi", "ad1");
        }));

        var winsize = cc.winSize;
        menu.x = winsize.width * 3 / 4;
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

