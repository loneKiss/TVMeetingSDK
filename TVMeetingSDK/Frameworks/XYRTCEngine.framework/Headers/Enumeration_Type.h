//
//  Enumeration_Type.h
//  NemoSDK
//
//  Created by 杨旭东 on 16/9/30.
//  Copyright © 2016年 JackYang. All rights reserved.
//

#ifndef Enumeration_Type_h
#define Enumeration_Type_h

/// 呼叫状态
typedef NS_ENUM(NSInteger, NemoCallState) {
    NemoCallState_Connected = 0,    ///<已连接
    NemoCallState_DisConnected,     ///<未连接
    NemoCallState_Connecting,       ///<正在连接
};

/// 通话模式
typedef NS_ENUM(NSInteger, NemoCallMode) {
    NemoCallMode_Movie,     ///<视频
    NemoCallMode_Audio      ///<音频
};

/// 分享content类型
typedef NS_ENUM(NSInteger, NemoShareContentType) {
    NemoShareContentType_Image,     ///<分享图片
    NemoShareContentType_Screen     ///<分享屏幕
};

/// 分享content状态
typedef NS_ENUM(NSInteger, NemoShareContentState) {
    NemoShareContentState_Idle,            ///<闲置，停止发送
    NemoShareContentState_Acquiring,       ///<content开始发送
    NemoShareContentState_Sending,         ///<content发送中
    NemoShareContentState_Unsupported,     ///<不支持
    NemoShareContentState_NoBandwidth,     ///<带宽不足
    NemoShareContentState_Unknown          ///<未知
};

/// 视频流状态
typedef NS_ENUM(NSInteger, NemoStreamState) {
    NemoStreamState_Idle,                ///<闲置
    NemoStreamState_Observing,           ///<监听
    NemoStreamState_Mute,                ///<视频关闭
    NemoStreamState_Requesting,          ///<请求中
    NemoStreamState_NoBandwidth,         ///<带宽不足
    NemoStreamState_NoDecoder,           ///<无解码
    NemoStreamState_Received,            ///<正常接收
    NemoStreamState_Telephone,           ///<电话
    NemoStreamState_AudioOnly,           ///<只有音频
    NemoStreamState_ReceivedAudioOnly    ///<只收到音频
};

/// 会控状态
typedef NS_ENUM(NSInteger, NemoConferenceManagerManagementType) {
    NemoConferenceManagerManagementType_Default,           ///<无操作
    NemoConferenceManagerManagementType_Mute,              ///<静音
    NemoConferenceManagerManagementType_MuteMandatory,     ///<强制静音
    NemoConferenceManagerManagementType_Unmute,            ///<取消静音
    NemoConferenceManagerManagementType_UnmuteTemporary    ///<暂时取消静音
};

/// log级别
typedef NS_ENUM(NSInteger, XYLogLevel) {
    XYLogLevel_Error = 0,   ///<错误信息
    XYLogLevel_Warn,        ///<警告信息
    XYLogLevel_Info,        ///<媒体信息
    XYLogLevel_Debug        ///<调试信息
};

/// 远端类型
typedef NS_ENUM(NSInteger, NemoDeviceType) {
    NemoDeviceType_Unknown,         ///<未知
    NemoDeviceType_Contact = 1,     ///<人
    NemoDeviceType_Device,          ///<小鱼
    NemoDeviceType_MeetingRoom,     ///<云会议室
    NemoDeviceType_PSTN,            ///<电话
    NemoDeviceType_Desktop = 5,     ///<电脑
    NemoDeviceType_H323,            ///<323
    NemoDeviceType_Bruce,           ///<大鱼
    NemoDeviceType_Tvbox,           ///<tvbox
    NemoDeviceType_Shuttle          ///<监控
} ;

/// 视频关闭原因
typedef NS_ENUM(NSInteger, XYVideoMuteReason) {
    XYVideoMuteReason_MuteByUser,       ///<用户关闭视频
    XYVideoMuteReason_MuteByBWLimit,    ///<带宽限制
    XYVideoMuteReason_MuteByNoInput,    ///<没有输入
    XYVideoMuteReason_MuteByConfMgmt    ///<会控关闭
};

/// 视频状态
typedef NS_ENUM(NSInteger, NemoVideoState) {
    NemoVideoState_Normal,              ///<正常状态，ui不需要显示 ＝ 0
    NemoVideoState_LowAsLocalBw,        ///<本地网络不稳定 ＝ 1
    NemoVideoState_LowAsLocalHardware,  ///<系统忙，视频质量降低 ＝ 2
    NemoVideoState_LowAsRemote,         ///<对方网络不稳定 ＝ 3
    NemoVideoState_NetworkError,        ///<网络不稳定，请稍候
    NemoVideoState_LocalWifiIssue       ///<WiFi信号不稳定
};

/// 字幕显示位置
typedef NS_ENUM(NSInteger, NemoCaptionLocation) {
    NemoCaptionLocationTop,         ///<上
    NemoCaptionLocationMiddle,      ///<中
    NemoCaptionLocationBottom,      ///<下
};

/// 字体大小
typedef NS_ENUM(NSInteger,NemoCaptionFontSize) {
    NemoCaptionFontSizeSmall,       ///<小
    NemoCaptionFontSizeMiddle,      ///<中
    NemoCaptionFontSizeBig,         ///<大
};

/// 请流布局优先级
typedef NS_ENUM(NSInteger, NemoLayoutPriority) {
    NemoLayoutPriority_High     = 100,  ///<较高
    NemoLayoutPriority_Normal   = 200,  ///<一般
    NemoLayoutPriority_Low      = 300,  ///<较低
};

/// 请流视频质量
typedef NS_ENUM(NSInteger, NemoVideoQuality) {
    NemoVideoQuality_High     = 100,    ///<较高
    NemoVideoQuality_Normal   = 200,    ///<一般
    NemoVideoQuality_Base     = 300,    ///<较低
};

/// 请流分辨率
typedef NS_ENUM(NSInteger, NemoVideoResolution) {
    NemoVideoResolution_180P      = 100,    ///<180p
    NemoVideoResolution_360P      = 200,    ///<360p
    NemoVideoResolution_720P      = 300,    ///<720p
    NemoVideoResolution_1080P     = 400,    ///<1080p
};

/// 白板远端状态
typedef NS_ENUM(NSInteger, NemoWhiteboardRemoteState) {
    NemoWhiteboardRemoteState_Unknown,  ///<未知
    NemoWhiteboardRemoteState_Start,    ///<开启
    NemoWhiteboardRemoteState_Stop,     ///<关闭
    NemoWhiteboardRemoteState_Error,    ///<错误
};

/// 白板操作
typedef NS_ENUM(NSInteger, NemoWhiteboardOperationState) {
    NemoWhiteboardOperation_setCanvas = 0,  ///<设置画布
    NemoWhiteboardOperation_Draw,           ///<画
    NemoWhiteboardOperation_Clear,          ///<清理
    NemoWhiteboardOperation_All,            ///<所有信息
    NemoWhiteboardOperation_Undo,           ///<撤销
    NemoWhiteboardOperation_Redo,           ///<重做
    NemoWhiteboardOperation_Unkown,         ///<未知
};

///标注状态
typedef NS_ENUM(NSUInteger, NemoAnnotationStatus) {
    NemoAnnotationStatus_Unknown,  ///< 未知
    NemoAnnotationStatus_Start,    ///< 开启
    NemoAnnotationStatus_Stop,     ///< 关闭
    NemoAnnotationStatus_Error     ///< 错误
};

//标注操作
typedef NS_ENUM(NSUInteger, NemoAnnotationOperation) {
    NemoAnnotationOperation_DrawLine,          ///< 画线
    NemoAnnotationOperation_Clear,             ///< 清理
    NemoAnnotationOperation_GetAllLine,        ///< 获取
    NemoAnnotationOperation_Undo,              ///< 撤销
    NemoAnnotationOperation_Redo,              ///< 重做
    NemoAnnotationOperation_Status,            ///< 获取状态
    NemoAnnotationOperation_Info,              ///< 获取信息
    NemoAnnotationOperation_Feedback,          ///< 画线反馈
    NemoAnnotationOperation_None,              ///< 无操作
};

/// 设置视频输出分辨率
typedef NS_ENUM(NSInteger, XYVideoDimension) {
    XYVideoDimension_180P,  ///<180p
    XYVideoDimension_360P,  ///<360p
    XYVideoDimension_720P   ///<720p
};

/// 网络测试结果
typedef NS_ENUM(NSInteger, NemoNetworkTestCode) {
    NemoNetworkTestCode_NoError,              ///<正常
    NemoNetworkTestCode_Expired,              ///<终止
    NemoNetworkTestCode_Killed,               ///<强制结束
    NemoNetworkTestCode_CreateTCPSocketFail,  ///<tcp连接失败
    NemoNetworkTestCode_CreateUDPSocketFail,  ///<udp连接失败
    NemoNetworkTestCode_LostConnection,       ///<无网络连接
    NemoNetworkTestCode_NotFoundServer,       ///<未找到服务器
};

/// 虚拟背景配置
typedef NS_ENUM(NSInteger, NemoVirtualBackgroundMode) {
    NemoVirtualBackgroundMode_Close = 0,   ///<无背景
    NemoVirtualBackgroundMode_Blur,        ///<背景模糊
    NemoVirtualBackgroundMode_Image        ///<图片选择
};

/// FECC
typedef NS_ENUM(NSInteger, XYFECCOperation) {
    XYFECCOperation_TurnLeft,
    XYFECCOPeration_StepLeft,
    XYFECCOperation_TurnRight,
    XYFECCOPeration_StepRight,
    XYFECCOperation_Stop,
    XYTILT_CAMERA_TURN_UP,
    XYTILT_CAMERA_STEP_UP,
    XYTILT_CAMERA_TURN_DOWN,
    XYTILT_CAMERA_STEP_DOWN,
    XYTILT_CAMERA_TURN_STOP,
    XYFECCOperation_ZoomIn,
    XYFECCOperation_ZoomOut,
    XYFECCOperation_STEP_ZOOM_IN,
    XYFECCOperation_STEP_ZOOM_OUT,
    XYFECCOperation_ZOOM_TURN_STOP,
    XYFECCOperation_MOVE_LEFT_TURN,
    XYFECCOperation_MOVE_LEFT_STEP,
    XYFECCOperation_MOVE_RIGHT_TURN,
    XYFECCOperation_MOVE_RIGHT_STEP,
    XYFECCOperation_MOVE_UP_TURN,
    XYFECCOperation_MOVE_UP_STEP,
    XYFECCOperation_MOVE_DOWN_TURN,
    XYFECCOperation_MOVE_DOWN_STEP,
    XYFECCOperation_MOVE_STOP
};

#endif /* Enumeration_Type_h */
