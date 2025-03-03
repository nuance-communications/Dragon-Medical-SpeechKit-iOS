//
//  NUSASessionDelegate.h
//  Dragon Medical SpeechKit
//
//  Copyright 2011 Nuance Communications, Inc. All rights reserved.
//
//  SDK version: 6.2.2.1
//

#import <UIKit/UIKit.h>
#import "NUSATypes.h"

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
/** @brief NUSASession delegate messages.
 
	@xmlonly<nmFramework>DragonMedicalSpeechKit</nmFramework>@endxmlonly
	@since 1.0
 
	Delegate messages sent by the NUSASession class to its delegate receiver. All messages 
	provided by the protocol are optional and can be implemented by the receiver. 
*/
@protocol NUSASessionDelegate <NSObject>
@optional

//////////////////////////////////////////////////////////////////////////////////////////
/// @name Recording sessions
//////////////////////////////////////////////////////////////////////////////////////////

/** @brief Sent after audio data recording has started.
	@since 1.0
	
	Sent to the delegate whenever a recording session is started.
 */
- (void) sessionDidStartRecording;

/** @brief Sent after audio data recording has stopped and standby mode disabled.
	@since 3..9
    Sent to the delegate in the following conditions:
    1. Standby mode is disabled and the recording session is stopped.
    2. An error occurs when starting the recording session.
    3. An error occurs starting standby mode.
    4. Long press on the microphone button of the SpeechBar when the microphone is in recording or standby mode.
 */
- (void) sessionDidStopRecording;

//////////////////////////////////////////////////////////////////////////////////////////
/// @name TTS
//////////////////////////////////////////////////////////////////////////////////////////

/** @brief Sent after speaking has started.
    @since 1.3
 
    Sent to the delegate whenever speaking is started.
    If a call to startSpeaking() cancels a previous call to startSpeaking(), this message is not sent again.
 */
- (void) sessionDidStartSpeaking;

/** @brief Sent after speaking has stopped.
    @since 1.3
 
    Sent to the delegate whenever speaking is finished. This message is sent when the session has finished speaking the provided text or stopSpeaking() is called. 
    If speaking is cancelled by another call to startSpeaking(), this message is only sent after the last text has been finished.
 */
- (void) sessionDidStopSpeaking;

//////////////////////////////////////////////////////////////////////////////////////////
/// @name Standby mode
//////////////////////////////////////////////////////////////////////////////////////////

/** @brief Sent after standby mode has started.
    @since 3.9
    Sent to the delegate in the following conditions:
    1.Standby mode enabled and started.
    2.Standby mode is enabled and the recording  session is stopped.
 */
- (void) sessionDidStartStandby;


//////////////////////////////////////////////////////////////////////////////////////////
/// @name Authentication Token
//////////////////////////////////////////////////////////////////////////////////////////

/** @brief Sent after authentication token is invalid
    @since 6.0

    Sent to the delegate whenever the authentication token is been considered invalid.
    Once this message is sent the user must get new token from authentication library and send the new token by calling updateAuthenticationToken API
 */
- (void) sessionDidReceiveInvalidAuthenticationToken;

/** @brief Called when authentication token is about to expire
	@since 6.0
 */
- (void) sessionDidNotifyAuthenticationTokenIsAboutToExpire;


//////////////////////////////////////////////////////////////////////////////////////////
/// @name Audio Interruption
//////////////////////////////////////////////////////////////////////////////////////////

/** @brief Called whenever audio interruption is received and its state changes
    @param state state of audio interruption being received
    @since 6.2
 */
- (void) sessionDidReceiveAudioInterruptionState:(NUSAAudioInterruptionState)state;


/** @brief  Configures interrupt handling behavior when system displays incoming calls using a banner
    @return Return true to continue recording.
            By default SDK stops recording on receiving incoming call or other audio interrupts
    @since 6.2
 */
- (BOOL) sessionShouldContinueRecordingDuringCallBanners;

@end
