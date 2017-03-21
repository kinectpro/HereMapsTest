/*
 * Copyright (c) 2011-2017 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAAutoSuggest.h"

/**
 * \addtogroup NMA_Search NMA Search Group
 * @{
 */

@class NMACategory;
@class NMAGeoBoundingBox;
@class NMAGeoCoordinates;
@class NMAPlaceRequest;

/**
 * \class NMAAutoSuggestPlace NMAAutoSuggestPlace.h "NMAAutoSuggestPlace.h"
 *
 * Represents a suggested place.
 *
 * \sa NMAAutoSuggestSearch
 */
@interface NMAAutoSuggestPlace : NMAAutoSuggest

/**
 * The NSString description of the location of the NMAPlace.
 *
 * Typically, this property is derived from the address, but could also
 * contain any other description that helps an application user understand
 * where the place is located.
 *
 * \note vicinity description for a place is optional. Attempts to read
 * this property could return nil.
 */
@property (nonatomic, readonly, strong) NSString *vicinityDescription;

/**
 * The %NMAGeoCoordinates representing the geographical position of the NMAPlace.
 */
@property (nonatomic, readonly, strong) NMAGeoCoordinates *position;

/**
 * The NSString representation of the category for the NMAPlace.
 */
@property (nonatomic, readonly, strong) NSString *category;

/**
 * The enclosing %NMAGeoBoundingBox describing a range of coordinates
 * that correspond to the NMAPlace. Typically, bounding boxes are
 * associated with places such as cities and countries.
 *
 * \note Bounding box information for a place is optional. Attempts to read
 * this property could return nil.
 */
@property (nonatomic, readonly, strong) NMAGeoBoundingBox *boundingBox;

/**
 * Gets the %NMAPlaceRequest to retrieve the NMAPlace details.
 */
- (NMAPlaceRequest *)placeDetailsRequest;

@end

/** @} */
