//
//  VSChannel.m
//  VideoStreamSample
//
//  Created by Murat Sudan
//  Copyright (c) 2013-2016 Murat Sudan. All rights reserved.
//  Elma DIGITAL
//

#import "Channel.h"

@implementation Channel

@synthesize name = _name;
@synthesize urlAddress = _urlAddress;
@synthesize description = _description;
@synthesize options = _options;

+ (id)channelWithName:(NSString *)name addr:(NSString *)addr description:(NSString *)description options:(NSDictionary *)options {
    return [[[self alloc] initWithName:name addr:addr description:description options:options] autorelease];
}

- (id)initWithName:(NSString *)name addr:(NSString *)addr description:(NSString *)description options:(NSDictionary *)options {
    self = [super init];
    if (self) {
        _name = [name retain];
        _urlAddress = [addr retain];
        _description = [description retain];
        _options = [options retain];
    }
    return self;
}

- (void)dealloc {
    [_name release];
    [_urlAddress release];
    [_description release];
    [_options release];
    [super dealloc];
}

@end
