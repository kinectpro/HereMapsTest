/***************************************************************
 * Copyright (c) 2011-2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

// Common Category String
// defined http://developer.here.com/places#_48_INSTANCE_1FN2Ea4jadS4_=http%3A%2F%2Fdeveloper.here.com%2Fdocs%2Fplaces%2Findex.html%3F

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT NSString* const CATEGORY_ACCOMODATION;
FOUNDATION_EXPORT NSString* const CATEGORY_ADMINISTRATIVE_AREAS_BUILDINGS;
FOUNDATION_EXPORT NSString* const CATEGORY_EAT_DRINK;
FOUNDATION_EXPORT NSString* const CATEGORY_GOING_OUT;
FOUNDATION_EXPORT NSString* const CATEGORY_LEISURE_OUTDOOR;
FOUNDATION_EXPORT NSString* const CATEGORY_NATURAL_GEOGRAPHICAL;
FOUNDATION_EXPORT NSString* const CATEGORY_SHOPPING;
FOUNDATION_EXPORT NSString* const CATEGORY_SIGHTS_MUSEUMS;
FOUNDATION_EXPORT NSString* const CATEGORY_TRANSPORT;
FOUNDATION_EXPORT NSString* const CATEGORY_PETROL_STATION;
FOUNDATION_EXPORT NSString* const CATEGORY_ATM_BANK_EXCHANGE;
FOUNDATION_EXPORT NSString* const CATEGORY_TOILET_REST_AREA;
FOUNDATION_EXPORT NSString* const CATEGORY_HOSPITAL_HEALTH_CARE_FACILITY;
FOUNDATION_EXPORT NSString* const CATEGORY_NONE;

NS_ASSUME_NONNULL_END

/**
 * \addtogroup NMA_Search NMA Search Group
 * @{
 */

/**
 * Defines types of categories filter.
 */
typedef NS_ENUM(NSUInteger, NMACategoryFilterType) {
    /** No category. */
    NMACategoryFilterTypeNone = 0,
    /** The accommodation category.*/
    NMACategoryFilterTypeAccommodation,
    /** The administrative-areas-buildings category. */
    NMACategoryFilterTypeAdministrativeAreasBuildings,
    /** The eat-drink category. */
    NMACategoryFilterTypeEatDrink,
    /** The going-out category. */
    NMACategoryFilterTypeGoingOut,
    /** The leisure-outdoor category. */
    NMACategoryFilterTypeLeisureOutdoor,
    /** The natural-geographical category. */
    NMACategoryFilterTypeNaturalGeographical,
    /** The shopping category. */
    NMACategoryFilterTypeShopping,
    /** The sights-museums category. */
    NMACategoryFilterTypeSightsMuseums,
    /** The transport category. */
    NMACategoryFilterTypeTransport,
    /** The petrol-station category. */
    NMACategoryFilterTypePetrolStation,
    /** The atm-bank-exchange category. */
    NMACategoryFilterTypeAtmBankExchange,
    /** The toilet-rest-area category. */
    NMACategoryFilterTypeToiletRestArea,
    /** The hospital-health-care-facility category. */
    NMACategoryFilterTypeHospitalHealthCareFacility
};


/**
 * \class NMACategoryFilter NMACategoryFilter.h "NMACategoryFilter.h"
 *
 * Represents a filter used when performing a search for popular places within
 * a specific location (exploring). The filter limits a search to specified categories.
 */
@interface NMACategoryFilter : NSObject

/*!
 * Adds a NMACategoryFilterType to the NMACategoryFilter.
 *
 * \param categoryFilterType An NMACategoryFilterType filter
 */
- (void)addCategoryFilterFromType:(NMACategoryFilterType)type
NS_SWIFT_NAME(add(fromType:));

/*!
 * Adds an NMACategory's uniqueId to the NMACategoryFilter.
 *
 * \param uniqueId An NSString for NMACategory's uniqueId
 */
- (void)addCategoryFilterFromUniqueId:(nonnull NSString *)uniqueId
NS_SWIFT_NAME(add(fromUniqueId:));

/*!
 * Returns a stringified NMACategoryFilter, within which individual
 * categories are separated by commas.
 *
 * \return The stringified, comma-delimited set of categories.
 */
- (nonnull NSString *)toString;

@end

/** @} */
