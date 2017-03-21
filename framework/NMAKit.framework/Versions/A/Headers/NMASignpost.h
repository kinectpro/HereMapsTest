/***************************************************************
 * Copyright (c) 2011-2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>

/**
 * \addtogroup NMA_Route NMA Routing Group
 * @{
 */


/**
 * \class NMASignpost NMASignpost.h "NMASignpost.h"
 *
 * This class stores signpost information along the Route.
 *
 */
@interface NMASignpost : NSObject

/**
 *  The exit text of the signpost.
 */
@property (nullable, nonatomic, readonly) NSString *exitText;

@end

/** @} */
