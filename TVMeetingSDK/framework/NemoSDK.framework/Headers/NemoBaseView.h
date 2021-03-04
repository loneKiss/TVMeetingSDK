//
//  NemoBaseView.h
//  NemoSDK
//
//  Created by 杨旭东 on 2016/12/2.
//  Copyright © 2016年 JackYang. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface NemoBaseView : UIView

@property (nonatomic, strong) UILabel *displayNameLabel;

@property (nonatomic, strong) UIImageView *signImageview;

@property (nonatomic, strong) UILabel *alertMsgLabel;

#pragma mark NemoBaseView

/**
 *  获取NemoBaseView对象
 *  @param view(获取到的NemoBaseView对象)
 */
+ (void)setUp:(void (^)(NemoBaseView *view))view;


/**
 *  设置尺寸
 *  @param size(视频、分享等小视图的尺寸, 全屏尺寸)
 */
- (NemoBaseView *(^)(CGSize, CGSize))nemoSize;


/**
 *  设置起始位置和父视图
 *  @param origin(起始位置, 父视图, 全屏尺寸)
 */
- (NemoBaseView *(^)(CGPoint, UIView *))nemoOrigin;


/**
 *  设置圆角半径
 *  @param cornerRadius(圆角半径)
 */
- (NemoBaseView *(^)(float))cornerRadius;


/**
 *  全屏
 */
- (NemoBaseView *(^)())fullScreen;


/**
 *  移动缩小到指定位置
 *  @param move(指定位置)
 */
- (NemoBaseView *(^)(CGPoint))move;


/**
 *  关闭视图
 */
- (void (^)())dismiss;


/**
 *  视图是否全屏
 */
@property (readonly, nonatomic, getter=isFullScreen) BOOL FullScreen;

- (NemoBaseView *(^)(BOOL))videoMute;

/**
 *  设置触摸响应
 *  @param tapEnable(开启或关闭触摸响应)
 */
- (NemoBaseView *(^)(BOOL))tapEnable;

/**
 *  设置拖动响应
 *  @param haulEnable(开启或关闭拖动响应)
 */
- (NemoBaseView *(^)(BOOL))haulEnable;

- (void)exchange:(void (^)(void (^)(NemoBaseView *)))changeview;
@end





#pragma mark NemoVideo

@interface NemoVideo : NemoBaseView

/**
 *  获取NemoVideo对象
 *  @param view(获取到的NemoVideo对象)
 */
+ (void)setUpVideo:(void (^)(NemoVideo *video))view;


/**
 *  设置视频流信息
 *  @param layoutInfo(单个视频流信息)
 */
- (NemoVideo *(^)(NemoLayout *))layoutInfo;

/**
 *  获取当前video的layout信息
 */
- (NemoLayout *)getLayout;


/**
 *  设置视频帧率
 *  @param frameRate(视频帧率)
 */
- (NemoVideo *(^)(float))frameRate;


/**
 *  开始绘制
 */
- (void (^)())start;


/**
 *  停止绘制
 */
- (void (^)())stop;


/**
 *  调整呼叫模式
 *  @param mode(视频/音频)
 */
- (NemoVideo *(^)(NemoCallMode))mode;


/**
 *  本地mic静音状态
 */
- (NemoVideo *(^)(BOOL))muteOfMic;


/**
 *  是否是本地视频
 */
@property (readonly, nonatomic, getter=isLocalVideoView) BOOL LocalVideoView;


/**
 *  视频流是否存在
 *  @param existence(视频流信息组)
 */
- (int (^)(NSArray *))existence;

/** 隐藏 */
- (NemoVideo *(^)(BOOL))videoHide;

#pragma mark - 1.2
/**
 *  本地视频是否关闭
 */
- (NemoVideo *(^)(BOOL))muteOfVideo;


/**
 重置当前view的全面状态
 */
- (void)resetFullScreenState;

@end





#pragma mark NemoImage

@interface NemoImage : NemoBaseView

/**
 *  获取NemoImage对象
 *  @param view(获取到的NemoImage对象)
 */
+ (void)setUpContent:(void (^)(NemoImage *content))view;


/**
 *  开始显示
 */
- (NemoImage *(^)())start;


/**
 *  停止显示共享内容
 *  @param stop(共享结束时默认全屏的NemoBaseView)
 */
- (NemoImage *(^)(NemoBaseView *))stop;

@end





