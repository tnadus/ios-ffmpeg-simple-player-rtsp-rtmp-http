//
//  VSManager.h
//  VideoStreamSample
//
//  Created by Murat Sudan on 11/07/14.
//  Copyright (c) 2013-2016 Murat Sudan. All rights reserved.
//

#import <Foundation/Foundation.h>

#include <libavcodec/avcodec.h>
#include <config.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
#include <libavutil/opt.h>

#include "cmdutils.h"

//#define TRIAL                            0
#define VS_PAID_VERSION                  0

#define VS_CLIENT_VERSION                @"3.1"

///Video Stream Error enumerations
typedef enum {
    kVSErrorNone = 0,
    kVSErrorUnsupportedProtocol,
    kVSErrorStreamURLParseError,
    kVSErrorOpenStream,
    kVSErrorStreamInfoNotFound,
    kVSErrorStreamsNotAvailable,
    kVSErrorStreamDurationNotFound,
    kVSErrorAudioStreamNotFound,
    kVSErrorVideoStreamNotFound,
    kVSErrorAudioCodecNotFound,
    kVSErrorVideoCodecNotFound,
    kVSErrorAudioCodecNotOpened,
    kVSErrorUnsupportedAudioFormat,
    kVSErrorAudioStreamAlreadyOpened,
    kVSErrorVideoCodecNotOpened,
    kVSErrorAudioAllocateMemory,
    kVSErrorVideoAllocateMemory,
    kVSErrorStreamReadError,
    kVSErrorStreamEOFError,
    kVSErroSetupScaler,
} VSError;

@interface VSManager : NSObject {
    BOOL _debugBuild;
    BOOL _trialBuild;
}


- (id)initWithUsername:(NSString *)username secret:(NSString *)secret;

- (void)initEngine;

- (AVFormatContext *)allocateContext;

- (int)startConnectionWithContext:(AVFormatContext **)avCtx fileName:(const char *)avName avInput:(AVInputFormat *)avFmt
                          options:(AVDictionary **)avOptions userOptions:(AVDictionary **)avUserOptions;

- (VSError)parseOptionsFromURLString:(NSString *)urlString
                      finalURLString:(NSString **)finalURLString;

- (BOOL)willAbort;

- (void)abort;

@end
