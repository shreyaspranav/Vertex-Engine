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

		VT_LOG_ENGINE_WARN("OpenGL Info: \n");
		VT_LOG_ENGINE_INFO("Vendor: {0}", glGetString(GL_VENDOR));
		VT_LOG_ENGINE_INFO("Renderer: {0}", glGetString(GL_RENDERER));
		VT_LOG_ENGINE_INFO("Version: {0} \n", glGetString(GL_VERSION));
	}

	void OpenGLContext::Update()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0, 0, 0, 1);
	}
}