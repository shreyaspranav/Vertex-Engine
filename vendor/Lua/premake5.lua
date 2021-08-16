project "Lua"
	kind "StaticLib"
	language "C"
	staticruntime "On"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/")

	files
	{
		"src/**.c",
		"include/**.h"
	}

	includedirs
	{
		"include/"
	}

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"