//
//  VSStreamInfoView.h
//  VideoStream
//
//  Created by Murat Sudan on 08.02.2013.
//  Copyright (c) 2013-2016 Murat Sudan. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 *  A custom UIView which shows extra information on screen such as codecs, connection type, data usage, etc ...
 */
@interface VSStreamInfoView : UIView

/**
 *  update info view with stream's related info
 *
 *  @param info A dictionary that holds all information to be shown on screen
 */
- (void)updateSubviewsWithInfo:(NSDictionary *)info;

@end
