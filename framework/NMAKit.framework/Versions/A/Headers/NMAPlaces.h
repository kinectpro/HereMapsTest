/***************************************************************
 * Copyright (c) 2011-2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>

@class NMACategoryFilter;
@class NMADiscoveryRequest;
@class NMAGeoBoundingBox;
@class NMAGeoCoordinates;
@class NMAPlaceRequest;
@class NMASuggestionRequest;
@class NMAAutoSuggestionRequest;
@class NMACategory;

/**
 * \addtogroup NMA_Search NMA Search Group
 *
 * The Search group provides classes, protocols, and enumerations
 * for performing place and geocoder searches.
 * Some important classes in this group are
 * {@link NMAPlaces} and {@link NMAGeocoder}.
 *
 * @{
 */

NS_ASSUME_NONNULL_BEGIN

/**
 * \brief Places Reference Source for core POI IDs.
 */
FOUNDATION_EXPORT NSString *const NMAPlacesSourcePVID;
/**
 * \brief Places Reference Source for sharing IDs.
 */
FOUNDATION_EXPORT NSString *const NMAPlacesSourceSharing;
/**
 * \brief Places Reference Source for all types of venue IDs.
 */
FOUNDATION_EXPORT NSString *const NMAPlacesSourceVenuesAll;
/**
 * \brief Places Reference Source for venue IDs.
 */
FOUNDATION_EXPORT NSString *const NMAPlacesSourceVenuesVenue;
/**
 * \brief Places Reference Source for venue content IDs.
 */
FOUNDATION_EXPORT NSString *const NMAPlacesSourceVenuesContent;
/**
 * \brief Places Reference Source for venue destination IDs.
 */
FOUNDATION_EXPORT NSString *const NMAPlacesSourceVenuesDestination;
/**
 * \brief Places Reference Source for building IDs.
 */
FOUNDATION_EXPORT NSString *const NMAPlacesSourceBuilding;

/**
 * A typedef of a block parameter signature used with
 * \link NMAPlaces::refreshTopLevelCategoriesWithCompletion:\endlink.
 *
 * \param categories An NSArray of localized NMACategory if available, nil otherwise.
 * \param error The error if the refresh failed, or nil if the refresh was successful.
 *
 * \sa \link NMAPlaces::refreshTopLevelCategoriesWithCompletion:\endlink
 *
 * \note The block will be called on the main queue.
 */
typedef void (^NMAPlacesCategoriesCompletionBlock)(NSArray<NMACategory *> * _Nullable categories, NSError * _Nullable error);

/**
 * \class NMAPlaces NMAPlaces.h "NMAPlaces.h"
 *
 * Represents a factory for creating places requests.
 *
 * <p>
 * The %NMAPlaces service supports a variety of use cases that center
 * around two major features:
 * <ul>
 * <li>Place discovery - helps users find places that are relevant to them.</li>
 * <li>Place information retrieval - provides detailed information about places
 *     in which users are interested.</li></ul></p>
 * <p>
 * For place discovery, the %NMAPlaces API supports two use cases from which
 * to choose according to the requirements for the application:
 * <ul>
 * <li>Search - finds places that match user-provided search terms.</li>
 * <li>Explore - guides users to relevant places nearby.</li></ul></p>
 * <p>
 * The %NMAPlaces API defines resources that represent entry points for
 * supported use cases, employing links to describe the application flow within
 * a particular use case.</p>
 * <p>
 * For example, the discovery request is an entry point to the %NMAPlaces
 * API resource. When an application user submits a discovery request to the
 * search resource, the response contains, among other items, a list of links
 * to places or to place resources. Each referenced place might have rich
 * content associated with it, including ratings, images, reviews, editorials,
 * and owner content. Each place also contains references to related places, which
 * allow users to discover places relevant to or otherwise related to their
 * original search.</p>
 *
 * \note NMAPlaces requires valid authentication credentials to be set via
 * NMAApplicationContext. If valid credentials are not present the API may not
 * function correctly or may stop functioning correctly in the future when server
 * side configurations change.
 */
@interface NMAPlaces : NSObject

/**
 * Returns the %NMAPlaces singleton instance.
 *
 * \note Use this method to obtain a %NMAPlaces instance. Do not call
 * init directly.
 *
 * \return shared %NMAPlaces instance
 */
+ (NMAPlaces *)sharedPlaces;

/*!
 * Creates a %NMAPlaces search request using a specified location
 * and query.
 *
 * The results of the search request are sets of places that match a
 * user's search term in a specific location. Additional user's current position
 * will also be sent to ensure you get the best results possible. The user's
 * current position is only available if [NMAPositioningManager active] is true.
 *
 * The viewport is a bounding box used to perform the search. To ensure you get
 * the best results possible, you should match the viewport to your map if there
 * is a map visible to the user. The viewport is optional (see also \link NMARequest::viewport\endlink).
 *
 * \param location A %NMAGeoCoordinates representing the query's location
 *                 context used to search for results that are
 *                 appropriate to the query parameter
 * \param query %NSString specifying the kind of places to locate
 * \return The %NMADiscoveryRequest if both parameters are valid,
 *         nil otherwise.
 */
- (nullable NMADiscoveryRequest *)createSearchRequestWithLocation:(NMAGeoCoordinates *)location
                                                            query:(NSString *)query
NS_SWIFT_NAME(makeSearchRequest(location:query:));

/*!
 * Creates a %NMAPlaces explore request using a specified location
 * context and category filter. If a category filter is provided, the created
 * request will limit results to include only items with categories specified
 * in the filter.
 *
 * <p>The results of the explore request is a list of nearby relevant places
 * for a given positon. It answers the question "What interesting places are near
 * a location?" The results returned are confined to those located in the current
 * search area and are ordered by popularity.</p>
 *
 * \note In addition to the requested location this search also considers the
 * current device position as returned by NMAPositioningManager.
 *
 * \param location A %NMAGeoCoordinates representing the location
 *                 context used to search for nearby places
 * \param geoArea  A %NMAGeoBoundingBox representing the query's search area
 *                (this is an optional parameter and should not be set unless
 *                 such functionality is explicitly intended in the application)
 * \param filters A %NMACategoryFilter representing the category filter
 * \return The %NMADiscoveryRequest if parameters are valid
 */
- (nullable NMADiscoveryRequest *)createExploreRequestWithLocation:(NMAGeoCoordinates *)location
                                                        searchArea:(NMAGeoBoundingBox * _Nullable)geoArea
                                                           filters:(NMACategoryFilter * _Nullable)filters
NS_SWIFT_NAME(makeExploreRequest(location:geoArea:filters:));

/*!
 * Creates a %NMAPlaces "What's here?" request using a specified
 * location context and category filter. If a category filter is provided, the
 * created request will limit results to include only items with categories
 * specified in the filter.
 *
 * <p>The results of the here request is a list of places with addresses that
 * lie within the vicinity of the search location. The feature is typically used
 * by applications that include "check-in" or "click on map to get more
 * information" options. </p>
 *
 * \note In addition to the requested location this search also considers the
 * current device position as returned by NMAPositioningManager.
 *
 * \param location A %NMAGeoCoordinates representing the location
 *                 context used to search for nearby places
 * \param filters A %NMACategoryFilter representing the category filter
 * \return The %NMADiscoveryRequest if both parameters are valid
 */
- (nullable NMADiscoveryRequest *)createHereRequestWithLocation:(NMAGeoCoordinates *)location
                                                        filters:(NMACategoryFilter * _Nullable)filters
NS_SWIFT_NAME(makeHereRequest(location:filters:));

/*!
 * Creates a %NMAPlaces request to return a list of suggested search terms
 * that are related to a specified location context and partial search term.
 *
 * \note In addition to the requested location this search also considers the
 * current device position as returned by NMAPositioningManager.
 *
 * \param location A %NMAGeoCoordinates representing the query location context
 * \param partialTerm A %NSString specifying the partial search term
 * \return The %NMASuggestionRequest if the \p location is valid, nil otherwise
 */
- (nullable NMASuggestionRequest *)createSuggestionRequestWithLocation:(NMAGeoCoordinates *)location
                                                           partialTerm:(NSString *)partialTerm
NS_SWIFT_NAME(makeSuggestionRequest(location:partialTerm:));

/*!
 * Creates a %NMAPlaces request to return lists of suggested search terms, instant results and
 * refined search links related to a specified location context and partial search term.
 *
 * IMPORTANT: This is a Beta API, and is subject to change without notice.
 *
 * Note that this Autosuggest request supports online only. Please use
 * createSuggestionRequestWithLocation:partialTerm for offline.
 *
 * In addition to the requested location this search also considers the
 * current device position as returned by NMAPositioningManager.
 *
 * A search location context must be provided by setting a search location.
 * Failing to set a location context will result in
 * an error NMARequestErrorInvalidParameter when executing the request.
 *
 * \param location A %NMAGeoCoordinates representing the query location context
 * \param partialTerm An NSString specifying the partial search term
 *
 * \return The %NMAAutoSuggestionRequest if the \p location is valid, nil otherwise
 */
- (nullable NMAAutoSuggestionRequest *)createAutoSuggestionRequestWithLocation:(NMAGeoCoordinates *)location
                                                                   partialTerm:(NSString *)partialTerm
NS_SWIFT_NAME(makeAutoSuggestionRequest(location:partialTerm:));

/*!
 * Creates a %NMAPlaceRequest based on a reference identifier and source.
 * <p>
 * The supported sources are "pvid", "sharing", "venues", "venues.content",
 * "venues.venue", "venues.destination", "building".
 * See also <a
 * href="https://places.demo.api.here.com/places/static/doc/public/#topics/resource-lookup.html">Resource
 * look-up</a>.
 * </p>
 * <p>"sharing" example:</p>
 * <p>
 * The 'referenceIdentifier' argument to use is found in NMAPlace#viewUrl.
 * The 'referenceIdentifier' is the last path segment of the View URI.
 * </p>
 * <p>
 * Using the following example View URI:
 * </p>
 * \code
 * http://here.com/p/s-aWQ9Mjc2dTMzZGMtMzk0NGE0NzQ4YTYyNDk5Y2I3OTVjZjhiZWUzNDljOWM7bj1BbnRpcG9kZXM7Yz1jb2ZmZWUtdGVhO
 * 3BoPSUyQjQ5MTc2MzgzNDAxMTg7bGF0PTUyLjUzMDkzO2xvbj0xMy40MDk5Mg
 * \endcode
 * <p>
 * The sharing reference identifier is:
 * </p>
 * \code
 * s-aWQ9Mjc2dTMzZGMtMzk0NGE0NzQ4YTYyNDk5Y2I3OTVjZjhiZWUzNDljOWM7bj1BbnRpcG9kZXM7Yz1jb2ZmZWUtdGVhO
 * 3BoPSUyQjQ5MTc2MzgzNDAxMTg7bGF0PTUyLjUzMDkzO2xvbj0xMy40MDk5Mg
 * \endcode
 * <p>
 * The reference source is \link NMAPlacesSourceSharing\endlink.
 * </p>
 * <p>
 * For example:
 * </p>
 * \code
 * NMAPlaceRequest* request =
 *     [[NMAPlaces sharedPlaces] createLookupRequestWithReferenceIdentifier:
 *
 *     @"s-aWQ9Mjc2dTMzZGMtMzk0NGE0NzQ4YTYyNDk5Y2I3OTVjZjhiZWUzNDljOWM7bj1BbnRpcG9kZXM7Yz1jb2ZmZWUtdGVhO
 *       3BoPSUyQjQ5MTc2MzgzNDAxMTg7bGF0PTUyLjUzMDkzO2xvbj0xMy40MDk5Mg"
 *     inSource:NMAPlacesSourceSharing];
 * \endcode
 * <p>
 * "venues.venue" example:
 * </p>
 * <p>
 * The venue reference identifier for Alexa Shopping Center is DM_7171.
 * The reference source is NMAPlacesSourceVenuesVenue.
 * </p>
 * <p>
 * For example:
 * </p>
 * \code
 *     NMAPlaceRequest* request = [[NMAPlaces sharedPlaces]
 *     createLookupRequestWithReferenceIdentifier:@"DM_7171" inSource:NMAPlacesSourceVenuesVenue];
 * \endcode
 *
 * \param referenceIdentifier The reference identifier of the requested NMAPlace
 * in a specified source (ie Core POI, %Venue).
 *
 * \param source The NSString of the source in lower case (for examle pvid).
 *
 * \return The %NMAPlaceRequest if the reference identifier is valid, nil otherwise
 */

- (nullable NMAPlaceRequest *)createLookupRequestWithReferenceIdentifier:(NSString *)referenceIdentifier
                                                                inSource:(NSString*)source
NS_SWIFT_NAME(makeLookupRequest(referenceIdentifier:source:));

/*!
 * Return the localized top level categories for Places Search.
 *
 * User can manually refresh the categories with refreshTopLevelCategoriesWithCompletion:
 *
 * \note The list of categories is cached. The update request to Places backend
 * is made periodically and when device locale is changed. If there is no cache
 * or cache is being updated, a nil is returned. User should try again later.
 *
 * \return An NSArray of localized NMACategory if available, nil otherwise
 */
- (nullable NSArray<NMACategory *> *)topLevelCategories;

/*!
 * Refresh the localized top level categories for Places Search.
 */
- (void)refreshTopLevelCategoriesWithCompletion:(NMAPlacesCategoriesCompletionBlock)completionBlock
NS_SWIFT_NAME(refreshTopLevelCategories(completionBlock:));

@end

NS_ASSUME_NONNULL_END

/** @} */
