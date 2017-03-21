/***************************************************************
 * Copyright (c) 2011-2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>

/**
 * \addtogroup NMA_Search NMA Search Group
 * @{
 * \class NMAAddress NMAAddress.h "NMAAddress.h"
 * Represents address information for a geographic location.
 * \sa NMAPlaceLocation
 */
@interface NMAAddress : NSObject

/**
 * The floor number in a multi-story building.
 */
@property (nullable, nonatomic, strong) NSString *floorNumber;

/**
 * The house number.
 */
@property (nullable, nonatomic, strong) NSString *houseNumber;

/**
 * The suite number or unit name.
 */
@property (nullable, nonatomic, strong) NSString *suiteNumberOrName;

/**
 * The street name.
 */
@property (nullable, nonatomic, strong) NSString *street;

/**
 * The district name.
 */
@property (nullable, nonatomic, strong) NSString *district;

/**
 * The county name.
 */
@property (nullable, nonatomic, strong) NSString *county;

/**
 * The city name.
 */
@property (nullable, nonatomic, strong) NSString *city;

/**
 * The state name.
 */
@property (nullable, nonatomic, strong) NSString *state;

/**
 * The postal code.
 */
@property (nullable, nonatomic, strong) NSString *postalCode;

/**
 * The country code.
 *
 * \note The country code defined in "ISO 3166-1 alpha-3" three letter format.
 */
@property (nullable, nonatomic, strong) NSString *countryCode;

/**
 * The country name.
 */
@property (nullable, nonatomic, strong) NSString *countryName;

/**
 * The descriptive label for the %NMAAddress.
 */
@property (nullable, nonatomic, strong) NSString *label;

/**
 * The %NSString representation of the address formatted according to local standards.
 */
@property (nonnull, nonatomic, strong) NSString *formattedAddress;

/**
 * Gets the %NSDictionary containing all additional key-value
 * %NMAAddress data.
 *
 * \return The %NSDictionary of additional key-value data
 */
- (nonnull NSDictionary<NSString *, NSString *> *)additionalData;

@end
/** @}  */
