#import <Foundation/Foundation.h>

#define WHITE_LIST 0
#define GRAY_LIST  1
#define BLACK_LIST 2

@interface CacheData : NSObject <NSCoding> {

	NSDate   * lastRequestDate;
    NSString * admobiOSAdUnitIdBanner;
    NSString * admobiOSAdUnitIdInterstitial;
	
    int modValue;
    BOOL inWhiteList;
    BOOL forceUpdate;
}


@property (nonatomic, retain) NSDate   * lastRequestDate;
@property (nonatomic, retain) NSString * admobiOSAdUnitIdBanner;
@property (nonatomic, retain) NSString * admobiOSAdUnitIdInterstitial;
@property (nonatomic, retain) NSString * bundleId;

@property (nonatomic, assign) int numberOfBannerAdReq4AdMobiOSModule;
@property (nonatomic, assign) int numberOfTotalBannerAdRequests;
@property (nonatomic, assign) int numberOfIntAdReq4AdMobiOSModule;
@property (nonatomic, assign) int numberOfTotalIntAdRequests;
@property (nonatomic, assign) int numberOfSuccessBannerAdReq4AdMobiOSModule;
@property (nonatomic, assign) int numberOfSuccessTotalBannerAdRequests;
@property (nonatomic, assign) int numberOfSuccessIntAdReq4AdMobiOSModule;
@property (nonatomic, assign) int numberOfSuccessTotalIntAdRequests;

@property (nonatomic, assign) int testNumberOfBannerAdReq4AdMobiOSModule;
@property (nonatomic, assign) int testNumberOfTotalBannerAdRequests;
@property (nonatomic, assign) int testNumberOfIntAdReq4AdMobiOSModule;
@property (nonatomic, assign) int testNumberOfTotalIntAdRequests;
@property (nonatomic, assign) int testNumberOfSuccessBannerAdReq4AdMobiOSModule;
@property (nonatomic, assign) int testNumberOfSuccessTotalBannerAdRequests;
@property (nonatomic, assign) int testNumberOfSuccessIntAdReq4AdMobiOSModule;
@property (nonatomic, assign) int testNumberOfSuccessTotalIntAdRequests;


@property (nonatomic, assign) int modValue;
@property (nonatomic, assign) BOOL inWhiteList;
@property (nonatomic, assign) BOOL forceUpdate;
@property (nonatomic, assign) int numerator;
@property (nonatomic, assign) int denominator;
@property (nonatomic, assign) int listType;
@property (nonatomic, assign) int adStrategy;

@end



