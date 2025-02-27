// swift-tools-version:5.7
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "Dragon-Medical-SpeechKit-iOS",
    defaultLocalization: "en",
    platforms: [
        .iOS(.v16)
        ],
    products: [
        // Products define the executables and libraries produced by a package, and make them visible to other packages.
        .library(
            name: "Dragon-Medical-SpeechKit-iOS",
            targets: ["Bundle", "DragonMedicalSpeechKit"]
        )
    ],
    targets: [
        // Targets are the basic building blocks of a package. A target can define a module or a test suite.
        // Targets can depend on other targets in this package, and on products in packages which this package depends on.
        .target(
            name: "Bundle",
            dependencies: ["MicrosoftCognitiveServicesSpeech"],
            path: "Sources/SDK",
            resources: [
                .process("Bundle/Resources"),
                .copy("Bundle/UI/Correction.storyboardc")
            ]
        ),
        .binaryTarget(
                    name: "DragonMedicalSpeechKit",
                    path: "Sources/SDK/DragonMedicalSpeechKit.xcframework"
                ),
        .binaryTarget(
            name: "MicrosoftCognitiveServicesSpeech",
            path:  "Sources/MicrosoftCognitiveServicesSpeech/MicrosoftCognitiveServicesSpeech.xcframework"
        )
    ]
)

//
