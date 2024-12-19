//
//  NUSAVirtualAssistantTypesV2.h
//  DragonMedicalSpeechKit
//
//  Copyright © 2021 Nuance Communications, Inc. All rights reserved.
//

#ifndef NUSAVirtualAssistantTypesV2_h
#define NUSAVirtualAssistantTypesV2_h


/** @brief Virtual Assistant v2 error codes*/
typedef enum VAResultCode {
    /** @brief The request has been processed successfully.*/
    VAResultCodeSuccess = 0,
    /** @brief Failed to configure the DMVA. [ConfigurationError+ParameterError] */
    VAResultCodeBadRequestError,
    /** @brief General network error.*/
    VAResultCodeNetworkError,
    /** @brief There was a problem communicating with the DMVA server. The DMVA server is unresponsive or it is sending badly formed data. [ServerError] */
    VAResultCodeInternalServerError,
    /** @brief The application state is not valid for this operation.*/
    VAResultCodeApplicationStateError,
    /** @brief An unknown error has occurred. [Unknown error+VANotAllowedWithWebViewIntegration error]*/
    VAResultCodeInternalSDKError,
    /** @brief No session error. */
    VAResultCodeNoSessionError,
    /** @brief Attempts auto reconnecting to VA when the server becomes unreachable*/
    VAResultCodeAutoReconnecting
} VAResultCode;



/** @brief Virtual Assistant v2 states*/
typedef enum VAState {
    /** @brief The DMVA has initialized and is ready to process virtual assistant requests.*/
    VAStateOpened = 0,
    /** @brief The DMVA is not initialized. All virtual assistant requests will be rejected in this state.*/
    VAStateClosed
} VAState;



/** @brief Virtual Assistant v2 event types*/
typedef enum VAEventType {
    /** @brief VA Inactive event*/
    VAEventTypeInactive = 0,
    /** @brief VA Active event*/
    VAEventTypeActive,
    /** @brief VA processing event*/
    VAEventTypeProcessing,
    /** @brief VA complete event*/
    VAEventTypeComplete,
    VAEventTypeCanceled,
    VAEventTypeBadRequest,
    VAEventTypeTimeout,
    VAEventTypePartialASR
}VAEventType;



/** @brief Virtual Assistant v2 event*/
@interface VAEvent : NSObject
    /** @brief Virtual Assistant v2 event types*/
    @property (nonatomic, assign) VAEventType eventType;
    /** @brief Virtual Assistant v2 event details string*/
    @property (nonatomic, strong) NSString *details;
@end


/** @brief VA Partner Feedback types*/
typedef enum VAFeedbackType {
    /** @brief On getting desired result*/
    VAFeedbackTypeSupported = 0,
    /** @brief In case of received intent is not supported by the partner application*/
    VAFeedbackTypeUnsupported,
    /** @brief When any error or time out is received in vaComplete event*/
    VAFeedbackTypeProcessingError
}VAFeedbackType;


#endif /* NUSAVirtualAssistantTypesV2_h */
