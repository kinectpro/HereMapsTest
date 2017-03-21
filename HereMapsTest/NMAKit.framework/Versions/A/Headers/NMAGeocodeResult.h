/***************************************************************
 * Copyright (c) 2011-2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>

@class NMAPlaceLocation;

FOUNDATION_EXPORT const float NMAGeocodeResultInvalidRelevance;

/**
 * \addtogroup NMA_Search NMA Search Group
 * @{
 */

NS_ASSUME_NONNULL_BEGIN

/**
 * \brief Represents the result of a geocode request.
 *
 * The data of a geocode result is represented by an instance of NMAPlaceLocation,
 * accessed through the location property. The quality of the result can be
 * assessed in a broad sense with the relevance property, or in more detail using
 * the matchQuality dictionary.
 *
 * \sa NMAGeocodeRequest
 */
@interface NMAGeocodeResult : NSObject

/**
 * \brief The location data of the geocode result.
 */
@property (nonatomic, readonly) NMAPlaceLocation *location;

/**
 * \brief The relevance of the result location to the original search parameters.
 *
 * The relevance of a result provides a measure of how accurate or reliable it is.
 * The valid range is [0, 1], with a value of 1 representing a perfect match. If
 * relevancy data is unavailable (such as for an offline search), this property
 * will have the value NMAGeocodeResultInvalidRelevance.
 */
@property (nonatomic, readonly) float relevance;

/**
 * \brief Details about the quality of the result.
 *
 * Additional information about the accuracy of the result is available in the
 * matchQuality dictionary. It contains one or more NSNumber values representing
 * how well each individual search parameter was matched. The values will be in
 * the range [0, 1] with a value of 1 indicating a perfect match.
 *
 * The possible keys are "State", "County", "City", "District", "Street",
 * "SecondaryStreet", "HouseNumber", and "PostalCode".
 *
 * \note The "SecondaryStreet" key will be present if an intersection was specified
 * in the geocode request. For example, if the request contained "1st St at 2nd Ave",
 * the "Street" key would access the match value for "1st St" and the "SecondaryStreet"
 * key would access the match value for "2nd Ave".
 */
@property (nonatomic, readonly) NSDictionary<NSString *, NSNumber *> *matchQuality;

@end

NS_ASSUME_NONNULL_END

/** @} */
