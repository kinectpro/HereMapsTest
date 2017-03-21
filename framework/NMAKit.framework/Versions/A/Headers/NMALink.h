/***************************************************************
 * Copyright (c) 2011-2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>

/**
 * \addtogroup NMA_Search NMA Search Group
 * @{
 */

/**
 * \class NMALink NMALink.h "NMALink.h"
 *
 * Represents a HERE Places resource link which requires another request to be made
 * in order to retrieve the full detauls of the resource. The link contains basic metadata
 * about the linked resource.
 *
 * The interface is typically subclassed to provide methods to make the appropriate resource
 * request.
 *
 */
@interface NMALink : NSObject

/**
 * Gets the unique identifier for the resource to which the %NMALink refers.
 *
 * \note An identifier for a linked object is optional, so this property could be nil.
 */
@property (nullable, nonatomic, readonly) NSString *uniqueId;

/**
 * Gets the %NSString representation of the link URL.
 * </p>
 * <p>
 * This URL may be used to perform an HTTP GET request to the HERE Places REST service
 * to retrieve the full metadata of the linked resources.
 * </p>
 * <p>
 * The request may return a HTML or JSON response. If url contains "places.hybrid.api.here.com",
 * it will return a JSON response as specified at http://developer.here.com/places
 * If URL contains other domains, it will most likely return a HTML response.
 *
 * \note For convenience it is recommended to use request methods in dervied classes when
 * available.
 */
@property (nonnull, nonatomic, readonly) NSString *url;

/**
 * Gets the localized name for the resource to which the %NMALink refers.
 * </p>
 * <p>
 * Client applications can safely display this name to the user.
 *
 * \note A title for a linked object is optional, so this property could be nil.
 */
@property (nullable, nonatomic, readonly) NSString *name;

/**
 * Gets an URL of the icon for the resource to which assiciated with this NMALink.
 *
 * \note An icon URL for a NMALink object is optional, so this property could be nil.
 * Application can download the icon online with this URL, but it needs to use
 * its own icon for offline.
 */
@property (nullable, nonatomic, readonly) NSString *iconUrl;

@end
/** @} */
