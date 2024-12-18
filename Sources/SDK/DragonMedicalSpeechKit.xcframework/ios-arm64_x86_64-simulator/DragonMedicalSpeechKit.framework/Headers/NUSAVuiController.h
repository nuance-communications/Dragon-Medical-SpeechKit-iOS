//
//  NUSAVuiController.h
//  Dragon Medical SpeechKit
//
//  Copyright 2011 Nuance Communications, Inc. All rights reserved.
//
//  SDK version: 6.1.17.1
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import <DragonMedicalSpeechKit/NUSAVuiControllerDelegate.h>
#import <DragonMedicalSpeechKit/NUSATypes.h>

//////////////////////////////////////////////////////////////////////////////////////////
/// @name Vui topics 
/// @relates NUSAVuiController
///
/// @brief Constants for the topic property of NUSAVuiController instances. 
///
/// @{
/// 
//////////////////////////////////////////////////////////////////////////////////////////

/** @brief VUI topic for a General Medicine-specific vocabulary 
 *
 *	This is the default topic used for VUI forms if no topic is specified by your integration.
 */
extern NSString* const kNUSAVuiTopicGeneralMedicine;
/** @brief VUI topic for an Internal Medicine-specific vocabulary */
extern NSString* const kNUSAVuiTopicInternalMedicine;
/** @brief VUI topic for a Surgery-specific vocabulary */
extern NSString* const kNUSAVuiTopicSurgery;
/** @brief VUI topic for a Mental Health-specific vocabulary */
extern NSString* const kNUSAVuiTopicMentalHealth; 
/** @brief VUI topic for a Neurology-specific vocabulary */
extern NSString* const kNUSAVuiTopicNeurology; 
/** @brief VUI topic for a Cardiology-specific vocabulary */
extern NSString* const kNUSAVuiTopicCardiology;
/** @brief VUI topic for a Clinical Administration-specific vocabulary */
extern NSString* const kNUSAVuiTopicClinicalAdministration;
/** @brief VUI topic for a Emergency-specific vocabulary */
extern NSString* const kNUSAVuiTopicEmergency;
/** @brief VUI topic for a Orthopaedics-specific vocabulary */
extern NSString* const kNUSAVuiTopicOrthopaedics;
/** @brief VUI topic for a Obstetrics and Gynecology-specific vocabulary */
extern NSString* const kNUSAVuiTopicObstetricsAndGynecology;
/** @brief VUI topic for a Oncology-specific vocabulary */
extern NSString* const kNUSAVuiTopicOncology;
/** @brief VUI topic for a Pathology-specific vocabulary */
extern NSString* const kNUSAVuiTopicPathology;
/** @brief VUI topic for a Pediatrics-specific vocabulary */
extern NSString* const kNUSAVuiTopicPediatrics;

/// @}

//////////////////////////////////////////////////////////////////////////////////////////
/// @name Document states
/// @relates NUSAVuiController
///
/// @brief 	Constants for the document states which can be passed in VuiController close call.

///
/// @{
///
//////////////////////////////////////////////////////////////////////////////////////////

/** @brief Default value
 *
 *	If in doubt, use this state; use another state only if your document workflow enforces one of the other states.
 */
extern const NSInteger kNUSADocumentStateUndefined;
/** @brief Use this state if you can guarantee with very high probability that your users have corrected any possible misrecognitions in the text. */
extern const NSInteger kNUSADocumentStateCorrected;
/** @brief Use this state if you can guarantee with very high probability that your users have not corrected misrecognitions in the text. */
extern const NSInteger kNUSADocumentStateUncorrected;

/// @}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
/** @brief Controller managing the voice user interface (VUI) attached to a graphical user interface (GUI)
 
	@xmlonly<nmFramework>DragonMedicalSpeechKit</nmFramework>@endxmlonly
	@since 1.0
 
	This controller manages the VUI aspects of a GUI view and speech-enables controls that 
	are supported by the web service for speech recognition. The VUI controller will initialize 
	with the contents of the GUI view as soon as it is created. The application is responsible 
	for keeping the VUI in sync with changes to the GUI view hierarchy later on (see synchronizeWithView()). 
 
	The NUSAVuiController class is prepared for creation via NIB deserialisation. Alternatively, 
	it can be created programmatically via initWithView:(). 

	Usually each GUI view, that is to be speech enabled, should have a corresponding VUI 
	via attaching its own NUSAVuiController instance to it. The application is responsible 
	for attaching the VUI controller. The lifetime of a VUI controller instance is 
	best bound to the lifetime of the GUI view controller. 
	
*/
@interface NUSAVuiController : NSObject {
	@protected
	UIView*		view;
}

//////////////////////////////////////////////////////////////////////////////////////////
/// @name Properties
//////////////////////////////////////////////////////////////////////////////////////////

/** @brief GUI view this controller is bound to
	@since 1.0
 
	Every VUI controller is connected to a single GUI view (which in turn is 
	bound to a GUI view controller in your application). The VUI controller will inspect 
	the GUI view and create a corresponding VUI form.
    Setting this property is reserved for internal use, it must not be changed except by calling initWithView:().
*/
@property (nonatomic, retain) IBOutlet UIView* view;

/** @brief The language to be used by the VUI form.
	@since 1.0
 
	Applications can set the language that should be used by the VUI form. The language can 
	only be set prior to the first recording session. The default is the application language or the language set for the session.
 
	The language must be passed in the IETF format (see http://en.wikipedia.org/wiki/ISO_3166-1_alpha-2). 
	Currently the SDK expects the IETF language and region subtags to be passed. The language 
	subtag must conform to ISO 639-1 (http://www.loc.gov/standards/iso639-2/php/English_list.php) 
	and is mandatory if set. The region subtag must conform to ISO 3166-1 alpha-2 
	(http://en.wikipedia.org/wiki/ISO_3166-1_alpha-2) and is optional. 
 
	Examples: 
	en-US	English (USA)
	en-GB	English (UK)
	de-DE	German (Germany)
	de-AT	German (Austria)
 */
@property (nonatomic, copy) NSString* language;

/** @brief The topic (medical specialty) of the speech recognition vocabulary used by the VUI form
	@since 1.0
 
	Applications can set the topic (specialty) of the speech recognition vocabulary for the 
	VUI form. Setting the topic is optional. 
 */
@property (nonatomic, copy) NSString* topic; 

/** @brief NUSAVuiController delegate.
	@since 1.0
 
	This delegate receives messages from the VUI controller instance. Delegates must 
	conform to the NUSAVuiControllerDelegate protocol. The delegate will not be 
	retained and will send its messages to the thread that set the delegate property. 
*/
@property (nonatomic, weak) id<NUSAVuiControllerDelegate> delegate; 

/** @brief Deprecated The location of the volume meter.
    
 @since 1.6
 @deprecated As of release @since 5.?
 
 Applications can set the location of the volume meter.
 The default value is NUSAVolumeMeterLocationNone when using the speech bar and NUSAVolumeMeterLocationBottom when using the speech control.
 */
@property (nonatomic, assign) NUSAVolumeMeterLocation volumeMeterLocation __attribute__((deprecated));

/** @brief Deprecated The color of the volume meter for good sound quality.
    
 @since 1.6
 @deprecated As of release @since 5.?
 
 Applications can set the color of the volume meter for good sound quality.
 If this value is nil, a default blue color is used.
 The default value is nil.
 */
@property (nonatomic, copy) UIColor* volumeMeterColor __attribute__((deprecated));

/** @brief Deprecated The color of the volume meter for good sound quality.
    
 @since 1.6
 @deprecated As of release @since 5.?
 
 Applications can set the color of the volume meter for bad sound quality.
 If this value is nil, a default red color is used.
 The default value is nil.
*/
@property (nonatomic, copy) UIColor* volumeMeterBadQualityColor __attribute__((deprecated));

/** @brief A Boolean value that determines whether the system keyboard should be shown by default.
 @since 1.6
 
 Setting the value of this property to YES shows the keyboard by default and setting it to NO hides the keyboard. The default value is NO.
 When using the default speech bar, the keyboard is initially hidden when the speech bar is shown for the first time. This property can be used to change this behavior.
 This property should be set before a control becomes first responder, after the speech bar is shown, setting this property has no effect.
 Setting this property has no effect if the speech control is used.
*/
@property (nonatomic, getter=isKeyboardVisibleByDefault) BOOL keyboardVisibleByDefault;

//////////////////////////////////////////////////////////////////////////////////////////
/// @name Initializing the instance
//////////////////////////////////////////////////////////////////////////////////////////

/** @brief Initializes and opens the VUI controller.
	@since 1.0
 
	This message initializes and opens the VUI controller and binds it to the GUI view passed. 
	The VUI controller is associated with an unnamed document. 
    You can use this initializer if you create the VUI controller manually. You do not need to initialize
	the VUI controller manually via this method if the VUI controller is created as part of your 
	NIB deserialisation.
	Using this initializer is equivalent to using initWithView:andOpen: with parameter open set to YES.

	@param aView GUI view that will be speech enabled by this VUI controller object
*/
- (id) initWithView: (UIView*)aView;

/** @brief Initializes the VUI controller and optionally opens it.
	@since 2.1
 
	This message initializes the VUI controller and binds it to the GUI view passed. 
	If the open flag is set to YES the VUI controller is opened and associated with an unnamed document. 
 
	@param aView GUI view that will be speech enabled by this VUI controller object
	@param open Flag indicating if a VUI controller should be initialized as open
 */
- (id) initWithView: (UIView*)aView andOpen: (BOOL)open;


/** @brief Initializes and opens the VUI controller and disables all speech controls.
	@since 3.5
	
	This message initializes and opens the VUI controller, binds it to the GUI view passed
	and excludes all text controls from speech recognition. The speech bar is displayed;
	the user can say voice commands and open the personalization and help screen.
	This initializer is for use cases where the user is not dictating text but still requires the speech bar,
	for example, virtual assistant use cases.
	The VUI controller is associated with an unnamed document.
	You can use this initializer if you create the VUI controller manually. You do not need to initialize
	the VUI controller manually via this method if the VUI controller is created as part of your
	NIB deserialisation.
	Using this initializer is equivalent to using initWithView:andOpen: with parameter open set to YES.
	
	@param aView GUI view that will be speech enabled by this VUI controller object
	@param disableSpeechViews Bool Specifies if all text controls will be excluded from speech recognition
 */
- (id) initWithView: (UIView*)aView andDisableSpeechViews: (BOOL)disableSpeechViews;


//////////////////////////////////////////////////////////////////////////////////////////
/// @name Updating the voice user interface (VUI)
//////////////////////////////////////////////////////////////////////////////////////////
	
/** @brief Synchronizes the VUI form with the GUI view.
	@since 1.0
 
	This method synchronizes the VUI form, controlled by this VUI controller, with the GUI
	of the view object referenced. You must call this method to trigger synchronization
	when the GUI layout of the GUI view contents are changed by your application (e.g. 
	you add or remove controls, change concept names or document ids). 
    This method must also be called to commit command set and command placeholder assignment changes.

	Synchronizing should be done once you have updated all of your GUI view contents, so the 
	VUI form can be updated in one step. Additionally, do not synchronize GUI views that are 
	currently not visible to the user, unless you want to pre-cache a GUI view that will be 
	shown in the immediate future.
*/
- (void) synchronizeWithView; 

//////////////////////////////////////////////////////////////////////////////////////////
/// @name Assigning command sets
//////////////////////////////////////////////////////////////////////////////////////////

/** @brief Sets the application-defined command set placeholders available for application commands.
 @since 1.3
 
    The command sets supplied for the call overwrite any command sets assigned previously.
	The command set assignment will not be effective until synchronizeWithView() is called. 
 
    @param commandSets The array of NUSACommandSet objects that describe the application command sets available for this VUI form.
    
    @see assignCommandPlaceholders
    @see NUSACommandSet
    @see NUSACommandPlaceholder
 */
- (void) assignCommandSets: (NSArray *)commandSets; 

//////////////////////////////////////////////////////////////////////////////////////////
/// @name Assigning command placeholders
//////////////////////////////////////////////////////////////////////////////////////////

/** @brief Sets the application-defined command set placeholders available for application commands.
    @since 1.3
 
    The command placeholders supplied for the call overwrite any command placeholders assigned previously.
    The command placeholder assignment will not be effective until synchronizeWithView() is called. 
 
    @param commandPlaceholders The array of NUSACommandPlaceholder objects that describe the placeholders that can be used in application commands.
    
    @see assignCommandSets
    @see NUSACommandPlaceholder
    @see NUSACommandSet
 */
- (void) assignCommandPlaceholders: (NSArray *)commandPlaceholders; 

//////////////////////////////////////////////////////////////////////////////////////////
/// @name Document workflow
//////////////////////////////////////////////////////////////////////////////////////////

/** @brief Sets document metadata.
 @since 2.1
 
 Associates metadata with the document currently open or to be opened.

 @param value Metadata value.
 @param key Metadata key.
 */
- (void) setDocumentMetadata: (NSString *)value forKey: (NSString *)key;

/** @brief Gets document metadata.
 @since 2.1
 
 Retrieves metadata of the currently open document.

 @param key Metadata key.
 
 @return	Returns metadata value for the given key.
*/
- (NSString*) getDocumentMetadata: (NSString *)key;

/** @brief Open VUI controller.
 @since 2.1
 
 Opens the VUI controller and associates it with an unnamed document.
 */
- (void)open;

/** @brief Open VUI controller.
 @since 2.1
 
 Opens the VUI controller and associates it with the document ID supplied.

 @param documentId Identifier of the document to be associated with this VUi controller. If a VUI form was previously saved with the given documentId, it will be loaded and SR will be based on the previously saved state.
 */
- (void)openWithDocumentId: (NSString*)documentId;

/** @brief Close VUI controller.
 @since 2.1
 
 Closes the VUI controller and saves the associated VUI form with the document ID passed to open. If no document ID was provided, an unnamed VUI form is saved.
 */
- (void)close;

/** @brief Close VUI controller.
 @since 2.1
 
 Closes the VUI controller and saves the associated VUI form under the identifier supplied.
 
 @param documentId Document identifier under which the VUI form associated with this VuiController will be saved.  If this is the empty string, an unnamed VUI form will be saved.
 */
- (void)closeWithDocumentId: (NSString*)documentId;

/** @brief Close VUI controller.
 @since 2.1
 
 Closes the VUI controller and saves the associated VUI form under the identifier supplied.
 
 @param documentId Document identifier under which the VUI form associated with this VuiController will be saved.  If this is the empty string, an unnamed VUI form will be saved.
 @param documentState State of the document in the application workflow.
 */
- (void)closeWithDocumentId: (NSString*)documentId andState: (NSInteger)documentState;

@end
