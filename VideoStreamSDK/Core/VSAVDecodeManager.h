//
//  VSAVDecodeManager.h
//  VideoStreamSDK
//
//  Created by Murat Sudan
//  Copyright (c) 2013-2016 Murat Sudan. All rights reserved.
//  Elma DIGITAL
//

#import "VSDecodeManager.h"

@interface VSAVDecodeManager : VSDecodeManager

/**
 *  Initialize Audio Video decoder
 *  @param username - If license-form is not accessible, fill this parameter with your username taken from our server
 *  @param secret   - If license-form is not accessible, fill this parameter with your secret taken from our server
 *  @return VSAVDecodeManager object
 */
- (id)initWithUsername:(NSString *)username secret:(NSString *)secret;

@end
