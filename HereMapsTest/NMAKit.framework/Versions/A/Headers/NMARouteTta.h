/***************************************************************
 * Copyright (c) 2011-2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

/**
 * \addtogroup NMA_Route NMA Routing Group
 * @{
 */

/**
 * Identifiers for detailed explanation of travel duration (NMARoute::duration) estimates relating
 * to a route.
 *
 * \note This is a bitwise enum. If none of the bit is set, NMARouteDurationDetailAccurate is assumed
 */
typedef NS_OPTIONS(NSUInteger, NMARouteDurationDetail) {
    /** \brief The estimate is accurate. */
    NMARouteDurationDetailAccurate = 0,
    /** \brief The route uses a road that is blocked. */
    NMARouteDurationDetailBlockedRoad = 1 << 0,
    /** \brief The route uses a road with carpool restriction. */
    NMARouteDurationDetailCarPool = 1 << 1,
    /** \brief The route uses a restricted turn. */
    NMARouteDurationDetailRestrictedTurn = 1 << 2
};

/**
 * \class NMARouteTta NMARouteTta.h "NMARouteTta.h"
 *
 * Describes Time to Arrival details of a NMARoute or a subleg of a
 * NMARoute.
 */
@interface NMARouteTta : NSObject

/**
 * Duration in seconds. -1 if not available.
 */
@property (nonatomic, readonly) NSTimeInterval duration;

/*
 * Details of this estimated time to arrival. See NMARouteDurationDetail.
 */
@property (nonatomic, readonly) NMARouteDurationDetail details;

/**
 * Whether a blocked road is present.
 */
@property (nonatomic, readonly, getter = isBlocked) BOOL blocked;

@end

/** @}  */
