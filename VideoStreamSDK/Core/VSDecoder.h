//
//  VSDecoder.h
//  VideoStreamSDK
//
//  Created by Murat Sudan
//  Copyright (c) 2013-2016 Murat Sudan. All rights reserved.
//  Elma DIGITAL
//

#import <Foundation/Foundation.h>
#import "VSDecodeManager.h"
#import "VSQueue.h"

#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
#include "libswresample/swresample.h"
#include <libavutil/opt.h>
#include <pthread.h>

@class VSClock;

/**
 *  Base class of VSAudioDecoder & VSVideoDecoder classes. It holds common ffmpeg related datas such as CodecContext, AVCodec, etc...
 */
@interface VSDecoder : VSQueue {
    AVCodecContext* _codecContext;
    AVCodec* _codec;
    AVStream* _stream;
    NSInteger _streamId;
    
    //manager
    id _manager;
    id _clockManager;
    
    int _ffmpegVersMajor;
    VSClock *_decoderClock;
}

/* init with codec context */
/**
 *  Initialize VSDecoder with AVCodecContext, AVStream, stream index, and manager parameters
 *
 *  @param cdcCtx  FFmpeg's codec I/O context
 *  @param strm    FFmpeg's Stream structure
 *  @param sId     Stream index
 *  @param manager VSDecodeManager object
 *
 *  @return VSDecoder object
 */
- (id)initWithCodecContext:(AVCodecContext*)cdcCtx stream:(AVStream *)strm streamId:(NSInteger)sId manager:(id)manager;

///The stream index in streams list in FFmpeg
@property (nonatomic, readonly) NSInteger streamId;

///VSDecodeManager object, used for retrieving global states
@property (nonatomic, readonly) id manager;

@property (nonatomic, readonly) VSClock *decoderClock;

@end
