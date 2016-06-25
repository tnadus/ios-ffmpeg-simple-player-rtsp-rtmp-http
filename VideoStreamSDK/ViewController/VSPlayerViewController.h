//
//  VSPlayerController.h
//  VideoStreamSDK
//
//  Created by Murat Sudan
//  Copyright (c) 2013-2016 Murat Sudan. All rights reserved.
//  Elma DIGITAL
//

#import <UIKit/UIKit.h>
#import "VSAVDecodeManager.h"

@class VSPlayerController;

/* VSDecoder decode option keys */

///Defining RTSP protocol transport layer. Values are predefined under "VSDecoder decode option values"
extern NSString *VSDECODER_OPT_KEY_RTSP_TRANSPORT;

///Selection of audio default stream by index. Value must be an NSNumber object. (High priority)
extern NSString *VSDECODER_OPT_KEY_AUD_STRM_DEF_IDX;

///Selection of audio default stream by string. Value must be an NSString object (normal priority)
extern NSString *VSDECODER_OPT_KEY_AUD_STRM_DEF_STR;

///FFmpeg can not determine some formats, so we force ffmpeg to use mjpeg format. Value must be @"1" which is an NSString object
extern NSString *VSDECODER_OPT_KEY_FORCE_MJPEG;

/* VSDecoder decode option values*/

///RTSP uses UDP transport layer - advantage fast, disadvantage packets can be lost
extern NSString *VSDECODER_OPT_VALUE_RTSP_TRANSPORT_UDP;

///RTSP uses TCP transport layer, advantage no packet loss, disadvantage slow when comparing with UDP
extern NSString *VSDECODER_OPT_VALUE_RTSP_TRANSPORT_TCP;

// /RTSP uses multicast UDP to retrieve packets
extern NSString *VSDECODER_OPT_VALUE_RTSP_TRANSPORT_UDP_MULTICAST;

///RTSP uses http tunnelling to retrieve packets
extern NSString *VSDECODER_OPT_VALUE_RTSP_TRANSPORT_HTTP;

/**
 *  Implement this delegate if you want to get notified about state changes with error codes
 */
@protocol VSPlayerViewControllerDelegate <NSObject>
@optional

/**
 *  Optional delegate method, add this method to your viewcontroller if you want to be notified
 *
 *  @param state   Indicates the state in VSDecoderState type
 *  @param errCode Indicates the error code in VSError type
 */
- (void)onPlayerViewControllerStateChanged:(VSDecoderState)state errorCode:(VSError)errCode;

@end

@class VSGLES2View;

/**
 * A Player object which is subclass of UIViewController, it's useful for showing video in full screen in a easy and practical way like Apple's native API "MPMovieViewController"
 */
@interface VSPlayerViewController : UIViewController{
    //Timers & timer controls
    BOOL _panelIsHidden;
}

/**
 * Init Player View Controller with url & protocol options. For ex: rtsp protocol has transport layer options, this can be used like below [NSDictionary dictionaryWithObject:@"udp" forKey:@"rtsp_transport"] for more info please see http://iosvideokit.com/documentation/#RTSP_OPTIONS
 *
 *  @param urlString The location of the file or remote stream url. If it's a file then it must be located on a remote server
 *  @param options   Streaming options according to the used protocol
 *
 *  @return VSPlayerViewController object
 */
- (id)initWithURLString:(NSString *)urlString decoderOptions:(NSDictionary *)options;

///The bar title of Video Player
@property (nonatomic, retain) NSString *barTitle;

///Specify YES to hide status bar, default is NO
@property (nonatomic, assign, getter=isStatusBarHidden) BOOL statusBarHidden;

///Set your Parent View Controller as delegate If you want to be notified for state changes of VSPlayerViewController
@property (nonatomic, assign) id<VSPlayerViewControllerDelegate> delegate;

///Specify YES to show first video picture during the initial buffering, default is NO
@property (nonatomic, assign) BOOL showPictureOnInitialBuffering;

///The video rendering view, opengl configuration is done to be ready for rendering
@property (nonatomic, readonly) VSGLES2View *renderView;

#pragma mark License management properties

///If license-form is not accessible, fill this parameter with your username taken from our server
@property (nonatomic, retain) NSString *username;

///If license-form is not accessible, fill this parameter with your secret taken from our server
@property (nonatomic, retain) NSString *secret;

@end
