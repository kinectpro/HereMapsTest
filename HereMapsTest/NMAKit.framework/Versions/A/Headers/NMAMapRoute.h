/***************************************************************
 * Copyright (c) 2011-2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <UIKit/UIColor.h>

#import "NMAMapObject.h"

@class NMARoute;

NS_ASSUME_NONNULL_BEGIN

/**
 * \addtogroup NMA_Map NMA Mapping Group
 * @{
 * \class NMAMapRoute NMAMapRoute.h "NMAMapRoute.h"
 *
 * \brief Represents a NMAMapObject in the shape of a route that can be
 * displayed on a map.
 *
 * In order to display the route object on the map, the route object
 * needs to be added to an NMAMapView using its addMapObject: method.
 * The NMAViewObject location property for a NMAMapRoute returns the
 * coordinates of the first waypoint.
 *
 * \sa NMARoute
 */
@interface NMAMapRoute : NMAMapObject

/**
 * A convenience constructor for NMAMapRoute.
 * \param route The route object from which to construct the NMAMapRoute.
 */
+ (instancetype)mapRouteWithRoute:(NMARoute *)route;

/**
 * Use mapRouteWithRoute to instantiate a NMAMapRoute.
 */
- (instancetype)init UNAVAILABLE_ATTRIBUTE;

/**
 * Indicates whether the maneuver number is displayed on the %NMAMapRoute.
 */
@property (nonatomic) BOOL maneuverNumberDisplayed;

/**
 * The %UIColor representing the color of the %NMAMapRoute.
 *
 * \note Alpha-value transparency is supported and will also be set when setting this
 * property.
 *
 * \return The user-defined route color if user has set route color. Otherwise,
 * the default color for %NMAMapRoute.
 */
@property (nonatomic, strong) UIColor *color;

/**
 * The NMARoute represented by the NMAMapRoute.
 */
@property (nonatomic, strong) NMARoute *route;

@end

NS_ASSUME_NONNULL_END

/** @}  */
