#pragma once
#include "core/Layer.h"

#include "Shader.h"

#include <glad/glad.h>

namespace Vertex {
	
	class TestLayer : public Layer
	{

		unsigned int VBO, VAO, EBO;

		void OnAttach() override {

			const std::string& vertexSrc = "#version 330 core\n"
				"layout (location = 0) in vec3 aPos;\n"
				"void main()\n"
				"{\n"
				"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
				"}\0";
			const std::string& fragmentSrc = "#version 330 core\n"
				"out vec4 FragColor;\n"
				"void main()\n"
				"{\n"
				"   FragColor = vec4(0.8f, 0.2f, 0.4f, 1.0f);\n"
				"}\n\0";

			Shader shader(vertexSrc, fragmentSrc);
			shader.Bind();

			float vertices[] = {
				 0.5f,  0.5f, 0.0f,  // top right
				 0.5f, -0.5f, 0.0f,  // bottom right
				-0.5f, -0.5f, 0.0f,  // bottom left
				-0.5f,  0.5f, 0.0f   // top left 
			};
			unsigned int indices[] = {  // note that we start from 0!
				0, 1, 3,  // first Triangle
				1, 2, 3   // second Triangle
			};

			glGenVertexArrays(1, &VAO);
			glGenBuffers(1, &VBO);
			glGenBuffers(1, &EBO);

			// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
			glBindVertexArray(VAO);

			glBindBuffer(GL_ARRAY_BUFFER, VBO);
			glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
			glEnableVertexAttribArray(0);

			// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
			glBindBuffer(GL_ARRAY_BUFFER, 0);

			// remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
			//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

			// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
			// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
			glBindVertexArray(0);


			// uncomment this call to draw in wireframe polygons.
			//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		}
		void OnDetach() override {

		}
		void OnUpdate(float timestep) override {
			glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
	   //glDrawArrays(GL_TRIANGLES, 0, 6);
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		}
		void OnEvent(Event& event) override {

			if (event.GetName() == "WindowResize")
			{
				WindowResizeEvent& e = (WindowResizeEvent&)event;
				glViewport(0, 0, e.GetWidth(), e.GetHeight());
			}
		}
	};
}