//
//  NUSAVuiControllerDelegate.h
//  Dragon Medical SpeechKit
//
//  Copyright 2011 Nuance Communications, Inc. All rights reserved.
//
//  SDK version: 6.1.17.1
//

#import <UIKit/UIKit.h>

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
/** @brief NUSAVuiController delegate messages.
 
	@xmlonly<nmFramework>DragonMedicalSpeechKit</nmFramework>@endxmlonly
	@since 1.0
 
	Delegate messages sent by the NUSAVuiController class to its delegate receiver. All messages 
	provided by the protocol are optional and can be implemented by the receiver. Messages will 
	be sent on the thread that registered for the delegate. 
*/
@protocol NUSAVuiControllerDelegate <NSObject>
@optional

//////////////////////////////////////////////////////////////////////////////////////////
/// @name Processing state handling 
//////////////////////////////////////////////////////////////////////////////////////////

/** @brief Sent after the end user has started to speak.
	@since 1.0
 
	Sent to the receiver whenever the user starts speaking in a speech-enabled GUI view. 
	Each vuiControllerDidStartProcessing() message will be paired with a corresponding 
	vuiControllerDidFinishProcessing() message.
 */
- (void) vuiControllerDidStartProcessing; 

/** @brief Sent after Dragon Medical SpeechKit has finished processing all audio data
	@since 1.0
 
	Sent to the receiver whenever the user stops speaking and Dragon Medical SpeechKit has finished
	processing all audio data and added all recognized text to the views' text controls. Note that 
	there might be a delay between when the user stops speaking and this message. The same is true if 
	you send the NUSASession::stopRecording() message. 
 */
- (void) vuiControllerDidFinishProcessing; 

/** @brief Sent after the end user has started a new utterance in a speech-enabled text control￼.
	@since 1.0
 
	Sent to the receiver whenever the user started an utterance in a speech enabled UIView 
	object on your applications user interface. Each vuiControllerDidStartProcessingForView:()
	message will be paired with a corresponding vuiControllerDidFinishProcessingForView:() message.

    @param view A pointer to the speech enabled UIView (for NUSAVuiController) or a pointer to the 
        object that implements the NUSATextControl protocol (as passed to NUSACustomVuiController’s 
        initWithView or synchronize methods).
*/
- (void) vuiControllerDidStartProcessingForView: (UIView*) view; 

/** @brief Sent after Nuance SpeechAnyhwere has recognized all utterances started by the end user in a 
		   specific text control.￼
	@since 1.0
 
	Sent to the receiver when Dragon Medical SpeechKit has finished working on all utterances started for
	a speech-enabled text control. Note that this message does not indicate that the 
	user stopped speaking and a new utterance can be started at any point while recording is 
	on. At the time this message is sent, the text contents of the UIView are already updated 
	with the recognized text. 
 
	@param view A pointer to the speech enabled UIView (for NUSAVuiController) or a pointer to the
        object that implements the NUSATextControl protocol (as passed to NUSACustomVuiController’s
        initWithView or synchronize methods).
*/
- (void) vuiControllerDidFinishProcessingForView: (UIView*) view;

/** @brief Sent when an application command is recognized.￼
    @since 1.3

	Sent to the receiver whenever an application command is recognized. 
	
    @param id The unique identifier of the command
    @param spokenPhrase The spoken phrase of the application command
    @param placeholderValues A dictionary containing the placeholder identifiers (as keys) and values that were present in the recognized application command. 
*/
- (void) vuiControllerDidRecognizeCommand: (NSString*) id spokenPhrase: (NSString*) spokenPhrase placeholderValues: (NSDictionary *) placeholderValues;

@end
