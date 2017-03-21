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
@class NMADiscoveryRequest;

/**
 * \class NMAAutoSuggestSearch NMAAutoSuggestSearch.h "NMAAutoSuggestSearch.h"
 *
 * Represents a suggested search.
 *
 * \sa NMAAutoSuggestPlace
 */
@interface NMAAutoSuggestSearch : NMAAutoSuggest

/**
 * The %NMAGeoCoordinates representing the geographical position of the NMAPlace.
 *
 * \note position for a place is optional. Attempts to read this property could return nil.
 */
@property (nonatomic, readonly, strong) NMAGeoCoordinates *position;

/**
 * The NSString representation of the category for the NMAPlace.
 *
 * \note category for a place is optional. Attempts to read this property could return nil.
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
 * Gets the %NMADiscoveryRequest to perform a suggested search e.g. category search.
 */
- (NMADiscoveryRequest *)suggestedSearchRequest;

@end

/** @} */
