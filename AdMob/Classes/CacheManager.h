//
//  CacheManager.h
//  admob-module-ios
//
//  Created by Murat Sudan on 09/07/15.
//
//

#import <Foundation/Foundation.h>
#import "CacheData.h"

@interface CacheManager : NSObject

+(CacheManager*)sharedCacheManager;

- (CacheData *)initializeCacheData;
- (void)saveDictionaryToCache :(NSDictionary *)dictionary;
- (void)saveObjectToCache :(CacheData *)object;
- (CacheData *)loadFromCache;
- (void)resetCacheCounters;

@end
