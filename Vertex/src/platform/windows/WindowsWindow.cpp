#include "pch.h"
#include "WindowsWindow.h"
#include "core/Log.h"
#include <event/Event.h>

namespace Vertex {
	Window* Window::GetWindow(WindowProperties& properties)
	{
		return new WindowsWindow(properties);
	}

	WindowsWindow::WindowsWindow(WindowProperties& properties)
	{
		data.width = properties.width;
		data.height = properties.height;
		data.title = properties.title;
		data.vsync = properties.vsync;
	}

	void WindowsWindow::SetEventCallbackFn(EventCallbackFn fn)
	{
		data.EventFn = fn;
	}

	WindowsWindow::~WindowsWindow()
	{
		CleanUp();
	}

	void WindowsWindow::Init()
	{
		bool b = glfwInit();
		if (!b) {
			VT_LOG_ENGINE_ERROR("Error: GLFW failed to initialise!");
			while (1);
		}

		if (b) {
			VT_LOG_ENGINE_INFO("GLFW initilaised!");
		}

		window = glfwCreateWindow(data.width, data.height, data.title.c_str(), NULL, NULL);
		VT_LOG_ENGINE_TRACE("Window: {0} X {1}, Title: {2}", data.width, data.height, data.title);

		glfwShowWindow(window);
		glfwMakeContextCurrent(window);

		glfwSetWindowUserPointer(window, &data);

		glfwSetErrorCallback([](int error_code, const char* description)
			{
				VT_LOG_ENGINE_ERROR("Error: {0}", error_code);
				VT_LOG_ENGINE_ERROR(description);
			});

		glfwSetWindowCloseCallback(window, [](GLFWwindow* window)
			{
				WindowData& windowData = *(WindowData*)glfwGetWindowUserPointer(window);
				WindowCloseEvent closeEvent;

				windowData.EventFn(closeEvent);
			});

		glfwSetWindowSizeCallback(window, [](GLFWwindow* window, int width, int height)
			{
				WindowData& windowData = *(WindowData*)glfwGetWindowUserPointer(window);

				windowData.width = width;
				windowData.height = height;

				WindowResizeEvent resizeEvent(width, height);

				windowData.EventFn(resizeEvent);
			});

		glfwSetWindowFocusCallback(window, [](GLFWwindow* window, int focus)
			{
				WindowData& windowData = *(WindowData*)glfwGetWindowUserPointer(window);

				if (focus == GLFW_TRUE)
				{
					WindowFocusEvent focusEvent;
					windowData.EventFn(focusEvent);
				}

				else if (focus == GLFW_FALSE)
				{
					WindowLostFocusEvent lostFocusEvent;
					windowData.EventFn(lostFocusEvent);
				}
			});

		glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				WindowData& windowData = *(WindowData*)glfwGetWindowUserPointer(window);

				if (action == GLFW_PRESS)
				{
					KeyPressedEvent keyEvent((KeyCode)key, 0);
					windowData.EventFn(keyEvent);
				}

				if (action == GLFW_RELEASE)
				{
					KeyReleasedEvent keyEvent((KeyCode)key);
					windowData.EventFn(keyEvent);
				}

				if (action == GLFW_REPEAT)
				{
					KeyPressedEvent keyEvent((KeyCode)key, 1);
					windowData.EventFn(keyEvent);
				}
			});

		glfwSetCursorPosCallback(window, [](GLFWwindow* window, double x, double y)
			{
				WindowData& windowData = *(WindowData*)glfwGetWindowUserPointer(window);
				MouseMovedEvent event(x, y);

				windowData.EventFn(event);

			});

		glfwSetMouseButtonCallback(window, [](GLFWwindow* window, int button, int action, int mods)
			{
				WindowData& windowData = *(WindowData*)glfwGetWindowUserPointer(window);

				if (action == GLFW_PRESS)
				{
					double x, y;
					glfwGetCursorPos(window, &x, &y);
					MouseButtonPressedEvent event((KeyCode)button, 0, x, y);
					windowData.EventFn(event);
				}

				if (action == GLFW_RELEASE)
				{
					double x, y;
					glfwGetCursorPos(window, &x, &y);
					MouseButtonReleasedEvent event((KeyCode)button, x, y);
					windowData.EventFn(event);
				}

				if (action == GLFW_REPEAT)
				{
					double x, y;
					glfwGetCursorPos(window, &x, &y);
					MouseButtonPressedEvent event((KeyCode)button, 1, x, y);
					windowData.EventFn(event);
				}
			});

		glfwSetScrollCallback(window, [](GLFWwindow* window, double xoffset, double yoffset)
			{
				WindowData& windowData = *(WindowData*)glfwGetWindowUserPointer(window);
				MouseButtonScrolledEvent event((MouseButtonScrolledEvent::ScrollDir)yoffset);
				windowData.EventFn(event);
			});


		if (data.vsync) {
			glfwSwapInterval(1);
		}

		else {
			glfwSwapInterval(0);
		}

		// temporary
		glfwMakeContextCurrent(window);
	}

	void WindowsWindow::Update()
	{
		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	void WindowsWindow::CleanUp()
	{
		glfwDestroyWindow(window);
		glfwTerminate();
	}
}