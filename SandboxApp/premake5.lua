project "SandboxApp"
    kind "ConsoleApp"
    language "C++"

    targetdir("%{wks.location}/bin/" .. outputdir .. "/")
    objdir ("%{wks.location}/bin/" .. outputdir .. "/")

    files {
        "src/**.h",
        "src/**.cpp"
    }

    -- Add include dirs
    includedirs {
        "%{wks.location}/Vertex/src"
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

    filter "configurations:Release"
        defines "VT_RELEASE"
        optimize "On"
