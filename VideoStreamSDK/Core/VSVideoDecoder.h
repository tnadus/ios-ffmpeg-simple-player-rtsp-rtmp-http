//
//  VSVideoDecoder.h
//  VideoStreamSDK
//
//  Created by Murat Sudan
//  Copyright (c) 2013-2016 Murat Sudan. All rights reserved.
//  Elma DIGITAL
//

#import <Foundation/Foundation.h>
#import "VSDecoder.h"

/// A notification when a video frame is decoded and ready for render.
extern NSString *kVSVideoFrameReadyForRenderNotification;

/// A userInfo key for kVSVideoFrameReadyForRenderNotification notification to get videoframe object
extern NSString *kVSVideoFrame;

@class VSAudioDecoder;

/**
 *  VSVideoDecoder is responsible for decoding video packets into video frames, queuing frames for AV syncing, and feeding OpenGL view with frames
 */
@interface VSVideoDecoder : VSDecoder

/**
 *  Initialize video decoder with AVCodecContext, AVStream, stream index, and audioIsOK parameters
 *
 *  @param avFmtCtx     FFmpeg's format I/O context
 *  @param cdcCtx       FFmpeg's codec I/O context
 *  @param strm         FFmpeg's Stream structure
 *  @param sId          Stream index
 *  @param manager      VSDecodeManager object
 *  @param audioDecoder VSAudioDecoder object to be used in AV sync algorithm
 *  @return VSVideoDecoder object
 */
/* initialize video decoder with AVCodecContext, AVStream, stream index, and audioIsOK parameters */
- (id)initWithFormatContext:(AVFormatContext*)avFmtCtx codecContext:(AVCodecContext*)cdcCtx stream:(AVStream *)strm
                    streamId:(NSInteger)sId manager:(id)manager audioDecoder:(VSAudioDecoder *)audioDecoder;

/**
 *  Shutdown video decoder
 */
- (void)shutdown;

/**
 *  Queues are interworking with eachother and uses wait mechanism for management, this methods unlocks all queues
 */
- (void)unlockQueues;

/**
 *  A loop for refreshing screen with pictures
 */
- (void)schedulePicture;

/* decoder action on state change */

/**
 * Inform Video Decoder that Audio Decoder is destroyed
 */
- (void)onAudioDecoderDestroyed;

/**
 *  Inform Video Decoder that streaming/playing is paused
 */
- (void)onStreamPaused;

/**
 *  Inform Video Decoder that Audio stream is cycled/changed
 *
 *  @param decoder VSAudioDecoder object should be set again in Video Decoder
 */
- (void)onAudioStreamCycled:(VSAudioDecoder *)decoder;

/**
 *  Inform Video Decoder that it's reached end of file
 *
 *  @param value Specify YES for end of file is reached or NO for continue playing
 */
- (void)setEOF:(BOOL)value;

/**
 *  Start to decode video packets (This method needs to be called after a succesful connection)
 */
- (int)decodeVideo;

/// A Boolean that indicates whether if the decode process is done not not, used for managing threads
@property (nonatomic, readonly) BOOL decodeJobIsDone;

/// A Boolean that indicates whether if the scheduling of picture process is done not not, used for managing threads
@property (nonatomic, readonly) BOOL schedulePictureJobIsDone;

///Current byte position of AVPacket in stream, used for AV syncing
@property (nonatomic, readonly) int64_t currentPos;

@end
