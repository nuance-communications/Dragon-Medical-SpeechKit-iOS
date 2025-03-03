//
//  NUSATextControl.h
//  Dragon Medical SpeechKit
//
//  Copyright (c) 2012 Nuance Communications, Inc. All rights reserved.
//
//  SDK version: 6.2.2.1
//

#import <Foundation/Foundation.h>

extern NSString *const NUSATextControlDidBeginEditingNotification;

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
/** @brief NUSATextControl messages.
 
 @xmlonly<nmFramework>DragonMedicalSpeechKit</nmFramework>@endxmlonly
 @since 1.3
 
 This protocol must be implemented for speech-enabling text controls that are not supported by Dragon Medical SpeechKit.
 
 */

@protocol NUSATextControl <NSObject>

/** @brief Return text.
 @since 1.3
 
 Return the text in the specified range.
 
 @param range A range of text in a control.
 @return A substring of text that falls within the specified range.
*/
- (NSString*) vuiTextInRange:(NSRange)range;

/** @brief Replace text
 @since 1.3
 
 Replace the text in a document that is in the specified range.
 After a vuiReplaceRange() call the insertion point must be located at the same position
 in the text as before the call. This means that if vuiReplaceRange() inserts or removes
 characters to the left of the current insertion point or selection, the location of the
 insertion point must be moved accordingly. If vuiReplaceRange() modifies text to the 
 right of the insertion point, the insertion point must not change. If vuiReplaceRange()
 modifies characters at the insertion point, the insertion point must be set to the end 
 of the modified region. Ideally, if vuiReplaceRange() is called while the user is typing 
 and modifies text to the left or right of the typing location, this will not interfere
 with the user's keyboard input. This is to ensure that speech recognition results can be
 inserted in the text asynchronously while the user is, for example, correcting a 
 misrecognition at another location in the text.
 
 @param range A range of text in a control.
 @param text A string to replace the text in range.
 @return A substring of text that falls within the specified range.
 */
- (void)vuiReplaceRange:(NSRange)range withText:(NSString *)text;

//////////////////////////////////////////////////////////////////////////////////////////
/// @name Properties
//////////////////////////////////////////////////////////////////////////////////////////
/** @brief The range of selected text in a control.
 @since 1.3
 
 If the text range has a length, it indicates the currently selected text. If it has zero 
 length, it indicates the caret (insertion point).
 */
@property(readwrite)  NSRange vuiSelectedTextRange; 

/** @brief The length of the text in a control.
 @since 1.3
*/
@property(readonly)   NSUInteger vuiTextLength; 

/** @brief The VUI concept for the control.
 @since 1.3
*/
@property(readwrite, copy)  NSString* vuiConceptName; 

/** @brief The VUI document field id for the control.
 @since 2.1
 */
@property(readwrite, copy)  NSString* vuiDocumentFieldId;

/** @brief Returns a Boolean value indicating whether the receiver is the first responder for recognition results.
 @since 1.3
 
 This method is called by SpeechKit to determine which control has the first responder status for recognition results, i.e. where the recognized text should be inserted.
 If the NUSATextControl protocol is implemented on a class that derives from a responder class, this method is already available and does not need to be implemented.

 @return YES if the receiver is the first responder, otherwise NO.
*/
- (BOOL)isFirstResponder;

/** @brief Notifies the receiver that it is about to become first responder for recognition results.
 @since 1.3
 
 Classes that adopt the NUSATextProtocol can use this method to perform some action, such as highlighting the active control.
 This method is called by SpeechKit when the active control is changed in response to a navigation command. The implementation of becomeFirstResponder is responsible for resigning the first responder state from other custom controls if needed.
 If the NUSATextControl protocol is implemented on a class that derives from a responder class and can become the first responder, this method is already available and does not need to be implemented.
 
 @return YES if the receiver accepts first-responder status or NO if it refuses this status.
 */
- (BOOL)becomeFirstResponder;

/** @brief A Boolean value that determines whether automatic speech focus handling is disabled in this control.
 @since 1.3
 
 When set to YES, the automatic speech focus handling is disabled, if it is enabled gestures are supported. The default value of this property is NO.
 Automatic speech focus handling is the red border around the speech-enabled controls during recording and the flame inside the speech-enabled controls.
 You should set this property to YES when your custom control has multiple input fields. In this case the automatic speech focus handling is ambiguous and should be disabled.
*/ 

@optional
@property(readwrite)  BOOL vuiDisableAutomaticSpeechFocusHandling; 

@end
