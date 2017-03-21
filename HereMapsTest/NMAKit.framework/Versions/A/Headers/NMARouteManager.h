/***************************************************************
 * Copyright (c) 2011-2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>

@class NMARouteManager;
@class NMARoute;
@class NMARoutingMode;


/**
 *  The minimum number of stops to calculate a route
 */
FOUNDATION_EXPORT const NSUInteger NMARouteManagerMiniumStopsCount;

/**
 *  The maximum number of stops to calculate route calculation
 */
FOUNDATION_EXPORT const NSUInteger NMARouteManagerMaximumStopsCount;

/**
 * \addtogroup NMA_Route NMA Routing Group
 *
 * The Routing group contains classes, protocols, and enumerations
 * for describing and calculating routes.
 * The key class to this group is {@link NMARouteManager}.
 *
 * @{
 */
/**
 * Defines types of error codes that can be returned from route calculation
 * operations.
 */
typedef NS_ENUM(NSUInteger, NMARouteManagerError) {
    /** \brief There was no error, route calculation succeeded. */
    NMARouteManagerErrorNone = 0,
    /** \brief There was an unknown error. */
    NMARouteManagerErrorUnknown,
    /** \brief There was an out-of-memory error. */
    NMARouteManagerErrorOutOfMemory,
    /** \brief There was an error due to invalid parameters. */
    NMARouteManagerErrorInvalidParameters,
    /** \brief There was an error due to another request already being processed. */
    NMARouteManagerErrorInvalidOperation,
    /** \brief There was an error because no route could be found. */
    NMARouteManagerErrorGraphDisconnected,
    /**
     * \brief There was an error because no route could be found, possibly due to some option
     * (e.g. disabled highways) preventing it.
     */
    NMARouteManagerErrorGraphDisconnectedCheckOptions,
    /** \brief There was an error because no starting waypoint could be found. */
    NMARouteManagerErrorNoStartPoint,
    /** \brief There was an error because no destination waypoint could be found. */
    NMARouteManagerErrorNoEndPoint,
    /**
     * \brief There was an error because the destination point is unreachable, possibly due to
     * some option (e.g. disabled highways) preventing it.
     */
    NMARouteManagerErrorNoEndPointCheckOptions,
    /**
     * \brief There was an error because pedestrian mode was specified yet is not practical
     * (e.g. the route is too long).
     */
    NMARouteManagerErrorCannotDoPedestrian,
    /** \brief There was an error because the application user cancelled the route calculation. */
    NMARouteManagerErrorRoutingCancelled,
    /**
     * \brief There was an error because the route calculation request included options that prohibit
     * successful completion.
     */
    NMARouteManagerErrorViolatesOptions,
    /** \brief There was an error because the service could not digest the requested route parameters. */
    NMARouteManagerErrorRouteCorrupted,
    /** \brief There was an error due to invalid or missing HERE Developer credentials. */
    NMARouteManagerErrorInvalidCredentials
};

/**
 * \brief Implicit routing options that may be violated by routes returned from NMARouteManager.
 *
 */
typedef NS_OPTIONS(NSInteger, NMARouteViolatedOption) {
    /** The returned route does not violate any options */
    NMARouteViolatedOptionNone                          = 0,
    /** The route passes through a blocked road (e.g. due to construction) */
    NMARouteViolatedOptionBlockedRoad                   = 1 << 8,
    /** The route passes through a road with a time-based turn restriction */
    NMARouteViolatedOptionTurnRestriction               = 1 << 9
};

NS_ASSUME_NONNULL_BEGIN

/**
 * \brief Represents a delegate to handle NMARouteManager route calculation updates.
 *
 * Methods of this protocol are called on the main queue.
 */
@protocol NMARouteManagerDelegate<NSObject>

@required
/*!
 *  Callback upon completion of route calculation.
 *
 * \param routeManager The NMARouteManager instance which calculated the route.
 *
 * \param routes An NSArray of NMARoute objects representing alternate route
 *                   solutions, or nil if route calculation failed. The route at
 *                   index 0 is the best result found. The number of routes in
 *                   the array will be less than or equal to the resultCount
 *                   property specified in the NMARoutingMode used for the route
 *                   request.
 *
 * \param error A routing calculation error.
 *                   See NMARouteManagerError for possible error codes. If
 *                   NMARouteManagerErrorRouteUseDisabledRoads is returned then
 *                   \p violatedOptions is not empty (the returned NMARoute is valid
 *                   and can be used for navigation although it uses roads which were
 *                   disabled in the original NMARoutingMode::routingOptions options).
 * \param violatedOptions An NSArray of NSNumber objects, one per route calculated,
 *                   representing which options (if any) were violated for the
 *                   corresponding route. The NSNumber objects should be converted to
 *                   NSUInteger before checking. The value will be an OR combination of
 *                   NMARoutingOption and NMARouteViolatedOption values, or NMARouteViolatedOptionNone
 *                   if no options were violated. If route calculation failed, the array will
 *                   contain a single object containing all the routing options (if any).
 */
- (void)routeManager:(NMARouteManager *)routeManager
  didCalculateRoutes:(nullable NSArray<__kindof NMARoute *> *)routes
           withError:(NMARouteManagerError)error
     violatedOptions:(nullable NSArray<NSNumber *> *)violatedOptions
NS_SWIFT_NAME(routeManagerDidCalculate(_:routes:error:violatedOptions:));

@optional

/*!
 *  Callback for reporting the progress of route calculation; values range
 * from 0.0 (starting) to 1.0 (complete).
 *
 * \note In certain circumstances a recalculation is required and this percentage will go from 1.0 to 0.0
 *
 * \param routeManager The NMARouteManager singleton instance.
 * \param progress The progress of the current routing operation.
 */
- (void)routeManager:(NMARouteManager *)routeManager didUpdateProgress:(float)progress
NS_SWIFT_NAME(routeManagerDidUpdate(_:progress:));

@end

NS_ASSUME_NONNULL_END

NS_ASSUME_NONNULL_BEGIN

/**
 * \class NMARouteManager NMARouteManager.h "NMARouteManager.h"
 *
 * \brief Represents a manager responsible for calculating a NMARoute from a
 * list of stops and (optionally) a NMARoutingMode.
 * <p>
 * NMARouteManagerDelegate is used to monitor route calculation progress and
 * route calculation completion. Set the NMARouteManager delegate property
 * in order to receive callbacks through NMARouteManagerDelegate protocol.
 * </p>
 * <p>
 * The current status of the NMARouteManager can be checked via the busy property.
 * </p>
 * <p>NMARouteManager only supports one routing request at a time. Attempts
 * to make another request before the current request has finished will fail.</p>
 *
 * <p>NMARouteManager requires valid authentication credentials to be set via
 * NMAApplicationContext. If valid credentials are not present the API may not
 * function correctly or may stop functioning correctly in the future when server
 * side configurations change.</p>
 *
 * <p>Routing within China is supported, but routes may not cross the Chinese border.
 * Thus, any route calculation which begins, ends, or passes through China and involves
 * one or more other countries will fail.</p>
 */
@interface NMARouteManager : NSObject

/**
 * Returns the %NMARouteManager singleton instance.
 *
 * \note Use this method to obtain a %NMARouteManager instance. Do not call
 * init directly.
 *
 * \return shared %NMARouteManager instance
 */
+ (NMARouteManager *)sharedRouteManager;

/**
 * The %NMARouteManagerDelegate that listens for messages from the
 * %NMARouteManager.
 */
@property (nullable, nonatomic, weak) id<NMARouteManagerDelegate> delegate;

/*!
 * Indicates whether or not the NMARouteManager is currently calculating a route.
 *
 * \note Any requests made while the NMARouteManager is busy will fail.
 */
@property (nonatomic, readonly, getter = isBusy) BOOL busy;

/*!
 * \brief Starts a route calculation with the given stop list and the default NMARoutingMode
 *
 * <p>
 * The array of stops used to calculate the route must have at least two items. Any of
 * the following may be included in any combination:
 * <ol>
 * <li> NMAGeoCoordinates
 * <li> NMAPlace
 * <li> NMAPlaceLocation
 * <li> NMAWaypoint
 * </ol>
 * </p>
 * <p>
 * If a request is made while a previous request is still in progress, this method will
 * return NO and no callback will be sent to the delegate. If there is not another request
 * in progress but the parameters of the current request are invalid, this method will
 * return NO and a callback will be sent to the delegate.
 * </p>
 *
 * \note See NMARoutingMode for the default routing mode properties.
 *
 * \note NMARouteManagerDelegate routeManager:didCalculateRoutes:withError:violatedOptions:
 * will be called upon success. The returned route will contain a list of NMAWayPoints
 * based on the stop locations; the original stops will be not be returned.
 *
 * \param stops A list of stops to route between
 * \return YES if the route calculation request was made successfully, NO otherwise
 */
- (BOOL)calculateRouteWithStops:(NSArray *)stops
NS_SWIFT_NAME(calculateRoute(stops:));

/*!
 *  Starts a route calculation with the give stop list and routing mode.
 *
 * \note NMARouteManagerDelegate routeManager:didCalculateRoutes:withError:violatedOptions:
 * will be called upon completion.
 * \sa \link calculateRouteWithStops:\endlink
 *
 * \param stops A list of stops to route between
 * \param mode The NMARoutingMode to use for route calculation
 * \return YES if route calculation was successful, NO otherwise
 */
- (BOOL)calculateRouteWithStops:(NSArray *)stops routingMode:(NMARoutingMode *)mode
NS_SWIFT_NAME(calculateRoute(stops:mode:));

/*!
 * \brief Cancels the current route calculation.
 * <p>
 * If route calculation has been started, calling this method cancels the
 * calculation and then notifies the delegate by way of
 * calling routeManager:didCalculateRoutes:withError:violatedOptions: with error code
 * NMARouteManagerErrorRoutingCancelled.
 * If routing calculation could not be cancelled (e.g. no existing calculation
 * is being performed), the delegate will not be notified and NO will be returned
 * from this method.</p>
 *
 * \return YES if the cancellation can be processed, NO otherwise
 */
- (BOOL)cancel;

@end

NS_ASSUME_NONNULL_END

/** @}  */
