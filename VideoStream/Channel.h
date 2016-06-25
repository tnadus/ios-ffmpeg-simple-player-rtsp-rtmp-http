//
//  VSChannel.h
//  VideoStreamSample
//
//  Created by Murat Sudan
//  Copyright (c) 2013-2016 Murat Sudan. All rights reserved.
//  Elma DIGITAL
//

#import <Foundation/Foundation.h>

@interface Channel : NSObject {
    NSString *_name;
    NSString *_urlAddress;
    NSString *_description;
    NSDictionary *_options;
}

@property (nonatomic, readonly) NSString *name;
@property (nonatomic, readonly) NSString *urlAddress;
@property (nonatomic, readonly) NSString *description;
@property (nonatomic, readonly) NSDictionary *options;

+ (id)channelWithName:(NSString *)name addr:(NSString *)addr description:(NSString *)description options:(NSDictionary *)options;
- (id)initWithName:(NSString *)name addr:(NSString *)addr description:(NSString *)description options:(NSDictionary *)options;

@end
