// Parameters.h
#pragma once

using namespace System;
using namespace System::IO;

public ref class Parameters {
public:
    String^ ConstructCommand(String^ javaPath, String^ nativesPath, String^ librariesPath, String^ versionPath, String^ logConfigPath, String^ basePath, String^ username) {
        // Implementation of ConstructCommand
        // Construct and return the command string
        return String::Format("\"{0}\" -Djava.library.path=\"{1}\" -cp \"{2};{3}\" -Dlog4j.configurationFile=\"{4}\" net.minecraft.launchwrapper.Launch --username {5} --version 1.7.10 --gameDir \"{6}\" --assetsDir \"{7}\" --assetIndex 1.7.10 --uuid {8} --accessToken {9} --userType mojang --tweakClass cpw.mods.fml.common.launcher.FMLTweaker",
            javaPath, nativesPath, librariesPath, versionPath, logConfigPath, username, basePath, Path::Combine(basePath, "assets"), "uuid", "accessToken");
    }
};
