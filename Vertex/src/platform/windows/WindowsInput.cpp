#include "pch.h"
#include "WindowsInput.h"
#include "GLFW/glfw3.h"

#include "core/Application.h"

namespace Vertex {

	Input* Input::s_Input_Instance = new WindowsInput();

	bool WindowsInput::IsKeyPressedImpl(KeyCode code)
	{
		bool to_return = 0;

		GLFWwindow* window = (GLFWwindow*)Application::GetAppInstance().GetWindow().GetNativeWindow();
		auto state = glfwGetKey(window, (int)code);

		if (state == GLFW_PRESS || state == GLFW_REPEAT)
			to_return = 1;

		return to_return;
	}

	bool WindowsInput::IsMouseButtonPressedImpl(KeyCode code)
	{
		bool to_return = 0;

		GLFWwindow* window = (GLFWwindow*)Application::GetAppInstance().GetWindow().GetNativeWindow();
		auto state = glfwGetMouseButton(window, (int)code);

		if (state == GLFW_PRESS || state == GLFW_REPEAT)
			to_return = 1;

		return to_return;
	}

	int WindowsInput::GetMouseXImpl()
	{
		double to_return = -1;

		GLFWwindow* window = (GLFWwindow*)Application::GetAppInstance().GetWindow().GetNativeWindow();
		glfwGetCursorPos(window, &to_return, nullptr);

		return (int)to_return;
	}

	int WindowsInput::GetMouseYImpl()
	{
		double to_return = -1;

		GLFWwindow* window = (GLFWwindow*)Application::GetAppInstance().GetWindow().GetNativeWindow();
		glfwGetCursorPos(window, nullptr, &to_return);

		return (int)to_return;
	}

}
