/***************************************************************
 * Copyright (c) 2011-2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import "NMARequest.h"

/**
 * \addtogroup NMA_Search NMA Search Group
 * @{
 */

/**
 * \class NMAReverseGeocodeRequest NMAReverseGeocodeRequest.h "NMAReverseGeocodeRequest.h"
 *
 * Represents a request to retrieve NMAPlaceLocation data by way of
 * NMAGeocoder search services.
 *
 * \note A %NMAReverseGeocodeRequest is a kind of NMARequest, and its response is an instance
 * of NMAReverseGeocodeResult.
 */
@interface NMAReverseGeocodeRequest : NMARequest

/**
 * The text format of the request results.
 *
 * \deprecated This method is deprecated as of NMA SDK 3.1. As this type of search no longer support this.
 */
@property (nonatomic) NMATextFormat textFormat DEPRECATED_ATTRIBUTE;

@end

/** @}  */
