/***************************************************************
 * Copyright (c) 2011-2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>

/**
 * \addtogroup NMA_Search NMA Search Group
 * @{
 */

/**
 * \class NMARatings NMARatings.h "NMARatings.h"
 *
 * Represents a summary of the user-supplied ratings for a NMAPlace.
 */
@interface NMARatings : NSObject

/**
 * The average rating for the NMAPlace.
 */
@property (nonatomic, readonly) double average;

/**
 * The number of individual votes that users provide for rating the
 * NMAPlace.
 */
@property (nonatomic, readonly) NSUInteger count;

@end

/** @} */
