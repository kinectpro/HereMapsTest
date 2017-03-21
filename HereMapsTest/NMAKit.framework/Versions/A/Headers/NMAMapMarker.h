/***************************************************************
 * Copyright (c) 2011-2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import "NMAMapObject.h"
#import <UIKit/UIKit.h>
#import "NMATypes.h"

@class NMAGeoCoordinates;

/**
 * \addtogroup NMA_Map  NMA Mapping Group
 * @{
 */

/**
 * \brief The tap handler block called when the info bubble is tapped.
 */
typedef void (^NMAInfoBubbleEventBlock)(void);

/**
 * \class NMAMapMarker NMAMapMarker.h "NMAMapMarker.h"
 *
 * Represents a marker used to display an icon on a geographical position on a map.
 * The map handles proper placement of icons on the screen as well as
 * panning.
 *
 * \note Application users can select %NMAMapMarker objects.
 *
 */
@interface NMAMapMarker : NMAMapObject

/**
 * A convenience method to construct an NMAMapMarker at the specified
 * coordinates.
 *
 * \param coordinates The NMAGeoCoordinates at which to create the map marker.
 */
+ (instancetype)mapMarkerWithGeoCoordinates:(NMAGeoCoordinates *)coordinates;

/**
 * A convenience method to construct an NMAMapMarker at the specified
 * coordinates and with a UIImage icon.
 * \param coordinates The NMAGeoCoordinates at which to create the map marker.
 * \param image The UIImage to use for the marker icon.
 */
+ (instancetype)mapMarkerWithGeoCoordinates:(NMAGeoCoordinates *)coordinates image:(UIImage *)image;

/**
 * The geographical coordinates at which the %NMAMapMarker is displayed on a map.
 */
@property (nonatomic, strong) NMAGeoCoordinates *coordinates;

/**
 * The UIImage displayed at the marker location.
 */
@property (nonatomic, strong) UIImage *icon;

/**
 * \brief The %CGPoint offset of the %NMAMapMarker from its anchored location.
 * <p>
 * Use this property to reposition a %NMAMapMarker as needed.
 * The x and y offset values are measured in points.
 * Positive offset values move the %NMAMapMarker down and to the right,
 * while negative values move it up and to the left.
 * </p>
 * <p> If no offset is provided, the %NMAMapMarker is centered on its
 * anchor; that is, the center of the marker image is located at the
 * map-space representation of the marker's world-space location (its
 * anchor, an %NMAGeoCoordinates).
 * </p>
 */
@property (nonatomic) CGPoint anchorOffset;

/**
 * The current title for the default info bubble. Default is nil.
 */
@property (nonatomic) NSString *title;

/**
 * Description text for the %NMAMapMarker. This is shown below the title.
 * Default is nil.
 */
@property (nonatomic) NSString *textDescription;

/**
 * This block is called when the info bubble is tapped.
 * Default is nil.
 */
@property (nonatomic) NMAInfoBubbleEventBlock infoBubbleEventBlock;

/*!
 * Initializes a %NMAMapMarker instance with the specified %NMAGeoCoordinates.
 *
 * \param coordinates A %NMAGeoCoordinates representing the map coordinates for displaying
 *               the %NMAMapMarker
 * \return The %NMAMapMarker
 */
- (instancetype)initWithGeoCoordinates:(NMAGeoCoordinates *)coordinates;

/*!
 * Initializes a %NMAMapMarker instance with the specified %NMAGeoCoordinates
 * and UIImage for the displayed icon.
 *
 * \param coordinates A %NMAGeoCoordinates representing the map coordinates for displaying
 *               the %NMAMapMarker
 * \param image A UIImage the icon.
 * \return The %NMAMapMarker
 */
- (instancetype)initWithGeoCoordinates:(NMAGeoCoordinates *)coordinates image:(UIImage *)image;

/*!
 * A convenience function to set where the %NMAMapMarker is attached to its
 * anchor
 *
 * \param position A %NMAnchorLocation for anchoring the marker icon.
 * \return The %CGPoint offset value that was applied to the anchorOffset property
 */
- (CGPoint)setAnchorOffsetUsingLayoutPosition:(NMALayoutPosition)position;

/**
 * \brief Display the default info bubble if the %NMAMapMarker's title has been set to
 * something non-nil. The info bubble is displayed only after the %NMAMapMarker is added
 * onto a %NMAMapView, otherwise making this call would make no effects. Also a non-zero
 * length of the title or the textDescription is required.
 *
 * As only one info bubble can be displayed on the map at a time, thus when calling showInfoBubble
 * on a different %NMAMapMarker, the current info bubble on the display will automatically
 * be closed before the newly selected one is shown.
 *
 * @return YES If the MapMarker meets all the requirements to show the bubble.
 */
- (BOOL)showInfoBubble;

/**
 * \brief Display the view passed as an info bubble.
 *
 * \param view The view to be used as the info bubble view.
 *
 * @return YES If the MapMarker meets all the requirements to show the bubble.
 *
 * \sa NMAMapMarker::showInfoBubble
 */
- (BOOL)showInfoBubble:(UIView *)view;

/**
 * \brief Hide the info bubble from %NMAMapView.
 *
 * @return YES If the info bubble is successfully hidden from %NMAMapView. NO if the info bubble is
 * not attached to this %NMAMapMarker.
 */
- (BOOL)hideInfoBubble;

@end
/** @}  */
