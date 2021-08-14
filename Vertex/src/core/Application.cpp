#include <pch.h>
#include "Application.h"
#include <iostream>
#include <gl/GL.h>

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


			glClear(GL_COLOR_BUFFER_BIT);
			glClearColor(0, 0, 0, 1);

			glBegin(GL_TRIANGLES);
			glColor3f(1.0, 0.0, 0.0); glVertex3f(-0.5, -0.5, 0.0);
			glColor3f(0.0, 1.0, 0.0); glVertex3f(0.0, 0.5, 0.0);
			glColor3f(0.0, 0.0, 1.0); glVertex3f(0.5, -0.5, 0.0);
			glEnd();

			window->Update();
		}
	}
}