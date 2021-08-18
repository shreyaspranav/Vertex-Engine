project "SandboxApp"
    kind "ConsoleApp"
    language "C++"
    staticruntime "Off"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/")
    objdir ("%{wks.location}/bin-int/" .. outputdir .. "/")

    files {
        "src/**.h",
        "src/**.cpp"
    }

    -- Add include dirs
    includedirs {
        "%{wks.location}/Vertex/src",
        "%{wks.location}/Vertex/src/pch",
        "%{wks.location}/Vertex/vendor/glad/include",
        "%{wks.location}/Vertex/vendor/spdlog/include",
    }

    links {
        "Vertex"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            "VT_PLATFORM_WINDOWS"
        }


    filter "configurations:Debug"
        defines "VT_DEBUG"
        symbols "On"
        buildoptions "/MDd"

    filter "configurations:Release"
        defines "VT_RELEASE"
        optimize "On"
        buildoptions "/MD"
