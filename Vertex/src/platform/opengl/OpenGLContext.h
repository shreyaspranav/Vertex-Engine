#pragma once

#include <glad/glad.h>
#include "renderer/G_Context.h"
#include "primitives/window/Window.h"
#include <GLFW/glfw3.h>


namespace Vertex {

	class OpenGLContext : public G_Context
	{
	public:
		OpenGLContext(Window* window);
		~OpenGLContext();

		void Init() override;
		void SwapBuffers() override;

	private:
		GLFWwindow* m_Window;
	};

}

