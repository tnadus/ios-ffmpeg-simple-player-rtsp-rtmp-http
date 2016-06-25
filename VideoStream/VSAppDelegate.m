//
//  VSAppDelegate.m
//  VideoStream
//
//  Created by Murat Sudan on 11/16/12.
//  Copyright (c) 2013-2016 Murat Sudan. All rights reserved.
//

#import "VSAppDelegate.h"
#import "VSChannelListViewController.h"

#define WRITE_LOGS_TO_FILE         0

@implementation VSAppDelegate

@synthesize navBarController = _navBarController;
@synthesize channelListVc = _channelListVc;

- (void)dealloc
{
    [_channelListVc release];
    [_navBarController release];
    [_window release];
    [super dealloc];
}

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{

#if (TARGET_IPHONE_SIMULATOR == 0) && (WRITE_LOGS_TO_FILE)
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    NSString *documentsDirectory = [paths objectAtIndex:0];
    NSString *logPath = [documentsDirectory stringByAppendingPathComponent:@"console.log"];
    freopen([logPath cStringUsingEncoding:NSASCIIStringEncoding],"a+",stderr);
#endif

    self.window = [[[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]] autorelease];
    // Override point for customization after application launch.
    self.window.backgroundColor = [UIColor blackColor];

    self.channelListVc = [[[VSChannelListViewController alloc] initWithNibName:@"VSChannelListViewController" bundle:nil] autorelease];
    self.navBarController = [[[UINavigationController alloc] initWithRootViewController:_channelListVc] autorelease];
    [self.window setRootViewController:_navBarController];
    [self addIntroView:NO];
    [self.window makeKeyAndVisible];
    return YES;
}

- (void)addIntroView:(BOOL)forceToShow {
    
    if (!forceToShow && [[[NSUserDefaults standardUserDefaults] objectForKey:@"dont_show_again"] boolValue])
        return;
    
    EAIntroPage *page1 = [EAIntroPage page];
    page1.title = @"Welcome to VideoStreamSDK Sample";
    page1.desc = @"This is a sample project that shows how to use VideoStream SDK for different streaming protocols";
    page1.titleImage = [UIImage imageNamed:@"intro-screen-1"];
    
    EAIntroPage *page2 = [EAIntroPage page];
    page2.title = @"How to test your streams/media files";
    page2.desc = @"ChannelManager is the place for adding/removing/editing the channels. You can add realtime or file network streams.";
    page2.titleImage = [UIImage imageNamed:@"intro-screen-2"];
    
    EAIntroPage *page3 = [EAIntroPage page];
    page3.title = @"Questions";
    page3.desc = @"You can see the documentation pdf file found in the VideoStreamSDK/documentation folder to get answers to your questions";
    page3.titleImage = [UIImage imageNamed:@"intro-screen-3"];
    
    EAIntroView *intro = [[EAIntroView alloc] initWithFrame:self.window.bounds andPages:@[page1,page2,page3]];
    intro.bgImage = [UIImage imageNamed:@"introBg"];
    [intro setDelegate:self];
    [intro showInView:self.navBarController.view animateDuration:0.0];
}

- (void)applicationWillResignActive:(UIApplication *)application
{
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later. 
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application
{
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

@end
