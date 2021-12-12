#include "pch.h"
#include "OpenGLContext.h"
#include "core/Log.h"


namespace Vertex {
	OpenGLContext::OpenGLContext(GLFWwindow* window_handle)
	{
		m_window_handle = window_handle;
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_window_handle);
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			VT_LOG_ENGINE_ERROR("Failed to load Glad!");
		}
	}

	void OpenGLContext::Update()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(1, 0, 1, 1);
	}
}