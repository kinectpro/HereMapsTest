/***************************************************************
 * Copyright (c) 2011-2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import "NMALink.h"

@class NMADiscoveryRequest;

/**
 * \addtogroup NMA_Search NMA Search Group
 * @{
 */

/**
 * \class NMADiscoveryLink NMADiscoveryLink.h "NMADiscoveryLink.h"
 *
 * \brief Represents a discovery search results link that can be used to perform another discovery search.
 */
@interface NMADiscoveryLink : NMALink

/**
 * An NMADiscoveryRequest object to perform another NMADiscoveryPage request.
 */
@property(nonnull, nonatomic, readonly) NMADiscoveryRequest *request;

@end

/** @} */
