#pragma once

#include "primitives/Context.h"
#include "glad/glad.h"

namespace Vertex {

	class OpenGLContext : public Context
	{
	public:

		OpenGLContext(GLFWwindow* window_handle);

		void Init() override;
		void Update() override;

	private:
		GLFWwindow* m_window_handle;

	};

}

