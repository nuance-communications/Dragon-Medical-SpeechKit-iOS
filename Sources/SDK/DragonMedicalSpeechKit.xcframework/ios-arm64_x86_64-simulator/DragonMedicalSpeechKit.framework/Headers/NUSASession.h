//
//  NUSASession.h
//  Dragon Medical SpeechKit
//
//  Copyright 2011 Nuance Communications, Inc. All rights reserved.
//
//  SDK version: 6.1.17.1
//

#import <Foundation/Foundation.h>
#import <DragonMedicalSpeechKit/NUSATypes.h>
#import <DragonMedicalSpeechKit/NUSASessionDelegate.h>
@class NUSAVuiController; 

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
/** @brief Representation of a mobile speech session.
 
	@xmlonly<nmFramework>DragonMedicalSpeechKit</nmFramework>@endxmlonly
	@since 1.0
 
	This interface manages the authentication and licensing with the web service provider 
	via the information passed in the openForApplication:partnerGuid:licenseGuid:userId:() 
	message and audio sessions via startRecording:() and stopRecording(). Once a session 
	is opened, it will stay open (usable) until explicitly closed via close(); this frees 
	the web service resources and releases the license, if applicable. The session instance 
	communicates asynchronous messages to its delegate, if set. The delegate methods are 
	not mandatory. 
 
	There is exactly one session instance available to an application; it is retrievable 
	via the sharedSession() class method. Usually the application will open the session as 
	soon as user credentials are available and keep it open for the lifetime of the 
	application. 
*/
@interface NUSASession : NSObject {
	@protected	
    __weak id<NUSASessionDelegate> delegate; 
}

//////////////////////////////////////////////////////////////////////////////////////////
/// @name Properties
//////////////////////////////////////////////////////////////////////////////////////////

/** @brief NUSASession delegate.
	@since 1.0

	This delegate receives messages from the session instance. Delegates must 
	conform to the NUSASessionDelegate protocol. The delegate will not be 
	retained. 
 */
@property (nonatomic, weak) id<NUSASessionDelegate> delegate;

/**	@brief Dragon Medical Server URL
	@since 1.1
	
	The Dragon Medical Server URL that the SpeechKit will contact and use for
	speech recognition functionality. 
 */
@property (nonatomic, copy) NSString* serverURL; 

/**	@brief Dragon Medical SpeechKit application help URL
 @since 1.3
 
URL where the application help is hosted. If this value is set prior to calling openForApplication, the "What You Can Say" page will contain the application's online help. 
 */
@property (nonatomic, copy) NSString* onlineHelpURL; 

/** @brief Returns the shared client session instance.
	@since 1.0

	Returns the shared Dragon Medical SpeechKit client session instance. The shared session instance
	is guaranteed to be valid throughout the life time of your application. 
 
	@return The shared Dragon Medical SpeechKit client session instance.
*/
+ (NUSASession*) sharedSession;

//////////////////////////////////////////////////////////////////////////////////////////
/// @name Authenticating with the service
//////////////////////////////////////////////////////////////////////////////////////////


/** @brief Authenticates a user with the Dragon Medical Server using authentication token.
	@since 6.0

	This message creates a connection to the Dragon Medical Server and authenticates
	the application, user and account information as passed. Sessions are usually opened as 
	soon as user credentials are available in your application. Licensing errors will 
	be displayed to the end user of your application.
 
	Note that the Dragon Medical Server will automatically free user licenses if there are
	longer periods of inactivity. In these cases you do not need to explicitly reopen or close the 
	session; the license will be reaquired automatically with the next user activity, e.g. starting 
	a recording session.
  
	If the licenseGuid or partnerGuid parameter were not specified (e.g. a @c nil object was passed), 
	Dragon Medical SpeechKit will not try to verify the license with the web service and will not offer 
	speech recognition related functionality to the end user or your application - it has the same effect 
	as not calling the method at all. E.g. calling startRecording:() will not have any effect. 
 
    Implement sessionDidReceiveInvalidAuthenticationToken delegate to know whether the token has expired. If expired, then get new token using authentication library and call the updateAuthenticationToken method

	@param userId			Mandatory user ID of the author. The user ID must be a non-empty string. 
	@param licenseGuid		Organization token (due to a terminology change the organization token should be passed to the licenseGuid parameter). Invalid organization tokens will be rejected during runtime and 
							cause an alert message to appear to the end user.  
    @param partnerGuid		Partner GUID. Invalid partner guids will be rejected during runtime and 
							cause an alert message to appear to the end user. 
	@param applicationName	Mandatory application name. The application name identifies your application on the 
							web service and can be chosen by your integration. The application name is not 
							part of the licensing information; it can be any string up to 50 characters in length. 
    @param authenticationToken     Pass  token acquired from the authentication library.
 */

- (void) openForApplication: (NSString*) applicationName partnerGuid: (NSString*) partnerGuid licenseGuid: (NSString*) licenseGuid userId: (NSString*) userId authenticationToken: (NSString * _Nonnull) authenticationToken tokenExpiryTime:(NSDate * _Nonnull )expiryTime;

/** @brief Authenticates a user with the Dragon Medical Server.
    @since 1.0

    This message creates a connection to the Dragon Medical Server and authenticates
    the application, user and account information as passed. Sessions are usually opened as
    soon as user credentials are available in your application. Licensing errors will
    be displayed to the end user of your application.
 
    Note that the Dragon Medical Server will automatically free user licenses if there are
    longer periods of inactivity. In these cases you do not need to explicitly reopen or close the
    session; the license will be reaquired automatically with the next user activity, e.g. starting
    a recording session.
  
    If the licenseGuid or partnerGuid parameter were not specified (e.g. a @c nil object was passed),
    Dragon Medical SpeechKit will not try to verify the license with the web service and will not offer
    speech recognition related functionality to the end user or your application - it has the same effect
    as not calling the method at all. E.g. calling startRecording:() will not have any effect.

    @param userId            Mandatory user ID of the author. The user ID must be a non-empty string.
    @param licenseGuid        Organization token (due to a terminology change the organization token should be passed to the licenseGuid parameter). Invalid organization tokens will be rejected during runtime and
                            cause an alert message to appear to the end user.
    @param partnerGuid        Partner GUID. Invalid partner guids will be rejected during runtime and
                            cause an alert message to appear to the end user.
    @param applicationName    Mandatory application name. The application name identifies your application on the
                            web service and can be chosen by your integration. The application name is not
                            part of the licensing information; it can be any string up to 50 characters in length.
 */

- (void) openForApplication: (NSString*) applicationName partnerGuid: (NSString*) partnerGuid licenseGuid: (NSString*) licenseGuid userId: (NSString*) userId;

/** @brief Frees web service resources and licenses on the Dragon Medical Server.
	@since 1.0

	This message disconnects and frees any speech recognition resources and user licenses on the 
	Dragon Medical Server. Usually the session should be closed when the application is
	shut down, or becomes inactive. 
 
	Note that the Dragon Medical Server will automatically free user licenses transparently
	to your application in case of longer periods of inactivity. In these cases you do not need to 
	explicitly reopen or close the session; the license will be reaquired automatically by the 
	next user activity, e.g. starting a recording session. 
 */
- (void) close;

//////////////////////////////////////////////////////////////////////////////////////////
/// @name Using speech recognition
//////////////////////////////////////////////////////////////////////////////////////////

/** @brief Starts recording audio data and audio processing on the Dragon Medical Server.
	@since 1.0

	This message starts recording audio data via the active audio route and starts 
	recognizing recorded and streamed audio data on the Dragon Medical Server.
	Once started, recording will continue until stopRecording() is called explicitly. Note that 
	recording will also be stopped implicitly after a period of inactivity. The session will send the 
	sessionDidStartRecording() message to its delegate. 
 
	While audio data recording is active, audio data will be sent to the web service to be 
	recognized. Recognized text is then added to the currently active GUI control.
 
	If audio data is already recorded, this method does not do anything. If the session has not 
	been previously opened, the method does not do anything. 
 
	@param	error	If recording could not be started, error information is passed via this
					parameter, otherwise @c nil.
	@return			Returns @c NO if recording could not be started. More information about the 
					failure is passed in the error parameter. 
 */
- (BOOL) startRecording: (NSError**) error;

/** @brief Stops recording audio data.
	@since 1.0

	This message stops recording audio data and requests any pending recognition results from the Dragon
	Medical Server. If recording is not running, this method does not do anything. If the
	session has not been previously opened, the method does not do anything. The session will send the 
	sessionDidStopRecording message to its delegate. 
 */
- (void) stopRecording;

/** @brief Aborts recording audio data.
	@since 1.3
 
	The message aborts recording audio data and discards any pending recognition results from the Dragon
	Medical Server. If recording is not running, this method does not do anything. If the
	session has not been previously opened, the method does not do anything. The session will send the 
	sessionDidStopRecording message to its delegate. 
 */
- (void) abortRecording;

//////////////////////////////////////////////////////////////////////////////////////////
/// @name Using TTS
//////////////////////////////////////////////////////////////////////////////////////////

/** @brief Starts speaking. 
    @since 1.3
 
    This message starts speaking the provided text. 
    Once started, speaking will continue until the text has been read in full or stopSpeaking is called.
	The session will send the sessionDidStartSpeaking message to its delegate.
 
	If speaking is already active, new request are queued.
    If the session has not been previously opened, the method does not do anything. If the provided text is nil or empty,
	the method does not do anything.
 
	@param	text	The string to be spoken.
 */
- (void) startSpeaking: (NSString*) text;

/** @brief Stops speaking.
    @since 1.3
 
    Stops speaking. All pending speaking request are cancelled.
    If speaking is not running, this method does not do anything. If the
	session has not been previously opened, the method does not do anything. The session will send the 
	sessionDidStopSpeaking message to its delegate. 
 */
- (void) stopSpeaking;


//////////////////////////////////////////////////////////////////////////////////////////
/// @name Personalization and help screen
//////////////////////////////////////////////////////////////////////////////////////////

/** @brief Displays the specified content in a separate window.
    @since 3.0
 
    The window is only displayed if an open VuiController exists. If there is no open VuiController or the session was not opened previously,
    the method does not do anything.
 
    @param contentType    Type of the content to be displayed.
 */
- (void) showFormWithContent: (NUSAContentType) contentType;


/** @brief Enable / Disable Standby Mode in SDK.
    @since 3.10
 
    Use this method to Enable / Disable Standby Mode in SDK.
    Standby Mode will be reset to YES for Session openForApplication API Call.
    @param enabled BOOL to enable/Disable Standby should be passed.
*/
- (void) setStandbyMode: (BOOL) enabled;

//////////////////////////////////////////////////////////////////////////////////////////
/// @name Update the authentication token
//////////////////////////////////////////////////////////////////////////////////////////

/** @brief Update authentication token
    @since 6.0
 
    Use this method to update the authentication token used by application session
 
    @param token A new authentication token
    @param expiryTime Token expiry time
 */
- (void) updateAuthenticationToken:(NSString * _Nonnull )token tokenExpiryTime:(NSDate * _Nonnull )expiryTime;

@end
