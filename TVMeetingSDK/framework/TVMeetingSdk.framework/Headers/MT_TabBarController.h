//
//  MT_TabBarController.h
//  jsh-app-meeting-ios
//
//  Created by 巨商汇 on 2020/4/2.
//  Copyright © 2020 巨商汇. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <NemoSDK/NemoSDK.h>
NS_ASSUME_NONNULL_BEGIN

@interface MT_TabBarController : UITabBarController<NemoSDKDelegate>

@property (nonatomic, assign) NemoCallState callState;

@property (nonatomic, copy) NSString *reason;

@end

NS_ASSUME_NONNULL_END
