//
//  AdIDManager.h
//  admob-module-ios
//
//  Created by Murat Sudan on 09/07/15.
//
//

#import <Foundation/Foundation.h>

#define DEFAULT_MOD                           3 
#define MODULE_VERSION                        @"1.0.0"

#define DEFAULT_NUMERATOR                     4
#define DEFAULT_DENOMINATOR                   10

#ifdef DEBUG
#   define DLog(...) NSLog(__VA_ARGS__)
#else
#   define DLog(...)
#endif

typedef NS_ENUM(NSUInteger, AdType) {
    Banner,
    Interstitial,
};

typedef NS_ENUM(NSUInteger, FairBalance) {
    Fair,
    AgainstClient,
    AgainstAdMobIOSModule,
};

typedef NS_ENUM(NSUInteger, RequestType) {
    Client,
    AdMobIOSModule,
};

typedef NS_ENUM(NSUInteger, AdStrategy) {
    RevenueSharing = 0,
    AllAds2Client,
    NoAds,
};

@protocol AdIdManagerDelegate <NSObject>

- (void) onConfigurationReceived : (NSDictionary *) configDictionary;

@end

@interface AdIDManager : NSObject

+(AdIDManager*)sharedAdIDManager;

- (void) initializeManager;
- (NSString *) getNextAdUnitIdForAdType : (AdType) adType;
- (void) updateCounterForAdType : (AdType) adType requestType : (RequestType) reqType success : (BOOL) success;
- (void) startURLSessionTask;
- (BOOL) moduleNeedsForceUpdate;
- (int)isInAppStore;

- (void) increasePlayCount;
- (int) retrievePlayCount;
- (int) retrieveListType;
- (BOOL) isAppWithNoAd;

@property (nonatomic, retain) NSString *clientAppUnitIdBanner;

@property (nonatomic, retain) NSString *clientAppUnitIdInterstitial;

@property (nonatomic, retain) NSString *lastAdUnitIdInterstitial;
@property (nonatomic, retain) NSString *lastAdUnitIdBanner;

@property (nonatomic, assign) id  delegate;

@end
