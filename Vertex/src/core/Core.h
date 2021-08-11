#pragma once

#ifdef VT_PLATFORM_WINDOWS
	#ifdef VT_BUILD_DLL
		#define VERTEX_API __declspec(dllexport)
	#else
		#define VERTEX_API __declspec(dllimport)
	#endif // VT_BUILD_DLL
#else
	#error Vertex Engine Supports only windows for now!

#endif // VT_PLATFORM_WINDOWS