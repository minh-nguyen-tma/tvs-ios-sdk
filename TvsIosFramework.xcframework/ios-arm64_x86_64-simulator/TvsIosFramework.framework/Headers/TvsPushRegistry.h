//
//  TvsPushRegistry.h
//  TvsIosFramework
//
//  Created by Minh Nguyen on 16/4/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT NSString * const kTvsPushRegistryNotificationName;
FOUNDATION_EXPORT NSString * const kTvsPushRegistryEventType;
FOUNDATION_EXPORT NSString * const kTvsPushRegistryNotificationDeviceToken;
FOUNDATION_EXPORT NSString * const kTvsPushRegistryNotificationDeviceTokenUpdated;
FOUNDATION_EXPORT NSString * const kTvsPushRegistryNotificationIncomingPushReceived;
FOUNDATION_EXPORT NSString * const kTvsPushRegistryNotificationPayload;


@interface TvsPushRegistry : NSObject

- (void)initPushRegistry;

@end

NS_ASSUME_NONNULL_END
