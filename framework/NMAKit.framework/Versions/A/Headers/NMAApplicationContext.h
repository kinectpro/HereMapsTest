/***************************************************************
 * Copyright (c) 2011-2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>

/**
 * \addtogroup NMA_Common  NMA Common Group
 * @{
 */

NS_ASSUME_NONNULL_BEGIN

/**
 * \class NMAApplicationContext NMAApplicationContext.h "NMAApplicationContext.h"
 *
 * Use this interface to set mandatory authentication crendentials
 *
 * \note YOU MUST SET AUTHENTICATION CREDENTIALS in order to use the APIs
 * contained within this SDK. Some APIs may appear to work without valid
 * credentials but they may stop functioning in the near future when server side
 * configurations change, so please obtain and use valid credentials.
 */
@interface NMAApplicationContext : NSObject

/** Sets the mandatory HERE Authentication Credentials.
 *
 * These credentials MUST be set in order to use the APIs in this SDK. It is
 * recommended to set the credentials in your application delegate, such as in
 * [UIApplicationDelegate didFinishLaunchingWithOptions]
 */
+ (void)setAppId:(NSString *)appId appCode:(NSString *)appCode
NS_SWIFT_NAME(set(appId:appCode:));

/** \brief Return the SDK version
 *  \return The SDK verion
 */
+ (NSString *)sdkVersion;

@end

NS_ASSUME_NONNULL_END

/** @}  */
