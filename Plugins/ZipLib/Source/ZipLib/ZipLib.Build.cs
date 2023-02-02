// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class ZipLib : ModuleRules
{
    public ZipLib(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PrivateIncludePaths.AddRange(new string[] { "ZipLib/Public" }); //to include headers for your library (*.h)

        if (UnrealTargetPlatform.Win32 == Target.Platform || UnrealTargetPlatform.Win64 == Target.Platform) //decide the platform to package the binaries
        {
            PublicAdditionalLibraries.Add(Path.Combine(PluginDirectory, "Source/ThirdParty/ZipLibLibrary/ZipStaticLib", "ZipLib.lib")); //the full path is "LibraryBinariesFolder/Windows/liblibrary.lib"
            PublicAdditionalLibraries.Add(Path.Combine(PluginDirectory, "Source/ThirdParty/ZipLibLibrary/ZipStaticLib", "bzip2.lib")); //the full path is "LibraryBinariesFolder/Windows/liblibrary.lib"
            PublicAdditionalLibraries.Add(Path.Combine(PluginDirectory, "Source/ThirdParty/ZipLibLibrary/ZipStaticLib", "lzma.lib")); //the full path is "LibraryBinariesFolder/Windows/liblibrary.lib"
            PublicAdditionalLibraries.Add(Path.Combine(PluginDirectory, "Source/ThirdParty/ZipLibLibrary/ZipStaticLib", "zlib.lib")); //the full path is "LibraryBinariesFolder/Windows/liblibrary.lib"
        }
        


        PublicIncludePaths.AddRange(
            new string[] {
				// ... add public include paths required here ...
			}
            );


        PrivateIncludePaths.AddRange(
            new string[] {
				// ... add other private include paths required here ...
			}
            );


        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "ZipLibLibrary",
                "Projects"
				// ... add other public dependencies that you statically link with here ...
			}
            );


        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
				// ... add private dependencies that you statically link with here ...	
			}
            );


        DynamicallyLoadedModuleNames.AddRange(
            new string[]
            {
				// ... add any modules that your module loads dynamically here ...
			}
            );
    }
}
