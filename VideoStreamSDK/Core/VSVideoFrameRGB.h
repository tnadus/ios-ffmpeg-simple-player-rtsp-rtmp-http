//
//  VSVideoFrameRGB.h
//  VideoStreamSDK
//
//  Created by Murat Sudan on 13/09/15.
//  Copyright (c) 2015-2016 Murat Sudan. All rights reserved.
//

#import "VSVideoFrame.h"

/**
 * VSVideoFrameRGB is subclass of VSVideoFrame class to hold RGB data
 */
@interface VSVideoFrameRGB : VSVideoFrame

///VKColorPlane object that holds data for Red, Green, Blue colors of image for RGB
@property (nonatomic, assign) VSColorPlane *pRGB;

@end
