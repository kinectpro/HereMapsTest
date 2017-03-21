/***************************************************************
 * Copyright (c) 2011-2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>
#import "NMATypes.h"

@class NMAMapTileLayer;
@class NMAGeoBoundingBox;

/**
 * \addtogroup NMA_Map NMA Mapping Group
 * @{
 */

/**
 * An interface for providing tile bitmap data to an NMAMapTileLayer instance.
 *
 * \note The methods of this protocol will be called on an internal NMA map rendering queue.
 * Blocking this queue for extended periods of time will adversely effect map rendering
 * performance.
 */
@protocol NMAMapTileLayerDataSource <NSObject>

@optional

/**
 * \brief Indicates if the specified tile should be rendered.
 *
 * <p>If this method returns NO then a further call to request tile bitmap data or tile URL will
 * not be made. Not implementing this protocol method is equivalent to returning YES.</p>
 *
 * <p>At each zoomLevel the framework expects the "world" to be rendered on (2^zoomLevel)^2 tiles.</p>
 *
 * <p>The x and y parameters indicate which tile is being requested for the given zoom level:
 * <ul>
 *      <li>At zoom level 3 the framework will ask you for 8 x 8 tiles</li>
 *      <li>At zoom level 4 the framework will ask you for 16 x 16 tiles</li>
 *      <li>...
 * </ul></p>
 *
 * \param mapTileLayer NMAMapTileLayer instance that is requesting the tile.
 * \param x X coordinate of the tile being requested in the range 1..(2^zoomLevel).
 * \param y Y coordinate of the tile being requested in the range 1..(2^zoomLevel).
 * \param zoomLevel Zoom level of the tile being requested in the range NMAMapViewMinimumZoomLevel..NMAMapViewMaximumZoomLevel.
 *                  The zoomLevel parameter value may NOT have the same value as the zoomLevel property of
 *                  the NMAMapView to which the NMAMapTileLayer has been added.
 *
 * \return YES if the requested tile should be rendered, NO otherwise.
 *
 * \note This method is called on an internal NMA map rendering queue. Blocking for extended
 * periods of time will impact map rendering performance.
 */
- (BOOL)mapTileLayer:(nonnull NMAMapTileLayer *)mapTileLayer
          hasTileAtX:(NSUInteger)x
                   y:(NSUInteger)y
           zoomLevel:(NSUInteger)zoomLevel;

/**
 * \brief Returns a URL from which the tile bitmap can be downloaded
 *
 * <p>Implement this method if you wish to have the framework download tile bitmap data from a URL
 * you provide. This method will be called whenever the map view needs bitmap data to render the
 * specified tile.</p>
 *
 * <p>This method is provided as a convenience for the common case of downloading bitmaps tiles
 * from a URL. The data returned from the URL must be in either png and jpg format.</p>
 * <p>
 * See mapTileLayer:hasTileAtX:y:zoomLevel: for a detailed description of the x, y and zoomLevel parameters.
 *
 * \note This method will not be called if you also implement mapTileLayer:requestTileAtX:y:zoomLevel:tileRequest
 * or mapTileLayer:requestTileAtX:y:zoomLevel
 *
 * \note This method is called on an internal NMA map rendering queue. Blocking for extended
 * periods of time will impact map rendering performance.
 *
 * \param mapTileLayer NMAMapTileLayer instance that is requesting the tile URL.
 * \param x X coordinate of the tile being requested in the range 1..(2^zoomLevel).
 * \param y Y coordinate of the tile being requested in the range 1..(2^zoomLevel).
 * \param zoomLevel Zoom level of the tile being requested in the range NMAMapViewMinimumZoomLevel..NMAMapViewMaximumZoomLevel.
 *                  The zoomLevel parameter value may NOT have the same value as the zoomLevel property of
 *                  the NMAMapView to which the NMAMapTileLayer has been added.
 *
 * \return URL to fetch the requested tile from.
 */
- (nonnull NSString *)mapTileLayer:(nonnull NMAMapTileLayer *)mapTileLayer
                     urlForTileAtX:(NSUInteger)x
                                 y:(NSUInteger)y
                         zoomLevel:(NSUInteger)zoomLevel;

/**
 * \brief Requests raw tile bitmap data for the specified tile.
 *
 * <p>Implement this method if you wish to supply raw tile bitmap data. This method will be called
 * whenever the map view needs bitmap data to render the specified tile.</p>
 *
 * <p>See mapTileLayer:hasTileAtX:y:zoomLevel: for a detailed description of the x, y and
 * zoomLevel parameters.</p>
 *
 * <p>Implementing this method will prevent mapTileLayer:urlForTileAtX:y:zoomLevel: and
 * mapTileLayer:requestTileAtX:y:zoomLevel:tileRequest from being called.</p>
 *
 * \note This method is called on an internal NMA map rendering queue. Blocking for extended
 * periods of time will impact map rendering performance.
 *
 * \param mapTileLayer NMAMapTileLayer instance that is requesting the tile bitmap.
 * \param x X coordinate of the tile being requested in the range 1..(2^zoomLevel).
 * \param y Y coordinate of the tile being requested in the range 1..(2^zoomLevel).
 * \param zoomLevel Zoom level of the tile being requested in the range NMAMapViewMinimumZoomLevel..NMAMapViewMaximumZoomLevel.
 *                  The zoomLevel parameter value may NOT have the same value as the zoomLevel property of
 *                  the NMAMapView to which the NMAMapTileLayer has been added.
 *
 * \return Raw tile bitmap data.
 */
- (nonnull NSData *) mapTileLayer:(nonnull NMAMapTileLayer *)mapTileLayer
            requestDataForTileAtX:(NSUInteger)x
                                y:(NSUInteger)y
                        zoomLevel:(NSUInteger)zoomLevel;

@end

/**
 * \class NMAMapTileLayer NMAMapTileLayer.h "NMAMapTileLayer.h"
 *
 * \brief A layer of custom raster tiles for display in an NMAMapView.
 *
 * <p>Raster tiles are supplied as bitmap data and can be supplied synchronously
 * or simply by providing a URL from which to download the tiles from.</p>
 *
 * <p>To use this class create an instance, configure the properties and call
 * NMAMapView#addMapTileLayer.</p>
 *
 * \note IMPORTANT! The properties of this interface should not be modified after the instance
 * has been added to an NMAMapView. See the NMAMapTileLayer#locked property.
 */
@interface NMAMapTileLayer : NSObject

/**
 * Data source that provides tile bitmap data for the NMAMapTileLayer
 *
 * \note This property cannot be set when the instance is locked. See NMAMapTileLayer#locked.
 */
@property (nullable, nonatomic, weak) id<NMAMapTileLayerDataSource> dataSource;

/**
 * Indicates if the tile layer is locked.
 *
 * <p>The tile layer is locked when it is added to an NMAMapView instance. While the tile layer
 * is locked attempts to set any properties will be ignored. The tile layer is unlocked when
 * it is removed from an NMAMapView instance.</p>
 */
@property (nonatomic, readonly, getter = isLocked) BOOL locked;

/**
 * \brief Specifies the Z-index (stacking order) for the bitmap tiles within the map layer
 * specified by the mapLayerType property.
 *
 * <p>All objects within a map layer have a Z-index associated with them. Objects with the highest
 * value are placed at the top of the stacking order. If two or more objects within a map layer
 * have the same z-index value the their stacking order is undefind.</p>
 *
 * <p>Z-index values range from NMAMapObjectMinimumZIndex to NMAMapObjectMaximumZIndex. The property
 * will be clamped to this range if invalid values are specified.</p>
 *
 * <p>This property defaults to NMAMapObjectMinimumZIndex.</p>
 *
 * \note This property cannot be set when the instance is locked. See NMAMapTileLayer#locked.
 */

@property (nonatomic) NSUInteger zIndex;

/**
 * \brief Specifies the NMAGeoBoundingBox within which tiles will be requested and rendered.
 *
 * <p>Tiles falling fully outside the boundingBox will not be requested.</p>
 *
 * <p>This property defaults to an unbounded value - i.e. tiles are rendered across the world.</p>
 *
 * \note This property cannot be set when the instance is locked. See NMAMapTileLayer#locked.
 */
@property (nullable, nonatomic) NMAGeoBoundingBox *boundingBox;

/**
 * \brief Specifies whether tile bitmaps will be cached to disk by the framework.
 *
 * <p>File system caching is provided as a convenience. If caching is enabled tiles will not
 * be re-requested via NMAMapTileLayerDelegate until they have expired.</p>
 *
 * <p>This property defaults to NO. Caching is enabled by calling setCacheEnabled:withIdentifier:.</p>
 */
@property (nonatomic, readonly, getter = isCacheEnabled) BOOL cacheEnabled;

/**
 * \brief Identifier used to associate disk cached tile data with a NMAMapTileLayer instance
 * to prevent clashes in the cache folder.
 *
 * <p>You must use unique cache identifiers to ensure there will be no filename clashes in the
 * cache folder structure. It also allows you to easily identify the cache in the filesystem.</p>
 *
 * <p>This property is set when you enable caching. See setCacheEnabled:withIdentifier:.</p>
 */
@property (nullable, nonatomic, readonly) NSString *cacheIdentifier;

/**
 * \brief Specifies the cache expiration time in seconds.
 *
 * <p>Tile bitmaps will expire cacheTimeToLive seconds after they have been
 * downloaded causing them to be re-requested via NMAMapTileLayerDataSource
 * when the map needs to render them.</p>
 *
 * <p>This property defaults to 0 which means the cached tiles never expire.</p>
 *
 * \note This property has no effect if the cacheEnabled property is set to NO.
 * Negative values will be reset to 0.
 */
@property (nonatomic) NSTimeInterval cacheTimeToLive;

/**
 * \brief Specifies the maximum size the cache will consume on disk.
 *
 * <p>The framework may allow the cache size to grow an additional 5MB to the size
 * specified in order to reduce disk access.</p>
 *
 * <p>This property defaults to 0 which means the cache size is not limited.</p>
 *
 * \note This property has no effect if the cacheEnabled property is set to NO.
 * Also, this property cannot be set when the instance is locked. See NMAMapTileLayer#locked.
 */
@property (nonatomic) NSUInteger cacheSizeLimit;

/**
 * /brief Enable/Disable caching of tile data to disk.
 *
 * <p>File system caching is provided as a convenience. If caching is enabled tiles will not
 * be re-requested via NMAMapTileLayerDelegate until they have expired.</p>
 *
 * <p>It's important to always use the same cache identifier for your tile data. Otherwise,
 * multiple disassociated cache folders will be created in the file system. This wastes disk
 * space, and you will not benefit from persistent disk caching across sessions.</p>
 *
 * \note Calling this method changes the values of the cacheEnabled and cacheIdentifier
 * properties.
 *
 * \param cacheEnabled YES to enable caching, NO to disable.
 * \param cacheIdentifier You must use a unique cache identifier to ensure there will be no
 *                        filename clashes in the cache folder structure. Passing a nil or
 *                        empty string will result in caching NOT being enabled. The
 *                        identifier is set the first time you call this method and will not
 *                        be changed by subsequent calls to this method for the lifetime of
 *                        the instance. If the identifier you supply contains non alphanumeric
 *                        characters they will be stripped from the identifier, with the
 *                        exception of "_" and "-".
 */
- (void)setCacheEnabled:(BOOL)enabled withIdentifier:(nonnull NSString *)identifier
NS_SWIFT_NAME(setCache(enabled:identifier:));

/**
 * Clear the file system cache identified by the cacheIdentifier property.
 *
 * \note To guarantee the cache is cleared this method should be called after the
 * NMAMapTileLayer instance has been removed from the NMAMapView
 */
- (void)clearCache;

/**
 * \brief Show the raster tiles at the specified zoom level.
 *
 * <p>You can control the tile visibility for each zoom level independently. For example, tiles
 * may be visible at levels 0, 5, 7 only. Tiles are shown at all zoom levels by default.</p>
 *
 * \note This method does nothing when the instance is locked. See NMAMapTileLayer#locked.
 *
 * \param zoomLevel Zoom level at which to show the tiles. Values outside the range
 *                  NMAMapViewMinimumZoomLevel..NMAMapViewMaximumZoomLevel will be ignored
 */
- (void)showAtZoomLevel:(int)zoomLevel
NS_SWIFT_NAME(show(atZoomLevel:));

/**
 * \brief Hide the raster tiles at the specified zoom level.
 *
 * <p>You can control the tile visibility for each zoom level independently. For example, tiles
 * may be visible at levels 0, 5, 7 only. Tiles are shown at all zoom levels by default.</p>
 *
 * \note This method does nothing when the instance is locked. See NMAMapTileLayer#locked.
 *
 * \param zoomLevel Zoom level at which to hide the tiles. Values outside the range
 *                  NMAMapViewMinimumZoomLevel..NMAMapViewMaximumZoomLevel will be ignored
 */
- (void)hideAtZoomLevel:(int)zoomLevel
NS_SWIFT_NAME(hide(atZoomLevel:));

/**
 * \brief Show the raster tiles at the specified zoom level range.
 *
 * <p>You can control the tile visibility for each zoom level independently. For example, tiles
 * may be visible at levels 0, 5, 7 only. Tiles are shown at all zoom levels by default.</p>
 *
 * <p>The method will do nothing if ANY parameters fall outside the range
 * NMAMapViewMinimumZoomLevel..NMAMapViewMaximumZoomLevel or if fromLevel > toLevel.</p>
 *
 * \note This method does nothing when the instance is locked. See NMAMapTileLayer#locked.
 *
 * \param fromLevel Lower zoom level index at which to show the tiles. Values outside the range
 *                  NMAMapViewMinimumZoomLevel..NMAMapViewMaximumZoomLevel will be ignored
 * \param toLevel   Upper zoom level index at which to show the tiles. Values outside the range
 *                  NMAMapViewMinimumZoomLevel..NMAMapViewMaximumZoomLevel will be ignored
 */
- (void)showFromZoomLevel:(int)fromLevel toZoomLevel:(int)toLevel
NS_SWIFT_NAME(show(fromZoomLevel:toZoomLevel:));

/**
 * \brief Hide the raster tiles at the specified zoom level range.
 *
 * <p>You can control the tile visibility for each zoom level independently. This method allows you
 * set the visibility for a range of zoom levels in one call.  Tiles are shown at all zoom levels
 * by default.</p>
 *
 * <p>The method will do nothing if ANY parameters fall outside the range
 * NMAMapViewMinimumZoomLevel..NMAMapViewMaximumZoomLevel or if fromLevel > toLevel.</p>
 *
 * \note This method does nothing when the instance is locked. See NMAMapTileLayer#locked.
 *
 * \param fromLevel Lower zoom level index at which to hide the tiles. Values outside the range
 *                  NMAMapViewMinimumZoomLevel..NMAMapViewMaximumZoomLevel will be ignored
 * \param toLevel   Upper zoom level index at which to hide the tiles. Values outside the range
 *                  NMAMapViewMinimumZoomLevel..NMAMapViewMaximumZoomLevel will be ignored
 */
- (void)hideFromZoomLevel:(int)fromLevel toZoomLevel:(int)toLevel
NS_SWIFT_NAME(hide(fromZoomLevel:toZoomLevel:));

/**
 * \brief Returns whether tiles are visisble at the specified zoom level
 *
 * <p>You can control the tile visibility for each zoom level independently. This method allows you
 * set the visibility for a range of zoom levels in one call.  Tiles are shown at all zoom levels
 * by default.</p>
 *
 * \param zoomLevel Zoom level. Values outside the range
 *                  NMAMapViewMinimumZoomLevel..NMAMapViewMaximumZoomLevel will return NO.
 *
 * \return YES if tiles are shown at the specified zoom level, NO otherwise
 */
- (BOOL)isShownAtZoomLevel:(int)zoomLevel
NS_SWIFT_NAME(isShown(atZoomLevel:));

@end

/**  @}  */
