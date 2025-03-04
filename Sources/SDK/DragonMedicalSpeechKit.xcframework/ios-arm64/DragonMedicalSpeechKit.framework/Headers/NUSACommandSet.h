//
//  NUSACommandSet.h
//  Dragon Medical SpeechKit
//
//  Copyright (c) 2012 Nuance Communications, Inc. All rights reserved.
//
//  SDK version: 6.2.2.1
//

#import <Foundation/Foundation.h>

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
/** @brief Representation of an application-defined command set. 
 
    @xmlonly<nmFramework>DragonMedicalSpeechKit</nmFramework>@endxmlonly
    @since 1.3
 
    A command set is a group of application commands that logically belong together. It is characterized by a human-readable name and a description that will appear in the "What You Can Say" page.
    
	Command sets contain a set of application commands. Each command must have a unique ID that identifies the recognized command in the vuiControllerDidRecognizeCommand() delegate message. 
	Commands should have a human-readable description and a spoken form. CommandPlaceholders can be used in spoken forms.
 
    A command set can be enabled (default) or disabled, in which case all the commands it contains are disabled.
*/
NS_ASSUME_NONNULL_BEGIN
@interface NUSACommandSet : NSObject {
    @protected
    BOOL        isEnabled;
}

/** @brief Initializes a command set.
    @since 1.3
 
    Use this method to create a set of application commands.
 
    @warning Raises an NSInvalidArgumentException if the command set name is nil or empty.
 
    @param name The human-readable name of the command set.
    @param description The description of the command set.
 
 */
- (id)initWithName: (NSString *)name description: (NSString *)description;

/** @brief Adds a new application command to the command set.
    @since 1.3
 
    The application must provide a unique id, a description and the command phrase. To create alternative phrases for
    a command call this method multiple times for the same id.
 
    @warning Raises an NSInvalidArgumentException if the command id or phrase is nil or empty.
 
    @param id The unique identifier of the command. Make sure the application command ID does not contain spaces and does not start with a number.
    @param phrase The application command phrase.
    @param displayString The application command display string (optional).
    @param description The human-readable description of the command.
 Can contain Placeholder identifiers: in this case, the corresponding placeholder objects must be created and supplied to the VuiController in a assignCommandPlaceholders() method call.
 
 Placeholder identifiers must be enclosed in < and > in the spoken form. For example, if the ID of the referenced placeholder is "patient", a correct spoken form can be "select patient <patient>"
 
 Alternative spoken forms are created by calling this method multiple times for the same ID. */
- (void)createCommand: (NSString *)id phrase: (NSString*) phrase displayString: (NSString * _Nullable)displayString description: (NSString *)description;

/** @brief Enables or disables the command with the corresponding ID.
    @since 1.3

    When enabled is set to YES, the command is enabled, else disabled. The default enabled state of a command is YES.
	
    @param id The unique identifier of the command.
    @param enabled Whether the command set is enabled or disabled.
 */
- (void)setCommand: (NSString *)id enabled: (BOOL) enabled;

/** @brief A Boolean value that determines whether a command set is enabled.
    @since 1.3
 
    When set to YES, the command set is enabled, else disabled. The default value of this property is YES.
 */
@property (nonatomic, assign) BOOL isEnabled;

@end
NS_ASSUME_NONNULL_END
