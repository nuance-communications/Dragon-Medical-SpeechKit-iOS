#
# Be sure to run `pod lib lint DragonMedicalSpeechKitPod.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'DragonMedicalSpeechKitPod'
  s.version          = '0.1.0'
  s.summary          = 'A short description of DragonMedicalSpeechKitPod.'
  
  # This description is used to generate tags and improve search results.
  #   * Think: What does it do? Why did you write it? What is the focus?
  #   * Try to keep it short, snappy and to the point.
  #   * Write the description between the DESC delimiters below.
  #   * Finally, don't worry about the indent, CocoaPods strips it!
  
  s.description      = <<-DESC
  TODO: Add long description of the pod here.
  DESC

  s.homepage         = 'https://github.com/klolage/DragonMedicalSpeechKitPod'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'klolage' => 'krishna.lolage@microsoft.com' }
  s.source           = { :git => 'https://github.com/klolage/DragonMedicalSpeechKitPod.git', :tag => s.version.to_s }
  s.ios.deployment_target = '16.0'
  s.platform = :ios
  s.source_files = 'Sources/SDK/**/*.{swift}'
  s.vendored_frameworks = "Sources/SDK/DragonMedicalSpeechKit.xcframework"
  s.swift_version = '5.0'
  s.dependency 'MicrosoftCognitiveServicesSpeech-iOS', '~> 1.33.0'
  
end
