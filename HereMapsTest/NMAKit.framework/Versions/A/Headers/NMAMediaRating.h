/***************************************************************
 * Copyright (c) 2011-2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import "NMAMedia.h"

/**
 * \addtogroup NMA_Search NMA Search Group
 * @{
 */

/**
 * \class NMAMediaRating NMAMediaRating.h "NMAMediaRating.h"
 *
 * Represents rating content about a NMAPlace.
 *
 * \sa NMAMediaImage
 * \sa NMAMediaReview
 * \sa NMAMediaEditorial
 */
@interface NMAMediaRating : NMAMedia

/**
 * The average rating for this NMAPlace.
 */
@property (nonatomic, readonly) double average;

/**
 * The number of individual votes that users provide for rating this
 * NMAPlace.
 */
@property (nonatomic, readonly) NSUInteger count;

@end

/** @} */
