/***************************************************************
 * Copyright (c) 2011-2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>

#import "NMATypes.h"

@class NMARequest;

/**
 * \addtogroup NMA_Search NMA Search Group
 * @{
 */

/**
 * Defines the name for Places API error domain
 */
FOUNDATION_EXPORT NSString * _Nonnull const NMA_PLACES_ERROR_DOMAIN;

/**
 * Represents an event listener that reports information about query
 * progress changes and query completion.
 *
 * Methods of this protocol are called on the main queue.
 */
@protocol NMAResultListener<NSObject>

@required
/**
 * \class NMAResultListener NMAResultListener.h "NMAResultListener.h"
 *
 * \brief Callback when a request has completed.
 *
 * The following list shows NMA requrest types on the left and the corresponding
 * result data types on the right. The data type of the first argument received by
 * this method is one of the types on the left, the data type of the second
 * argument is one of those on the right.
 * \code
 * NMAGeocodeRequest                  NSArray(NMAGeocodeResult)
 * NMAReverseGeocodeRequest           NSArray(NMAReverseGeocodeResult)
 * NMADiscoveryRequest                NMADiscoveryPage
 * NMAPlaceRequest                    NMAPlace
 * NMAMediaCollectionPageRequest      NMAMediaCollectionPage
 * NMASuggestionRequest               NSArray(NSString)
 * \endcode
 *
 * \param request An object of the type shown on the left in the list above.
 *
 * \param data An object containing the search results, the possible types are
 *        shown on the right-hand side in the list above. Can be nil if no
 *        results found or an error was encountered.
 *
 * \param error NSError for this request
 */
- (void)    request:(NMARequest * _Nonnull)request
didCompleteWithData:(id _Nullable)data
              error:(NSError * _Nullable)error
NS_SWIFT_NAME(requestDidComplete(_:data:error:));

@end

/** @} */
