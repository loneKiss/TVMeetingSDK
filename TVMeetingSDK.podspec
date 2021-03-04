
Pod::Spec.new do |spec|

spec.name         = "TVMeetingSDK"
spec.version      = "1.0.1"
spec.summary      = "TVMeetingSDK for IOS"
spec.description  = "TVMeetingSDK.framework一款用于开启即时视频会议的sdk"
spec.homepage     = "https://github.com/loneKiss/TVMeetingSDK"
spec.license      = { :type => "MIT", :file => "LICENSE" }
spec.author       = { "loneKiss" => "775865767@qq.com" }
spec.platform     = :ios, "9.0"
spec.source       = { :git => "https://github.com/loneKiss/TVMeetingSDK.git", :tag => spec.version }
spec.resources       = ['TVMeetingSDKReadme.md']
spec.vendored_frameworks = "TVMeetingSDK/framework/*.framework"


# 图片，其他资源文件存放的路径，需要注意的是，xib，nib也属于资源文件
spec.resource_bundles = {
    'TVMeetingSDK' => ['TVMeetingSDK/Resources/*'],
  }

spec.requires_arc    = true

spec.pod_target_xcconfig = {
    'FRAMEWORK_SEARCH_PATHS' => '$(inherited) $(PODS_ROOT)/**',
    'HEADER_SEARCH_PATHS' => '$(inherited) $(PODS_ROOT)/**',
    'VALID_ARCHS' => 'armv7 arm64 x86_64',
    'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'
  }

end
