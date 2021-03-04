//
//  ConnectManager.h
//  Meeting
//
//  Created by 巨商汇 on 2020/6/10.
//  Copyright © 2020 jsh. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MT_Single.h"
NS_ASSUME_NONNULL_BEGIN

@interface ConnectManager : NSObject

MT_InterfaceSingle(Manager)

MT_InterfaceDestroySingle(Manager)

/** 进入个人详情 */
-(void)enterPersonDetailVCWithAccountId:(NSString *)accountId fromVC:(UIViewController *)fromVC;
/** 聊天信息页面,进去创建群聊 */
-(void)enterCreatGroupVCWithAccountId:(NSString *)accountId fromVC:(UIViewController *)fromVC;
/** 已入群的群详情界面 */
-(void)enterAlreadyEnterGroupDetailVCWithGroupId:(NSString *)groupId fromVC:(UIViewController *)fromVC;
/** 转发单选页面 */
-(void)enterTransmitSingleChoiceVCWithFromVC:(UIViewController *)fromVC;
/** 会议通话界面 */
-(void)enterMeetingCallVCWithMeetingRoomNumber:(NSString *)meetingRoomNumber meetingId:(NSString *)meetingId fromVC:(UIViewController *)fromVC;
/** 创建会议界面 */
-(void)enterCreatMeetingVCWithFromVC:(UIViewController *)fromVC creatMeetingCompletionBlock:(void(^)(NSMutableDictionary *parameters))completionBlock;
/** 扫码页面 */
-(void)enterScanCodeVCWithFromVC:(UIViewController *)fromVC;
/** 发起群聊页面 */
-(void)enterStartGroupVCWithFromVC:(UIViewController *)fromVC;
/** 添加好友页面 */
-(void)enterAddContactsVCWithFromVC:(UIViewController *)fromVC;
/** 公共搜索页面 */
-(void)enterSearchVCWithFromVC:(UIViewController *)fromVC;


/**
*  跳转聊天页面逻辑
*
*  @param convId              会话 ID，用于唯一标识一个会话
*  @param convType            会话类型。*TIM_C2C 类型  *TIM_GROUP 群聊 类型  *TIM_SYSTEM 系统消息
*  @param title               会话标题
*  @param fromVC              来源控制器
*/
@property(nonatomic , copy) void(^ChatBlock)(NSString *convId,NSInteger convType,NSString *title,UIViewController *fromVC);

/**
*  置顶操作
*
*  @param convId              会话 ID，用于唯一标识一个会话
*  @param isSticky            置顶标识
*/
@property(nonatomic , copy) void(^TopConversationBlock)(NSString *convId,BOOL isSticky);

/**
*  删除单个会话和对应的会话消息
*
*  @param convId              会话 ID，用于唯一标识一个会话
*  @param convType            会话类型。*TIM_C2C 类型  *TIM_GROUP 群聊 类型  *TIM_SYSTEM 系统消息
*/
@property(nonatomic , copy) void(^DeleteConversationAndMessagesBlock)(NSString *convId,NSInteger convType);


/**
*  转发会话消息
*
*  @param dict              会话信息字典，用于存储会话的基本信息
*  @param convType          会话类型。*TIM_C2C 类型  *TIM_GROUP 群聊 类型  *TIM_SYSTEM 系统消息
*  @param fromVC            展示转发弹框的控制器
*/
@property(nonatomic , copy) void(^TransmitMessagesBlock)(NSMutableDictionary * dict,TIMConversationType convType,UIViewController *fromVC);

/**
*  修改个人资料操作
*
*  @param typeString             修改的值类型
*  @param valueString            修改后的值
*/
@property(nonatomic , copy) void(^ModifySelfProfileBlock)(NSString *typeString,NSString *valueString);


/**
*  单聊操作
*
*  @param convId              会话 ID，用于唯一标识一个会话
*  @param convType            会话类型。*TIM_C2C 类型  *TIM_GROUP 群聊 类型  *TIM_SYSTEM 系统消息
*  @param title               会话标题
*  @param fromVC              来源控制器
*/
@property(nonatomic , copy) void(^GoToSingleChatBlock)(NSString *convId,NSInteger convType,NSString *title,UIViewController *fromVC);


/**
*  创建群聊跳转聊天页面逻辑
*
*  @param convId              会话 ID，用于唯一标识一个会话
*  @param convType            会话类型。*TIM_C2C 类型  *TIM_GROUP 群聊 类型  *TIM_SYSTEM 系统消息
*  @param title               会话标题
*  @param fromVC              来源控制器
*/
@property(nonatomic , copy) void(^CreatGroupEnterChatBlock)(NSString *convId,NSInteger convType,NSString *title,UIViewController *fromVC);


/**
*  退出登录TIM逻辑
*/
@property(nonatomic , copy) void(^LogoutChatBlock)(void);


/**
*  被强制踢下线重新登录TIM逻辑
*/
@property(nonatomic , copy) void(^LogInAgainChatBlock)(void);

@end

NS_ASSUME_NONNULL_END
