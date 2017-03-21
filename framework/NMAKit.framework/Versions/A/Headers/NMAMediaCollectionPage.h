/***************************************************************
 * Copyright (c) 2011-2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>
#import "NMAMedia.h"

@class NMAMediaCollectionPageRequest;

/**
 * \addtogroup NMA_Search NMA Search Group
 * @{
 */

/**
 * \class NMAMediaCollectionPage NMAMediaCollectionPage.h "NMAMediaCollectionPage.h"
 *
 * Represents a paginated collection of NMAMedia objects of a specific type.
 *
 * \note Each collection contains objects of a single NMAMediaType
 *
 * \sa NMAMedia
 * \sa NMAMediaCollectionPageRequest
 */
@interface NMAMediaCollectionPage : NSObject

/**
 * The specialized content type of the objects on the page.
 */
@property (nonatomic, readonly) NMAMediaType type;

/**
 * The total number of available NMAMedia objects in this given media collection.
 */
@property (nonatomic, readonly) NSInteger available;

/**
 * The offset count for the current page of the completed NMAMediaCollectionPageRequest.
 */
@property (nonatomic, readonly) NSInteger offsetCount;

/**
 * The NMAMediaCollectionPageRequest for requesting the next page of the NMAMediaCollectionPage.
 *
 * \note This will be nil if no more pages are available.
 */
@property (nullable, nonatomic, readonly) NMAMediaCollectionPageRequest *nextPageRequest;

/**
 * Array of NMAMedia objects for the current page
 */
@property (nonnull, nonatomic, readonly) NSArray<__kindof NMAMedia *> *mediaContents;

@end

/** @} */
