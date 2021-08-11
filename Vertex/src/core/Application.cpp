#include <pch.h>
#include "Application.h"
#include <iostream>

namespace Vertex {
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::OnEvent(Event& event)
	{
		VT_LOG_ENGINE_TRACE(event.ToString());
		if (event.ToString() == "WindowClose")
		{
			exit(0);
		}
	}

	void Application::Run()
	{
		std::cout << "HelloWorld: Vertex Engine" << std::endl;

		WindowProperties props;
		Window* window = Window::GetWindow(props);
		window->Init();

		window->SetEventCallbackFn(std::bind(&Vertex::Application::OnEvent, this, std::placeholders::_1));
		while (true)
		{
			window->Update();
		}
	}
}