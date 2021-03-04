
Pod::Spec.new do |spec|

spec.name         = "TVMeetingSDK"
spec.version      = "1.0.0"
spec.summary      = "TVMeetingSDK for IOS"
spec.description  = "TVMeetingSDK.framework一款用于开启即时视频会议的sdk"
spec.homepage     = "https://github.com/loneKiss/TVMeetingSDK"
spec.license      = { :type => "MIT", :file => "LICENSE" }
spec.author       = { "loneKiss" => "775865767@qq.com" }
spec.platform     = :ios, "9.0"
spec.source       = { :git => "https://github.com/loneKiss/TVMeetingSDK.git", :tag => spec.version }
spec.resources       = ['TVMeetingSDKReadme.md']
spec.vendored_frameworks = "framework/*.framework"
spec.dependency 'AFNetworking','~> 3.2.1'
spec.dependency 'MBProgressHUD','~> 1.1.0'
spec.dependency 'LBXScan/LBXNative','~> 2.3'
spec.dependency 'LBXScan/LBXZXing','~> 2.3'
spec.dependency 'LBXScan/LBXZBar','~> 2.3'
spec.dependency 'LBXScan/UI','~> 2.3'        #只安装UI
spec.dependency 'SDAutoLayout'
spec.dependency 'HDAlertView'                #自定义alertView
spec.dependency 'MJRefresh'
spec.dependency 'IQKeyboardManager'
spec.dependency 'SDWebImage','5.1.1'
spec.dependency 'MJExtension'
spec.dependency 'Masonry'
spec.dependency 'TZImagePickerController'
spec.dependency 'PPBadgeView','~> 2.1.0'

spec.requires_arc    = true

spec.pod_target_xcconfig = {
    'FRAMEWORK_SEARCH_PATHS' => '$(inherited) $(PODS_ROOT)/**',
    'HEADER_SEARCH_PATHS' => '$(inherited) $(PODS_ROOT)/**',
    'VALID_ARCHS' => 'armv7 arm64 x86_64',
    'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'
  }

end
