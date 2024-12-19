//
//  NUSAVirtualAssistantTypes.h
//  MobileSpeechSDK
//
//  Created by Yan Tran on 11/20/18.
//  Copyright © 2018 Nuance Communications, Inc. All rights reserved.
//

#ifndef NUSAVirtualAssistantTypes_h
#define NUSAVirtualAssistantTypes_h

/** @brief Virtual Assistant error codes*/
typedef enum NUSAVirtualAssistantErrorCode {
    /** @brief The request has been processed successfully.*/
    NUSAVirtualAssistantErrorCodeNoError = 0,
    /** @brief Failed to configure the DMVA.*/
    NUSAVirtualAssistantErrorCodeConfigurationError,
    /** @brief General network error.*/
    NUSAVirtualAssistantErrorCodeNetworkError,
    /** @brief There was a problem communicating with the DMVA server.  The DMVA server is unresponsive or it is sending badly formed data.*/
    NUSAVirtualAssistantErrorCodeServerError,
    /** @brief The application state is not valid for this operation.*/
    NUSAVirtualAssistantErrorCodeApplicationStateError,
    /** @brief The supplied parameters are not valid.*/
    NUSAVirtualAssistantErrorCodeParameterError,
    /** @brief An unknown error has occurred.*/
    NUSAVirtualAssistantErrorCodeUnknownError,
    /** @brief VA not allowed in web view integrations. */
    NUSAVirtualAssistantNotAllowedWithWebViewIntegration
} NUSAVirtualAssistantErrorCode;

/** @brief Virtual Assistant states*/
typedef enum NUSAVirtualAssistantState {
    /** @brief The DMVA has initialized and is ready to process virtual assistant requests.*/
    NUSAVirtualAssistantStateOpened = 0,
    /** @brief The DMVA is not initialized.  All virtual assistant requests will be rejected in this state.*/
    NUSAVirtualAssistantStateClosed
} NUSAVirtualAssistantState;


#endif /* NUSAVirtualAssistantTypes_h */



