//
//  NemoSDK.h
//  NemoSDK
//
//  Created by 杨旭东 on 16/9/27.
//  Copyright © 2019 JackYang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Enumeration_Type.h"
#import <ReplayKit/ReplayKit.h>

NS_ASSUME_NONNULL_BEGIN

@class UIImage;

@interface XYSettings : NSObject

@property (nonatomic, copy) NSString *extID;                     ///<企业ID

@property (nonatomic, copy, nullable) NSString *server;          ///<server地址,不设置则默认cloud.xylink.com

@property (nonatomic, copy) NSString *httpPort;                  ///<http端口号，默认80

@property (nonatomic, copy) NSString *httpsPort;                 ///<https端口号，默认443

@property (nonatomic, copy) NSString *SocksProxyIp;              ///<socks代理 ip

@property (nonatomic, copy) NSString *SocksProxyPort;            ///<socks代理 端口

@property (nonatomic, copy) NSString *SocksProxyUserName;        ///<socks代理 用户名

@property (nonatomic, copy) NSString *SocksProxyPassword;        ///<socks代理 密码

@property (nonatomic, assign) XYLogLevel level;                  ///<log等级

@property (nonatomic, assign) BOOL enableLog;                    ///<是否打印log

@property (nonatomic, assign) BOOL needAudioMeter;               ///<音量探测

@property (nonatomic, assign) BOOL needSpeakers;                 ///<当前讲话者

//默认NO，开启后将client证书命名private-ca.cer
//如果格式不是.cer需要自行转换，拖进工程任意目录即可
@property (nonatomic, assign) BOOL enableSSLCertificate;         ///<开启签名认证

@property (nonatomic, assign) NSInteger defaultCameraId;         ///<0:后置摄像头,1:前置摄像头

@property (nonatomic, assign) XYVideoDimension videoDimension;   ///<视频输出配置

+ (XYSettings *)settings;                               ///<XYSettings统一初始化方法

@end


@interface XYUser : NSObject

@property (nonatomic, assign) long userId;          ///<用户ID

@property (nonatomic, assign) long deviceId;        ///<设备ID

@property (nonatomic, assign) int deviceType;       ///<设备类型

@property (nonatomic, copy) NSString *callNumber;   ///<号码

@property (nonatomic, copy) NSString *error;        ///<错误信息

@property (nonatomic, copy) NSString *displayName;  ///<用户名

@end


@interface NemoLayout : NSObject

@property (nonatomic, copy) NSString *remoteName;               ///<远端名称

@property (nonatomic, copy) NSString *streamID;                 ///<视频流ID

@property (nonatomic, copy) NSString *participantId;            ///<参会人ID

@property (nonatomic, assign) BOOL isContent;                   ///<是否是content

@property (nonatomic, assign) BOOL isAudioMute;                 ///<是否静音

@property (nonatomic, assign) BOOL isActiveSpeaker;             ///<是否发言

@property (nonatomic, assign) NSInteger videoWidth;             ///<视频宽度

@property (nonatomic, assign) NSInteger videoHeight;            ///<视频高度

@property (nonatomic, assign) NemoStreamState layoutState;      ///<视频流状态

@property (nonatomic, assign) NemoDeviceType deviceType;        ///<远端类型

@property (nonatomic, assign) long remoteID;                    ///<远端ID

@property (nonatomic, copy) NSString *remoteUri;                ///<远端uri

@property (nonatomic, assign) XYVideoMuteReason videoMuteReason;///<视频关闭原因

@property (nonatomic, assign) unsigned int feccOri;             ///<fecc

@property (nonatomic, copy) NSString *remoteAlias;              ///<远端别名

@end


@interface NemoVideoStramInfo : NSObject

@property (nonatomic, assign) NSUInteger participantId;     ///<参会者id

@property (nonatomic, assign) NSUInteger width;             ///<视频流宽度

@property (nonatomic, assign) NSUInteger height;            ///<视频流高度

@property (nonatomic, assign) NSUInteger originalWidth;     ///<视频流原始宽度

@property (nonatomic, assign) NSUInteger originalHeight;    ///<视频流原始高度

@end


@interface NemoRosterInfo : NSObject

@property (nonatomic, assign) int participantId;        ///<参会人ID

@property (nonatomic, assign) int feccOri;              ///<fecc能力值

@property (nonatomic, assign) int  weight;              ///<权重

@property (nonatomic, assign) NemoDeviceType deviceType;///<远端类型

@property (nonatomic, copy) NSString *deviceId;         ///<设备ID

@property (nonatomic, copy) NSString *deviceName;       ///<设备名

@property (nonatomic, copy) NSString *deviceAlias;      ///<设备别名

@property (nonatomic, assign) BOOL isTelephone;         ///<是否是电话

@property (nonatomic, assign) BOOL isObserver;          ///<是否是观察者

@property (nonatomic, assign) BOOL isAudioOnly;         ///<是否只有语音

@property (nonatomic, assign) BOOL isAudioMute;         ///<是否静音

@property (nonatomic, assign) BOOL isVideoMute;         ///<是否关闭视频

@property (nonatomic, assign) BOOL isForceFullScreen;   ///<是否被force到大屏

@property (nonatomic, assign) BOOL isRequested;         ///<requestRoster主动请求

@property (nonatomic, assign) BOOL isAnnotationEnable;  ///<是否允许标注

@end


@interface NemoRosters : NSObject

@property (nonatomic, strong) NSArray *peopleRosters;    ///<所有远端详细Roster信息，目前最大接受20个参会信息

@property (nonatomic, strong) NSArray *contentRosters;   ///<所有远端详细Roster信息，目前最大接受20个参会信息

@property (nonatomic, assign) int numberOfPeople;        ///<远端人数，会议中除自己外的总参会人数

@property (nonatomic, assign) NemoCallMode callMode;     ///<呼叫模式

@property (nonatomic, assign) int contentSenderPid;      ///<分享者

@property (nonatomic, assign) int activeSpeakerPid;      ///<正在讲话的人

@property (nonatomic, assign) int subscribeSequence;     ///<订阅序列

@property (nonatomic, assign) BOOL recvingVideoContent;  ///<接收content

@property (nonatomic, assign) BOOL hasOtherParticipants; ///<其他参会者

@end


@interface NemoCustomLayoutElement : NSObject

@property (nonatomic, assign) int participantId;                ///<参会人ID

@property (nonatomic, assign) NemoVideoResolution resolution;   ///<分辨率

@property (nonatomic, assign) NemoLayoutPriority priority;      ///<布局优先级

@property (nonatomic, assign) NemoVideoQuality quality;         ///<视频质量

@end


@interface NemoCustomLayoutInfo : NSObject

@property (nonatomic, strong) NSMutableArray <NemoCustomLayoutElement *> *layoutElements; ///<请流参数

@end

@interface NemoConfMgmtInfo : NSObject

@property (nonatomic, assign) BOOL isChairmanMode;          ///<主会场模式（判断主会场模式需要结合主会场ID）

@property (nonatomic, copy)  NSString *chairmanUri;         ///<主会场ID

@property (nonatomic, assign) bool muteIsDisabled;          ///<麦克风是否禁用

@property (nonatomic, assign) bool feccIsDisabled;          ///<fecc是否禁用

@property (nonatomic, assign) bool contentIsDisabled;       ///<共享内容是否禁用

@property (nonatomic, assign) bool recordIsDisabled;        ///<录制是否禁用

@property (nonatomic, assign) bool whiteboardIsDisabled;    ///<白板是否禁用

@end


@interface AICaptionInfo : NSObject

@property (nonatomic, assign) long pid;             ///<参会人ID

@property (nonatomic, copy) NSString *src;          ///<源

@property (nonatomic, copy) NSString *target;       ///<翻译后

@property (nonatomic, assign) BOOL isEnd;           ///<一句话是否已结束

@property (nonatomic, assign) BOOL isActive;        ///<收三路，同时只有一路active

@end


@interface NemoCaptionInfoModel : NSObject

@property (nonatomic, assign) BOOL display;                     ///<展示字幕

@property (nonatomic, copy) NSString * content;                 ///<字幕内容

@property (nonatomic, assign) NemoCaptionLocation location;     ///<位置

@property (nonatomic, assign) BOOL scroll;                      ///<是否滚动

@property (nonatomic, strong) NSString *scrollSpeed;            ///<速度

@property (nonatomic, strong) NSString * bgColor;               ///<背景色

@property (nonatomic, assign) CGFloat bgColorAlpha;             ///<背景透明度

@property (nonatomic, strong) NSString * fontColor;             ///<字体颜色

@property (nonatomic, assign) NemoCaptionFontSize fontType;     ///<字体大小

@end


@interface NemoContent : NSObject

@property (nonatomic, assign) NemoShareContentType type;        ///<分享类型

@property (nonatomic, strong) UIImage *image;                   ///<图片数据

@property (nonatomic, assign) NSInteger imageFrameRate;         ///<图片帧率

@property (nonatomic, assign) CMSampleBufferRef buffer;         ///<采集到的数据

@property (nonatomic, assign) RPSampleBufferType bufferType API_AVAILABLE(ios(10.0)); ///<采集到的数据类型

@end


@interface NemoVideoCanvas : NSObject

@property (nonatomic, strong) UIView *view;             ///<承载视频的父view

@property (nonatomic, strong) NemoLayout *layout;       ///<视频流信息

@property (nonatomic, assign) BOOL isLocal;             ///<是否是本地视频

- (void)clear;

@end


@interface NemoSpeakers : NSObject

@property (nonatomic, assign) NSInteger energyAverage;   ///<发言者语音能量值

@property (nonatomic, strong) NSString *calluri;         ///<发言者calluri

@property (nonatomic, assign) NSInteger participantId;   ///<发言者id

@end


@interface NemoInOutNotice : NSObject

@property (nonatomic, copy) NSString *externalId;       ///<三方di

@property (nonatomic, copy) NSString *displayName;      ///<名称

@property (nonatomic, assign) BOOL isIn;                ///<yes 入会 no 退会

@end


@interface NemoCallConfig : NSObject

@property (nonatomic, assign) BOOL audioMute;   ///<关闭音频入会

@property (nonatomic, assign) BOOL videoMute;   ///<关闭视频入会

@end


@interface NemoSitePathInfo : NSObject

@property (nonatomic, copy) NSString *displayName;       ///<线路名称
 
@property (nonatomic, copy) NSString *sitePathId;        ///<线路标识

@property (nonatomic, assign) NSInteger sitePathType;    ///<线路类型 0 公有 1 私有

@property (nonatomic, assign) NSInteger networkType;     ///<网络类型 0 内网 1 外网

@end


@interface NemoNetTestInfo : NSObject

@property (nonatomic, assign) int setBandwidth;     ///<测试带宽

@property (nonatomic, assign) int bandwidth;        ///<实际带宽

@property (nonatomic, assign) int lostRate;         ///<网络丢包

@property (nonatomic, assign) int jitter;           ///<抖动

@property (nonatomic, assign) int rtt;              ///<往返时间

@property (nonatomic, assign) int missorder;        ///<乱序

@property (nonatomic, assign) int pktNum;           ///<数据包数量

@end


@interface NemoNetTestResult : NSObject
//1：非常好  2：良好  3：一般  4：较差  5：很差
@property (nonatomic, assign) int sendQualityLevel;     ///<发送质量
//1：非常好  2：良好  3：一般  4：较差  5：很差
@property (nonatomic, assign) int recvQualityLevel;     ///<接收质量

@property (nonatomic, strong) NSArray <NemoNetTestInfo *> *sendDetail;    ///<发送详情

@property (nonatomic, strong) NSArray <NemoNetTestInfo *> *recvDetail;    ///<接收详情

@end


@protocol NemoSDKDelegate <NSObject>

@optional

/// 登录结果
///
/// 只有在调用登录接口后会触发回调，退出登录不会触发
///
/// @param user 登陆成功时返回用户信息，登录失败时返回对应的错误码
/// @param success 是否登录成功
- (void)nemoSDKDidLoginResult:(nullable XYUser *)user success:(BOOL)success;

/// 登录后与小鱼的连接状态
///
/// 登录成功后小鱼SDK会与服务器保持长连接，所有的会议都需要建立在长连接正常情况下，长连接断开后约40s左右会议被迫中断
/// 所以，建议您在保证此接口isConnect=YES时再进行呼叫入会等相关操作，退出登录后长连接会断开
///
/// @param isConnect 是否连接
- (void)nemoSDKDidConnectStateWithNemo:(BOOL)isConnect;

/// 登出状态
///
/// 调用退出登录接口后触发
///
/// @param success 登出是否成功
- (void)nemoSDKDidLogoutState:(BOOL)success;

/// 被迫下线
///
/// 同一个账号在其他设备登录时，当前的设备会被强制下线，小鱼不允许同一账号同时在多台移动设备上同时登录，但是允许同一
/// 个账号同时在移动端和桌面端登录
///
- (void)nemoSDKDidAccountWasKickOut;

/// 呼叫状态的回调
///
/// 此接口返回整个会议的状态，调用makeCall开会呼叫之后会返回
/// NemoCallState_Connecting表示正在连接会议室，
/// NemoCallState_Connected表示已经成功进入会议室
/// NemoCallState_DisConnected表示会议已经断开，正常结束时reason返回”state:200“，异常结束时返回对应的错误码，可查阅错误码文档获取详情信息
///
/// @param number 号码
/// @param callState 呼叫状态
/// @param reason 异常状态原因
- (void)nemoSDKDidCall:(NSString *)number stateChanged:(NemoCallState)callState reason:(NSString *)reason;

/// 接收到会议邀请或点对点呼叫
///
/// 只有在登录并且长连接正常时，小鱼才能正确下发邀请回调，收到点对点呼叫邀请时，您必须先挂断当前会议再接受邀请，如果您想点对点呼叫他人，需要在
/// makeCall时传入callNumber，callNumber可以从XYUser获取
///
/// @param number 会议号
/// @param displayName 用户名
/// @param isValid YES 呼叫邀请有效 NO 呼叫邀请有效已失效，即被其他端处理或取消
- (void)nemoSDKDidReceiveCall:(NSString *)number displayName:(NSString *)displayName isValid:(BOOL)isValid;

/// 分享内容回调
///
/// 只有您自己发起分享图片或屏幕时才会触发，另外一种情况是：您正在分享被会中其他人抢断，也会触发
///
/// @param type 类型
/// @param state 状态
- (void)nemoSDKDidContentShareStateChanged:(NemoShareContentType)type state:(NemoShareContentState)state;

/// 视频流信息改变回调
///
/// 调用setCustomLayout请流之后会触发，返回您请求的视频流，如果会议中的视频流状态发生变化时也会触发
/// 您需要监听此接口，通过返回的视频流数据来刷新页面
///
/// @param videos 当前通话视频信息，与会人Stream信息数组(包含streamID和其他stream信息)
- (void)nemoSDKDidVideoChanged:(NSArray<NemoLayout*> *)videos;

/// 单个视频流信息回调
///
/// 此接口配合标注使用，返回分享画面的实际分辨率
///
/// @param streamInfo 视频流信息
- (void)nemoSDKDidVideoStreamInfo:(NemoVideoStramInfo *)streamInfo;

/// 参会者信息变化回调
///
/// 入会成功后会自动触发，返回会议中的参会者信息，当会中有人员状态变动时也会触发
/// 您需要监听此接口，通过返回的参会者信息确认会中的人数，决定如何去请求（setCustomLayout）参会者的视频流
///
/// @param rosters 参会者信息
- (void)nemoSDKDidRosterChanged:(NemoRosters *)rosters;

/// 会控消息的回调
///
/// 入会成功后会自动触发，返回当前会议的会控消息，比如主持人设置主会场，静音和一些功能权限，当主持人操作了会控时也会触发
///
/// @param type 会控消息类型
/// @param info 会控消息
- (void)nemoSDKDidConferenceManagementStateChanged:(NemoConferenceManagerManagementType)type confMgmtInfo:(NemoConfMgmtInfo *)info;

/// 出入会通知
///
/// 有参会者入会、退会时触发
///
/// @param noticeInfos 通知信息
- (void)nemoSDKDidInOutNotice:(NSArray<NemoInOutNotice *> *)noticeInfos;

/// 录制状态
///
/// 录制状态改变时触发
///
/// @param start 录制是否开始
- (void)nemoSDKDidRecordingStateChanged:(BOOL)start;

/// 视频状态变化提示
///
/// 请监听 nemoSDKDidNetworkIndicatorLevel 代替此接口
///
/// @param state 当前视频状态
- (void)nemoSDKDidVideoStateChanged:(NemoVideoState)state;

/// 网络等级指示
///
/// 返回本地设置网络状态
///
/// @param level 网络等级(共分为4个等级-> 1 2 3 4，由低到高分别为差，中，良，优)
- (void)nemoSDKDidNetworkIndicatorLevel:(NSInteger)level;

/// 呼叫中心提示回调
///
/// SDK用户无需关系此接口
///
/// @param msg 信息
- (void)nemoSDKDidIMNotification:(NSString *)msg;

/// 音频注册回调被修改时调用
///
/// 当会议中有其他App或设备占用音频通道时会触发，比如会中来电话，您可以监听此接口获取相应的通知
///
/// @param began 开始 or 结束
- (void)nemoSDKDidAudioInterrupt:(BOOL)began;

/// 音频单位注册回调出现错误时调用
///
/// 初始化音频单元失败是触发，此场景比较少见
///
/// @param error 错误信息
- (void)nemoSDKDidAudioInitFailed:(NSString *)error;

/// 日志上传结果回调
///
/// 调用sendFeedbackLogWithComments接口上传日志结束时触发，上传成功时errorInfo为空
///
/// @param errorInfo 上传失败是返回的错误信息
- (void)nemoSDKDidUploadLogFileErrorInfo:(NSString *)errorInfo;

/// 白板改变状态
///
/// 会议中有人发起或结束白板时触发，小鱼SDK同一个会议中同一时间只允许一个人发起白板，其他人只有等白板结束后才能再次发起
///
/// @param remoteState 远端状态
/// @param reason 原因
- (void)nemoSDKDidWhiteboardStateChanged:(NemoWhiteboardRemoteState)remoteState reason:(NSString *_Nullable)reason;

/// 白板远端消息
///
/// 白板开启状态下，远端在白板上画线等操作会触发此回调，remoteMessage为消息内容，对应每一条画线，具体可参照demo
///
/// @param remoteMessage 消息
/// @param type 类型
- (void)nemoSDKDidWhiteboardReceieved:(id)remoteMessage type:(NemoWhiteboardOperationState)type;

/// 标注状态变化
///
/// 打开或关闭标注时触发，根据返回的状态值做相应的逻辑处理
///
/// @param state 状态
- (void)nemoSDKDidAnnotationStateChanged:(NemoAnnotationStatus)state;

/// 接收到标注消息
///
/// 标注开启状态下，远端在分享画面上画线等操作会触发此回调，message为消息内容，对应每一条画线，具体可参照demo
///
/// @param message 消息内容
/// @param operation 动作
- (void)nemoSDKDidAnnotationMsgReceived:(id)message operation:(NemoAnnotationOperation)operation;

/// 同传字幕回调
///
/// 此接口暂未使用
///
/// @param aiCaptionInfo AICaptionInfo
- (void)nemoSDKDidAiCaptionInfo:(AICaptionInfo *)aiCaptionInfo;

/// 旁路音频数据回调
///
/// 返回会中自己的音频数据，需要您在入会前调用setMicDataByAEReadyEnabled打开音频旁路开关
///
/// @param size 数据大小
/// @param data 数据内容
- (void)nemoSDKDidMicDataByAEReady:(NSInteger)size data:(void *)data;

/// 接收到字幕回调
///
/// 会议中，会控可以向所有人发送字幕消息，字幕消息包含文字内容、字体大小、颜色、背景等
///
/// @param captionInfo 字幕信息
- (void)nemoSDKDidRecieveCaptionDisplay:(NemoCaptionInfoModel *)captionInfo;

/// 讲话的人回调（最多3个人）
///
/// 返回当前正在讲话的3个人，使用此接口需要在初始化时设置needSpeakers=YES，此接口返回讲话者id，用户可以从NemoRosters中查询用户名
///
/// @param speakers 讲话的人
- (void)nemoSDKDidSpeakersChanged:(NSArray <NemoSpeakers *>*)speakers;

/// 啸叫检测
///
/// 当多台设备距离比较近时容易引发啸叫从而触发此接口，detected=YES代表检测到啸叫，detected=NO代表啸叫结束
///
/// @param detected 是否探测到啸叫
- (void)nemoSDKDidHowlingDetected:(BOOL)detected;

/// 系统音量变化
///
/// @param value 音量值
- (void)nemoSDKDidSystemVolumeDidChanged:(CGFloat)value;

/// 代理服务器测试接口回调
///
/// 设置代理服务器时，小鱼提供了测试接口validateSocksProxy，测试结果从此接口返回
///
/// @param result 结果 成功时返回OK，失败返回其他信息
- (void)nemoSDKDidSocksProxyValidateResult:(NSString *)result;

/// XYRTCSDK 错误回调，详见错误码
///
/// 在使用小鱼SDK过程中，监听此接口以获得异常反馈
///
/// @param code 错误码
/// @param message 错误信息
- (void)nemoSDKDidError:(NSString *)code message:(NSString *)message;

@end


@interface NemoSDK : NSObject

@property (nonatomic, weak) id <NemoSDKDelegate> delegate;

#pragma mark ---------- 初始化登录 相关接口 -----------

/// 单例
+ (NemoSDK *)sharedInstance;

/// 初始化NemoSDk环境
///
/// 此接口参数settings包含企业ID、服务器地址、socks代理和一些控制开关
/// “初始化之后想要更改企业ID（extID）、服务器地址（server、httpPort、httpsPort）、
/// socks代理（SocksProxyIp、SocksProxyPort、SocksProxyUserName、SocksProxyPassword），
/// 需要先退出登录，重新初始化相关参数，最后再重新登录，此时才能正确切换环境”
///
/// @param settings 初始化参数
- (void)shareNemoSessionSettings:(XYSettings *)settings;

/// 登录外部用户
///
/// 登录之后才可以使用SDK提供的会议服务，为了避免重复登录，请您务必在登录前调用“- (BOOL)isLogon"接口检查当前是否已经登录
/// extUserId是SDK标识用户的唯一凭据，每位用户只能有唯一一个extUserId与之对应
///
/// 回调方法 ”- (void)nemoSDKDidLoginResult:(nullable XYUser *)user success:(BOOL)success“
///
/// @param extUserId 用户唯一id，最大50个字符，支持大小写英文字母、数字、上横线“-”、下横线“_”
/// @param userName 外部用户名
/// @param enterpriseId 企业ID
- (void)loginExternalAccount:(NSString * _Nonnull)extUserId
                    userName:(NSString * _Nullable)userName
                enterpriseId:(NSString *)enterpriseId;

/// 小鱼用户登录
///
/// 小鱼账号登录接口，您可以通过小鱼易连App注册账号后使用此接口登录SDK
/// 小鱼易连App下载地址：https://www.xylink.com/download
///
/// @param userName 小鱼系统用户账号
/// @param password 小鱼系统用户密码
- (void)loginXYLinkAccount:(NSString *)userName
                  password:(NSString *)password;

/// 第三方授权登录
///
/// @param account 账户
/// @param token token(需要自己获取)
- (void)loginExternalAccountByToken:(NSString *)account
                              token:(NSString *)token;

/// 企业免密登录
///
/// @param account 账号
- (void)loginEnterpriseAccount:(NSString*)account;

/// 退出登录
///
/// 回调方法”- (void)nemoSDKDidLogoutState:(BOOL)success“
///
- (void)logout;

/// 登录状态
- (BOOL)isLogon;

/// WS连接状态
- (BOOL)isWSConnected;

/// 上传log
///
/// 上传日志，小鱼SDK会收集用户的操作日志，存储在/Documents目录下，
/// 日志文件最多存储10份，每份10M，共100M，均以vulture命名，
/// 调用此接口时SDK内部会自动读取日志文件并上传，您只需要传入遇到的问题描述即可，
/// log等级默认为XYLogLevel_Debug，如果您初始化时设置了其他等级，小鱼将不在收集日志，如无必要请勿设置此参数
///
/// 回调方法”- (void)nemoSDKDidUploadLogFileErrorInfo:(NSString *)errorInfo“
///
/// @param comments 问题描述
- (void)sendFeedbackLogWithComments:(NSString *)comments;

/// 获取版本号
- (NSString *)version;

#pragma mark ---------- 会议 相关接口 -----------

/// 呼叫入会
///
/// 请监听nemoSDKDidConnectStateWithNemo：接口先查看是否连接服务器，再做呼叫操作。不要在loginResult：之后直接调用呼叫操作
/// 调用此接口即可进入小鱼会议室，您需要监听会议状态回调接口来确认是否入会成功，根据返回的呼叫状态参数处理相应的逻辑
///
/// 回调方法”- (void)nemoSDKDidCall:(NSString *)number stateChanged:(NemoCallState)callState reason:(NSString *)reason“
///    NemoCallState_Connected = 0,    ///<已连接，代表入会成功
///    NemoCallState_DisConnected,     ///<未连接，代表会议结束
///    NemoCallState_Connecting,       ///<正在连接，代表正在呼叫中
///
/// @param number 会议号或终端号，不可为空
/// @param password 会议密码或终端密码，可为空
/// @param config 会议配置参数
- (void)makeCall:(NSString *)number password:(NSString *)password config:(NemoCallConfig * _Nullable)config;

/// 挂断当前会议
///
/// 回调方法 ”- (void)nemoSDKDidCall:(NSString *)number stateChanged:(NemoCallState)callState reason:(NSString *)reason“
///
- (void)hangup;

/// 接受会议邀请
///
/// 回调方法 ”- (void)nemoSDKDidCall:(NSString *)number stateChanged:(NemoCallState)callState reason:(NSString *)reason“
///
- (void)answer;

/// 拒绝会议邀请
///
/// 回调方法 ”- (void)nemoSDKDidCall:(NSString *)number stateChanged:(NemoCallState)callState reason:(NSString *)reason“
///
- (void)reject;

/// 是否在会议中
- (BOOL)isInMeeting;

/// 是否开启语音模式
/// @param audio 开启或关闭
- (void)audioMode:(BOOL)audio;

/// 请求视频流
///
/// 通过nemoSDKDidRosterChanged回调接口拿到参会者信息之后，您可以根据业务需求选择性的请求一路或多路视频流，
/// 此接口调用后会触发nemoSDKDidVideoChanged回调，返回指定参会者的视频流数据
///
/// 注意：此接口最多支持一次请求6路远端视频流
///
/// @param layoutInfo 布局信息
- (void)setCustomLayout:(NemoCustomLayoutInfo *)layoutInfo;

/// 创建video视图
///
/// 渲染视频流接口，通过nemoSDKDidVideoChanged回调接口拿到视频流信息后，调用此接口将视频渲染到您的UI上
///
/// @param videoCanvas 视频信息
- (void)setupVideo:(NemoVideoCanvas *)videoCanvas;

/// 更新video视图
///
/// 已经渲染并展示的是视频流，如果状态发生变化，需要调用此接口更新
///
/// @param videoCanvas 视频信息
- (void)updateVideo:(NemoVideoCanvas *)videoCanvas;

/// 设置本地视频预览视图，调用此方法会占用摄像头，设置完成后请务必调用finishSetVideoPreview释放资源
/// @param preview 预览视图
- (void)setVideoPreview:(UIView *)preview;

/// 设置完成，释放占用资源
- (void)finishSetVideoPreview;

/// 设置虚拟背景样式
/// @param mode 虚拟背景模式
/// NemoVirtualBackgroundModeClose 无背景
/// NemoVirtualBackgroundModeBlur 背景模糊
/// NemoVirtualBackgroundModeImage 图片选择 image 必传
/// @param image 图片
/// @param width 图片宽度 无背景、背景模糊 0
/// @param height 图片高度 无背景、背景模糊 0
- (void)setVirtualBackgroudMode:(NemoVirtualBackgroundMode)mode
                          image:(UIImage * _Nullable)image
                     imageWidth:(NSInteger)width
                    imageHeight:(NSInteger)height;

#pragma mark ---------- 音视频控制 相关接口 -----------
/// 开启音频，调用此方法来创建音频单元
///
/// 入会成功后调用此接口
///
- (void)startAudio;

/// 结束音频，调用此方法来销毁音频单元
///
/// 会议结束后调用此接口
///
- (void)stopAudio;

/// 开启或关闭麦克风
///
/// 关闭后，本地语音不会发送到远端
///
/// @param enable 麦克风是否静音
- (void)enableAudioOfMic:(BOOL)enable;

/// 麦克风是否关闭
- (BOOL)isLocalMicMuted;

/// 开启或关闭扬声器
/// @param enable 开启为扬声器，关闭为听筒
- (void)enableAudioOfSpeaker:(BOOL)enable;

/// 外放，mute后扬声器和听筒无音频播放
///
/// mute后，本地听不到远端的语音
///
/// @param mute 是否静音
- (void)setSpeakerMute:(BOOL)mute;

/// 外放是否静音
- (BOOL)isSpeakerMuted;

/// 是否开启视频
/// @param enable 开启或关闭
- (void)enableVideo:(BOOL)enable;

/// 视频是否关闭
- (BOOL)isLocalVideoMuted;

/// 切换摄像头
/// @param direction 摄像头方向
- (void)switchCamera:(AVCaptureDevicePosition)direction;

/// 设置手电筒
///
/// 手电筒只有在后置摄像头模式下才能打开
///
/// @param mode 手电筒开关
- (void)switchTorchMode:(AVCaptureTorchMode)mode;

/// 设置手电筒等级
/// @param level 手电筒等级 0~1
- (void)torchLevel:(float)level;

/// 手电筒开关状态
- (AVCaptureTorchMode)torchMode;

#pragma mark ---------- 会中录制 相关接口 -----------
/// 检查录制权限
/// @param meetingNumber 会议号码
/// @param handler isRecordable 是否可录制 recordingUrl 录制地址 errorInfo 错误信息）
- (void)checkPermissionWithMeetingNumber:(NSString* )meetingNumber
                              completion:(void (^)(BOOL isRecordable, NSString *recordingUrl, NSString *errorInfo))handler;

/// 检查存储空间
/// @param recordingUrl 录制地址
/// @param handler （isStorage  是否有存储空间 errorInfo  错误信息）
- (void)checkSorageSpaceWithRecordingUrl:(NSString* )recordingUrl
                              completion:(void (^)(BOOL isStorage,NSString *errorInfo))handler;

/// 开始录制
///
/// 在开启录制前，请务必检查 录制权限 和 存储空间，确保有录制权限并且有可用存储空间的情况下再开启录制
///
/// @param recordingUrl 录制地址
- (void)startRecordingWithRecordingUrl:(NSString *)recordingUrl;

/// 结束录制
///
/// 录制结束后，录制的视频可以通过小鱼服务端api获取 "https://openapi.xylink.com/api_server/api"
///
/// @param recordingUrl 录制地址
- (void)stopRecordingWithRecordingUrl:(NSString *)recordingUrl;

#pragma mark ---------- 交互互动 相关接口 -----------
/// 开启白板
///
/// 主动发起白板时调用，如果是会中远端用户发起的白板则不需要调用此接口
///
- (void)startWhiteboard;

/// 关闭白板
///
/// 主动发起的白板，需要关闭时调用
///
- (void)stopWhiteboard;

/// 白板状态
- (NemoWhiteboardRemoteState)whiteboardState;

/// 发送白板消息
///
/// 发送本地白板画线等消息，消息格式请参阅demo
///
/// @param data 数据
/// @param type 类型
- (void)sendDataWhiteboard:(nullable id)data type:(NemoWhiteboardOperationState)type;

/// 获取会控地址
- (NSString *)getMeetingHost;

/// 举手发言
///
/// 当主持人设置了全场静音并且不允许用户解除静音时，想要说话必须先 举手发言，等待主持人同意
/// 主持人同意的动作从 nemoSDKDidConferenceManagementStateChanged 接口回调
///
- (void)informManagerForRequestToSpeak;

/// 取消举手发言
///
/// 举手发言后主持人还未同意时，可以取消举手发言
///
- (void)informManagerForCancelSpeak;

/// 发言完毕
///
/// 发言结束后，调用此接口告知会控
///
- (void)informManagerForEndSpeak;

/// 开始分享content，分享屏幕仅支持iOS12及以上系统
/// @param type 类型
/// @param enableAnnotation 是否开启标注，只有type=NemoShareContentType_Image时，此参数有效
/// @param bundleID extension bundle id
- (void)startContentSharing:(NemoShareContentType)type
           enableAnnotation:(BOOL)enableAnnotation
                   bundleID:(NSString *_Nullable)bundleID;

/// 发送数据
///
/// 2.29.3及以上版本此接口只用来发送分享图片数据，分享手机屏幕接口请集成XYRTCEngineExtension.framework
///
/// @param content
///       type：类型
///       image：发送的图片数据，type = NemoShareContentType_Image 时有效
///       imageFrameRate：发送图片帧率 type = NemoShareContentType_Image 时有效，默认5针
- (void)sendContentMsg:(NemoContent *)content;

/// 停止分享
- (void)stopContentSharing;

/// 开启标注
- (void)startAnnotation;

/// 关闭标注
- (void)stopAnnotation;

/// 发送标注消息
///
/// 消息数据类型详情请查看demo
///
/// @param message 消息数据（json）
- (void)sendAnnotationMessage:(NSString *)message;

#pragma mark ---------- 其他通用功能 相关接口 -----------
/// 订阅roster 最多40个
///
/// SDK默认最多返回20个参会者信息，如果您会议中超过20人，想看20以后的参会者画面，则需要调用此接口订阅对应的参会者
/// 订阅后，nemoSDKDidRosterChanged接口会返回订阅的人
///
/// @param devices callUrl
- (void)subscribeRoster:(NSArray *)devices;

/// 请求参会者信息
///
/// 如果新想查看第20个以后的参会这信息，可以调用此接口分页获取参会者信息
///
/// @param startIndex 起始位置
/// @param length 长度（最大20）
- (void)requestRoster:(int)startIndex length:(int)length;

/// 根据ID获取指定视频流
/// @param streamID 视频流ID
/// @param completion 回调
- (void)getVideoStreamWithID:(NSString *)streamID
                  completion:(void (^)(int size, void *stream))completion;

/// 获取语音能量值
/// @param completion （peak 检测是否成功 meters 测量值）
- (void)getAudioPeakMetersCompletion:(void (^)(bool peak, NSArray *meters))completion;

/// 修改云会议室密码
/// @param number 云会议室号
/// @param password 新密码
/// @param completion 结果回调
- (void)updateCloudMeetingRoom:(NSString *)number
                      password:(NSString *)password
                    completion:(void (^)(BOOL success, id responseObject))completion;

/// 修改名称
/// @param displayName 名字，用于会中显示
/// @param completion 回调
- (void)modifyDisplayName:(NSString *)displayName
               completion:(void (^)(BOOL success, id responseObject))completion;

/// 旁路音频开关（入会之前设置）
/// @param enable 是否打开
- (void)setMicDataByAEReadyEnabled:(BOOL)enable;

/// 获取本地一帧视频数据
- (NSData *)getLocalVideoData;

/// 配置输出视频最大支持分辨率
/// @param dimension 最大支持分辨率
- (void)setVideoConfiguration:(XYVideoDimension)dimension;

/// 对URL进行签名
/// @param url 待签名的URL
/// @param methodType 请求方法
/// @param params 参数的json序列
/// @param token 签名需要的密钥
- (NSString *)signUrl:(NSString *)url
           methodType:(NSString *)methodType
               params:(NSString *)params
                token:(NSString *)token;

#pragma mark ---------- 小鱼硬件 相关接口 -----------
/// 远端硬件控制
/// @param participantID 参会人ID
/// @param operation 方向
- (void)farEndHardwareControl:(NSString *)participantID operation:(XYFECCOperation)operation;

/// DTMF
/// @param remoteUri 远端ID，从<NemoLayout>回调中获得
/// @param content 内容
- (void)dialDtmfWithRemoteUri:(NSString *)remoteUri content:(NSString *)content;

#pragma mark ---------- 网络设置 相关接口 -----------
/// 开始网络测试
/// @param completion 回调
- (void)startNetworkTestCompletion:(void (^)(NemoNetTestResult *_Nullable result, NemoNetworkTestCode testError))completion;

/// 结束网络测试
- (void)stopNetworkTest;

/// 线路配置
/// @param complete 回调
- (void)getSitePaths:(void (^)(NSArray <NemoSitePathInfo *>*infos))complete;

/// 保存线路配置
/// @param info 线路信息
/// @param complete 回调
- (void)configSitePath:(NemoSitePathInfo *)info
              complete:(void (^)(BOOL isSuccess))complete;

/// 删除线路配置
/// @param info 线路信息
/// @param complete 回调
- (void)deleteSitePath:(NemoSitePathInfo *)info
              complete:(void (^)(BOOL isSuccess))complete;

/// 测试代理服务器
/// @param ip 地址
/// @param port 端口
/// @param userName 用户名
/// @param password 密码
- (void)validateSocksProxy:(NSString *)ip
                      port:(NSString *)port
                  userName:(NSString *)userName
                  password:(NSString *)password;

/// 设置代理服务器
/// @param ip 地址
/// @param port 端口
/// @param userName 用户名
/// @param password 密码
- (void)setSocksProxy:(NSString *)ip
                 port:(NSString *)port
             userName:(NSString *)userName
             password:(NSString *)password;

#pragma mark ---------- 统计会议信息 相关接口 -----------
/// 获取统计信息
- (NSString *)getGeneralStatistics;

/// DBA信息
- (NSString *)getDBStatistics;

/// layout信息
- (NSString *)getLayoutStatistics;

/// 视频发送信息
- (NSString *)getVideoTxStatistics;

/// 视频接收信息
- (NSString *)getVideoRxStatistics;

/// 音频发送信息
- (NSString *)getAudioTxStatistics;

/// 音频接收信息
- (NSString *)getAudioRxStatistics;

/// 其他信息
- (NSString *)getOtherStatistics;


@end

NS_ASSUME_NONNULL_END
