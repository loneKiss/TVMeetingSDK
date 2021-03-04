//
//  TVMeetingSdk.h
//  TVMeetingSdk
//
//  Created by 龙阳昱辰 on 2021/3/3.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TVMeetingSdk : NSObject<NSCopying,NSMutableCopying>

/** 单例 */
+(instancetype)shareMeeting;

@property (strong, nonatomic) UIWindow *window;

- (void)launch;
- (void)didEnterBackground;
- (void)willEnterForeground;
- (void)didBecomeActive;

@end

NS_ASSUME_NONNULL_END
