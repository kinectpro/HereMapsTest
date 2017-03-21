/***************************************************************
 * Copyright (c) 2011-2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>

/**
 * \addtogroup NMA_Route NMA Routing Group
 * @{
 */

@class NMARoadElement;

/**
 * Defines types of route element.
 */
typedef NS_ENUM(NSInteger, NMARouteElementType) {
    /** Road Element */
    NMARouteElementRoad = 1,
    /** invalid  */
    NMARouteElementInvalid
};

/**
 * \class NMARouteElement NMARouteElement.h "NMARouteElement.h"
 *
 * Represents a generic container for an element of a route.
 */
@interface NMARouteElement : NSObject

/**
 * The route element type.
 */
@property (nonatomic, readonly) NMARouteElementType type;

/**
 * Road element of the route element.
 *
 * \note nil if type of the route element is not %NMARouteElementRoad
 */
@property (nullable, nonatomic, readonly) NMARoadElement *roadElement;

@end
/**  @}  */
