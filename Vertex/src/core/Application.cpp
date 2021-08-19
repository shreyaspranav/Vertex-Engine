#include <pch.h>
#include "Application.h"
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "debug/imgui/ImGuiLayer.h"


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
			Application::OnExit();
			exit(0);
		}

		for (auto it = stack.LayerRBegin(); it != stack.LayerREnd(); ++it)
		{
			if (event.event_handled)
				break;

			(*it)->OnEvent(event);
		}
	}

	void Application::PushLayer(Layer* layer)
	{
		stack.PushLayer(layer);
	}

	void Application::PopLayer(Layer* layer)
	{
		stack.PopLayer(layer);
	}

	void Application::PushOverlay(Layer* layer)
	{
		stack.PushOverlay(layer);
	}

	void Application::PopOverlay(Layer* layer)
	{
		stack.PopOverlay(layer);
	}

	void Application::OnStart()
	{
		OnStart();
	}

	void Application::OnUpdate(float interval)
	{
		OnUpdate(interval);
		glClear(GL_COLOR_BUFFER_BIT);
		for (auto i = stack.LayerBegin(); i != stack.LayerEnd(); ++i) {
			(*i)->OnUpdate(0.0f);
		}
	}

	void Application::OnExit()
	{
	}

	void Application::Run()
	{
		std::cout << "HelloWorld: Vertex Engine" << std::endl;

		WindowProperties props;
		std::unique_ptr<Window> window = std::unique_ptr<Window>(Window::GetWindow(props));
		window->Init();

		window->SetEventCallbackFn(std::bind(&Vertex::Application::OnEvent, this, std::placeholders::_1));

		// temporary
		gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		Application::OnStart();

		//PushOverlay(new ImGuiLayer());

		while (true)
		{
			Application::OnUpdate(0.0);
			window->Update();
		}
	}
}