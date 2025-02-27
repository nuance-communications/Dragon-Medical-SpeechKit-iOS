//
//  NUSAVirtualAssistantControllerV2Delegate.h
//  DragonMedicalSpeechKit
//
//  Copyright © 2021 Nuance Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <DragonMedicalSpeechKit/NUSAVirtualAssistantTypesV2.h>
/** @brief DMVA controller delegate.
 
 This delegate is used for all callbacks to the Dragon Medical Virtual Assistant (DMVA) client. It is registered with the NUSAVirtualAssistantControllerV2 instance. All the methods in the delegate are optional.*/

@protocol NUSAVirtualAssistantControllerV2Delegate <NSObject>
@optional

/** @brief Handles DMVA events.
 
 Notifies the integrator of different events received from DMVA after a request has been processed. For example, the user says "Hey Dragon, show me CBC". On recognizing the wake word, the SDK sends the begin speech audio to its response and gets the vaActive event from DMVA, which it passes to the integrator. When the DMVA command is processed on the DMVA server, vaComplete along with a JSON response is received from DMVA, which is passed to the integrator using this delegate method.
 
 @param event An object describing the event, including the event type and a result message.

 */

- (void)vaEventGenerated:(VAEvent * _Nonnull)event;


/** @brief Receives the DMVA state.
 
 Whenever the VA Controller state changes, this method is called to notify the integrator of the state change. This method is called on the delegate provided by the integrator, using the set delegate call.
 
@param state The state of the VA Controller: initialized or closed.
 
@param resultCode The result code received when opening or closing the VA Controller<br>
 
 VAResultCode Values:<br>
 
 VAResultCodeSuccess - The request completed successfully.<br>
 
 VAResultCodeBadRequestError - Invalid parameters were provided to server<br>
 
 VAResultCodeInternalServerError - The server encountered a problem. <br>
 
 VAResultCodeNetworkError - There was a problem with the network or the server is unavailable.<br>
 
@param message Additional information on the result code and state.
 */

- (void)vaSessionStateChanged:(VAState)state
             resultCode:(VAResultCode)resultCode
               message:(nullable NSString *)message;

@end
