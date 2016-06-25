//
//  ServerConfig.h
//  BannerExample
//
//  Created by oguz on 20/12/15.
//  Copyright © 2015 Google. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, SERVER_TYPE) {
    PROD,
    TEST,
    INTERNAL
};

typedef NS_ENUM(NSUInteger, CONNECTION_PREFIX) {
    HTTP,
    HTTPS,
};

typedef NS_ENUM(NSUInteger, SERVICE_NAME) {
    GET_CONFIGURATION,
};

@interface ServerConfig : NSObject

+(NSURL *) getServerUrl;
+(NSURL *) getServiceUrl : (SERVICE_NAME) requestService;

@end
