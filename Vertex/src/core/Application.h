#pragma once

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

		void OnEvent(Event& event);

		void PushLayer(Layer* layer);
		void PopLayer(Layer* layer);
		void PushOverlay(Layer* layer);
		void PopOverlay(Layer* layer);

		virtual void OnStart();
		virtual void OnUpdate(float interval);
		virtual void OnExit();

		void Run();

	private:
		LayerStack stack;
	};

	// To be Defined in the client!
	Application* CreateApplication();
}
