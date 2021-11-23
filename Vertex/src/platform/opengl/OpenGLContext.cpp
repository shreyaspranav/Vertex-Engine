#include "pch.h"
#include "OpenGLContext.h"

namespace Vertex {

	OpenGLContext::OpenGLContext(Window* window)
	{
		m_Window = (GLFWwindow*) window->GetNativeWindow();
	}
	OpenGLContext::~OpenGLContext()
	{

	}
	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_Window);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			VT_LOG_ENGINE_ERROR("Glad Failed to initialise!");
		}
	}
	void OpenGLContext::SwapBuffers()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);

		//temp
		glClear(GL_COLOR_BUFFER_BIT);

		glClearColor(1, 1, 0, 1);
	}

}