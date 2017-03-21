/***************************************************************
 * Copyright (c) 2011-2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>

#import "NMARequest.h"

/**
 * \addtogroup NMA_Search NMA Search Group
 * @{
 */

/**
 * \class NMAGeocodeRequest NMAGeocodeRequest.h "NMAGeocodeRequest.h"
 *
 * Represents a request to retrieve NMAPlaceLocation data by way of NMAGeocoder search services.
 *
 * \note A %NMAGeocodeRequest is a kind of NMARequest, and its response is an instance of NMAGeocodeResult.
 */
@interface NMAGeocodeRequest : NMARequest

/**
 * The text format of the request results.
 *
 * \deprecated This method is deprecated as of NMA SDK 3.1. As this type of search no longer support this.
 */
@property (nonatomic) NMATextFormat textFormat DEPRECATED_ATTRIBUTE;

@end

/** @} */
