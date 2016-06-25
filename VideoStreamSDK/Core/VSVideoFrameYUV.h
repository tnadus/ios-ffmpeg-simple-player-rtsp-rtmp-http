//
//  VSVideoFrameYUV.h
//  VideoStreamSDK
//
//  Created by Murat Sudan on 13/09/15.
//  Copyright (c) 2015-2016 Murat Sudan. All rights reserved.
//

#import "VSVideoFrame.h"

/**
 * VSVideoFrameYUV is subclass of VSVideoFrame class to hold YUV data
 */
@interface VSVideoFrameYUV : VSVideoFrame

///VSColorPlane object that holds data for brightness of image for YUV format
@property (nonatomic, assign) VSColorPlane *pLuma;

///VSColorPlane object that holds data for color of image for YUV format
@property (nonatomic, assign) VSColorPlane *pChromaB;

///VSColorPlane object that holds data for color of image for YUV format
@property (nonatomic, assign) VSColorPlane *pChromaR;

@end
