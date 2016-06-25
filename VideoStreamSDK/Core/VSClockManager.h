//
//  VSClockManager.h
//  VideoStreamSDK
//
//  Created by Murat Sudan on 18/09/15.
//  Copyright (c) 2015-2016 Murat Sudan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VSClock.h"

//Audio & Video sync tresholds
/* no AV sync correction is done if below the minimum AV sync threshold */
#define AV_SYNC_THRESHOLD_MIN 0.01
/* AV sync correction is done if above the maximum AV sync threshold */
#define AV_SYNC_THRESHOLD_MAX 0.1
/* If a frame duration is longer than this, it will not be duplicated to compensate AV sync */
#define AV_SYNC_FRAMEDUP_THRESHOLD 0.1
/* no AV correction is done if too big error */
#define AV_NOSYNC_THRESHOLD 10.0

extern int64_t av_gettime(void);

@interface VSClockManager : NSObject

- (id)init;

- (void)initClock:(VSClock *)clock serial:(int *)serial;
- (void)setPts:(double)pts serial:(int)serial clock:(VSClock *)clock;
- (void)setTime:(double)time pts:(double)pts serial:(int)serial clock:(VSClock *)clock;
- (void)setSpeed:(double)speed clock:(VSClock *)clock;
- (double)clockTime:(VSClock *)clock;
- (void)setClockTime:(VSClock *)clock pts:(double)pts serial:(int)serial;
- (void)syncClockToSlave:(VSClock *)clock slave:(VSClock *)slaveClock;
@end
