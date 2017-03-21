/***************************************************************
 * Copyright (c) 2011-2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import "NMARequest.h"

/**
 * \addtogroup NMA_Search NMA Search Group
 * @{
 */

/**
 * \class NMAPlaceRequest NMAPlaceRequest.h "NMAPlaceRequest.h"
 *
 * Represents a request to retrieve an NMAPlace object.
 *
 */
@interface NMAPlaceRequest : NMARequest

/**
 * To request an image media with specific width-height
 * dimensions. At least one of the sizes (width or height) needs to be valid
 * (greater than 0).
 * </p>
 * <p>
 * Note taht the provided width-height are used as upper boundaries
 * for the dimensions of the returned images.
 * </p>
 * <p>
 * For example:
 * </p>
 * \code
 * image_dimensions=w32-h32,w64-h64
 * image_dimensions=w32-h32,w300
 * image_dimensions=h200
 * \endcode
 *
 * \param width The image width.
 * \param height The image height.
 */
- (void)addImageSizeWithWidth:(NSInteger)width
                       height:(NSInteger)height
NS_SWIFT_NAME(addImageSize(width:height:));

/**
 * The text format of the request results.
 *
 * \note The default value is NMATextFormatHTML.
 */
@property (nonatomic) NMATextFormat textFormat;

@end

/** @} */
