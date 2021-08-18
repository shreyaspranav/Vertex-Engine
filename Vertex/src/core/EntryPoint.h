#pragma once
#include "Core.h"
#include "Application.h"
#include "Log.h"


#ifdef VT_PLATFORM_WINDOWS

extern Vertex::Application* Vertex::CreateApplication();

	void main()
	{
		VT_INIT_LOGGER;
		auto app = Vertex::CreateApplication();
		app->Run();
		delete app;
	}


#endif // VT_PLATFORM_WINDOWS

