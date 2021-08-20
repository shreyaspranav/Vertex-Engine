#pragma once

#include "pch.h"
#include "Core.h"
#include <event/Event.h>
#include "Log.h"
#include "Layer.h"
#include "primitives/window/Window.h"
#include "LayerStack.h"

namespace Vertex {
	class VERTEX_API Application
	{
	public:
		Application();
		virtual ~Application();

		inline static Application& GetAppInstance() { return *s_Instance; }
		inline Window& GetWindow() { return *window; }

		void OnEvent(Event& event);

		void PushLayer(Layer* layer);
		void PopLayer(Layer* layer);
		void PushOverlay(Layer* layer);
		void PopOverlay(Layer* layer);

		virtual void OnCreate();
		virtual void OnStart();
		virtual void OnUpdate(float interval);
		virtual void OnExit();

		void Run();

		unsigned int width = 1280, height = 720;
		std::string title = "Vertex Engine";
		bool vsync = 1;

		

	private:
		LayerStack stack;
		std::unique_ptr<Window> window;
		static Application* s_Instance;
	};

	// To be Defined in the client!
	Application* CreateApplication();
}
