//
//  Enumeration_Type.h
//  NemoSDK
//
//  Created by 杨旭东 on 16/9/30.
//  Copyright © 2016年 JackYang. All rights reserved.
//

#ifndef Enumeration_Type_h
#define Enumeration_Type_h


#endif /* Enumeration_Type_h */



#define LOCAL @"LocalStreamID" //本地视频流的ID


/**
 *  呼叫状态
 */
typedef NS_ENUM(NSInteger, NemoCallState) {
    /**
     *  已连接
     */
    NemoCallState_Connected = 0,
    /**
     *  未连接
     */
    NemoCallState_DisConnected,
    /**
     *  正在连接
     */
    NemoCallState_Connecting,
};


/**
 *  通话模式
 */
typedef NS_ENUM(NSInteger, NemoCallMode) {
    //视频
    NemoCallMode_Movie,
    //音频
    NemoCallMode_Audio
};

/**
 *  横竖屏切换
 */
typedef NS_ENUM(NSInteger, NemoVideoOrientation) {
    //竖屏
    NemoVideoOrientation_Portrait,
    //横屏 home朝右
    NemoVideoOrientation_LandscapeLeft,
    //横屏 home朝左
    NemoVideoOrientation_LandscapeRight,
};

/**
 *  分享content类型
 */
typedef NS_ENUM(NSInteger, NemoShareContentType) {
    //分享图片
    NemoShareContentType_Image,
    //分享屏幕
    NemoShareContentType_Screen
};

/**
 *  共享采集类型
 */
typedef NS_ENUM(NSInteger, NemoShareCaptureType) {
    //视频
    NemoShareCaptureType_Video,
    //音频
    NemoShareCaptureType_Audio,
};

/**
 *  挂断方式
 */
typedef NS_ENUM(NSInteger, NemoHangUpMode) {
    //默认挂断
    NemoHangUpMode_Default,
    //会中邀请挂断
    NemoHangUpMode_Invite
};


/**
 *  视频流状态
 */
typedef NS_ENUM(NSInteger, NemoStreamState) {
    /**
     *  闲置
     */
    NemoStreamState_Idle,
    /**
     *  监听
     */
    NemoStreamState_Observing,
    /**
     *  视频关闭
     */
    NemoStreamState_Mute,
    /**
     *  请求中
     */
    NemoStreamState_Requesting,
    /**
     *  带宽不足
     */
    NemoStreamState_NoBandwidth,
    /**
     *  无解码
     */
    NemoStreamState_NoDecoder,
    /**
     *  正常接收
     */
    NemoStreamState_Received,
    /**
     *  电话
     */
    NemoStreamState_Telephone,
    /**
     *  只有音频
     */
    NemoStreamState_AudioOnly,
    /**
     *  只收到音频
     */
    NemoStreamState_ReceivedAudioOnly
};

/**
 *  双流状态
 */
typedef NS_ENUM(NSInteger, NemoDualState) {

    NemoDualState_Idle = 0,
    NemoDualState_Acquiring,
    NemoDualState_Unsupported,
    NemoDualState_Unknown,
    NemoDualState_Sending,
    NemoDualState_NoBandwidth,
};

/**
 *  双流原因
 */
typedef NS_ENUM(NSInteger, NemoDualReason) {
    NemoDualReason_Normal,//正常
    NemoDualReason_Disconnect,//断开
    NemoDualReason_InvalidType,//无效类型
    NemoDualReason_NetworkError,//网络错误
    NemoDualReason_Timeout,//超时
    NemoDualReason_ServerFail,//服务器失败
    NemoDualReason_Unknown//未知错误
};

/**
 *  硬件设备
 */
typedef NS_ENUM(NSInteger, NemoDeviceType) {
    /**
     *  前置摄像头
     */
    NemoDeviceType_FrontCamera,
    /**
     *  后置摄像头
     */
    NemoDeviceType_BackCamera
};

/**
 *  手电筒
 */
typedef NS_ENUM(NSInteger, NemoTorchMode) {
    /**
     *  关闭手电筒
     */
    NemoTorchMode_off = 0,
    /**
     *  开启手电筒
     */
    NemoTorchMode_on,
    /**
     *  自动
     */
    NemoTorchMode_auto
};


/**
 *  会控状态
 */
typedef NS_ENUM(NSInteger, NemoConferenceManagerManagementType) {
    /**
     *  静音
     */
    NemoConferenceManagerManagementType_Mute,
    /**
     *  强制静音
     */
     NemoConferenceManagerManagementType_MuteMandatory,
    /**
     *  取消静音
     */
     NemoConferenceManagerManagementType_Unmute,
    /**
     *  暂时取消静音
     */
     NemoConferenceManagerManagementType_UnmuteTemporary
};


/**
 *  log级别
 */
typedef NS_ENUM(NSInteger, XYLogLevel) {
    /**
     *  错误信息
     */
    XYLogLevel_Error = 0,
    /**
     *  警告信息
     */
    XYLogLevel_Warn,
    /**
     *  媒体信息
     */
    XYLogLevel_Info,
    /**
     *  调试信息
     */
    XYLogLevel_Debug
};

/**
 *  远端类型
 */
typedef NS_ENUM(NSInteger, XYDataType)
{
    XYDataType_Unknown,     //未知
    XYDataType_Contact = 1, //人
    XYDataType_Device,      //小鱼
    XYDataType_MeetingRoom, //云会议室
    XYDataType_PSTN,        //电话
    XYDataType_Desktop = 5, //电脑
    XYDataType_H323,        //323
    XYDataType_Bruce,       //大鱼
    XYDataType_Tvbox,       //tvbox
    XYDataType_Shuttle      // 监控
} ;

/**
 *  视频关闭原因
 */
typedef NS_ENUM(NSInteger, XYVideoMuteReason)
{
    XYVideoMuteReason_MuteByUser,//用户关闭视频
    XYVideoMuteReason_MuteByBWLimit,//带宽限制
    XYVideoMuteReason_MuteByNoInput,//没有输入
    XYVideoMuteReason_MuteByConfMgmt//会控关闭
};

/**
 *  视频状态
 */
typedef NS_ENUM(NSInteger, XYVideoState)
{
    XYVideoState_Normal, //正常状态，ui不需要显示 ＝ 0
    XYVideoState_LowAsLocalBw,//本地网络不稳定 ＝ 1
    XYVideoState_LowAsLocalHardware,//系统忙，视频质量降低 ＝ 2
    XYVideoState_LowAsRemote,//对方网络不稳定 ＝ 3
    XYVideoState_NetworkError, //网络不稳定，请稍候
    XYVideoState_LocalWifiIssue //WiFi信号不稳定
};

/**
 *  默认音频输出
 */
typedef NS_ENUM(NSInteger, XYDefaultOutPut) {
    XYDefaultOutPut_Speaker,
    XYDefaultOutPut_Earphone
};

/**
 *  FECC
 */
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


/**
 字幕显示位置
 */
typedef NS_ENUM(NSInteger, NemoCaptionLocation) {
    NemoCaptionLocationTop,
    NemoCaptionLocationMiddle,
    NemoCaptionLocationBottom,
};

/**
字体大小
*/
typedef NS_ENUM(NSInteger,NemoCaptionFontSize){
    NemoCaptionFontSizeSmall,
    NemoCaptionFontSizeMiddle,
    NemoCaptionFontSizeBig,
};

#pragma mark - CustomLayout
/**
 布局优先级

 - NemoLayoutPriority_High: 高
 - NemoLayoutPriority_Normal: 正常
 - NemoLayoutPriority_Low: 低
 */
typedef NS_ENUM(NSInteger, NemoLayoutPriority) {
    NemoLayoutPriority_High     = 100,
    NemoLayoutPriority_Normal   = 200,
    NemoLayoutPriority_Low      = 300,
};


/**
 视频质量

 - NemoVideoQuality_High: 高
 - NemoVideoQuality_Normal: 正常
 - NemoVideoQuality_Base: 低
 */
typedef NS_ENUM(NSInteger, NemoVideoQuality) {
    NemoVideoQuality_High     = 100,
    NemoVideoQuality_Normal   = 200,
    NemoVideoQuality_Base     = 300,
};


/**
 分辨率

 - NemoVideoResolution_180P: 180P
 - NemoVideoResolution_360P: 360P
 - NemoVideoResolution_720P: 720P
 - NemoVideoResolution_1080P: 1080P
 */
typedef NS_ENUM(NSInteger, NemoVideoResolution) {
    NemoVideoResolution_180P      = 100,
    NemoVideoResolution_360P      = 200,
    NemoVideoResolution_720P      = 300,
    NemoVideoResolution_1080P     = 400,
};


/**
 白板远端状态

 - NemoWhiteboardRemoteState_Start：开启
 - NemoWhiteboardRemoteState_Stop：关闭
 - NemoWhiteboardRemoteState_Error：错误
 */
typedef NS_ENUM(NSInteger, NemoWhiteboardRemoteState)
{
    NemoWhiteboardRemoteState_Unknown,  // 未知
    NemoWhiteboardRemoteState_Start,    // 开启
    NemoWhiteboardRemoteState_Stop,     // 关闭
    NemoWhiteboardRemoteState_Error,    // 错误
};

typedef NS_ENUM(NSInteger, NemoWhiteboardOperationState) {
    NemoWhiteboardOperation_setCanvas = 0, // 设置画布
    NemoWhiteboardOperation_Draw, // 画
    NemoWhiteboardOperation_Clear, // 清理
    NemoWhiteboardOperation_All, // 所有信息
    NemoWhiteboardOperation_Undo, // 撤销
    NemoWhiteboardOperation_Redo, // 重做
    NemoWhiteboardOperation_Unkown, // xxx
};

/**
 设置视频输出分辨率

 - XYVideoDimension_360P: 360p
 - XYVideoDimension_720P: 720p
 */
typedef NS_ENUM(NSInteger, XYVideoDimension) {
    XYVideoDimension_360P,
    XYVideoDimension_720P
};
