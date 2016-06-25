//
//  VSPlayerViewController.h
//  VideoStream
//
//  Created by Murat Sudan on 13/03/16.
//  Copyright © 2016 Murat Sudan. All rights reserved.
//

#import "VSPlayerViewController.h"

#import <GoogleMobileAds/GoogleMobileAds.h>
#import "AdIDManager.h"

@class GADBannerView;
@class GADInterstitial;


@interface VSPlayerViewControllerWithAd : VSPlayerViewController<UIAlertViewDelegate>

/**
 * Init Player View Controller with url & protocol options. For ex: rtsp protocol has transport layer options, this can be used like below [NSDictionary dictionaryWithObject:@"udp" forKey:@"rtsp_transport"] for more info please see http://iosvideokit.com/documentation/#RTSP_OPTIONS
 *
 *  @param urlString The location of the file or remote stream url. If it's a file then it must be located on a remote server
 *  @param options   Streaming options according to the used protocol
 *
 *  @return VSPlayerViewController object
 */
- (id)initWithURLString:(NSString *)urlString decoderOptions:(NSDictionary *)options;


#pragma mark Advertisement properties

///Your ad unit id for banner type ads
@property (nonatomic, retain) NSString *clientAdUnitIdBanner;

///Your ad unit id for interstitial type ads
@property (nonatomic, retain) NSString *clientAdUnitIdInterstitial;

///Frequency for interstitial ads display per play
@property (nonatomic, assign) int interstitialAdFrequencyPerPlay;

@end


