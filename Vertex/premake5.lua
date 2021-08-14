project "Vertex"
    kind "SharedLib"
    language "C++"

    targetdir("%{wks.location}/bin/" .. outputdir .. "/")
    objdir ("%{wks.location}/bin/" .. outputdir .. "/")

    
    IncludeDir = {}

    IncludeDir["GLFW"] = "vendor/GLFW/include"

    pchheader "pch.h"
    pchsource "src/pch/pch.cpp"

    files {
        "src/**.h",
        "src/**.cpp"
    }
    
    includedirs {
        "vendor/spdlog/include",
        "src",
        "src/pch",
        "%{IncludeDir.GLFW}",
    }

    links{
        "GLFW",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            "VT_PLATFORM_WINDOWS",
            "VT_BUILD_DLL"
        }

    filter "configurations:Debug"
        defines "VT_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "VT_RELEASE"
        optimize "On"
