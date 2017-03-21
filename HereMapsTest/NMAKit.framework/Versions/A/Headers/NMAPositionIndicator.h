/***************************************************************
 * Copyright (c) 2011-2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>

/**
 * \addtogroup NMA_Map NMA Mapping Group
 * @{
 */

/**
 * \class NMAPositionIndicator NMAPositionIndicator.h "NMAPositionIndicator.h"
 * \brief Used to provide a visual indication of the user's current position.
 * <p>
 * Each instance of NMAMapView automatically has a NMAPositionIndicator created
 * for it. The position indicator is hidden by default; it can be displayed by
 * change its visible property to YES.
 * </p>
 * <p>
 * By default, the position indicator displays an NMAMapMarker showing a green
 * circle.
 * </p>
 * <p>
 * The accuracy of the current position is indicated by a circle surrounding the
 * indicator object. The visibility of the accuracy indicator is controlled via
 * the accuracyIndicatorVisible property, and its color may be changed by setting
 * the accuracyIndicatorColor.
 * </p>
 *
 * \note The NMAPositionIndicator requires NMAPositioningManager position updates
 * to function correctly, and will automatically start the positioning service
 * when required.
 */
@interface NMAPositionIndicator : NSObject

/**
 * Indicates whether the NMAPositionIndicator is visible.
 *
 * \note The getter is \p isVisible.
 *
 * \note Setting visible to YES will start NMAPositioningManager positioning
 * if it is not already active.
 */
@property (nonatomic, getter = isVisible) BOOL visible;

/**
 * Indicates whether the NMAPositionIndicator accuracy indicator
 * (the surrounding circle) is visible.
 *
 * \note The getter is \p isAccuracyIndicatorVisible.
 */
@property (nonatomic, getter = isAccuracyIndicatorVisible) BOOL accuracyIndicatorVisible;

/**
 * The color of the accuracy indicator circle.
 */
@property (nonnull, nonatomic) UIColor *accuracyIndicatorColor;

@end
/** @}  */
