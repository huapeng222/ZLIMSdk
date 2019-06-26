#
# Be sure to run `pod lib lint ZLIMSdk.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'ZLIMSdk'
  s.version          = '0.0.1'
  s.summary          = '致联软件消息sdk'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
致联软件消息sdk
                       DESC

  s.homepage         = 'https://code.aliyun.com/zhi-lian-ios/zhi-lian-imsdk-pod'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'huazhaopeng' => 'huazhaopeng@zhi-lian.com.cn' }
  s.source           = { :git => 'https://code.aliyun.com/zhi-lian-ios/zhi-lian-imsdk-pod.git', :tag => s.version.to_s }

  s.ios.deployment_target = '8.0'
  s.vendored_frameworks='ZLSdk.framework'
  s.dependency 'Protobuf', '~> 3.6.1'
  s.dependency 'MMKV', '~> 1.0.12'
  s.dependency 'Masonry','~> 1.1.0'
  s.dependency 'WCDB','~> 1.0.7.5'
  #s.dependency 'TZImagePickerController','~> 3.1.9'
  s.dependency 'SDWebImage','~> 4.4.5'
  s.dependency 'MLLabel','~> 1.10.5'
  s.dependency 'MBProgressHUD','~> 1.1.0'
  s.dependency 'AFNetworking', '~> 3.2.1'

  # s.source_files = 'ZLIMSdk/Classes/**/*'
  
  s.resource_bundles = {
    'ZLIMSdk' => ['ZLSdk/assets/zlsdkImage.xcassets','ZLSdk/assets/file/*']
  }
  # s.resources = ['ZLSdk/assets/zlsdkImage.xcassets']

  # s.public_header_files = 'Pod/Classes/**/*.h'
  s.frameworks = 'UIKit', 'CFNetwork', 'CoreTelephony', 'Foundation', 'SystemConfiguration'
  s.libraries = 'resolv.9', 'z'
  # s.dependency 'AFNetworking', '~> 2.3'
end
