/***************************************************************
 * Copyright (c) 2011-2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

/**
 * \addtogroup NMA_Common  NMA Common Group
 *
 * The Common group includes classes, protocols, and enumerations
 * that are generally used by other packages in the iOS SDK.
 * Some important classes in this group are
 * {@link NMAGeoCoordinates} and {@link NMAPositioningManager}.
 *
 * @{
 */

/**
 *  The minimum Z Index for an NMAMapObject
 */
FOUNDATION_EXPORT const NSUInteger NMAMapObjectMinimumZIndex;

/**
 *  The maximum Z Index for an NMAMapObject
 */
FOUNDATION_EXPORT const NSUInteger NMAMapObjectMaximumZIndex;


/**
 * Lower limit of the NMAMapView zoomLevel property.
 */
FOUNDATION_EXPORT const float NMAMapViewMinimumZoomLevel;

/**
 * Upper limit of the NMAMapView zoomLevel property.
 */
FOUNDATION_EXPORT const float NMAMapViewMaximumZoomLevel;

/**
 *  Represents fixed locations or regions within a bounding rectangle.
 */
typedef NS_ENUM(NSUInteger, NMALayoutPosition) {
    NMALayoutPositionTopLeft,
    NMALayoutPositionTopCenter,
    NMALayoutPositionTopRight,
    NMALayoutPositionCenterLeft,
    NMALayoutPositionCenter,
    NMALayoutPositionCenterRight,
    NMALayoutPositionBottomLeft,
    NMALayoutPositionBottomCenter,
    NMALayoutPositionBottomRight
};

/**
 * \brief Error codes that may be returned from places search requests.
 */
typedef NS_ENUM(NSUInteger, NMARequestError) {
    /** \brief No error.                                                   */
    NMARequestErrorNone = 0,
    /** \brief Unknown error.                                              */
    NMARequestErrorUnknown,
    /** \brief Request is missing an address parameter.                    */
    NMARequestErrorAddressMissing,
    /** \brief Location context is invalid.                                */
    NMARequestErrorLocationContextInvalid,
    /** \brief Request is missing location context parameter.              */
    NMARequestErrorLocationContextMissing,
    /** \brief Request is missing a country code in the address parameter. */
    NMARequestErrorCountryCodeMissing,
    /** \brief Request missing search text parameter.                      */
    NMARequestErrorSearchTextMissing,
    /** \brief Invalid query parameter.                                    */
    NMARequestErrorInvalidParameter,
    /** \brief Network communications error.                               */
    NMARequestErrorNetworkCommunication,
    /** \brief Backend server unreachable.                                 */
    NMARequestErrorNetworkServer,
    /** \brief Request input missing.                                      */
    NMARequestErrorNetworkEmptyInput,
    /** \brief Application ID and/or token are missing or invalid.         */
    NMARequestErrorInvalidCredentials,
    /** \brief Request failed due to an HTTP error.                        */
    NMARequestErrorHttp,
    /** \brief Unknown network error.                                      */
    NMARequestErrorNetworkUnknown,
    /** \brief Functionality not supported                                 */
    NMARequestErrorNotSupported,
    /**
     * \brief An entity is not ready. All poll functions return this when one needs to
     * poll again.  Also if an operation is in progress
      */
    NMARequestErrorNotReady,
    /** \brief When something was not found                                */
    NMARequestErrorNotFound,
    /** \brief When resource already exists                                */
    NMARequestErrorAlreadyExists,
    /** \brief Out of memory                                               */
    NMARequestErrorOutOfMemory,
    /** \brief When operation fails (e.g.extracting of file failed)        */
    NMARequestErrorOperationFailed,
    /** \brief Operation aborted by user                                   */
    NMARequestErrorAborted,
    /** \brief Search index failure                                        */
    NMARequestErrorFinderIndexFailure,
    /** \brief Resource moved (e.g. resource URI changed)                  */
    NMARequestErrorMovedPermanently,
    /** \brief Resource contend remains the same                           */
    NMARequestErrorNotModified,
    /** \brief Invalid request (places component might need to be updated) */
    NMARequestErrorBadRequest,
    /** \brief Resource no longer exists                                   */
    NMARequestErrorResourceGone,
    /** \brief An error occured during document parsing (json, etc.)       */
    NMARequestErrorParse,
    /** \brief Request timeout                                             */
    NMARequestErrorTimeout
};

/** @}  */
