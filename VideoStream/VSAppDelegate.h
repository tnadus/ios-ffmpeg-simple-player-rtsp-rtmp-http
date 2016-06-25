//
//  VSAppDelegate.h
//  VideoStream
//
//  Created by Murat Sudan on 11/16/12.
//  Copyright (c) 2013-2016 Murat Sudan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "UINavigationController+Additions.h"
#import "EAIntroView.h"

@class VSChannelListViewController;

@interface VSAppDelegate : UIResponder <UIApplicationDelegate, EAIntroDelegate>

@property (strong, nonatomic) UIWindow *window;
@property (strong, nonatomic) UINavigationController *navBarController;
@property (strong, nonatomic) VSChannelListViewController *channelListVc;

@end
