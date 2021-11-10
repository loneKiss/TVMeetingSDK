# TVMeetingSDK
一款用于开启即时视频会议的sdk

一、会议系统sdk
TVMeetingSDK.framework为会议系统组件
pod 'TVMeetingSDK' 
TVMeetingSDK依赖于NemoSDK,所以不需要下载NemoSDK,直接pod 'TVMeetingSDK' 即可

二、小鱼sdk
XYRTCEngine.framework

(1)在Xcode的Build Phases页面中，将XYRTCEngine.framework添加到Link Binary With Libraries；

(2)并将XYRTCEngine.framework添加到Copy Files，Destination选择Frameworks。

三、cocoapods依赖库
pod 'AFNetworking', '~> 3.2.1'
pod 'MBProgressHUD', '~> 1.1.0'
pod 'LBXScan/LBXNative','~> 2.3' #只安装系统原生API封装库
pod 'LBXScan/LBXZXing','~> 2.3'  #只安装ZXing封装库
pod 'LBXScan/LBXZBar','~> 2.3'   #只安装ZBar封装库
pod 'LBXScan/UI','~> 2.3'        #只安装UI
pod 'SDAutoLayout'
pod 'HDAlertView'                #自定义alertView
pod 'MJRefresh'
pod 'IQKeyboardManager'
pod 'SDWebImage','5.1.1'
pod 'MJExtension'
pod 'Masonry'
pod 'TZImagePickerController'
pod 'PPBadgeView','~> 2.1.0'


四、组件的使用
1、#import <TVMeetingSDK/MT_UserManager.h>
2、调用初始化会议系统的方法
4、如果要切换不同的环境，修改projectVersion这个参数的传入值，0：代表生产环境； 1代表pre环境；-1代表测试环境；

if (!TARGET_IPHONE_SIMULATOR) { ///仅支持真机调试
    // 初始化小鱼sdk
    // 在这里调用会议系统初始化方法
    [[MT_UserManager shareUserManager] saveAccountId:@"会议系统用户id" andAccountName:@" 会议系统用户名字" andFishAccountId:@"小鱼id" andAccessToken:@"登录会议系统的token" andRefreshToken:@" 刷新会议系统的token" andProjectToken:@"集成项目的token" andProjectVerson:0 withParentVC:@"当前显示的控制器"];
    //初始化旋转屏幕block代码块
    AppDelegate *appDelegate = (AppDelegate *)[UIApplication sharedApplication].delegate;
    [MT_UserManager shareUserManager].didRotatingScreen = ^(BOOL allowRotation) {
        appDelegate.allowRotation = allowRotation;
    };
    
}
