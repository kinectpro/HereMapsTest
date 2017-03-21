/***************************************************************
 * Copyright (c) 2011-2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>

@class NMAGeoCoordinates;

/**
 * \addtogroup NMA_Route NMA Routing Group
 * @{
 */

NS_ASSUME_NONNULL_BEGIN

/**
 * \class NMAWaypoint NMAWaypoint.h "NMAWaypoint.h"
 *
 * \brief Waypoints define a route's stopovers, including its start point it's
 * destination point and any points in between.
 *
 * Each waypoint represents a position along an NMARoute, this includes:
 * <ul>
 * <li>The original (input) coordinates specified as part of a search request</li><br/>
 * or
 * <li>The adjusted coordinates used to calculate the route. For example, the routing
 * engine may adjust the input coordinates so that they fall upon a road. The process of
 * adjusting the coordinates is known as map matching.</li>
 * </ul>
 *
 * \note A waypoint can represent the result of map matching.
 */
@interface NMAWaypoint : NSObject

/**
 * The NMAGeoCoordinates representing the original position of the
 * %NMAWaypoint - typically the coordinates passed into a routing request.
 */
@property (nonatomic, readonly) NMAGeoCoordinates *originalPosition;

/**
 * The %NMAGeoCoordinates representing the mapped position of the
 * %NMAWaypoint - the coordinates adjusted by the routing request.
 */
@property (nonatomic, readonly) NMAGeoCoordinates *mappedPosition;

@end

NS_ASSUME_NONNULL_END

/** @}  */
