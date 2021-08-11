#pragma once
#include "primitives/window/Window.h"

#include <GLFW/glfw3.h>
#include <event/Event.h>
#include <event/WindowEvent.h>
#include <event/KeyEvent.h>
#include <event/MouseEvent.h>

namespace Vertex
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(WindowProperties& properties);

	public:
		virtual ~WindowsWindow();

		struct WindowData {
			unsigned int width, height;
			std::string title;
			bool vsync;

			EventCallbackFn EventFn;
		};
		WindowData data;

		void Init() override;
		void Update() override;
		void CleanUp() override;

		void SetEventCallbackFn(EventCallbackFn fn) override;

	private:
		GLFWwindow* window;
	};
}

