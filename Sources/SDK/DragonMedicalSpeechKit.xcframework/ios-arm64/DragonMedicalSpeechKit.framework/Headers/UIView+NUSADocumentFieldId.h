//
//  UIView+NUSACDocumentFieldId.h
//  Dragon Medical SpeechKit
//
//  Copyright 2015 Nuance Communications, Inc. All rights reserved.
//
//  SDK version: 6.1.17.1
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
/** @brief Voice user interface (VUI) extension to the UIView interface.
 
	@xmlonly<nmFramework>DragonMedicalSpeechKit</nmFramework>@endxmlonly
	@since 2.1
 
*/
@interface UIView (NUSADocumentFieldId)

//////////////////////////////////////////////////////////////////////////////////////////
/// @name Associating a document field id with a view
//////////////////////////////////////////////////////////////////////////////////////////

/** @brief Associates the UIView instance with a VUI document field id
 
	@since 2.1

	@param vuiDocumentFieldId document field id
 */
- (void) setVuiDocumentFieldId: (NSString*) vuiDocumentFieldId;

/** @brief Gets the VUI document field id associated with the UIView instance.
 
	@since 2.1
 
	@return	Returns the VUI document field id if one was previously set.
 */
- (NSString*) vuiDocumentFieldId; 

@end
