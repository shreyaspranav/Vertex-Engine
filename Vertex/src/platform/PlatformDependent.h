#pragma once
#include "core/Core.h"

// Window Stuff
#include "primitives/Window.h"
#include "platform/windows/WindowsWindow.h"

// Input Stuff
#include "primitives/Input.h"
#include "platform/windows/WindowsInput.h"

namespace Vertex {
	
	Window* Window::GetWindow(WindowProperties& props)
	{
		#ifdef VT_PLATFORM_WINDOWS
			return new WindowsWindow(props);
		#endif

		#ifdef VT_PLATFORM_LINUX
			// TODO	
		#endif

		#ifdef VT_PLATFORM_MAC
			//TODO	
		#endif
	}

	void Input::Init()
	{
		#ifdef VT_PLATFORM_WINDOWS
			Input::s_Input_Instance = new WindowsInput();
		#endif
		
		#ifdef VT_PLATFORM_LINUX
			// TODO	
		#endif
		
		#ifdef VT_PLATFORM_MAC
			//TODO	
		#endif
	}
}