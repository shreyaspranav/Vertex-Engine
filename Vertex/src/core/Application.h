#pragma once

#include "Core.h"
#include <event/Event.h>
#include "Log.h"
#include "primitives/window/Window.h"

namespace Vertex {
	class VERTEX_API Application
	{
	public:
		Application();
		virtual ~Application();

		void OnEvent(Event& event);

		void Run();
	};

	// To be Defined in the client!
	Application* CreateApplication();
}
