/***************************************************************
 * Copyright (c) 2011-2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>

@class NMAExtendedAttribute;
@class NMAPlaceLocation;
@class NMALink;
@class NMAMediaCollectionPage;
@class NMARatings;
@class NMACategory;
@class NMAContactDetail;

/**
 * \addtogroup NMA_Search NMA Search Group
 * @{
 */

/**
 * \class NMAPlace NMAPlace.h "NMAPlace.h"
 *
 * \brief Represents a set of data about a physical place.
 *
 * A %NMAPlace acts as a container for various information about a place,
 * which itself is a point of interest such as a popular restaurant, a park, or
 * someone's home.
 *
 * \note A NMAPlace can contain attributes, collections of media
 * about the place, and key-value pairs of related places.
 *
 */
@interface NMAPlace : NSObject

/**
 * Unique consistent identifier for the place represented by this NMAPlace instance
 *
 * \note The identifier value is consistent across application sessions.
 * Applications that want to keep a reference to a specific place can
 * store this identifier  for subsequent linking to additional resources.
 */
@property (nonnull, nonatomic, readonly) NSString *uniqueId;

/**
 * URL to an external web page that represents the NMAPlace.
 *
 * \note Applications are encouraged to provide web links to places they display
 * information about. Atempts to read this property could return an empty string.
 */
@property (nonnull, nonatomic, readonly) NSString *viewUrl;

/**
 * The name of the NMAPlace and localized to language preference defined in NMARequest (if possible)
 *
 * \note Attempts to read this property could return an empty string.
 */
@property (nonnull, nonatomic, readonly) NSString *name;

/**
 * Gets the NSDictionary for the alternative names of NMAPlace in a list of mapping languages and alternative names
 *
 * \note An alternative name for a place is optional. Attempts to read this
 * property could return nil.
 */
@property (nullable, nonatomic, readonly) NSDictionary<NSString *, NSString *> *alternativeNames;

/**
 * The NMAPlaceLocation of the NMAPlace.
 */
@property (nonnull, nonatomic, readonly) NMAPlaceLocation *location;

/**
 * The NSArray of NMACategory objects linking to categories
 * that have been assigned to the NMAPlace.
 *
 * \note A NMACategory object extends the standard link object with an optional
 * icon link pointing to an icon appropriate for that category. Categories for
 * a place is optional. Attempts to read this property could return nil.
 */
@property (nullable, nonatomic, readonly) NSArray<NMACategory *> *categories;

/**
 * An URL of icon that represents the NMAPlace.
 *
 * \note Application can download the icon online with this URL, but it
 * needs to use its own icon for offline.
 */
@property (nonnull, nonatomic, readonly) NSString *iconUrl;

/**
 * Array of NMAContactDetail objects that provide information on how to
 * contact the place.

 * \note Contact information for a place is optional. Attempts to read this
 * property could return nil.
 */
@property (nullable, nonatomic, readonly) NSArray<NMAContactDetail *> *contacts;

/**
 * The string containing the attribution string for this NMAPlace.
 *
 * example :
 *   Provided by <a href=\"http://originalArticle...\">Qype</a> user <a href=\"http://userProfile...\">Max Mustermann</a>
 *
 * \note Attribution text for a place is optional. Attempts to read this
 * property could return nil.
 */
@property (nullable, nonatomic, readonly) NSString *attributionText;

/**
 * \brief Link to the supplier of the NMAPlace.
 * <p>
 * The supplier link extends the standard link object with an optional icon
 * link that points to the supplier's brand icon.
 * </p>
 * <p>
 * Example:
 * </p>
 * \code
 *   "name": "Qype",
 *   "url": "http://...",
 *   "icon": "http://..."
 * \endcode
 *
 * \note A supplier link for a place is optional. Attempts to read this
 * property could return nil.
 */
@property (nullable, nonatomic, readonly) NMALink *supplier;

/**
 * The user ratings for the NMAPlace.
 *
 * \note User ratings for a place are optional. Attempts to read this
 * property could return nil.
 */
@property (nullable, nonatomic, readonly) NMARatings *userRatings;


// Extended attributes

/**
 * NSArray of NMAExtendedAttribute objects representing additional information about
 * an NMAPlace.
 * <p>
 * An extensible collection of attributes can include:
 * </p>
 * <ul>
 * <li>payment - NMAExtendedAttribute</li>
 * <li>openingHours - NMAExtendedAttribute</li>
 * <li>annualClosings - NMAExtendedAttribute</li>
 * <li>price - NMAExtendedAttribute</li>
 * <li>nearestLandmark - NMAExtendedAttribute</li>
 * <li>languagesSpoken - NMAExtendedAttribute</li>
 * <li>availableParking - NMAExtendedAttribute</li>
 * <li>smoking - NMAExtendedAttribute</li>
 * <li>disabledAccess - NMAExtendedAttribute</li>
 * </ul>
 *
 * \note Extended attribute for a place is optional. Attempts to read this
 * property could return nil.
 *
 * \return The list of NMAExtendedAttribute objects
 *
 */
@property (nullable, nonatomic, readonly) NSArray<NMAExtendedAttribute *> *extendedAttributes;

// Media collections

/**
 * NMAMediaCollectionPage of NMAMediaImage objects. See also NMAMediaCollectionPage#mediaContents
 * related to this NMAPlace.
 *
 * \note Image content for a place is optional. Attempts to read this
 * property could return nil.
 */
@property (nullable, nonatomic, readonly) NMAMediaCollectionPage *images;

/**
 * NMAMediaCollectionPage of NMAMediaReview objects. See also NMAMediaCollectionPage#mediaContents
 * related to this NMAPlace.
 *
 * \note Review content for a place is optional. Attempts to read this
 * property could return nil.
 */
@property (nullable, nonatomic, readonly) NMAMediaCollectionPage *reviews;

/**
 * NMAMediaCollectionPage of NMAMediaEditorial objects. See also NMAMediaCollectionPage#mediaContents
 * related to this NMAPlace.
 *
 * \note Editorial content for a place is optional. Attempts to read this
 * property could return nil.
 */
@property (nullable, nonatomic, readonly) NMAMediaCollectionPage *editorials;

/**
 * NMAMediaCollectionPage of NMAMediaRating objects. See also NMAMediaCollectionPage#mediaContents
 * related to this NMAPlace.
 *
 * \note Rating content for a place is optional. Attempts to read this
 * property could return nil.
 */
@property (nullable, nonatomic, readonly) NMAMediaCollectionPage *ratings;

// Related attributes

/**
 * The NSDictionary of related places (where available) that might
 * also interest an application user.
 *
 * The NSDictionary is keyed by a localized title to language preference defined
 * in NMARequest (if possible) of the related places (for example, "Nearby",
 * "public-transport"), while the associated value is a link presented in class derived
 * from NMALink(i.e.NMADiscoveryLink, NMAPlaceLink,etc ...).
 *
 * \note Atempts to read this property could return nil.
 */
@property (nullable, nonatomic, readonly) NSDictionary<NSString *, __kindof NMALink *> *related;

/**
 * Gets the link for getting options for reporting a place because,
 * for example, it contains inappropriate content or the place does not exist.
 *
 * \note A reporting link for a place is optional. Attempts to read this
 * property could return nil.
 */
@property (nullable, nonatomic, readonly) NMALink *reportingLink;

/**
 * Get reference identifiers for a specific source. For example, a place
 * can have a reference to an extruded building object in the map. The
 * reference identifiers can be retrieved by calling this method with source
 * NMAPlacesSourceBuilding.
 * <p>
 * Index 0 is the primary reference identifier for the place.
 * </p>
 * \note A reference identifier will not be returned if it has not been queried
 * with the \link NMARequest::addSource:\endlink method.
 *
 * \param source %NSString specifying the source
 * \return An NSArray of reference identifiers. Return nil if reference
 * identifier does not exist.
 */
- (nullable NSArray<NSString *> *)referenceIdentifiersForSource:(nonnull NSString *)source
NS_SWIFT_NAME(referenceIdentifiers(forSource:));

@end
/** @} */
