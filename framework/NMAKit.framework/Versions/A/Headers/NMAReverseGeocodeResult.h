/***************************************************************
 * Copyright (c) 2011-2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>

@class NMAPlaceLocation;

FOUNDATION_EXPORT const float NMAReverseGeocodeResultInvalidDistance;

/**
 * \addtogroup NMA_Search NMA Search Group
 * @{
 */

/**
 * Represents the result of a reverse geocoding request.
 *
 * The data of a reverse geocoding result is represented by an instance of
 * NMAPlaceLocation, accessed via the location property. The distance
 * between the result and the original search location is give by the
 * distance property.
 */
@interface NMAReverseGeocodeResult : NSObject

/**
 * The location data of the reverse geocode result.
 */
@property (nonatomic, readonly) NMAPlaceLocation *location;

/**
 * The distance between the result and the search input coordinates.
 */
@property (nonatomic, readonly) float distance;

@end
/** @} */
