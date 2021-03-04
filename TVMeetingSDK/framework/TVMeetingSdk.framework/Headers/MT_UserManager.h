//
//  MT_UserManager.h
//  jsh-app-meeting-ios
//
//  Created by 巨商汇 on 2020/4/2.
//  Copyright © 2020 巨商汇. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MT_Single.h"

@interface MT_UserManager : NSObject

MT_InterfaceSingle(UserManager)

MT_InterfaceDestroySingle(UserManager)

@property (nonatomic, strong) UIViewController *controller;
/**
*  初始化会议系统
*
*  @param messageVC       消息sdk主控制器
*/
-(void)initMeetingSDK:(UIViewController *)messageVC;
/** 获取消息sdk主控制器 */
- (UIViewController *)getMessageController;
/**
 *  初始化会议系统
 *
 *  @param accountId                 用户id
 *  @param accountName               用户名字
 *  @param fishAccountId             小鱼id
 *  @param accessToken               登录token
 *  @param refreshToken              刷新登录token
 *  @param projectToken              集成项目的token
 *  @param versonType                项目环境配置
 */
- (void)saveAccountId:(NSString *)accountId andAccountName:(NSString *)accountName andFishAccountId:(NSString *)fishAccountId andAccessToken:(NSString *)accessToken andRefreshToken:(NSString *)refreshToken andProjectToken:(NSString *)projectToken withProjectVerson:(NSInteger)versonType;


/**
 *  极光推送初始化会议系统
 *
 *  @param userInfo                  极光推送进入会议系统初始化字典
 *  @param versonType                项目环境配置
 */
- (void)setUpMeetingSDKWithDictionary:(NSMutableDictionary *)userInfo withProjectVerson:(NSInteger)versonType;

/** 极光推送进入会议系统逻辑 */
- (void)jPushEnterMeetingAction;

- (void)saveDepartmentType:(NSString *)departmentType;
/** 登录会议系统的状态 0:登录中 1:登录失败 2:多终端登录 3:登陆成功*/
- (void)saveLoginStatusType:(NSInteger)statusType;
/** 登录后与小鱼的连接状态 */
- (void)saveIsConnectStatus:(BOOL)isConnect;
/** 全员静音状态 */
- (void)saveIsAllQuiet:(BOOL)isAllQuiet;
/** 保存开发环境 */
- (void)saveMT_Version_Type:(NSInteger)versonType;
/** 保存小鱼登录成功后的号码callNumber */
- (void)saveFishCallNumber:(NSString *)callNumber;
/** 保存登录账户父级部门id数组 */
- (void)saveParentDepartment:(NSArray *)parentDepartment;
/** 小鱼登录成功以后,服务器保存callNumber,用来呼叫参会人 */
-(void)uploadCallNumber:(NSString *)callNumber saveFishAccountId:(NSString *)fishID;

/** source 会议:1 群聊:2 */
- (void)saveSource:(NSString *)source;
- (NSString *)getSource;


/** 底部公用工具类型 */
- (void)saveToolType:(NSString *)toolType;
- (NSString *)getToolType;

/** 刷新会议系统登录token */
- (void)getMeetingRefreshToken;
- (NSString *)getLoginMessage;
/** 取值 */
-(NSString *)getAccountId;
- (NSArray *)getParentDepartment;
- (NSString *)getAccessToken;
- (NSString *)getRefreshToken;
- (NSString *)getProjectToken;
-(NSString *)getDepartmentType;


- (BOOL)getConnectStatus;
- (BOOL)getIsAllQuiet;
/** 获取bundle */
-(NSBundle *)getResourcesBundle;

/** 是否显示首字母索引条状态 */
- (void)saveIsIndexes:(BOOL)indexes;
- (BOOL)getIsIndexes;
 /** 登录会议系统 */
-(void)loginMeetingAction;
/** 退出登录 */
-(void)logOut;

/** 获取项目环境配置请求地址 */
-(NSString *)getMeetingCommonUrlWithProjectName:(NSString *)projectName;

/** 获取项目环境配置外置项目工程请求地址 */
-(NSString *)getOutSideProjectCommonUrlWithProjectName:(NSString *)projectName;

/** 上传日志 */
-(void)uploadLog:(NSString *)log;

/** 判断会议状态 --> 会议状态 0未开始 1进行中 2已结束  */
-(void)getMeetingStatus:(NSString *)meetingId;

/** 是否在会议中 */
- (BOOL)isNowInMeeting;

/** 极光推送跳转已结束会议的详情页面 */
-(void)enterEndMeetDetailVCWithFromVC:(UINavigationController *)fromNav meetingId:(NSString *)meetingId andNavigationTitle:(NSString *)navigationTitle;
/** 极光推送跳转未开始会议的详情页面 */
-(void)enterNoStartMeetDetailVCWithFromVC:(UINavigationController *)fromNav meetingId:(NSString *)meetingId;
/** 极光推送跳转会议室页面 */
-(void)enterMeetingRoomVCWithFromVC:(UIViewController *)fromVC meetingRoomNumber:(NSString *)meetingRoomNumber;

/** 旋转屏幕 */
@property (nonatomic, copy) void (^didRotatingScreen)(BOOL allowRotation);

@property(nonatomic,assign)BOOL allowRotation;//是否允许转向

@end

