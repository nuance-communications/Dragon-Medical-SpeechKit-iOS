//
//  NUSAVirtualAssistantControllerV2.h
//  DragonMedicalSpeechKit
//
//  Copyright © 2021 Nuance Communications, Inc. All rights reserved.
//


#import <Foundation/Foundation.h>

#import <DragonMedicalSpeechKit/NUSAVirtualAssistantControllerV2Delegate.h>

NS_ASSUME_NONNULL_BEGIN

/**
 @brief The primary object for Dragon Medical Virtual Assistant (DMVA).
 */
@interface NUSAVirtualAssistantControllerV2 : NSObject
{
@protected
    __weak id<NUSAVirtualAssistantControllerV2Delegate> delegate;
}

//////////////////////////////////////////////////////////////////////////////////////////
/// @name Properties
//////////////////////////////////////////////////////////////////////////////////////////

/** @brief NUSAVirtualAssistantControllerV2 delegate.

 This delegate receives messages from the DMVA instance. Delegates must
 conform to the NUSAVirtualAssistantControllerV2 protocol. The delegate won't be
 retained.
 */

@property (nonatomic, weak) id<NUSAVirtualAssistantControllerV2Delegate> delegate;


/**
@brief Returns a single instance of NUSAVirtualAssistantControllerV2.
 @return The pointer to the controller.
 */

+ (NUSAVirtualAssistantControllerV2*) sharedController;

/**
 @brief Opens DMVA for the specified grammar model.
 
 Opens DMVA for the specified grammar model. If the SpeechKit session isn't open, the application type isn't correct, the DMVA state is invalid, or the parameter value is invalid, the request will not be processed and VAResultCode value is returned. Otherwise, DMVA will continue to asynchronously validate the user license and initialize for the specified grammar model. The state will be set to Opening and VAResultCodeSuccess is returned. DMVA will transition to the Opened state when it has successfully completed license and grammar checks.
 
 The return value is one of the following:
 
 VAResultCodeSuccess - openVA has been initiated successfully and DMVA is in the Opening state.
 
 VAResultCodeNoSessionError - The request can't be processed because the session isn't initialised.
 
 VAResultCodeApplicationStateError - The application is in a state which doesn't allow an Open process to commence (either Opening or Closing).
 
 VAResultCodeBadRequestError - A bad request to the server. For example, model is null or an empty string, or doesn't start with one of "Administrator", "Physician", or "Nurse".
 
 VAResultCodeInternalSDKError - The process threw an unexpected exception.
 
@param model The name of the grammar model to load.
 
@param options A dictionary of objects containing optional parameters.

@return VAResultCode
 */

- (VAResultCode) openVA: (nonnull NSString*) model options: (nullable NSDictionary <NSString*, NSObject*>*) options;

/**
@brief Closes DMVA.
 Closes DMVA and frees up resources. DMVA will continue the closing process asynchronously and will transition to the Closed state when it has finished closing. If DMVA is already in the Closing state, the request won't be processed and VAResultCodeApplicationStateError is returned. Once closeVA is called, you'll need to call openVA again to use DMVA.
 
 The return value is one of the following:
 
 VAResultCodeSuccess - closeVA has completed successfully and DMVA has transitioned into the Closed state.
 
 VAResultCodeApplicationStateError - Attempt to close while in the Closing state.
 
 VAResultCodeNoSessionError - The request can't be processed because the session isn't initialised.
 
@return VAResultCode
 */

- (VAResultCode) closeVA;

/**
@brief Stops an active DMVA state.
 
 Aborts ongoing virtual assistant requests (for example, prompt) and returns the microphone to the previous mode. Any audio that was recorded while in DMVA mode is discarded.
 
 The return value is one of the following:
 
 VAResultCodeSuccess - DMVA accepted the request.
 
 VAResultCodeApplicationStateError - The application is in a state which doesn't allow a DMVA Active state to be aborted.
 
 VAResultCodeNoSessionError - The request can't be processed because the session isn't initialised.
 
@return VAResultCode:
 */

- (VAResultCode) stopVA;

/**
@brief Send text to DMVA.
 
 Sends text to DMVA to start a virtual assistant request.
 
 The return value is one of the following:
 
 VAResultCodeSuccess - DMVA accepted the request. DMVA will continue to process the request asynchronously.
 
 VAResultCodeApplicationStateError - The application is in a state which doesn't allow text to be sent.
 
 VAResultCodeBadRequestError - The text parameter is invalid.
 
 VAResultCodeNoSessionError - The request can't be processed because the session isn't initialised.
 
@param text The text to send to DMVA for processing.

@return VAResultCode
 */

- (VAResultCode) sendText: (nonnull NSString*) text;


/**
 @brief Uploads entity values for a dynamic entity.
 
 Uploads dynamic entity values to the DMVA server. These values are used as part of DMVA commands. For example, "Call Dr. Jones." In this example, "Dr. Jones" isn't part of the grammar but a dynamic entity value uploaded using this API. A call to this method returns immediately and the values are uploaded asynchronously. Once the upload completes, the completion handler passed to the completionHandler parameter is called.
 
 The return value is one of the following:
 
 VAResultCodeSuccess - DMVA accepted the request. DMVA will continue to process the request asynchronously.
 
 VAResultCodeNoSessionError - The request can't be processed because the session isn't initialised.
 
 VAResultCodeBadRequestError - The entityName or entityValuesJSON parameter is invalid.
 
 @param entityName The name of the entity.
 
 @param entityValuesJSON A string representation of an array of JSON objects, where each JSON object contains a single key-value pair of a literal and its corresponding value.
 
 @param completionHandler The block to be invoked once the dynamic data for the given entity is uploaded. This parameter can be null if the integrator doesn't require a response to the upload request. No other delegate method will be invoked.
 
 @return VAResultCode
 */

- (VAResultCode)uploadEntityValues:(nonnull NSString*)entityName
                         entityValues:(nonnull NSString*)entityValuesJSON
                withCompletionHandler:(void (^ _Nullable)(NSError * _Nullable error))completionHandler;


/**
 @brief Clears uploaded entity values asynchronously for a dynamic entity.
 
 Clears the uploaded dynamic entity values. A call to this method returns immediately and the clear request is sent asynchronously. Once the response is received, the completion handler passed to the completionHandler parameter is called.
 
 The return value is one of the following:
 
 VAResultCodeSuccess - DMVA accepted the request. DMVA will continue to process the request asynchronously.
 
 VAResultCodeNoSessionError - The request can't be processed because the session isn't initialised.

 VAResultCodeBadRequestError - The entityName parameter is invalid.
 
 @param entityName The name of the entity.
 
 @param completionHandler The block to be invoked once the dynamic data for the given entity is cleared. This parameter can be null if the integrator doesn't require a response to the clear request. No other delegate method will be invoked.

 @return VAResultCode
 */

- (VAResultCode)clearUploadedEntityValues:(nonnull NSString*)entityName
                       withCompletionHandler:(void (^ _Nullable)(NSError * _Nullable error))completionHandler;


/**@brief Clears all uploaded entity values.
 
 Clears all uploaded dynamic entity values for the current user. A call to this method returns immediately and the clear request is sent asynchronously. Once the response is received, the completion handler passed to the completionHandler parameter is called.
 
 The return value is one of the following:
 
 VAResultCodeSuccess - DMVA accepted the request. DMVA will continue to process the request asynchronously.
 
 VAResultCodeNoSessionError - The request can't be processed because the session isn't initialised.
 
 @param completionHandler The block to be invoked once all the dynamic data uploaded earlier is cleared. This parameter can be null if the integrator doesn't require a response to the clear request. No other delegate method will be invoked.
 
 @return VAResultCode
 */

- (VAResultCode) clearAllUploadedEntityValues:(void (^ _Nullable)(NSError * _Nullable error))completionHandler;


/** @brief Starts a confirmation prompt.
 
 Starts a prompt for the user to provide confirmation, i.e. YES or NO and their common synonyms. A call to this method returns immediately and a request is sent to DMVA asynchronously. On receiving a successful response, the microphone is put in the VA Active mode.
 
 The return value is one of the following:
 
 VAResultCodeSuccess - DMVA accepted the request.
 
 VAResultCodeNoSessionError - The request can't be processed because the session isn't initialised.
 
 VAResultCodeApplicationStateError - The application is in a state which doesn't allow PromptForConfirmation to be called.
 
 VAResultCodeBadRequestError - Parameters aren't properly provided.
 
 @param prompt A prompt message to be played before the microphone turns to VA Active. The message is optional; this parameter can be set to empty or null if not required.
 
 @return VAResultCode
 */

- (VAResultCode) promptForConfirmation:(nullable NSString *)prompt;


/** @brief Starts a prompt for a free text virtual assistant request.
 
 Starts a prompt for the user to provide free-form text; for example, "to review CBC". A call to this method returns immediately and a request is sent to DMVA asynchronously. On receiving a successful response, the microphone is put in the VA Active mode.
 
 The return value is one of the following:
 
 VAResultCodeSuccess - DMVA accepted the request.
 
 VAResultCodeNoSessionError - The request can't be processed because the session isn't initialised.
 
 VAResultCodeApplicationStateError - The application is in a state which doesn't allow PromptForFreeText to be called.
 
 VAResultCodeBadRequestError - Parameters aren't properly provided.
 
 @param prompt A prompt message to be played before the microphone turns to VA Active. The message is optional; this parameter can be set to empty or null if not required.
 
 @return VAResultCode
 */

- (VAResultCode) promptForFreeText:(nullable NSString *)prompt;

/** @brief Starts a prompt to choose from a list.
 
 Starts a prompt for the user's choice. The user chooses from the specified list of choices, provided in JSON format to the choices parameter. A call to this method returns immediately and a request is sent to DMVA asynchronously. On receiving a successful response, the microphone is put in the VA Active mode.

 The return value is one of the following:
 
 VAResultCodeSuccess - DMVA accepted the request.
 
 VAResultCodeNoSessionError - The request can't be processed because the session isn't initialised.
 
 VAResultCodeApplicationStateError - The application is in a state which doesn't allow text transactions.
 
 VAResultCodeBadRequestError - Parameters aren't properly provided; for example, the JSON is incorrectly formatted.
 
 Here is an example value for items:
 
 @code
 [
  { "literal": "save", "value": "save"},
  { "literal": "delete", "value": "delete"},
 ]
 @endcode
 
 @param choices A string representing a json array of objects containing "literal" and "value" properties.

 @param prompt A prompt message to be played before the microphone turns to VA Active. The message is optional; this parameter can be set to empty or null if not required.

 @return VAResultCode
 */

- (VAResultCode) promptForChoice:(nonnull NSString *)choices withPrompt:(nullable NSString *)prompt;


/** @brief Starts a prompt for specified entities.
 
 Starts a prompt for specified entities. A call to this method returns immediately and a request is sent to the DMVA asynchronously. On receiving a successful response, the microphone is put in the VA Active mode.
 
 The return value is one of the following:
 
 VAResultCodeSuccess - DMVA accepted the request.
 
 VAResultCodeNoSessionError - The request can't be processed because the session isn't initialised.
 
 VAResultCodeApplicationStateError - The application is in a state which doesn't allow a prompt for an entity.
 
 VAResultCodeBadRequestError - The text parameter is invalid.
 
 @param entities The list of entities for which the integrator needs to provide the data. For example, with [ "TASK_DATE" ] passed as the parameter, the SDK expects the user to provide a date/time input.
 
 @param prompt A prompt message to be played before the microphone turns to VA Active. The message is optional; this parameter can be set to empty or null if not required.
 
 @param allow Allows starting new intent when a prompt is already in progress.
 
 @return VAResultCode
 */

- (VAResultCode) promptForEntities:(nonnull NSArray *)entities withPrompt:(nullable NSString *)prompt allowNewIntent:(BOOL)allow;


/**
 @brief Submits user feedback to the DMVA server.
 
 Submits user feedback to the DMVA server. This API isn't intended for PHI; it's expected that data received via this API doesn't include PHI. A call to this method returns immediately and the feedback sends asynchronously. Once the feedback is submitted, the completion handler passed to the completionHandler parameter is called.
 
 The return value is one of the following:
 
 VAResultCodeSuccess - DMVA accepted the request. DMVA will continue to process the request asynchronously.
 
 VAResultCodeNoSessionError - The request can't be processed because session isn't initialised.
 
 VAResultCodeBadRequestError - The parameters aren't properly provided. 
 
 @param rating The user can rate their experience on a scale of 1 (bad) - 5 (excellent).
 
 @param feedbackText The user can provide a custom message based on their experience, up to 300 characters.
 
 @param nluId The Nlu Id received as part of the nlu result in the VAComplete event
 
 @param completionHandler The block to be invoked once the user feedback is submitted. This parameter can be null if the integrator doesn't require a response to their submitted feedback request. No other delegate method will be invoked.
 
 @return VAResultCode
 */

- (VAResultCode) userFeedback: (nonnull NSNumber*) rating
                 feedbackText: (nullable NSString*) feedbackText
                        nluId: (nullable NSString*) nluId
        withCompletionHandler: (void (^ _Nullable)(NSError * _Nullable error))completionHandler;


/**
 @brief Submits partner application generated feedback to the DMVA server based.
 
 Submits partner feedback to the DMVA server. A call to this method returns immediately and the feedback sends asynchronously. Once the feedback is submitted, the completion handler passed to the completionHandler parameter is called.
 
 The return value is one of the following:
 
 VAResultCodeSuccess - DMVA accepted the request. DMVA will continue to process the request asynchronously.
 
 VAResultCodeNoSessionError - The request can't be processed because the session isn't initialised.
 
 VAResultCodeBadRequestError - The parameters aren't properly provided.
 
 @param feedbackType One of the types from the VAFeedbackType enum.
 
 @param intentName The intent received from the DMVA server.
 
 @param nluId The Nlu Id received as part of the nlu result in the VAComplete event.
 
 @param feedbackInfo The feedback message generated by the partner application.
 
 @param completionHandler The block to be invoked once the parter feedback is submitted. This parameter can be null if the integrator doesn't require a response to their submitted feedback request. No other delegate method will be invoked.
 
 @return VAResultCode
 */

- (VAResultCode) partnerFeedback: (VAFeedbackType) feedbackType
                      intentName: (nonnull NSString*) intentName
                           nluId: (nonnull NSString*) nluId
                    feedbackInfo: (nullable NSString*) feedbackInfo
           withCompletionHandler:(void (^ _Nullable)(NSError * _Nullable error))completionHandler;

@end

NS_ASSUME_NONNULL_END
