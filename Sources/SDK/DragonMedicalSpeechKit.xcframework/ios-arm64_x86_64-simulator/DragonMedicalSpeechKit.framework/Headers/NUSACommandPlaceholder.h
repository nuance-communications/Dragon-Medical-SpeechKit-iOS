//
//  NUSACommandPlaceholder.h
//  Dragon Medical SpeechKit
//
//  Copyright (c) 2012 Nuance Communications, Inc. All rights reserved.
//
//  SDK version: 6.1.17.1 
//

#import <Foundation/Foundation.h>

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
/** @brief Representation of a placeholder in an application command of an application-defined command set. 
 
 @xmlonly<nmFramework>DragonMedicalSpeechKit</nmFramework>@endxmlonly
 @since 1.3
 
 */
@interface NUSACommandPlaceholder : NSObject

/** @brief Initializes a placeholder object.
 @since 1.3
 
 Use this method to create a command placeholder.
 
 @param id The unique identifier of the placeholder. This will be returned in the vuiControllerDidRecognizeCommand() delegate message for identification of the placeholder.
 @param label The user-readable label for the placeholder.
  */
- (id)initWithID: (NSString *)id label: (NSString*)label;

/** @brief Adds a new set of values to the placeholder.
 @since 1.3
 @param values The values that the system will return when it recognizes the associated spoken form. Must have exactly as many members as spokenForms.
 @param spokenForms The spoken forms that the system attempts to recognize. Must have exactly as many members as values. Multiple spoken forms can be defined for a single value by separting them with '|'.
 */
- (void)setValues: (NSArray *)values withSpokenForms: (NSArray*)spokenForms;

/** @brief Clears all values and associated spoken forms.
 @since 1.3
 */
- (void)clearValues;

@end
