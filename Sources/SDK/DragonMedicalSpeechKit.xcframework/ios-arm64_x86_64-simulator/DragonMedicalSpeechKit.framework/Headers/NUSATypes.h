//
//  NUSATypes.h
//  Dragon Medical SpeechKit
//
//  Copyright 2011 Nuance Communications, Inc. All rights reserved.
//
//  SDK version: 6.2.2.1
//

#import <Foundation/Foundation.h>

#pragma mark Exception names
extern NSString* NUSAInvalidOperationException;

#pragma mark NSError domains
extern NSString* NUSASessionErrorDomain;

#pragma mark Versioning information
extern NSString* NUSAVersionString;

/** @brief Options for placing the volumer meter.
 @since 1.6
 */
typedef enum NUSAVolumeMeterLocation {
    /** @brief No volume meter. This option is ignored when using the speech control. */
    NUSAVolumeMeterLocationNone   = 0,
    /** @brief Volume meter at the top of the screen. */
    NUSAVolumeMeterLocationTop,
    /** @brief Volume meter at the bottom of the screen. This option is ignored when using the speech bar. */
    NUSAVolumeMeterLocationBottom,
    /** @brief Volume meters at both sides of the screen. */
    NUSAVolumeMeterLocationSide,
} NUSAVolumeMeterLocation;

/** @brief Options for placing the bad sound quality indicator.
 @since 1.7
 */
typedef enum NUSABadQualityIndicatorLocation {
    /** @brief Top left, sliding in from top. */
    NUSABadQualityIndicatorLocationTopLeft   = 0,
    /** @brief Top center, sliding in from top. */
    NUSABadQualityIndicatorLocationTopCenter,
    /** @brief Top right, sliding in from top. */
    NUSABadQualityIndicatorLocationTopRight,
    /** @brief Bottom left, sliding in from bottom. */
    NUSABadQualityIndicatorLocationBottomLeft,
    /** @brief Bottom center, sliding in from bottom. */
    NUSABadQualityIndicatorLocationBottomCenter,
    /** @brief Bottom right, sliding in from bottom. */
    NUSABadQualityIndicatorLocationBottomRight,
} NUSABadQualityIndicatorLocation;

/** @brief The content options for opening the WCIS control.
 @since 3.0
 */
typedef enum NUSAContentType {
    /** @brief Display default form. */
    NUSAContentTypeDefault = 0,
    /** @brief Display voice commands. */
    NUSAContentTypeVoiceCommands,
    /** @brief Display end user help. */
    NUSAContentTypeEndUserHelp,
    /** @brief Display the auto-text management page, if applicable. */
    NUSAContentTypeAutoTexts,
    /** @brief Display the manage vocabulary page, if applicable. */
    NUSAContentTypeAddWord
} NUSAContentType;

/** @brief Audio interruption state for session
 @since 6.2
 */
typedef NS_ENUM(NSInteger, NUSAAudioInterruptionState) {
    /** @brief Audio interruption began*/
    NUSAAudioInterruptionStateBegan,
    /** @brief Audio interruption ended*/
    NUSAAudioInterruptionStateEnded
};
