/***************************************************************
 * Copyright (c) 2011-2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import "NMARequest.h"

/**
 * \addtogroup NMA_Search NMA Search Group
 * @{
 */

/**
 * \class NMAAutoSuggestionRequest NMAAutoSuggestionRequest.h "NMAAutoSuggestionRequest.h"
 *
 * Represents a request to retrieve a list of suggested search terms, instant results and refined
 * search links related to a specified location context and partial search term.
 *
 * IMPORTANT: This is a Beta API, and is subject to change without notice.
 */
@interface NMAAutoSuggestionRequest : NMARequest

/**
 * The text format of the request results.
 *
 * \note The default value is NMATextFormatHTML.
 */
@property (nonatomic) NMATextFormat textFormat;

@end

/** @} */
