# Nuance Dragon Medical SpeechKit
Dragon Medical SpeechKit enables industry-leading healthcare speech recognition services for mobile and desktop application developers. For more information, documentation and other resources, register at: https://www.nuance.com/healthcare/developers.html

This GitHub repository provides the Swift package for Dragon Medical SpeechKit (iOS edition).

## Installation
To add the Swift package to your project, do the following:
     1.     In the Xcode **Projects and Targets** list, select your project, then select the **Swift Package** tab.
     2.     Select + in the lower left corner of the **Swift Packages** section to add a new package.
     3.     In the search bar, enter the repository URL: https://github.com/nuance-communications/Dragon-Medical-SpeechKit-iOS
     4.     In the **Dependency Rule** menu, select **Exact version** and confirm the version number corresponds to the Dragon Medical SpeechKit version you want to add.
     5.     Click **Add Package**.
     6.     In the **Choose Package Products** window, select Dragon-Medical-SpeechKit-iOS and choose your target, then select **Add Package**. Xcode will resolve the package and add the SpeechKit package to your selected target. You should see **Dragon-Medical-SpeechKit-iOS** listed in your package dependencies.
  7.   To import the package, add the import statement to your code :

    Swift: import DragonMedicalSpeechKit
    Objective C: @import DragonMedicalSpeechKit;

For more information on working with Swift packages, see: https://developer.apple.com/documentation/xcode/adding-package-dependencies-to-your-app

## Speech-enabling your app
To activate speech recognition, you will need licensing information in the form of a partner GUID and an organization token; your integration passes these parameters to Dragon Medical SpeechKit when initializing a session. Once your registration at https://www.nuance.com/healthcare/developers.html is approved, you will receive licenses for a 90-day evaluation period. You will also have access to the SDK documentation, support forums and other resources to help you optimize your integration for production usage.

## Built for Healthcare

With decades of healthcare experience, an extensive industry footprint, and our highly scalable voice platform, Nuance offers SDKs to match the needs and priorities of healthcare clients.

Nuance advanced voice and language technologies are based on billions of end-user interactions. Our hosted platform learns at scale, capturing more than 300 million minutes of voice dictation every year for a smarter, faster, more responsive experience.

By offering a unique blend of sophistication and simplicity, we can drastically enhance your healthcare app without complicated coding. Complete integration of speech dictation and voice-enabled workflows in minutes or hours, not days or weeks.

Advanced command and control and text-to-speech capabilities create a more natural and responsive user experience. Beyond simply recording speech, our SDKs and services drive secure, intelligent voice-enabled workflows with features such as Auto-texts, custom medical vocabularies, voice correction capabilities and more.

Available in a range of hosted and on-premise configurations, our platform supports 20 languages for developers and clients in more than 30 countries.
