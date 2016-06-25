//
//  VSDecodeManager.h
//  VideoStreamSDK
//
//  Created by Murat Sudan
//  Copyright (c) 2013-2016 Murat Sudan. All rights reserved.
//  Elma DIGITAL
//

#import <Foundation/Foundation.h>
#import <AudioToolbox/AudioToolbox.h>
#import <AVFoundation/AVFoundation.h>
#import "VSManager.h"
#import "VSClockManager.h"

#pragma mark
//Language properties
#ifndef RTL
#define TR(A) NSLocalizedString((A), @"")
#else
#define TR(A) [NSLocalizedString((A), @"") stringReversed]
#endif

#ifndef NS_BLOCK_ASSERTIONS
#define NS_BLOCK_ASSERTIONS
#endif

#ifndef NS_ENUM
#define NS_ENUM(_type, _name) enum _name : _type _name; enum _name : _type
#endif

#ifndef NS_OPTIONS
#if (__cplusplus)
#define NS_OPTIONS(_type, _name) _type _name; enum : _type
#else
#define NS_OPTIONS(_type, _name) enum _name : _type _name; enum _name : _type
#endif
#endif

//defines
#ifndef FFMPEG_VERSION
    #define FFMPEG_VERSION                          "2.x"
#endif

typedef enum {
    VSVideoStreamColorFormatUnknown = 0,
    VSVideoStreamColorFormatYUV,
    VSVideoStreamColorFormatRGB
} VSVideoStreamColorFormat;

#pragma mark
///Log definitions & levels

typedef NS_OPTIONS(NSUInteger, VSLogLevel) {
    kVSLogLevelDisable      = 0,
    kVSLogLevelStateChanges = 1 << 0,
    kVSLogLevelDecoder      = 1 << 1,
    kVSLogLevelDecoderExtra = 1 << 2,
    kVSLogLevelOpenGL       = 1 << 3,
    kVSLogLevelAVSync       = 1 << 4,
    kVSLogLevelAll          = 31,
};

extern VSLogLevel log_level;

#define VSLog(A, ...) do {  \
                            if (A & log_level) { \
                                NSLog(__VA_ARGS__);\
                            } \
                    } while (0)


///Stream info data keys
extern NSString *STREAMINFO_KEY_CONNECTION;
extern NSString *STREAMINFO_KEY_DOWNLOAD;
extern NSString *STREAMINFO_KEY_BITRATE;
extern NSString *STREAMINFO_KEY_AUDIO;
extern NSString *STREAMINFO_KEY_VIDEO;

///Decoder state enumerations
typedef enum {
    kVSDecoderStateNone = 0,
    kVSDecoderStateInitialized,
    kVSDecoderStateConnecting,
    kVSDecoderStateConnected,
    kVSDecoderStateConnectionFailed,
    kVSDecoderStateGotStreamDuration,
    kVSDecoderStateGotAudioStreamInfo,
    kVSDecoderStateGotVideoStreamInfo,
    kVSDecoderStateInitialLoading,
    kVSDecoderStateReadyToPlay,
    kVSDecoderStateBuffering,
    kVSDecoderStatePlaying,
    kVSDecoderStatePaused,
    kVSDecoderStateStoppedByUser,
    kVSDecoderStateStoppedWithError,
} VSDecoderState;

enum {
    AV_SYNC_AUDIO_MASTER, /* default choice */
    AV_SYNC_VIDEO_MASTER,
    AV_SYNC_EXTERNAL_CLOCK, /* synchronize to an external clock */
};

extern int av_usleep(unsigned usec);

@protocol VSDecoderDelegate;

/**
 *  VSDecodeManager is the authority of core engine part of VideoStreamSDK. VSDecodeManager is responsible for the management of Audio & Video decoders, management of connection and reading packets from stream or file. Also, VSPlayerController communicates VSDecoderManager to do non-UI actions and configurations.
 */

@interface VSDecodeManager : VSManager {

    unsigned long _totalBytesDownloaded;
    NSMutableDictionary *_streamInfo;
    
    NSObject<VSDecoderDelegate> *_delegate;
}
        

#pragma mark - Private methods
        
- (void)setDecoderStateWithData:(NSDictionary *)data;

#pragma mark - Function declerations

/**
 *  Initialize decoder
 *  @param username - If license-form is not accessible, fill this parameter with your username taken from our server
 *  @param secret   - If license-form is not accessible, fill this parameter with your secret taken from our server
 *  @return VSDecodeManager object
 */
- (id)initWithUsername:(NSString *)username secret:(NSString *)secret;

/**
 *  Connect to stream URL String with decode options
 *
 *  @param urlString The location of the remote stream url. If it's a file then it must be located on a remote server.
 *  @param options   Streaming options according to the used protocol
 *
 *  @return kVSErrorNone If success otherwise kVSError typed error
 */
- (VSError)connectWithStreamURLString:(NSString*)urlString options:(NSDictionary *)options;

/**
 *  Toggle play & pause the stream/file
 */
- (void)streamTogglePause;

/**
 *  This represents the master clock (audio clock if audio stream exists)
 *
 *  @return audio clock time if audio stream exists otherwise video clock time
 */
- (double)masterClock;

/**
 *  This represents the current time (BASED ON AV_TIME_BASE)
 *
 *  @return current time with the help of master clock
 */
- (double)currentTime;

/**
 *  Set log levels accourding to the VSLogLevel enums
 *
 *  @param logLevel Filter or expand the log mechanism, values are VSLogLevel enumerations
 */
- (void)setLogLevel:(VSLogLevel)logLevel;

/* External clock sync  */

/**
 *  Check External clock speed and update it if necessary
 */
- (void)checkExternalClockSpeed;

/**
 *  Sync audio and video with mastering one of them, only mastering to audio is implemented
 *
 *  @return Enumeration of sync types
 */
- (int)masterSyncType;

/**
 *  Detects whether if the stream is realtime or not
 *
 *  @return YES if the stream is realtime otherwise NO
 */
- (BOOL)isRealTime;

/**
 *  Fires ffmpeg methods to get packets and later decode them. (This method needs to be called after a successful connection)
 */
- (void)startToReadAndDecode;

#pragma mark - Public Actions
        
/**
 *  Call below method for an RTSP connection in order to close connection on server peacefully
 */
- (void)sendRTSPCloseMessage;

/**
 *  Toggle play or pause the stream/file
 */
- (void)togglePause;

/**
 *  Update the screen with the following video frame
 */
- (void)stepToNextFrame;

/**
 *  abort method stops/unlock all waiting threads/queues
 *
 *  Before stoping the decoder, abort must be called.
 */
- (void)abort;

/**
 *  stop method shuts down the decoder
 *
 * abort must be called before stop method to kill decoder safely
 */
- (void)stop;

/**
 *  Seek in files located remotely
 *
 *  @param value A double value in seconds
 */
- (void)doSeek:(double)value;

/**
 *  Seek in buffered data coming from streaming server
 *
 *  This is a special method for realtime communication, it reduces the latency in realtime streaming
 *
 *  @param value Set a float value between 0.0 and 1.0. 1.0 means the end of the buffered data
 */
- (void)seekInDecoderBufferByValue:(float)value;

/**
 *  Cycle/Change to next the audio stream if remote stream/file has more than 1 audio stream
 */
- (void)cycleAudioStream;

/**
 *  Change to desired audio stream with index if remote stream/file has more than 1 audio stream
 *
 *  @param index Index of audio stream
 */
- (void)cycleAudioStreamWithStreamIndex:(int) index;

/**
 *  Provides information of codecs used in stream/file
 *
 *  @param index Index of stream
 *
 *  @return Information in NSString format
 */
- (NSString *)codecInfoWithStreamIndex:(int) index;

/**
 *  Provides the list of playable video streams
 *
 *  @return The list of playable video streams in NSArray (video stream objects are nsdictionary format and have keys which are "index, description")
 */
- (NSArray *)playableVideoStreams;

/**
 *  Provides the list of playable audio streams
 *
 *  @return The list of playable audio streams in NSArray (audio stream objects are nsdictionary format and have keys which are "index, description")
 */
- (NSArray *)playableAudioStreams;

/**
 *  Updates the information of codecs used in stream/file for a stream
 *
 *  @param index     Index of the stream
 *  @param mediaType MediaType in AVMediaType enumerations
 */
- (void)updateStreamInfoWithSelectedStreamIndex:(int)index type:(int)mediaType;

#pragma mark - Audio interruption handling

#pragma mark iOS 5.x

///AVAudioSession beginInterruption handler
- (void)beginInterruption;

//AVAudioSession endInterruptionWithFlags handler with flags
- (void)endInterruptionWithFlags:(NSUInteger)flags;

#pragma mark iOS 6.x or higher Audio interruption handling

//AVAudioSession interruption handler with notification
- (void) interruption:(NSNotification*)notification;

#pragma mark - Variable declerations

///If set, then delegate class instance will get all state change events of VSDecodeManager
@property (nonatomic, assign) NSObject<VSDecoderDelegate> *delegate;

@property (nonatomic, readonly) VSVideoStreamColorFormat videoStreamColorFormat;

///Indicates whether the decoder is paused or not
@property (nonatomic, readonly) BOOL streamIsPaused;

///Indicates whether any abort action is requested
@property (nonatomic, readonly) int abortIsRequested;

///Indicates the maximum frame duration, used in AV sync
@property (nonatomic, readonly) double maxFrameDuration;

///An integer value that indicates the action of showing the next video frame
@property (nonatomic, readonly) int step;

///Holds return code of av_read_pause FFmpeg API, used in AV sync
@property (nonatomic, readonly) int readPauseCode;

///Frame's width retrieved from AVCodecContext
@property (nonatomic, readonly) NSUInteger frameWidth;

///Frame's height retrieved from AVCodecContext
@property (nonatomic, readonly) NSUInteger frameHeight;

///Holds the state of application, used for not updating opengl view if app is in background
@property (nonatomic, readonly) BOOL appIsInBackgroundNow;

///Holds the total bytes that streamed from network
@property (nonatomic, readonly) unsigned long totalBytesDownloaded;

///Information that holds current audio and video stream and codecs
@property (nonatomic, readonly) NSMutableDictionary *streamInfo;
        
@property (nonatomic, readonly) VSClock *externalClock;

/**
 *  A readonly value that indicates the total duration
 *
 *  This value is valid for only files, live streams do not have duration information
 */
@property (nonatomic, readonly) float durationInSeconds;

///Size of data to probe, useful for reducing connection duration
@property (nonatomic, assign) int64_t probeSize;

///Maximum time (in AV_TIME_BASE units) during which the input should be analyzed in avformat_find_stream_info()
@property (nonatomic, assign) int64_t maxAnalyzeDuration;

/**
 *  Specify YES for better file streaming
 *
 *  Live streaming and remote file streaming needs some fine-tuning, so set this value YES for better remote file streaming
 */
@property (nonatomic, assign) BOOL remoteFileStreaming;

///The size of decoded pictures queue, for using to limit memory usage, default is 4
@property (nonatomic, assign) int videoPictureQueueSize;

///The size of queues in bytes of both Audio & Video encoded packets, for using to limit memory usage, default is 15 * 1024* 1024
@property (nonatomic, assign) int maxQueueSize;

///Get packets till this number then start playing, higher value increases buffering time, default is 15
@property (nonatomic, assign) int minFramesToStartPlaying;

///Shows audio's, and video's clocks difference logs for a specified interval, default is 0.01, & must be less or equal to 1
@property (nonatomic, assign) float avSyncLogFrequency;

///Shows read packets count from a stream for a specific interval, default is 0.01, & must be less or equal to 1
@property (nonatomic, assign) float avPacketCountLogFrequency;
        
///Shows read errors count from a stream for a specific interval, default is 0.01, & must be less or equal to 1
@property (nonatomic, assign) float avPacketReadErrorCountLogFrequency;

///Disable audio stream, default is NO
@property (nonatomic, assign) BOOL audioIsDisabled;

///The time, specified in seconds within the video timeline, when playback should start
@property (nonatomic, assign) int64_t initialPlaybackTime;

///Loops movie playback given times. 0 means forever
@property (nonatomic, assign) int loopPlayback;

///Stop decoder when video is done playing
@property (nonatomic, assign) BOOL autoStopAtEnd;

///Show first picture during initial bufferings
@property (nonatomic, assign) BOOL showPicOnInitialBuffering;
 
///Manage the audio, video and external clocks for A/V syncing
@property (nonatomic, readonly) VSClockManager *clockManager;
        
///A boolean that indicates any read error is happened
@property (nonatomic, readonly) BOOL readErrorGot;
        
/**
 * This is a gain volume effect which must be between 0.0 - 1.0, default value is 1.0
 *
 * volumeLevel does not have any effect on MPVolumeView or not have any relation with MPVolumeView
 */
@property (nonatomic, assign) float volumeLevel;

///Indicate the ffmpeg libraries version used in VideoStreamSDK
@property (nonatomic, readonly) NSString *ffmpegVersion;

///Use CPU in color format conversion and image scaling, default is NO (GPU is used)
@property (nonatomic, assign) BOOL useFFmpegSWScaleRender;

/**
 * Disable dropping video frames
 *
 * Default is enabled, video packets may be dropped to be synced with audio packets
 */
@property (nonatomic, assign) BOOL disableDropVideoPackets;


@end

/**
 *  Implement this delegate if you want to get notified about state changes with error codes of VSDecodeManager
 */
@protocol VSDecoderDelegate<NSObject>
@required

/**
 *  Required delegate method, If delegate object is set
 *
 *  @param state   Indicates the state in VSDecoderState type
 *  @param errCode Indicates the error code in VSError type
 */
- (void)decoderStateChanged:(VSDecoderState)state errorCode:(VSError)errCode;

@end

