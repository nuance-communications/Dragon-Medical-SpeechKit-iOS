//
//  NUSACustomVuiController.h
//  Dragon Medical SpeechKit
//
//  Copyright 2012 Nuance Communications, Inc. All rights reserved.
//
//  SDK version: 6.1.17.1
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import <DragonMedicalSpeechKit/NUSAVuiControllerDelegate.h>
#import <DragonMedicalSpeechKit/NUSACustomVuiControllerDelegate.h>
#import <DragonMedicalSpeechKit/NUSATypes.h>


//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
/** @brief Controller managing the voice user interface (VUI) attached to a graphical user interface (GUI)
 
	@xmlonly<nmFramework>DragonMedicalSpeechKit</nmFramework>@endxmlonly
	@since 1.3
 
	This controller manages the VUI aspects of a GUI view and speech-enables controls that 
	are not supported by the web service for speech recognition. The VUI controller will initialize 
	from an array of controls that conform to the NUSATextControl protocol. The application is responsible 
	for keeping the VUI in sync with changes to the controls that should be speech-enabled (see synchronize()). 
 
	The NUSACustomVuiController must be created programmatically via initWithView:controls:(). 

	Usually each GUI view, that is to be speech enabled, should have a corresponding VUI 
	via attaching its own NUSAVuiController instance to it. The application is responsible 
	for attaching the VUI controller. The lifetime of a VUI controller instance is 
	best bound to the lifetime of the GUI view controller. 
	
*/
@interface NUSACustomVuiController : NSObject {
	@protected
	UIView*		view;
}

//////////////////////////////////////////////////////////////////////////////////////////
/// @name Properties
//////////////////////////////////////////////////////////////////////////////////////////

/** @brief GUI view this controller is bound to
	@since 1.3
 
	Every VUI controller is connected to a single GUI view (which in turn is 
	bound to a GUI view controller in your application). 
*/
@property (nonatomic, retain, readonly) IBOutlet UIView* view;

/** @brief The language to be used by the VUI form.
	@since 1.3
 
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
	@since 1.3
 
	Applications can set the topic (specialty) of the speech recognition vocabulary for the 
	VUI form. Setting the topic is optional. 
 */
@property (nonatomic, copy) NSString* topic; 

/** @brief NUSAVuiController delegate.
 @since 1.3
 
 This delegate receives messages from the VUI controller instance. Delegates must 
 conform to the NUSAVuiControllerDelegate protocol. The delegate will not be 
 retained and will send its messages to the thread that set the delegate property. 
 */
@property (nonatomic, assign) id<NUSAVuiControllerDelegate> delegate; 


/** @brief NUSACustomVuiController delegate.
 @since 1.3
 
 This delegate receives messages from the VUI controller instance. Delegates must 
 conform to the NUSACustomVuiControllerDelegate protocol. The delegate will not be 
 retained and will send its messages to the thread that set the delegate property. 
 */
@property (nonatomic, assign) id<NUSACustomVuiControllerDelegate> customDelegate;

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

//////////////////////////////////////////////////////////////////////////////////////////
/// @name Initializing the instance
//////////////////////////////////////////////////////////////////////////////////////////

/** @brief Initializes the VUI controller.
	@since 1.3
 
	This message initializes and opens the VUI controller and binds it to the GUI view passed. 
	The VUI controller is associated with an unnamed document. 
    All objects in the specified array are speech-enabled if they conform to the NUSATextControl protocol. Objects that do not conform to the NUSATextControl protocol will not be speech-enabled. 
	Using this initializer is equivalent to using initWithView:controls:andOpen: with parameter open set to YES.

	@param aView GUI view that will be speech-enabled by this VUI controller object.
    @param speechEnabledControls An array of controls that should be speech-enabled.
*/
- (id) initWithView: (UIView*)aView controls: (NSArray*)speechEnabledControls;

/** @brief Initializes the VUI controller and optionally opens it.
	@since 2.1
 
	This message initializes the VUI controller and binds it to the GUI view passed. 
    All objects in the specified array are speech-enabled if they conform to the NUSATextControl protocol. Objects that do not conform to the NUSATextControl protocol will not be speech-enabled. 
	If the open flag is set to YES the VUI controller is opened and associated with an unnamed document. 
 
	@param aView GUI view that will be speech enabled by this VUI controller object
    @param speechEnabledControls An array of controls that should be speech-enabled.
	@param open Flag indicating if a VUI controller should be initialized as open
 */
- (id) initWithView: (UIView*)aView controls: (NSArray*)speechEnabledControls andOpen: (BOOL)open;

//////////////////////////////////////////////////////////////////////////////////////////
/// @name Updating the voice user interface (VUI)
//////////////////////////////////////////////////////////////////////////////////////////
	
/** @brief Synchronizes the VUI form with a set of text controls.
	@since 1.3
 
	This method synchronizes the VUI form, controlled by this VUI controller, with the array of speech-enabled controls. 
    This method must also be called to commit command set and command placeholder assignment changes.

    @param speechEnabledControls An array of controls that should be speech-enabled.
*/
- (void) synchronize: (NSArray*) speechEnabledControls;

//////////////////////////////////////////////////////////////////////////////////////////
/// @name Assigning command sets
//////////////////////////////////////////////////////////////////////////////////////////

/** @brief Sets the application-defined command set placeholders available for application commands.
 @since 1.3
 
    The command sets supplied for the call overwrite any command sets assigned previously.
	The command set assignment will not be effective until synchronize() is called. 
 
    @param commandSets The array of NUSACommandSet objects that describe the application command sets available for this VUI form.
    
    @see assignCommandPlaceholders
    @see NUSACommandSet
    @see NUSACommandPlaceholder
 */
- (void) assignCommandSets: (NSArray *)commandSets; 

//////////////////////////////////////////////////////////////////////////////////////////
/// @name Assigning command placeholders
//////////////////////////////////////////////////////////////////////////////////////////

/** @brief Sets the application-defined command set placeholders available for 		 application commands.
    @since 1.3
 
    The command placeholders supplied for the call overwrite any command placeholders assigned previously.
    The command placeholder assignment will not be effective until synchronize() is called. 
 
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

/** @brief A Boolean value that determines whether the system keyboard should be shown by default.
 @since 3.2
 
 Setting the value of this property to YES shows the keyboard by default and setting it to NO hides the keyboard. The default value is NO.
 When using the default speech bar, the keyboard is initially hidden when the speech bar is shown for the first time. This property can be used to change this behavior.
 This property should be set before a control becomes first responder, after the speech bar is shown, setting this property has no effect.
 Setting this property has no effect if the speech control is used.
 */
@property (nonatomic, getter=isKeyboardVisibleByDefault) BOOL keyboardVisibleByDefault;

@end
