#include "pch.h"

#include "core/Layer.h"
#include "core/Log.h"

#include <glad/glad.h>

namespace Vertex {
	class TestOpenGL : public Layer
	{
		
		GLuint vertexbuffer;

		void OnAttach() override {
			//GLuint VertexArrayID;
			//glGenVertexArrays(1, &VertexArrayID);
			//glBindVertexArray(VertexArrayID);

			const GLfloat g_vertex_buffer_data[] = {
				-0.5f, -0.5f, 0.0f,
				 0.5f, -0.5f, 0.0f,
				 0.0f,  0.5f, 0.0f,
			};

			glGenBuffers(1, &vertexbuffer);
			glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
			glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

			
			glVertexAttribPointer(
				0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
				3,                  // size
				GL_FLOAT,           // type
				GL_FALSE,           // normalized?
				0,                  // stride
				(void*)0            // array buffer offset
			);

			glEnableVertexAttribArray(0);

		}
		void OnDetach() override {

		}
		void OnUpdate(float timestep) override {
			//glClear(GL_COLOR_BUFFER_BIT);

			glDrawArrays(GL_TRIANGLES, 0, 3); // 3 indices starting at 0 -> 1 triangle

			//glDisableVertexAttribArray(0);

		}
		void OnEvent(Event& event) override {

		}
	};
}
