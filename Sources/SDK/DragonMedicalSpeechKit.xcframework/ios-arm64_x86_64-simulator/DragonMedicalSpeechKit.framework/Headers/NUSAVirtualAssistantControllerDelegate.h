//
//  NUSAVirtualAssistantControllerDelegate.h
//  MobileSpeechSDK
//
//  Created by Yan Tran on 11/20/18.
//  Copyright © 2018 Nuance Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <DragonMedicalSpeechKit/NUSAVirtualAssistantTypes.h>
/** @brief DMVA controller delegate.
 
 This delegate is used for all callbacks to the Dragon Medical Virtual Assistant (DMVA) client. It is registered with the NUSAVirtualAssistantController instance through the openWithModel method.  All the methods in the delegate are optional.*/
NS_ASSUME_NONNULL_BEGIN
@protocol NUSAVirtualAssistantControllerDelegate <NSObject>
@optional
/** @brief Handles dialog results.
 
 Called when DMVA wants to send dialog results to the client.
 
 @param result A string containing JSON formatted as described in the SDK help, "NLU result structure".
 
 @param errorCode The error code<br>
 
 NUSAVirtualAssistantErrorCode Values:<br>
 
 NUSAVirtualAssistantErrorCodeNoError - The request completed successfully.<br>
 
 NUSAVirtualAssistantErrorCodeConfigurationError - Invalid parameters were provided to server.<br>
 
 NUSAVirtualAssistantErrorCodeServerError - The server encountered a problem.<br>
 
 NUSAVirtualAssistantErrorCodeNetworkError - There was a problem with the network or the server was unavailable.<br>
 
 @param message A description of the status for logging and debugging purposes. The information in the message isn't intended to be displayed to the user.
 */
- (void) dialogResult: (NSString*) result errorCode : (NUSAVirtualAssistantErrorCode) errorCode message: (NSString*) message;

/** @brief Receives the DMVA state.
 
 A NUSAVirtualAssistantErrorCodeNoError value will be given when DMVA has encountered an unrecoverable error. When this happens the state will be Closed.
 
@param errorCode The status code<br>
 
 NUSAVirtualAssistantErrorCode Values:<br>
 
 NUSAVirtualAssistantErrorCodeNoError - The request completed successfully.<br>
 
 NUSAVirtualAssistantErrorCodeConfigurationError - Invalid parameters were provided to the server.<br>
 
 NUSAVirtualAssistantErrorCodeServerError - The server encountered a problem. <br>
 
 NUSAVirtualAssistantErrorCodeNetworkError - There was a problem with the network or the server was unavailable.<br>
 
@param message A description of the status for logging and debugging purposes. The information in the message isn't intended to be displayed to the user.
 */
- (void) stateChanged:(NUSAVirtualAssistantState) state errorCode: (NUSAVirtualAssistantErrorCode) errorCode message: (NSString*) message;

/** @brief Receives concept upload results.
 
Called when a concept upload or clear call has been received and processed by DMVA.
@param errorCode The error code

@param message A description of the status for logging and debugging purposes. The information in the message isn't intended to be displayed to the user.*/

- (void) conceptResult:(NUSAVirtualAssistantErrorCode) errorCode message: (NSString*) message;

/** @brief Received when DMVA has started a speech interaction.
 */
-(void) didStartDialog;

/** @brief Received when DMVA has stopped a speech interaction.
 */

-(void) didStopDialog;

@end

NS_ASSUME_NONNULL_END
