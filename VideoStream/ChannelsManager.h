//
//  ChannelsManager.h
//  VideoStreamSample
//
//  Created by Murat Sudan
//  Copyright (c) 2013-2016 Murat Sudan. All rights reserved.
//  Elma DIGITAL
//

#import <foundation/Foundation.h>
#import "Channel.h"

@interface ChannelsManager : NSObject

+ (id)sharedManager;

- (void)updateChannelList;

@property(nonatomic, readonly) NSMutableArray *streamList;

@end
