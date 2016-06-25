//
//  VSColorPlane.h
//  VideoStreamSDK
//
//  Created by Murat Sudan on 13/09/15.
//  Copyright (c) 2015-2016 Murat Sudan. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  A data class that holds video frames's color data and data size
 */
@interface VSColorPlane : NSObject

///Frame's color data size
@property (nonatomic, assign) int size;

///Frame's color data
@property (nonatomic, assign) UInt8 *data;

@end
