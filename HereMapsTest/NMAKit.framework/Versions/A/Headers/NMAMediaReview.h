/***************************************************************
 * Copyright (c) 2011-2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import "NMAMedia.h"

@class NMALink;

/**
 * \addtogroup NMA_Search NMA Search Group
 * @{
 */

/**
 * \class NMAMediaReview NMAMediaReview.h "NMAMediaReview.h"
 *
 * Represents review content that provides access to user reviews and ratings about
 * a NMAPlace.
 *
 * \sa NMAMediaEditorial
 * \sa NMAMediaImage
 * \sa NMAMediaRatings
 */
@interface NMAMediaReview : NMAMedia

/**
 * The %NSDate specifying the date when the user contributed the review.
 */
@property (nonnull, nonatomic, readonly) NSDate *contributionDate;

/**
 * The title of the review that the user contributed.
 *
 * \note A title for a review is optional. Attempts to read this property
 * could return empty string.
 */
@property (nonnull, nonatomic, readonly) NSString *title;

/**
 * The rating that the review contributor gave for the place.
 *
 * \note The rating may come from various systems with different rating schemes.
 * The value of this attribute may not reflect the rating scheme of the
 * supplier's service, but is adjusted to the value range of the Places API [1..5].
 */
@property (nonatomic, readonly) double rating;

/**
 * The review content for the NMAPlace.
 *
 * \note Depending on the NMASupplier, the full content might not be displayed
 * and the full review might be available only within the resource to which
 * the optional \p via attribute links.
 */
@property (nullable, nonatomic, readonly) NSString *description;

/**
 * The BCP-47 language code in which the review is available.
 *
 * \note Attempts to read this property could return empty string as the language code
 * for a review is optional. If nil the \link description\endlink language is unkown but is likely
 * to be English.
 */
@property (nullable, nonatomic, readonly) NSString *languageCode;

/**
 * Details of the user who contributed the review.
 *
 * \note The contributor may be unkown. Attempts to read this property
 * could return nil.
 */
@property (nullable, nonatomic, readonly) NMALink *contributor;

@end

/** @} */
