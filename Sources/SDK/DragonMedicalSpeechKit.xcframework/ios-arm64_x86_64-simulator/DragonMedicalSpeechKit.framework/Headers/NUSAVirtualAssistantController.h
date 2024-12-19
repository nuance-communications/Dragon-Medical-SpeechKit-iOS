//
//  NUSAVirtualAssistantController.h
//  MobileSpeechSDK
//
//  Created by Yan Tran on 11/20/18.
//  Copyright © 2018 Nuance Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <DragonMedicalSpeechKit/NUSAVirtualAssistantControllerDelegate.h>

NS_ASSUME_NONNULL_BEGIN


/**
 @brief The primary object for Dragon Medical Virtual Assistant (DMVA).
 */
@interface NUSAVirtualAssistantController : NSObject
{
@protected
    __weak id<NUSAVirtualAssistantControllerDelegate> delegate;
}

//////////////////////////////////////////////////////////////////////////////////////////
/// @name Properties
//////////////////////////////////////////////////////////////////////////////////////////

/** @brief NUSAVirtualAssistantController delegate.

 This delegate receives messages from the DMVA instance. Delegates must
 conform to the NUSAVirtualAssistantController protocol. The delegate won't be
 retained.
 */
@property (nonatomic, weak) id<NUSAVirtualAssistantControllerDelegate> delegate;


/**
@brief Returns a single instance of NUSAVirtualAssistantController.
 @return The pointer to the controller.
 */
+ (NUSAVirtualAssistantController*) sharedController;

/**
 @brief Opens DMVA for the specified grammar model.
 
 Opens DMVA for the specified grammar model. If the SpeechKit session isn't open, the application type isn't correct, the DMVA state is invalid, or the parameter value is invalid, the request won't be processed and VAResultCode value is returned. Otherwise, DMVA will continue to asynchronously validate the user license and initialize for the specified grammar model. The state will be set to Opening and VAResultCodeSuccess is returned. DMVA will transition to the Opened state when it has successfully completed license and grammar checks.
 
 The return value is one of the following:
 
 NUSAVirtualAssistantErrorCodeNoError - openWithModel has been initiated successfully and DMVA is in the Opening state.
 
 NUSAVirtualAssistantErrorCodeApplicationStateError - The application is in a state which doesn't allow an Open process to commence (either Opening or Closing).
 
 NUSAVirtualAssistantErrorCodeParameterError - model is null or an empty string, or doesn't start with one of "Administrator", "Physician", or "Nurse".
 
 NUSAVirtualAssistantErrorCodeUnknownError - The process threw an unexpected exception.
 
@param model The name of the grammar model to load.
@param options A dictionary of objects containing optional parameters.

@return NUSAVirtualAssistantErrorCode
 
 */
- (NUSAVirtualAssistantErrorCode) openWithModel: (NSString*) model options: (nullable NSDictionary <NSString*, NSObject*>*) options;

/**
 @brief Closes DMVA.
 Closes DMVA and frees up resources. Aborts all active dialogs and removes any transactions that were scheduled. DMVA will continue the closing process asynchronously and will transition to the Closed state when it has finished closing. If DMVA is already in the Closing state, the request won't be processed and NUSAVirtualAssistantErrorCodeApplicationStateError is returned. Once close is called, you'll need to call open again to use DMVA.
 
 The return value is one of the following:
 
 NUSAVirtualAssistantErrorCodeNoError - close has completed successfully and DMVA has transitioned into the Closed state.
 
 NUSAVirtualAssistantErrorCodeApplicationStateError - Attempt to close while in the Closing state.
 
@return NUSAVirtualAssistantErrorCode
 */
- (NUSAVirtualAssistantErrorCode) close;

/**
 @brief Stops an active dialog.
 
 If there is an active dialog, the dialog is canceled and the dialogResult method of the registered NUSAVirtualAssistantController delegate will be called. The SDK exits out of DMVA mode and returns to its previous mode. Audio that was recorded while in DMVA mode is discarded.
 
 The return value is one of the following:
 
 NUSAVirtualAssistantErrorCodeNoError - DMVA accepted the request.
 
 NUSAVirtualAssistantErrorCodeApplicationStateError - The application is in a state which doesn't allow a dialog to be aborted.
 
@return NUSAVirtualAssistantErrorCode:
 

 
 */
- (NUSAVirtualAssistantErrorCode) stopDialog;

/**
 @brief Sends dialog text to DMVA.
 
Sends text to DMVA to start or continue a dialog.
 
 The return value is one of the following:
 
 NUSAVirtualAssistantErrorCodeNoError - DMVA accepted the request. DMVA will continue to process the request asynchronously.
 
 NUSAVirtualAssistantErrorCodeApplicationStateError- The application is in a state which doesn't allow text to be sent.
 
 NUSAVirtualAssistantErrorCodeParameterError - The text parameter is invalid.
 

@param text The text to send to DMVA for processing.

 @return NUSAVirtualAssistantErrorCode

 */
- (NUSAVirtualAssistantErrorCode) sendText: (NSString*) text;


/** @brief Uploads concept values for a dynamic concept.
 
 Asynchronously sets the list of literal-value pairs for a dynamic concept.  The specified concept will be overwritten with the contents of the new list for the current user.  This is meant to be used right after the Virtual Assistant has opened so that the items in the concept are available for all the transactions. Note: The command call returns a status synchronously, but the upload and processing by the DMVA server is asynchronous. The registered NUSAVirtualAssistantControllerDelegate's uploadConceptResult method will be called when the upload has occurred. Items will persist in DMVA after it has closed and will be available for the current user in subsequent sessions until clearUploadedValuesForConcept is called. Therefore, if it isn't expected that the items will be valid beyond the current session, we recommend you call clearUploadedValuesForConcept before closing the DMVA session. If you need to update a concept for immediate use, use setInlineValuesForConcept instead. If DMVA isn't open, the request isn't processed and false is returned.
 
 @param conceptName The name of the concept.
 
 @param conceptValuesJSON A string representation of an array of JSON objects, where each JSON object contains a single key-value pair of a literal and its corresponding value.
 
 Here's an example value:
 @code
 [
 { "literal": "Susan", "value": "Susan Walker"},
 { "literal": "Timothy", "value": "Timothy Walker"},
 { "literal": "Tim", "value": "Timothy Walker"},
 { "literal": "Jonathan", "value": "Jonathan Walker"},
 ]
 @endcode
 
 
  The return value is one of the following:
 
 NUSAVirtualAssistantErrorCodeNoError - DMVA accepted the request. DMVA will continue to process the request asynchronously and will call the registered NUSAVirtualAssistantControllerDelegate's conceptResult method when it has finished.
 
 NUSAVirtualAssistantErrorCodeApplicationStateError - The application is in a state which doesn't allow concept values to be uploaded.
 
 NUSAVirtualAssistantErrorCodeParameterError - The conceptName or conceptValuesJSON parameter is invalid.
 
@return  NUSAVirtualAssistantErrorCode
 
 
 */
- (NUSAVirtualAssistantErrorCode) uploadValuesForConcept: (NSString*) conceptName conceptValues:(NSString*) conceptValuesJSON;

/**
 @brief Uploads concept values for a dynamic concept.
 @param conceptName The name of the concept.
 @param conceptValuesJSON A string representation of an array of JSON objects, where each JSON object contains a single key-value pair of a literal and its corresponding value.
 @param completionHandler The completionHandler block invoked when the response is returned.
 @return NUSAVirtualAssistantErrorCodeNoError - DMVA accepted the request. DMVA will continue to process the request asynchronously and will call the registered NUSAVirtualAssistantControllerDelegate's conceptResult method when it has finished.
 NUSAVirtualAssistantErrorCodeApplicationStateError - The application is in a state which doesn't allow concept values to be uploaded.
 NUSAVirtualAssistantErrorCodeParameterError - The conceptName or conceptValuesJSON parameter is invalid.
 */

- (NUSAVirtualAssistantErrorCode)uploadValuesForConcept:(NSString*)conceptName
                                          conceptValues:(NSString*)conceptValuesJSON
                                  withCompletionHandler:(void (^ _Nullable)(NSError * _Nullable error))completionHandler;

/** @brief Clears uploaded concept values for a dynamic concept.
 
 Asynchronously clears the specified concept where the items had been set by uploadValuesForConcept. The command call returns a status synchronously, but the processing of the request by DMVA is asynchronous. The registered NUSAVirtualAssistantControllerDelegate's conceptResult method will be called when the request has been uploaded.
 
 
  The return value is one of the following:
 
 NUSAVirtualAssistantErrorCodeNoError - DMVA accepted the request. DMVA will continue to process the request asynchronously and call the registered NUSAVirtualAssistantControllerDelegate's conceptResult method when it has finished.
 
 NUSAVirtualAssistantErrorCodeApplicationStateError - The application is in a state which doesn't allow concept values to be uploaded.
 
 NUSAVirtualAssistantErrorCodeParameterError - The conceptName or conceptValues parameter is invalid.
 
@param conceptName The name of the concept.

@return NUSAVirtualAssistantErrorCode

 */
- (NUSAVirtualAssistantErrorCode) clearUploadedValuesForConcept: (NSString*) conceptName;

/**
 @brief Clears uploaded concept values asynchronously for a dynamic concept.
 @param conceptName The name of the concept.
 @param completionHandler The completionHandler block invoked when the response is returned.
 @return NUSAVirtualAssistantErrorCodeNoError - DMVA accepted the request. DMVA will continue to process the request asynchronously and call the registered NUSAVirtualAssistantControllerDelegate's conceptResult method when it has finished.
 NUSAVirtualAssistantErrorCodeApplicationStateError - The application is in a state which doesn't allow concept values to be uploaded.
 NUSAVirtualAssistantErrorCodeParameterError - The conceptName or conceptValues parameter is invalid.
*/

- (NUSAVirtualAssistantErrorCode)clearUploadedValuesForConcept:(NSString*)conceptName
                                         withCompletionHandler:(void (^ _Nullable)(NSError * _Nullable error))completionHandler;


/**@brief Clears uploaded concept values for a dynamic concept.
 
 Asynchronously clears all of a user's dynamic concepts that were set with the uploadValuesForConcept method. The command call returns a status synchronously, but the processing of the request by DMVA is asynchronous. The registered NUSAVirtualAssistantControllerDelegate's conceptResult method will be called when the request has been uploaded.
 NUSAVirtualAssistantControllerDelegate's conceptResult method will be called when the request has been uploaded.
 
 
 The return value is one of the following:
 
 NUSAVirtualAssistantErrorCodeNoError - DMVA accepted the request. DMVA will continue to process the request asynchronously and call the registered NUSAVirtualAssistantControllerDelegate's conceptResult method when it has finished.
 
 NUSAVirtualAssistantErrorCodeApplicationStateError - The application is in a state which doesn't allow concept values to be cleared.
 
 
@return NUSAVirtualAssistantErrorCode

 */
- (NUSAVirtualAssistantErrorCode) clearAllUploadedConceptValues;


/**@brief Sets inline concept values for dynamic concepts.
 
 Adds a list of literal-value pairs to a dynamic concept for immediate use. This is meant to be used for a small number of items (50 or fewer) right before they are needed for a particular dialog. The items in the concept will be available for recognition immediately following this call. Use clearInlineValuesForConcept to clear the concept when the items are no longer needed, or the items will continue to be available until DMVA closes. Uploading a large number of items with this call will result in degraded performance. If a concept needs to be overwritten with a large number of items, use uploadValuesForConcept instead. If DMVA isn't open, the request isn't processed and NUSAVirtualAssistantErrorCodeApplicationStateError is returned.
 
 
  The return value is one of the following:
 
 NUSAVirtualAssistantErrorCodeNoError - DMVA accepted the request.
 
 NUSAVirtualAssistantErrorCodeApplicationStateError - The application is in a state which doesn't allow concept values to be cleared.
 
 NUSAVirtualAssistantErrorCodeParameterError - The conceptName or conceptValues parameter is invalid.
 
 @param conceptName The name of the concept.
 
 @param conceptValuesJSON An array of JSON objects, where each JSON object contains a single key-value pair of a literal and its corresponding value.
 
 Here's an example value:
 @code
 [
 { "literal": "Susan", "value": "Susan Walker"},
 { "literal": "Timothy", "value": "Timothy Walker"},
 { "literal": "Tim", "value": "Timothy Walker"},
 { "literal": "Jonathan", "value": "Jonathan Walker"},
 ]
 @endcode
 @return NUSAVirtualAssistantErrorCode

 
 */
- (NUSAVirtualAssistantErrorCode) setInlineValuesForConcept: (NSString*) conceptName conceptValues:(NSString*) conceptValuesJSON;

/** @brief Clears inline concept values for a dynamic concept.
 
 Clears one immediate concept. The concept is fully cleared once the call returns. If DMVA isn't open, the request is ignored and NUSAVirtualAssistantErrorCodeApplicationStateError is returned.

 The return value is one of the following:
 
 NUSAVirtualAssistantErrorCodeNoError - The concept was cleared of inline values.
 
 NUSAVirtualAssistantErrorCodeApplicationStateError - The application is in a state which doesn't allow inline concept values to be cleared.
 
 NUSAVirtualAssistantErrorCodeParameterError - The conceptName parameter is invalid.
 
@param conceptName The name of the concept.

 @return NUSAVirtualAssistantErrorCode
 */

- (NUSAVirtualAssistantErrorCode) clearInlineValuesForConcept: (NSString*) conceptName;
/** @brief Starts a confirmation prompt.
 
 Starts a prompt for the user to provide confirmation. The microphone enters VA Active mode. The user will be expected to reply either 'yes' or 'no'.  If the user responds 'yes', the dialogResult method will be called again with the task state set to "confirmed". Otherwise the task state will be "aborted". DMVA won't provide text-to-speech or text prompts for this dialog, so the integrator needs to generate the prompts, call startSpeaking, and wait for didStopSpeaking to be called before calling promptForConfirmation.

Note: Calling PromptForConfirmation() causes any active dialog to be aborted.
 
 
 The return value is one of the following:
 
 NUSAVirtualAssistantErrorCodeNoError - DMVA accepted the request.
 
 NUSAVirtualAssistantErrorCodeApplicationStateError - The application is in a state which doesn't allow PromptForConfirmation to be called.
 
 
@return NUSAVirtualAssistantErrorCode

 */
- (NUSAVirtualAssistantErrorCode) promptForConfirmation;

/** @brief Starts a prompt for a free text virtual assistant request.
 
Starts a dialog where the user is prompted for free text.
 
The microphone enters VA Active mode. After the user speaks, the dialogResult method will be called and the JSON result for the intent dmvaPromptForFreeText will have a FREE_TEXT concept populated with the text of the recognized speech from the user. DMVA doesn't provide text-to-speech or text prompts for this dialog, so the integrator needs to generate the prompts, call startSpeaking, and wait for didStopSpeaking to be called before calling promptForFreeText.

 
 The return value is one the following:
 
 NUSAVirtualAssistantErrorCodeNoError - DMVA accepted the request.
 
 NUSAVirtualAssistantErrorCodeApplicationStateError - The application is in a state which doesn't allow PromptForFreeText to be called.
 
 @return NUSAVirtualAssistantErrorCode

 */
- (NUSAVirtualAssistantErrorCode) promptForFreeText;

/** @brief Starts a prompt to make a choice.
 
Starts a dialog where the user is prompted to make a choice.  The microphone enters VA Active mode. The items parameter holds a JSON string containing key-value pairs of literals and their corresponding values. DMVA waits for the speaker to say one of the literals from the items parameter. When the speaker says one of the choices, the dialogResult method will be called and the JSON result for dmvaPromptForChoice will have a CHOICE concept populated with the value that corresponds to the literal that the speaker provided. DMVA doesn't provide text-to-speech or text prompts for this dialog, so it will be up to the integrator to generate the prompts, call startSpeaking, and wait for didStopSpeaking to be called before calling promptForChoice.


 
The return value is one the following:
 
 NUSAVirtualAssistantErrorCodeNoError - DMVA accepted the request.
 
 NUSAVirtualAssistantErrorCodeApplicationStateError - The application is in a state which doesn't allow text transactions.
 
 NUSAVirtualAssistantErrorCodeParameterError - The text parameter is invalid.
 
Here's an example value for items:
@code
[
 { "literal": "save", "value": "save"},
 { "literal": "delete", "value": "delete"},
 ]
@endcode
@param items - A string representing an array of JSON objects, where each JSON object contains a single key-value pair of a literal and its corresponding value.

@return NUSAVirtualAssistantErrorCode
 */
- (NUSAVirtualAssistantErrorCode) promptForChoice: (NSString*) items;

@end

NS_ASSUME_NONNULL_END
