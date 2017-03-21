/***************************************************************
 * Copyright (c) 2011-2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>
#import "NMAMapObject.h"

/**
 * \addtogroup NMA_Map NMA Mapping Group
 * @{
 */

NS_ASSUME_NONNULL_BEGIN

/**
 * \class NMAMapContainer NMAMapContainer.h "NMAMapContainer.h"
 *
 * \brief A container of NMAMapObject instances, containers can be added to a NMAMapView
 * instance.
 *
 * Applications can, as necessary, add or remove certain
 * types of %NMAMapObject objects to or from a %NMAMapContainer (refer to
 * \link addMapObject:\endlink for details). A %NMAMapContainer is also
 * useful for grouping together %NMAMapObject objects to allow application operations
 * on entire groups of map objects without requiring an iterative approach to
 * inspecting or changing the state of each individual %NMAMapObject (e.g. for changing
 * their visibility).
 *
 * You can use the \p visible property to control
 * whether the objects in the container are visible. If it's set to YES, then
 * the visibility settings of each map object in the container are used. But
 * unlike other map objects, %NMAMapContainer does not support the use of
 * visibility masks, so you cannot set container visibility on a zoom level basis.
 *
 * \note The zOrder of an NMAMapObject instance in a container is relative only to other
 * NMAMapObject instances within the same container. Note that containers are derived
 * from NMAMapObject also have zOrder.
 */
@interface NMAMapContainer : NMAMapObject

/**
 * The %NSArray of NMAMapObject objects within the %NMAMapContainer.
 */
@property (nonatomic, readonly, copy) NSArray<__kindof NMAMapObject *> *mapObjects;

/**
 * \brief Adds a %NMAMapObject to the %NMAMapContainer.
 *
 * %NMAMapObject types that can be added to a %NMAMapContainer are:
 *
 * <ul>
 * <li>NMAMapMarker</li>
 * <li>NMAMapCircle</li>
 * <li>NMAMapPolygon</li>
 * <li>NMAMapPolyline</li>
 * </ul>
 *
 * \note Attempts to add an object twice to the same container will be ignored.
 *
 * \param aMapObject A %NMAMapObject to be added to the %NMAMapContainer.
 *
 * \return YES if the %NMAMapObject was added successfully, NO otherwise.
 *
 * \sa \link removeMapObject:\endlink
 */
- (BOOL)addMapObject:(NMAMapObject *)aMapObject
NS_SWIFT_NAME(add(_:));

/**
 * Removes the specified %NMAMapObject from the %NMAMapContainer.
 *
 * \note If the specified %NMAMapObject is not contained within the %NMAMapContainer,
 * the container will be unchanged.
 *
 * \param aMapObject A %NMAMapObject to remove from the %NMAMapContainer.
 *
 * \return YES if the %NMAMapObject was removed successfully, NO otherwise.
 *
 * \sa removeAllMapObjects
 */
- (BOOL)removeMapObject:(NMAMapObject *)aMapObject
NS_SWIFT_NAME(remove(_:));

/**
 * Removes all NMAMapObject objects from the %NMAMapContainer.
 *
 * \return YES if all %NMAMapObject objects were removed successfully, NO otherwise.
 */
- (BOOL)removeAllMapObjects
NS_SWIFT_NAME(removeAll());

@end

NS_ASSUME_NONNULL_END

/** @}  */
