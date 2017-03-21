/***************************************************************
 * Copyright (c) 2011-2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import "NMAMedia.h"

/**
 * \addtogroup NMA_Search NMA Search Group
 * @{
 */

/**
 * \class NMAMediaEditorial NMAMediaEditorial.h "NMAMediaEditorial.h"
 *
 * Represents editorial content about a NMAPlace.
 *
 * \sa NMAMediaImage
 * \sa NMAMediaReview
 * \sa NMAMediaRating
 */
@interface NMAMediaEditorial : NMAMedia

/**
 * The %NSString for this editorial content.
 */
@property (nonnull, nonatomic, readonly) NSString *description;

/**
 * The BCP-47 language code for the editorial text.
 *
 * \note A language code for an editorial is optional and so attempts to read
 * this property could return empty string. In this scenario the language of
 * editorial is unknown but it is likely to be English.
 */
@property (nonnull, nonatomic, readonly) NSString *languageCode;

@end

/** @} */
