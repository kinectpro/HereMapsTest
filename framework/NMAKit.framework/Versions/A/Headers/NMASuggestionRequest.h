/*
 * Copyright (c) 2015-2017 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMARequest.h"

/**
 * \addtogroup NMA_Search NMA Search Group
 * @{
 */

/**
 * \class NMASuggestionRequest NMASuggestionRequest.h "NMASuggestionRequest.h"
 *
 * Represents a request to retrieve a list of search terms.
 *
 * \deprecated This class is deprecated as of release 3.3. Please use NMAAutoSuggestionRequest
 */

DEPRECATED_MSG_ATTRIBUTE("This class is deprecated since release 3.3. Please use NMAAutoSuggestionRequest")
@interface NMASuggestionRequest : NMARequest

/**
 * The text format of the request results.
 *
 * \note The default value is NMATextFormatHTML.
 */
@property (nonatomic) NMATextFormat textFormat;

@end

/** @} */
