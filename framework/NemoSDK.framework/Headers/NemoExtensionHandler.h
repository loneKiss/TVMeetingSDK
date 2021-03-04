//
//  NemoExtensionHandler.h
//  NemoSDK
//
//  Created by gao chenyang on 2020/1/6.
//  Copyright © 2020 JackYang. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NemoExtensionHandler : NSObject


/// 设置回调代理
/// @param handler 代理
+(void)broadcastStartSampleHandlerWithHandler:(id )handler;

/// 记录当前发送的数据类型
/// @param type RPSampleBufferType
+(void)broadcastBufferType:(RPSampleBufferType)type;


/// 发送数据
/// @param sampleBuffer 采集到的数据
/// @param type 类型 RPSampleBufferType
+(void)broadcastHandleSampleBuffer:(CMSampleBufferRef)sampleBuffer
                         bufferType:(RPSampleBufferType)type;

/// 分享屏幕结束
+(void)broadcastFinished;

/// 录制停止
/// @param message 原因
+(void)broadcastStopReasonMessage:(NSString *)message;
@end

NS_ASSUME_NONNULL_END
