/***************************************************************
 * Copyright (c) 2011-2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>

/**
 * \addtogroup NMA_Search NMA Search Group
 * @{
 */

NS_ASSUME_NONNULL_BEGIN

/**
 * \class NMAContactDetail NMAContactDetail.h "NMAContactDetail.h"
 *
 * Represents detailed information about a contact for a NMAPlace.
 *
 * For example, if a NMAPlace has among its known contacts array the
 * phone number 555-1234, use this interface to access details about that particular
 * contact's label ("Phone") and value ("555-1234").
 *
 */
@interface NMAContactDetail : NSObject

/**
 * The localized label describing the mechanism by which application end users
 * can contact the place.
 */
@property (nonatomic, readonly) NSString *label;

/**
 * The string value appropriate to the localized label.
 */
@property (nonatomic, readonly) NSString *value;

/**
 * The type (email, fax, phone, website, etc.) of the NMAContactDetail.
 */
@property (nonatomic, readonly) NSString *type;

@end

NS_ASSUME_NONNULL_END

/** @} */
