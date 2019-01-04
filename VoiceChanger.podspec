 Pod::Spec.new do |s|
  s.name         = "VoiceChanger"
  s.version      = "0.0.2"
  s.summary      = "Voice Changer With Six Type For IOS"
  s.description  = <<-DESC
  Voice Changer With Six Type For IOS"
                      DESC
  s.homepage     = "https://github.com/Kayshen-X/ios_voice_changer"
  s.license      = "MIT"
  s.author             = { "Kayshen-X" => "kayshen_xu@163.com" }
  s.platform     = :ios, "8.0"
  s.source       = { :git => "https://github.com/Kayshen-X/ios_voice_changer.git", :tag => "#{s.version}" }
  s.source_files = "Classes/**/*","FMOD/inc/**/*"
  s.public_header_files = "Classes/**/*.h"
  s.frameworks = "AVFoundation","AudioToolbox"
  s.libraries = "c++"
  s.vendored_libraries="FMOD/lib/libfmod_iphoneos.a","FMOD/lib/libfmod_iphonesimulator.a","FMOD/lib/libfmodL_iphoneos.a","FMOD/lib/libfmodL_iphonesimulator.a"



end
