# Release Notes for Dragon Medical SpeechKit 2024\.4 (iOS edition 6\.1 R1\)

## New in version 2024\.4 (6\.1 R1\)

* iOS 18 and Xcode 16 are now supported.
* iOS 15 is no longer supported.
* The iOS SDK now supports authentication using Microsoft Entra ID; send the `authenticationToken` and `authenticationTokenExpiryTime` parameters with the open session call. This authentication method requires additional updates to backend components before it can be used.
* The SDK is no longer delivered as an XCFramework. It is now only available as a Swift package at [https://github.com/nuance\-communications/Dragon\-Medical\-SpeechKit\-iOS](https://github.com/nuance-communications/Dragon-Medical-SpeechKit-iOS). If you were using an earlier version of the SDK as an embedded framework or XCFramework and need to switch to the Swift package, you must first remove/unlink the embedded framework/XCFramework from your project.

**Note:** For information on previous releases, see: [Release history](#release-history).

## Solved in version 2024\.4 (6\.1 R1\)

* A memory leak of 1\.3 MB no longer occurs every 75 seconds while the application is in recording mode. \[DNB\-32086]
* US and Canada systems only, English only: Standby mode and the wake word have been reactivated.
* US systems only, English only: Virtual assistant trigger phrases have been reactivated.

## Important information

* Mobile operating system support: The current major iOS version is supported along with the previous two major versions. \[HCPLAT\-1485, DNB\-31832]
* Dragon Medical SpeechKit 2024\.4 (iOS edition) is compatible with Dragon Medical Server 2023 and 2024\.
* Dragon Medical Server 2024\.4 is compatible with Dragon Medical SpeechKit and Dragon Medical Embedded versions 2023 and 2024\.
* The SystemConfiguration framework must be linked explicitly to your application, even if `Link Frameworks Automatically` is set to `YES`. If `Link Frameworks Automatically` is set to `NO`, the WebKit framework must also be linked to your application.
* Split View isn't supported. \[DNB\-28030]

## Infrastructure

### Infrastructure no longer supported

* Dragon Medical SpeechKit and Dragon Medical Embedded 2024\.4 applications don't work with version 2022 servers.
* Version 2022 client applications don't work with version 2024 servers.

### Infrastructure changes planned for the next release

* Dragon Medical SpeechKit and Dragon Medical Embedded 2025\.1 and higher won't work with version 2023\.1 servers.
* Version 2023\.1 client applications won't work with version 2025\.1 servers.

## System requirements\*

|  | Recommended | Supported |
|-|-|-|
| Operating System | iOS 18 | iOS 16 \- 18 |
| Architecture |  | Physical device: arm64  iOS Simulator: x86\_64, arm64 |
| Development environment | Xcode 16 | Xcode 15\-16 |

### \*End\-of\-life: third\-party environments

Support for third\-party environments is only valid as long as they're supported by the corresponding vendor and might be subject to other restrictions. Please contact Nuance Technical Support for details. For more information, see the documentation delivered with the third\-party product and supporting Nuance documentation.

When standard support by the vendor has stopped, Nuance will continue support if an issue is specific to the Nuance solution, within the limitations of the vendor's standard end\-of\-life and Nuance's policy. This means that issues that are a combination of the vendor's component and the Nuance solution cannot be supported.

## Dragon Medical SpeechKit product life cycle

To take advantage of technical innovations and security enhancements, it's important to stay up to date with the latest versions of our SDKs.

We use the following versioning standard:

* Major release \- represented by an increment in the major application version number; for example 2023\.1, 2023\.2\.
* Point release \- a service release between major releases, represented by an increment in the minor application version number; for example 2023\.2\.1, 2023\.2\.2\.

We provide support for the current Dragon Medical SpeechKit version and one previous version. We investigate issues in the most current version and the previous version, or all versions released within the last 12 months (whichever includes more versions). Updates that address issues identified in previous versions are always based on the most current version.

When we release a new version of Dragon Medical SpeechKit that includes breaking changes, you might need to update your application’s source code. In these cases, we continue support for the previous version, prior to the breaking changes, for 12 months.

We won't investigate issues after the end of support.

| Version | Status | End of support | End of life | Deactivation |
| --- | --- | --- | --- | --- |
| Dragon Medical SpeechKit 2020\.3 (iOS edition 3\.8 R1\) | End of life | 2021\-08\-31 | 2021\-11\-31 | 2025\-01\-29 |
| Dragon Medical SpeechKit 2020\.4 (iOS edition 3\.9 R1\) | End of life | 2021\-12\-31 | 2022\-03\-31 | 2025\-01\-29 |
| Dragon Medical SpeechKit 2021\.1 (iOS edition 3\.9 R2\) | End of life | 2022\-02\-28 | 2022\-05\-31 | 2025\-01\-29 |
| Dragon Medical SpeechKit 2021\.1\.1 (iOS edition 3\.9 R3\) | End of life | 2022\-02\-28 | 2022\-05\-31 | 2025\-01\-29 |
| Dragon Medical SpeechKit 2021\.1\.2 (iOS edition 3\.9 R4\) | End of life | 2022\-02\-28 | 2022\-05\-31 | 2025\-01\-29 |
| Dragon Medical SpeechKit 2021\.1\.3 (iOS edition 3\.9 R5\) | End of life | 2022\-02\-28 | 2023\-05\-31 | 2025\-01\-29 |
| Dragon Medical SpeechKit 2021\.2 (iOS edition 3\.10 R1\) | End of life | 2022\-06\-30 | 2022\-09\-30 | 2025\-03 |
| Dragon Medical SpeechKit 2021\.3 (iOS edition 3\.11 R1\) | End of life | 2022\-09\-30 | 2022\-12\-31 | 2025\-03 |
| Dragon Medical SpeechKit 2022\.2 (iOS edition 4\.1 R1\) | End of life | 2023\-04\-30 | 2023\-07\-31 | 2025\-12 |
| Dragon Medical SpeechKit 2022\.4 (iOS edition 4\.4 R1\) | End of life | 2023\-12\-31 | 2024\-03\-31 | 2025\-12 |
| Dragon Medical SpeechKit 2023\.1 (iOS edition 5\.0 R1\) | End of life | 2024\-02\-29 | 2024\-05\-31 | 2025\-12 |
| Dragon Medical SpeechKit 2024\.1 (iOS edition 5\.7 R1\) | Supported | 2025\-02\-28 | 2025\-05\-31 |  |
| Dragon Medical SpeechKit 2024\.3 (iOS edition 5\.8 R1\) | Supported | 2025\-09\-30 | 2025\-12\-31 |  |
| Dragon Medical SpeechKit 2024\.4 (iOS edition 6\.1 R1\) | Supported | 2025\-12\-31\* | 2026\-03\-31\* |  |

\*Preliminary date depending on the next major or point release. If this is longer than 12 months, the support period will be extended until the next major or point release.

At Nuance, we place a strong emphasis on security and take a proactive approach to safeguarding our platform. To this end, 12 months after the end of support, Nuance deactivates unsupported client versions on the Nuance cloud. To avoid any disruption in service, we strongly recommend that partners integrating client SDKs that are in restricted maintenance mode upgrade their customers to the latest version of Dragon Medical SpeechKit as soon as possible.

## Release history

### New in version 2024\.3 (5\.8 R1\)

* US and Canada systems only, English only: Standby mode and the wake word are disabled for this release. The stop recording voice command turns off the microphone instead of starting standby mode. Go to sleep is written as spoken and not recognized as a command. The standby feature will be reactivated in version 2024\.4\. \[1770281]
* US systems only, English only: For this release, Dragon Medical Virtual Assistant trigger phrases are written as spoken and not recognized as commands. Virtual assistant trigger phrases will be reactivated in version 2024\.4\. \[1770281]
* ARM64 simulators are now supported. You can now build and run apps on M1 or higher machines. It's no longer necessary to add arm64 to the Excluded Architectures settings for Simulator builds.

### New in version 2024\.1 (5\.7 R1\)

* iOS 17 and Xcode 15 are now supported. \[HCPLAT\-3216]
* iOS 14 is no longer supported. \[DNB\-52206]
* Xcode 12 is no longer supported. \[DNB\-52206]
* The SDK now includes a privacy manifest. \[HCPLAT\-3131]
* The Bitcode version of the SDK is no longer available.
* The SDK is no longer delivered as an embedded framework; it's now only available as a Swift package and an XCFramework. If you were using an earlier version of the SDK as an embedded framework and need to switch to the Swift package or XCFramework, you must first remove/unlink the embedded framework from your project.
* Nuance Healthcare ID is no longer available and NHID APIs have been removed. \[HCCSP\-2532]
* The methods `NUSAVolumeMeterLocation`, `volumeMeterColor` and `volumeMeterBadQualityColor` are deprecated and should no longer be used. \[DNB\-52232]
* The following APIs were declared deprecated in previous versions and have now been removed \[DNB\-52232]:

   `@property (nonatomic, copy) NSString* language _attribute_((deprecated));`

   `@property (nonatomic, copy) NSString* speakingVoice DEPRECATED_MSG_ATTRIBUTE("Setting this property will have no effect");`

   `extern NSString* const kNUSASpeakingVoiceFemale DEPRECATED_MSG_ATTRIBUTE("Using this value will have no effect");`

   `extern NSString* const kNUSASpeakingVoiceMale DEPRECATED_MSG_ATTRIBUTE("Using this value will have no effect");`

   `@property (nonatomic, retain) NUSASpeechView* speechView _attribute_((deprecated));`

   `@property (nonatomic, retain) UIImage* volumeMeterTooLoudImage _attribute_((deprecated));`

   `@property (nonatomic, retain) UIImage* volumeMeterTooSoftImage _attribute_((deprecated));`

   `@property (nonatomic, retain) UIImage* volumeMeterTooNoisyImage _attribute_((deprecated));`

   `@property (nonatomic, assign) NUSABadQualityIndicatorLocation badQualityIndicatorLocation _attribute_((deprecated));`

   `(void) addFilter: (NSString *)value forKey: (NSString *)key _attribute_((deprecated));`

* The `content` parameter has been removed from `vuiControllerDidRecognizeCommand`. If you're using this method, you must update your integration accordingly. \[DNB\-52232]

Old method:

```objC
(void) vuiControllerDidRecognizeCommand: (NSString*) id spokenPhrase: (NSString*) spokenPhrase withContent: (NSString *) content placeholderValues: (NSDictionary *) placeholderValues;
```

New method:

```objC
(void) vuiControllerDidRecognizeCommand: (NSString*) id spokenPhrase: (NSString*) spokenPhrase placeholderValues: (NSDictionary *) placeholderValues;
```

* Dragon Medical Virtual Assistant (US hosted systems only, US English only): `userFeedback` and `partnerFeedback` methods are now available to send user feedback and app\-generated feedback to DMVA. For more information, see the Dragon Medical SpeechKit (iOS edition) help, "Sending feedback to DMVA" and the API reference. \[FLOR\-50923]

### Solved in version 2024\.1 (5\.7 R1\)

* GUI styles indicating the speech\-enabled field no longer disappear one second after the integration calls the `startRecording` method. \[DNB\-51794]
* Resolved an issue that could occur when the app was sent to the background with the personalization and help screen open. When the user brings the app back to the foreground, the speechbar and personalization and help screen are displayed as expected. \[FLOR\-50899]
* Dragon Medical Virtual Assistant (US hosted systems only, US English only): Resolved a crash in the `endVARequestWithID` method. \[FLOR\-59470]

### New in version 2023\.1 (5\.0 R1\)

* Dragon Medical SpeechKit (iOS edition) is now available as a Swift package. To get the package, go to: [https://github.com/nuance\-communications/Dragon\-Medical\-SpeechKit\-iOS](https://github.com/nuance-communications/Dragon-Medical-SpeechKit-iOS)

For more information on integrating Swift packages with your app, see the Apple developer documentation: [https://developer.apple.com/documentation/xcode/adding\-package\-dependencies\-to\-your\-app](https://developer.apple.com/documentation/xcode/adding-package-dependencies-to-your-app)

* Dragon Medical Virtual Assistant (US hosted systems only, US English only): You can now enable automatic reconnection when the app returns to the foreground and when the DMVA server connection is lost and restored. Specify the `AutoReconnectOnAppForeground` and `AutoReconnectOnServerReachable` parameters in the `openVA` call. For more information, see the Dragon Medical SpeechKit (iOS edition) help, "Dragon Medical Virtual Assistant automatic reconnection". \[FLOR\-14772]

### Solved in version 2023\.1 (5\.0 R1\)

* Text\-To\-Speech no longer plays audio through the device speaker when a Bluetooth speaker is connected. The audio plays though the Bluetooth speaker as expected. \[DNB\-46813]
* The personalization and help screen now displays in the correct orientation consistently. \[DNB\-47912]

### New in version 2022\.4 (4\.4 R1\)

* Dragon Medical Virtual Assistant (US hosted systems only, US English only): The new event `VAEventTypePartialASR` sends partial speech recognition results to your integration as the user is speaking. The partial speech recognition result is updated approximately every 500 ms. Users might perceive the intervals between NLU results as inactivity; use this event to keep them informed that speech recognition is taking place. \[FLOR\-47179]
* Dragon Medical Virtual Assistant (US hosted systems only, US English only): You can now add ISO 8601 date\-time values to the NLU result JSON. To enable this, pass your IANA time zone value (for example, `"America/New_York"`) to the optional `IANATimezone` parameter in the `openVA` method. To disable this, omit the `IANATimezone` parameter or pass an empty string. \[FLOR\-47184]
* iOS 16 and Xcode 14 are now supported.
* iOS 13 is no longer supported.

### Solved in version 2022\.4 (4\.4 R1\)

* Dragon Medical Virtual Assistant (US hosted systems only, US English only): The speech bar no longer disappears after the user opens and closes the personalization \& help screen. \[DNB\-45095]

### New in version 2022\.2 (4\.1 R1\)

* iOS 15 and Xcode 13 are now supported.
* iOS 12 and Xcode 11 are no longer supported.
* Standby mode and the wake word functionality are now available for Canadian English. \[HCPLAT\-2424]
* There is now only one voice available for Text\-To\-Speech. The NUSASession APIs `speakingVoice`, `kNUSASpeakingVoiceFemale` and `kNUSASpeakingVoiceMale` no longer have any effect and will be removed in future versions. \[DNB\-41171]
* The Dragon Medical SpeechKit end user help is now only available in the personalization \& help window when using a speech\-enabled application. It is no longer available as a URL. \[DNB\-38606]

### Solved issues in version 2022\.2 (4\.1 R1\)

* The app no longer crashes when the speech recognition session is closed without explicitly destroying the VuiController. \[DNB\-38159]
* Alert and notification sounds now play correctly when the app is in standby mode. \[FLOR\-31840]
* The wake word functionality now works correctly after the native iOS dictation functionality has been used. \[FLOR\-37967]
* **Dragon Medical Virtual Assistant (DMVA):** The app no longer crashes when the virtual assistant session is opened before the speech recognition session is opened. DMVA is only available for US English in Nuance\-hosted systems. \[DNB\-38204]
