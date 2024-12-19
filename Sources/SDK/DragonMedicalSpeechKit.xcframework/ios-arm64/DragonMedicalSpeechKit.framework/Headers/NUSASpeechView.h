//
//  NUSASpeechView.h
//  Dragon Medical SpeechKit
//
//  Copyright (c) 2012 Nuance Communications, Inc. All rights reserved.
//
//  SDK version: 6.1.17.1
//

#import <UIKit/UIKit.h>

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
/** @brief A GUI element for replacing the standard speech bar.
 
 @xmlonly<nmFramework>DragonMedicalSpeechKit</nmFramework>@endxmlonly
 @since 1.3
 
 The NUSASpeechView class defines a GUI element for replacing the standard speech bar
 with a skinnable speech view. This view can be placed anywhere on the screen or can be 
 added to a toolbar.
 The background color or the background image of the view can be set to a custom value (not both).
 The speech view can be activated by setting the speechView property of a
 NUSAVUIController.
*/
@interface NUSASpeechView : UIView

//////////////////////////////////////////////////////////////////////////////////////////
/// @name Properties
//////////////////////////////////////////////////////////////////////////////////////////

/** @brief The background color of the speech view.
 @since 1.3
 
 The default value is nil; in this case the default background color will be used. 
 It is only possible to set either the background color or background image of the speech view. If both values are set, the most recently set value will be used.
*/
@property (nonatomic, retain) UIColor*  buttonBackgroundColor; 

/** @brief The background image of the speech view.
 @since 1.3
 
 The default value is nil; in this case the default background image will be used.
 It is only possible to set either the background color or background image of the speech view. If both values are set, the most recently set value will be used.
 */
@property (nonatomic, retain) UIImage*  buttonBackgroundImage; 

/** @brief The background image of the speech view for highlighted state.
 @since 1.4
 
 The default value is nil; in this case the default background image will be used.
 */
@property (nonatomic, retain) UIImage*  buttonBackgroundImageHighlighted;

@end
