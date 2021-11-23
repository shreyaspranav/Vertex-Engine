#pragma once
#include "primitives/window/Window.h"

#include <GLFW/glfw3.h>
#include <event/Event.h>
#include <event/WindowEvent.h>
#include <event/KeyEvent.h>
#include <event/MouseEvent.h>

#include <renderer/G_Context.h>
#include <platform/opengl/OpenGLContext.h>

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

			GraphicsAPI api;
			EventCallbackFn EventFn;
		};
		WindowData data;

		void Init() override;
		void Update() override;
		void CleanUp() override;

		void SetEventCallbackFn(EventCallbackFn fn) override;

		inline unsigned int GetWidth() override { return data.width; }
		inline unsigned int GetHeight() override { return data.height; }

		inline void* GetNativeWindow() override { return window; }

	private:
		GLFWwindow* window;
		G_Context* context;
	};
}

