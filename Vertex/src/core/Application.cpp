#include <pch.h>
#include "Application.h"
#include <iostream>
#include <GLFW/glfw3.h>
#include "KeyCodes.h"
#include "platform/PlatformDependent.h"
#include "primitives/Input.h"

namespace Vertex {

	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		
	}

	Application::~Application()
	{

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

	void Application::OnCreate()
	{
		OnCreate();
		WindowProperties props(width, height, title, vsync);
		window = std::unique_ptr<Window>(Window::GetWindow(props));
		s_Instance = this;
		VT_LOG_ENGINE_ERROR(props.title);
	}

	void Application::OnStart()
	{
		window->Init();
		window->SetEventCallbackFn(std::bind(&Vertex::Application::OnEvent, this, std::placeholders::_1));

		Input::Init();
		OnStart();
		
	}

	void Application::OnUpdate(float interval)
	{
		OnUpdate(interval);
		//glClear(GL_COLOR_BUFFER_BIT);
		//glClearColor(0, 0, 0, 1);

		VT_LOG_ENGINE_INFO("{0}", Input::GetMouseX());

		for (auto i = stack.LayerBegin(); i != stack.LayerEnd(); ++i) {
			(*i)->OnUpdate(0.0f);
		}
	}

	void Application::OnExit()
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

	void Application::Run()
	{
		Application::OnCreate();
		Application::OnStart();

		while (true)
		{
			Application::OnUpdate(0.0);
			window->Update();
		}
	}
}