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
#define LOCAL @"LocalStreamID" //本地视频流的ID

@class UIImage;

NS_ASSUME_NONNULL_BEGIN



#pragma mark XYVideoConfig -- 视频输出配置

@interface XYVideoConfig : NSObject

@property (nonatomic, assign) XYVideoDimension videoDimension;

@end



#pragma mark XYSettings -- 初始化设置

@interface XYSettings : NSObject

@property (nonatomic, copy) NSString *extID;//企业ID

@property (nonatomic, copy, nullable) NSString *server;//server地址,不设置则默认cloud.xylink.com

@property (nonatomic, assign) XYLogLevel level;//log等级

@property (nonatomic, assign) BOOL enableLog;//是否打印log

@property (nonatomic, assign) BOOL needAudioMeter;//是否需要音量探测

@property (nonatomic, assign) NSInteger defaultCameraId;//0:后置摄像头,1:前置摄像头

@property (nonatomic, strong) XYVideoConfig *videoConfig;

+ (XYSettings *(^)())settings;//XYSettings统一初始化方法

@end

#pragma mark XYUser -- 用户信息

@interface XYUser : NSObject

@property (nonatomic, assign) long userId; // 用户ID

@property (nonatomic, assign) long deviceId;//设备ID

@property (nonatomic, assign) int deviceType;//设备类型

@property (nonatomic, copy) NSString *callNumber;//号码

@property (nonatomic, copy) NSString *error;//错误信息

@property (nonatomic, copy) NSString *deviceDisplayName;

@end



#pragma mark NemoLayout -- 视频流信息

@interface NemoLayout : NSObject

@property (nonatomic, copy) NSString *remoteName;//远端名称

@property (nonatomic, copy) NSString *streamID;//视频流ID

@property (nonatomic, copy) NSString *participantId;//参会人ID

@property (nonatomic, assign) BOOL isContent;//是否是content

@property (nonatomic, assign) BOOL isAudioMute;//是否静音

@property (nonatomic, assign) BOOL isActiveSpeaker;//是否发言

@property (nonatomic, assign) NemoStreamState layoutState;//视频流状态

@property (nonatomic, assign) XYDataType dataType;//远端类型

@property (nonatomic, assign) long remoteID;//远端ID

@property (nonatomic, copy) NSString *remoteUri;//远端uri

@property (nonatomic, assign) XYVideoMuteReason videoMuteReason;//视频关闭原因

@property (nonatomic, assign) unsigned int feccOri;

@property (nonatomic, copy) NSString *remoteAlias;

@end



#pragma mark NemoRosterInfo -- 视频流信息

@interface NemoRosterInfo : NSObject

@property (nonatomic, assign) int participantId;//参会人ID

@property (nonatomic, assign) int feccOri;//fecc能力值

@property (nonatomic, assign) int  weight;

@property (nonatomic, assign) XYDataType deviceType;

@property (nonatomic, copy) NSString *deviceId;//设备ID

@property (nonatomic, copy) NSString *deviceName;//设备名

@property (nonatomic, copy) NSString *deviceAlias;//设备别名

@property (nonatomic, assign) BOOL isTelephone;//是否是电话

@property (nonatomic, assign) BOOL isObserver;

@property (nonatomic, assign) BOOL isAudioOnly;//是否只有语音

@property (nonatomic, assign) BOOL isAudioMute;//是否静音

@property (nonatomic, assign) BOOL isVideoMute;//是否关闭视频

@property (nonatomic, assign) BOOL isForceFullScreen;//是否被force到大屏

@property (nonatomic, assign) BOOL isRequested; //requestRoster主动请求

@end



#pragma mark NemoRosters -- 远端Roster信息

@interface NemoRosters : NSObject

@property (nonatomic, strong) NSArray *peopleRosters;//所有远端详细Roster信息，目前最大接受20个参会信息

@property (nonatomic, strong) NSArray *contentRosters;//所有远端详细Roster信息，目前最大接受20个参会信息

@property (nonatomic, assign) int numberOfPeople;//远端人数，会议中除自己外的总参会人数

@property (nonatomic, assign) NemoCallMode callMode;

@property (nonatomic, assign) int contentSenderPid;

@property (nonatomic, assign) int activeSpeakerPid;

@property (nonatomic, assign) int subscribeSequence;

@property (nonatomic, assign) BOOL recvingVideoContent;

@property (nonatomic, assign) BOOL recvingPictureContent;

@property (nonatomic, assign) BOOL hasOtherParticipants;

@end



#pragma mark NemoCustomLayoutElement -- 自定义布局元素

@interface NemoCustomLayoutElement : NSObject

/** 参会人ID */
@property (nonatomic, assign) int participantId;

/** 分辨率 NemoVideoResolution */
@property (nonatomic, assign) NemoVideoResolution resolution;

/** 布局优先级 NemoLayoutPriority */
@property (nonatomic, assign) NemoLayoutPriority priority;

/** 视频质量 NemoVideoQuality */
@property (nonatomic, assign) NemoVideoQuality quality;

@end


#pragma mark NemoCustomLayoutInfo -- 自定义布局信息

@interface NemoCustomLayoutInfo : NSObject

@property (nonatomic, strong) NSMutableArray <NemoCustomLayoutElement *> *layoutElements;

@end



#pragma mark NemoUserProfile -- 用户

@interface NemoUserProfile : NSObject

@property (nonatomic, assign) long objectId;

@property (nonatomic, copy) NSString *displayName;

@property (nonatomic) BOOL debug;

@property (nonatomic, copy) NSString *avatar;

@property (nonatomic, copy) NSString *number;

@end



#pragma mark NemoConfMgmtInfo -- 会控

@interface NemoConfMgmtInfo : NSObject

@property (nonatomic, assign) BOOL isChairmanMode;

/** 主会场ID（会控管理员设置的主会场，其他参会者的画面会切为主会场视频）*/
@property (nonatomic, copy)  NSString *chairmanUri;

@property (nonatomic, assign) bool muteIsDisabled;

@property (nonatomic, assign) bool feccIsDisabled;

@property (nonatomic, assign) bool contentIsDisabled;

@property (nonatomic, assign) bool recordIsDisabled;

@property (nonatomic, assign) bool whiteboardIsDisabled;

@end



#pragma mark NemoFacePosition -- 人脸位置信息

@interface NemoFacePosition : NSObject

/** 人脸的id */
@property (nonatomic, assign) long faceId;

/** 检测人脸的左侧距离 */
@property (nonatomic, assign) long left;

/** 检测人脸的顶部距离 */
@property (nonatomic, assign) long top;

/** 检测人脸的右侧距离 */
@property (nonatomic, assign) long right;

/** 检测人脸的底部距离 */
@property (nonatomic, assign) long bottom;

@end



#pragma mark NemoFaces -- 人脸识别

@interface NemoFaces : NSObject

/** 参会人ID */
@property (nonatomic, assign) long participantId;

/** 备用字段, type */
@property (nonatomic, assign) int type;

/** 备用字段, seq */
@property (nonatomic, assign) int seq;

/** 返回的人脸位置信息列表 */
@property (nonatomic, strong) NSMutableArray <NemoFacePosition *>*positionVec;

@end



#pragma mark - AICaptionInfo

@interface AICaptionInfo : NSObject

/** 参会人ID */
@property (nonatomic, assign) long pid;

/** 源 */
@property (nonatomic, copy) NSString *src;

/** 翻译后 */
@property (nonatomic, copy) NSString *target;

/** 一句话是否已结束 */
@property (nonatomic, assign) BOOL isEnd;

/** 收三路，同时只有一路active */
@property (nonatomic, assign) BOOL isActive;

@end

@interface NemoCaptionInfoModel : NSObject
@property (nonatomic, assign) BOOL display;
@property (nonatomic, copy) NSString * content;
@property (nonatomic, assign) NemoCaptionLocation location;
@property (nonatomic, assign) BOOL scroll;
@property (nonatomic, strong) NSString *scrollSpeed;
@property (nonatomic, strong) NSString * bgColor;
@property (nonatomic, assign) CGFloat bgColorAlpha;
@property (nonatomic, strong) NSString * fontColor;
@property (nonatomic, strong) UIFont * font;
@property (nonatomic, assign) NemoCaptionFontSize fontType;
@end



#pragma mark - NemoSDK Callback
/*******************************************************************************/

@protocol NemoSDKDelegate <NSObject>

@optional

/**
 登录外部账户的结果(成功时返回账户号码，失败时返回错误原因)

 @param user 是否登录成功
 @param success 登陆成功时返回分配的账号信息，登录失败时为nil
 */
- (void)loginResult:(nullable XYUser *)user success:(BOOL)success;

/**
 登录后与小鱼的连接状态

 @param isConnect 是否连接
 */
- (void)connectStateWithNemo:(BOOL)isConnect;


/**
 登出状态
 
 @param success    登出是否成功
 */
- (void)logoutState:(BOOL)success;


/**
 与服务器连接状态和在线状态的回调
 
 @param kick    同一个账号在其他设备登录时，该账号在之前的设备会被强制下线
 */
- (void)accountWasKickOut;


/**
 呼叫异常的回调
 
 @param number     号码
 @param reason  异常说明
 */
- (void)nemoSDKDidCall:(NSString *)number
                failed:(NSString *)reason;


/**
 呼叫状态的回调
 
 @param number    号码
 @param callState 呼叫状态
 @param reason    异常状态原因
 */
- (void)nemoSDKDidCall:(NSString *)number
          stateChanged:(NemoCallState)callState
                reason:(NSString *)reason;


/**
 来电的回调
 
 @param number         号码
 @param displayName    名称
 */
- (void)nemoSDKDidReceiveCall:(NSString *)number
                  displayName:(NSString *)displayName;


/**
 双流状态改变的回调

 @param state NemoDualState
 */
- (void)nemoSDKDidDualStreamStateChanged:(NemoDualState)state reason:(NSString *)reason;


/**
 通话视频信息改变回调
 
 @param videos 当前通话视频信息，与会人Stream信息数组(包含streamID和其他stream信息)
 */
- (void)nemoSDKDidVideoChanged:(NSArray<NemoLayout*> *)videos;


/**
 Roster发生改变的回调

 @param rosters 参考NemoRosters
 */
- (void)nemoSDKDidRosterChanged:(NemoRosters *)rosters;

/**
 会控消息的回调

 @param type 会控消息
 @param confMgmtInfo 参考NemoConfMgmtInfo
 */
- (void)nemoSDKDidConferenceManagementStateChanged:(NemoConferenceManagerManagementType)type confMgmtInfo:(NemoConfMgmtInfo *)info;

/**
 录制状态
 
 @param start 录制是否开始
 */
- (void)nemoSDKDidRecordingStateChanged:(BOOL)start;


/**
 视频状态变化提示
 
 @param state 当前视频状态
 */
- (void)nemoSDKDidVideoStateChanged:(XYVideoState)state;


/**
 网络等级指示，本地网络质量提示回调
 通常用于通话中显示本地信号强度
 
 @param level网络等级(共分为4个等级-> 1 2 3 4，由低到高分别为差，中，良，优)
 */
- (void)nemoSDKNetworkIndicatorLevel:(int)level;


/**
 呼叫中心提示回调
 
 @param msg 信息
 */
- (void)nemoSDKIMNotification:(NSString *)msg;


/**
 音频注册回调被修改时调用
 
 */
- (void)nemoSDKDidAudioInterrupt:(BOOL)began;

/**
 音频单位注册回调被出现错误时调用
 
 */
- (void)nemoSDKDidAudioInitFailed:(NSString *)error;

/**
 日志上传结果回调

 @param errorInfo 错误信息
 @param sender 发送者
 */
- (void)nemoSDKDidUploadLogFileErrorInfo:(NSString *)errorInfo sender:(id)sender;

/**
 远端人脸识别

 @param faces 参考NemoFaces
 */
- (void)nemoSDKAiFaceReceive:(NemoFaces *)faces;

/**
 本地人脸识别

 @param faces 参考NemoFaces
 */
- (void)nemoSDKLocalFaceDetected:(NemoFaces *)faces;


/**
 白板改变状态
 
 @param remoteState 远端状态
 @param reason 原因
 */
- (void)nemoSDKWhiteboardDidStateChanged:(NemoWhiteboardRemoteState)remoteState
                                  reason:(NSString *)reason;


/**
 白板远端消息
 
 @param remoteMessage remoteMessage description
 */
-(void)nemoSDKWhiteboardDidReceieved:(id)remoteMessage
                                type:(NemoWhiteboardOperationState)type;


/**
 同传字幕回调

 @param aiCaptionInfo aiCaptionInfo
 */
-(void)nemoSDKDidAiCaptionInfo:(AICaptionInfo *)aiCaptionInfo;

/**
 旁路音频数据回调
 
 @param size 数据大小
 @param data 音频数据
 */
- (void)nemoSDKDidMicDataByAEReady:(int)size data:(void *)data;

/**
 屏幕共享开始
 */
-(void)nemoSDKScreenSharingStarted;

/**
 屏幕共享结束
 */
-(void)nemoSDKScreenSharingStopped;

/**
 接收到字幕回调

 @param display 显示/隐藏
 @param content 字幕内容
 @param duration 显示时长
 @param location 显示位置
 @param speed 滚动速度
 */
- (void)nemoSDKDidRecieveCaptionDisplay:(NemoCaptionInfoModel *)captionInfo;

@end



#pragma mark - NemoSDK
/*******************************************************************************/

@interface NemoSDK : NSObject


@property (nonatomic, weak) id <NemoSDKDelegate> delegate;

/** 来电是否已被其他终端响应 (同一账号在不同平台登录时，需要判断状态) */
@property (readonly, nonatomic, assign) BOOL isComingCallDispose;
/**
 初始化NemoSDk环境

 @param settings 初始化参数
 @return NemoSDK
 */
+ (NemoSDK *)shareNemoSessionSettings:(XYSettings *)settings;


/**
 登录外部用户
 
 @param extUserId 外部用户ID，唯一用户标示，需保证唯一，建议使用自己业务系统的UserID
 @param userName 外部用户名
 @param enterpriseId 企业ID
 */
- (void)loginExternalAccount:(NSString * _Nonnull)extUserId
                    userName:(NSString * _Nullable)userName
                enterpriseId:(NSString *)enterpriseId;


/**
 小鱼用户登录
 
 @param userName  小鱼系统用户名
 @param password  小鱼系统用户密码
 */
- (void)loginXYLinkAccount:(NSString *)userName
                  password:(NSString *)password;


/**
 第三方授权登录

 @param account 账户
 @param token token(需要自己获取)
 */
- (void)loginExternalAccountByToken:(NSString *)account
                              token:(NSString *)token;

/** 退出登录 */
- (void)logout;


/**
 对URL进行签名
 
 @param url        待签名的URL
 @param methodType 请求方法
 @param params     参数的json序列
 @param token      签名需要的密钥
 
 @return 签名字符串
 */
+ (NSString *)signUrl:(NSString *)url
           methodType:(NSString *)methodType
               params:(NSString *)params
                token:(NSString *)token;


/**
 呼叫
 
 @param number      会议号或终端号，不可为空
 @param password    会议密码或终端密码，可为空
 
 备注：请使用connectStateWithNemo：查先查看是否连接服务器，在做呼叫操作。不要在loginResult：之后调用呼叫操作。
 */
- (void)makeCall:(NSString *)number
        password:(NSString *)password
     orientation:(NemoVideoOrientation)orientation;

/**
 切换横竖屏
 @param orientation
 */
- (void)changeVideoOrientation:(NemoVideoOrientation)orientation;

/**
 开启音频（可以根据需要在不同的呼叫状态开启音频）
 当YES扬声器，当NO时变成听筒
 */
- (void)speakerOnModeDefault:(BOOL)enable;

/** 关闭音频所有操作 */
- (void)stopAudio;

/** 接听来电 */
- (void)answer:(NemoVideoOrientation)orientation;

/**
 挂断来电
 @param mode 挂断方式
 */
- (void)hangup:(NemoHangUpMode)mode;


/**
 *  登录状态
 */
- (BOOL)isLogon;


/**
 *  WS连接状态
 */
- (BOOL)isWSConnected;


/**
 *  是否在会议中
 */
- (BOOL)isInMeeting;


/**
 根据ID获取指定视频流
 
 @param streamID   视频流ID (ID为LOCAL时获取本地视频流)
 @param completion 视频流的回调
 */
- (void)getVideoStreamWithID:(NSString *)streamID
                  completion:(void (^)(int size, void *stream))completion;


/**
 获取语音能量值
 
 @param peak 检测是否成功
 @param meters 测量值
 */
- (void)getAudioPeakMetersCompletion:(void (^)(bool peak, NSArray *meters))completion;

/**
 是否开启视频
 */
- (void)enableVideo:(BOOL)enable;


/**
 是否开启语音模式
 */
- (void)audioMode:(BOOL)audio;


/**
 设置摄像头
 
 @param type摄像头类型
 */
- (void)switchCamera:(NemoDeviceType)type;

/**
 设置手电筒
 
 @param mode 手电筒开关
 */
- (void)switchTorchMode:(NemoTorchMode)mode;

/**
 设置手电筒等级
 
 @param level 手电筒等级 0~1
 */
- (void)torchLevel:(float)level;

/**
 手电筒开关状态
 
 */
- (NemoTorchMode)torchMode;


/**
 开启或关闭麦克风
 
 @param enable 麦克风是否静音
 */
- (void)enableAudioOfMic:(BOOL)enable;


/**
 开启或关闭扬声器
 
 @param enable是否可用
 */
- (void)enableAudioOfSpeaker:(BOOL)enable;


/** 举手发言*/
- (void)informManagerForRequestToSpeak;


/** 取消举手发言 */
- (void)informManagerForCancelSpeak;


/** 发言完毕 */
- (void)informManagerForEndSpeak;


/** 获取统计信息 */
- (NSString *)getGeneralStatistics;


/** 获取版本号 */
+ (NSString *)version;

/**
订阅roster
 
订阅后，会下发指定的roster，devices最多40个

 @param devices callUrl
*/
- (void)subscribeRoster:(NSArray *)devices;

/**
请求roster
 
 @param startIndex 起始位置
 @param length 长度（最大20）
*/
- (void)requestRoster:(int)startIndex length:(int)length;

/**
 修改云会议室密码
 
 @param number 云会议室号
 @param password 新密码
 @param completion 结果回调
 */
- (void)updateCloudMeetingRoom:(NSString *)number
                      password:(NSString *)password
                    completion:(void (^)(BOOL success, id responseObject))completion;


/**
 检查录制权限
 
 @param handler
 
 @param meetingNumber 会议号码
 @param handler  存储地址 错误信息
 @param isRecordable 是否可录制
 @param recordingUrl 录制地址
 @param errorInfo 错误信息
 */
- (void)checkPermissionWithMeetingNumber:(NSString* )meetingNumber
                              completion:(void (^)(BOOL isRecordable, NSString *recordingUrl, NSString *errorInfo))handler;


/**
 检查存储空间
 
 @param recordingUrl 录制地址
 @param handler  是否有存储空间 错误信息
 @param isStorage  是否有存储空间
 @param errorInfo  错误信息
 */
- (void)checkSorageSpaceWithRecordingUrl:(NSString* )recordingUrl
                              completion:(void (^)(BOOL isStorage,NSString *errorInfo))handler;
/** 开始录制
 
 @param recordingUrl 录制地址
 */
- (void)startRecordingWithRecordingUrl:(NSString *)recordingUrl;

/** 结束录制
 
 @param recordingUrl 录制地址
 */
- (void)stopRecordingWithRecordingUrl:(NSString *)recordingUrl;


/// 获取当前用户信息
- (NemoUserProfile *)getUserProfile;


/**
 远端硬件控制
 
 @param participantID 参会人ID
 @param operation 方向
 */
- (void)farEndHardwareControl:(NSString *)participantID operation:(XYFECCOperation)operation;


/**
 DTMF
 
 @param remoteID 远端ID
 @param dataType 远端类型
 @param content 内容
 */
- (void)dialDtmfWithRemoteID:(long)remoteID dataType:(XYDataType)dataType content:(NSString *)content;


/**
 feedback log
 
 配合 nemoSDKDidUploadLogFileErrorInfo:sender:使用
 
 @param comments 内容
 @param sender
 */
- (void)sendFeedbackLogWithComments:(NSString *)comments sender:(id)sender;

/** 设置自定义布局 */
- (void)setCustomLayout:(NemoCustomLayoutInfo *)layoutInfo;

/// 获取会控地址
- (NSString *)getMeetingHost;

/**
 获取本地视频信息

 @return NSData
 */
- (NSData *)getLocalVideoData;


/** 开启白板 */
- (void)startWhiteboard;

/** 关闭白板 */
- (void)stopWhiteboard;

/** 白板状态 */
- (NemoWhiteboardRemoteState)whiteboardState;

/** 发送白板消息 */
- (void)sendDataWhiteboard:(nullable id)data type:(NemoWhiteboardOperationState)type;

/**
 旁路音频开关（入会之前设置）

 @param enable 是否
 */
- (void)setMicDataByAEReadyEnabled:(BOOL)enable;
/**
 配置视频输出

 @param config 具体配置
 */
- (void)setVideoConfiguration:(XYVideoConfig *)config;

#pragma mark- share content
/**
 分享content开关
 
 @param open 是否打开分享
 @param contentType 分享的content类型
 */
-(void)switchShareContent:(BOOL)open contentType:(NemoShareContentType)contentType;

/**
 发送图片
 
 @param image 图片 默认5帧
 */
-(void)sendImage:(UIImage *)image;

/**
 发送图片
 
 @param image 图片
 @param frameRate 帧率 最大12帧  推荐 5帧  传0默认5帧
 */
-(void)sendImage:(UIImage *)image frameRate:(NSInteger)frameRate;

/// 是否需要打开音频或视频采集数据写入本地  音频写入文件在Document文件夹下 文件名nemo_shareContent_audio.pcm
/// @param type 写入数据类型
/// @param open 是否打开 （默认 NO）
+ (void)switchFileWriteByCaptureType:(NemoShareCaptureType)type open:(BOOL)open;


#pragma mark - 开发统计

- (NSString *)getDBStatistics;

- (NSString *)getLayoutStatistics;

/** 视频发送信息 */
- (NSString *)getVideoTxStatistics;

/** 视频接收信息 */
- (NSString *)getVideoRxStatistics;

/** 音频发送信息 */
- (NSString *)getAudioTxStatistics;

/** 音频接收信息 */
- (NSString *)getAudioRxStatistics;

/** 其他信息 */
- (NSString *)getOtherStatistics;

@end

NS_ASSUME_NONNULL_END
