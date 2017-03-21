/***************************************************************
 * Copyright (c) 2011-2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>

@class NMALink;

/**
 * \addtogroup NMA_Search NMA Search Group
 * @{
 */

/**
 * Represents available NMAMedia derived objects.
 */
typedef NS_ENUM(NSUInteger, NMAMediaType) {
    /** \brief NMAMedia object unknown */
    NMAMediaTypeUnknown = 0,
    /** \brief NMAMediaEditorial */
    NMAMediaTypeEditorial,
    /** \brief NMAMediaImage */
    NMAMediaTypeImage,
    /** \brief NMAMediaReview */
    NMAMediaTypeReview,
    /** \brief NMAMediaRating */
    NMAMediaTypeRating
};

/**
 * \class NMAMedia NMAMedia.h "NMAMedia.h"
 *
 * \brief Represents the base interface for additional rich content about
 * a NMAPlace.
 * <p>
 * The following specialized content might be available:
 * <ul>
 * <li>images</li>
 * <li>editorials</li>
 * <li>reviews</li></ul></p>
 *
 */
@interface NMAMedia : NSObject

/**
 * The %NSString representation of the attribution text for the
 * %NMAMedia, according to the terms and conditions of the originating source.
 */
@property (nullable, nonatomic, readonly) NSString *attributionText;

/**
 * The %NMALink to the resource representing the supplier of
 * the content (the object provides details on the origin of the information).
 */
@property (nullable, nonatomic, readonly) NMALink *supplierLink;

/**
 * The %NMALink to the origin of the information,
 * usually a website of the supplier. The type attribute of the link
 * might need to be checked to see if there is a better user agent than a web
 * browser for handling the media type of the linked-to resource.
 */
@property (nullable, nonatomic, readonly) NMALink *viaLink;

/**
 * The specialized content type.
 */
@property (nonatomic, readonly) NMAMediaType type;

@end

/** @} */
