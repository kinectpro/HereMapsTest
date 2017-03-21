/***************************************************************
 * Copyright (c) 2011-2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import "NMARequest.h"

/**
 * \addtogroup NMA_Search NMA Search Group
 * @{
 */

/**
 * \class NMADiscoveryRequest NMADiscoveryRequest.h "NMADiscoveryRequest.h"
 *
 * Represents a request to retrieve an NMADiscoveryPage object.
 *
 */
@interface NMADiscoveryRequest : NMARequest

/**
 * The text format of the request results.
 *
 * \note The default value is NMATextFormatHTML.
 */
@property (nonatomic) NMATextFormat textFormat;

@end

/** @} */
