//
//  UIView+NUSAConceptName.h
//  Dragon Medical SpeechKit
//
//  Copyright 2011 Nuance Communications, Inc. All rights reserved.
//
//  SDK version: 6.1.17.1
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
/** @brief Voice user interface (VUI) extension to the UIView interface.
 
	@xmlonly<nmFramework>DragonMedicalSpeechKit</nmFramework>@endxmlonly
	@since 1.0
 
*/
@interface UIView (NUSAConceptName)

//////////////////////////////////////////////////////////////////////////////////////////
/// @name Associating a concept with a view
//////////////////////////////////////////////////////////////////////////////////////////

/** @brief Associates the UIView instance with a VUI concept
 
	@since 1.0

	@param vuiConceptName VUI concept identifier
 */
- (void) setVuiConceptName: (NSString*) vuiConceptName; 

/** @brief Gets the VUI concept associated with the UIView instance.
 
	@since 1.0
 
	@return	Returns the VUI concept identifier if one was previously set.  
 */
- (NSString*) vuiConceptName; 

@end
