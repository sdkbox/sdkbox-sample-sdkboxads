/****************************************************************************

 Copyright (c) 2014-2016 SDKBOX Inc

 ****************************************************************************/
#ifndef __PLUGIN_FYBER_H__
#define __PLUGIN_FYBER_H__

#include <string>
#include <map>

namespace sdkbox
{
    static const int FYB_OFFERWALL_PRESENTED = 1;
    static const int FYB_OFFERWALL_DISMISSED = 2;
    static const int FYB_OFFERWALL_ERROR     = 3;

    static const int FYB_REWARDED_VIDEO_STARTED  = 1;
    static const int FYB_REWARDED_VIDEO_FINISHED = 2;
    static const int FYB_REWARDED_VIDEO_ABORTED  = 4;
    static const int FYB_REWARDED_VIDEO_ERROR    = 3;
    static const int FYB_REWARDED_VIDEO_DISMISS  = FYB_REWARDED_VIDEO_FINISHED;


    class FyberListener
    {
    public:
        //
        // Virtual Currency Connection Delegate
        //

        virtual void onVirtualCurrencyConnectorFailed(int error,                    // deprecated filed, always: 0
                                                      const std::string& errorCode, // deprecated filed, alwasy: ""
                                                      const std::string& errorMsg) = 0;
        virtual void onVirtualCurrencyConnectorSuccess(double deltaOfCoins,
                                                       const std::string& currencyId,
                                                       const std::string& currencyName,
                                                       const std::string& transactionId) = 0;

        //
        // Interstitial
        //

        virtual void onCanShowInterstitial(bool canShowInterstitial) = 0;
        virtual void onInterstitialDidShow() = 0;
        virtual void onInterstitialDismiss(const std::string& reason) = 0;
        virtual void onInterstitialFailed() = 0;

        //
        // Rewarded Video
        //

        virtual void onBrandEngageClientReceiveOffers(bool areOffersAvailable) = 0;
        virtual void onBrandEngageClientChangeStatus(int status, const std::string& msg) = 0;

        //
        // Offer Wall
        //

        virtual void onOfferWallFinish(int status) = 0;
    };

    class PluginFyber
    {
    public:
        /*!
         * initialize the fyber plugin.
         */
        static void init(const std::string& userID = "");

        /**
         * Set listener to listen for fyber events
         */
        static void setListener(FyberListener* listener);

        /**
         * Get the listener
         */
        static FyberListener* getListener();

        /**
         * Remove the listener, and can't listen to events anymore.
         */
        static void removeListener();

        // offer wall

        /**
         * Presents the Fyber Mobile OfferWall as a child view controller of your own view controller.
         *
         * @placementId (deprecated)
         */
        static void showOfferWall(const std::string& placementId = "");


        // rewarded video

        /**
         * Request the server for rewarded video availability.
         */
        static void requestOffers(const std::string& placementId = "");
        /**
         * Show an available rewarded video.
         *
         * @placementId (deprecated)
         */
        static void showOffers(const std::string& placementId = "");


        // interstitial

        /**
         * Check if interstitial ads are available
         */
        static void requestInterstitial();
        /**
         * Shows an interstitial ad. Check first that one is ready to be shown with requestInterstitial.
         */
        static void showInterstitial();

        /**
         * Fetches the amount of a given currency earned since the last time this method was
         * invoked for the current user ID / app ID combination.
         */
        static void requestDeltaOfCoins(const std::string& currencyId = "");
    };
}

#endif
