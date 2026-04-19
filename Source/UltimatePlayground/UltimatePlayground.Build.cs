// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UltimatePlayground : ModuleRules
{
	public UltimatePlayground(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"UltimatePlayground",
			"UltimatePlayground/Variant_Platforming",
			"UltimatePlayground/Variant_Platforming/Animation",
			"UltimatePlayground/Variant_Combat",
			"UltimatePlayground/Variant_Combat/AI",
			"UltimatePlayground/Variant_Combat/Animation",
			"UltimatePlayground/Variant_Combat/Gameplay",
			"UltimatePlayground/Variant_Combat/Interfaces",
			"UltimatePlayground/Variant_Combat/UI",
			"UltimatePlayground/Variant_SideScrolling",
			"UltimatePlayground/Variant_SideScrolling/AI",
			"UltimatePlayground/Variant_SideScrolling/Gameplay",
			"UltimatePlayground/Variant_SideScrolling/Interfaces",
			"UltimatePlayground/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
