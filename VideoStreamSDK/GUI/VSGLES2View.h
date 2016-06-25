//
//  VSGLES2View.m
//  VideoStream
//
//  Created by Murat Sudan on 30.05.2013.
//  Copyright (c) 2013-2016 Murat Sudan. All rights reserved.
//

#import <UIKit/UIKit.h>

@class VSDecodeManager;
@class VSVideoFrame;

/**
 *  VideoStream SDK uses opengl framework to render pictures & make color conversion fastly. VSGLES2View is a subclass of UIView and its opengl settings are ready for opengl rendering.
 */
@interface VSGLES2View : UIView

#pragma mark - public methods

/**
 *  Initialize openGL view with DecodeManager
 *
 *  @param decoder VSDecodeManager object to be feed from
 *
 *  @return 0 for succes and non-zero for failure
 */
- (int)initGLWithDecodeManager:(VSDecodeManager *)decoder;

/**
 *  Enable-disable retina frames if device has retina support, default is YES
 *
 *  @param value Specify YES for enabling or NO for disabling Retina
 */
- (void)enableRetina:(BOOL)value;

/**
 * Get snapshot of glview in UIImage format
 *
 * @return UIImage object
 */
- (UIImage *)snapshot;

/**
 *  destroy openGL view
 */
- (void)shutdown;

@end
