//
//  VSClock.h
//  VideoStreamSDK
//
//  Created by Murat Sudan on 13/09/15.
//  Copyright (c) 2015-2016 Murat Sudan. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
    kVSClockTypeAudio = 1,
    kVSClockTypeVideo,
    kVSClockTypeExternal
} VSClockType;


@interface VSClock : NSObject

- (id)initWithType:(VSClockType)type;

- (int*)serialPtr;

@property(nonatomic, assign) double pts;           /* clock base */
@property(nonatomic, assign) double ptsDrift;     /* clock base minus time at which we updated the clock */
@property(nonatomic, assign) double last_updated;
@property(nonatomic, assign) double speed;
@property(nonatomic, assign) int serial;           /* clock is based on a packet with this serial */
@property(nonatomic, assign) int paused;
@property(nonatomic, assign) int *queueSerial;
@property (nonatomic, readonly) VSClockType type;

@end
