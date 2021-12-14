#pragma once
#include "pch.h"

namespace Vertex {

	class Shader
	{
	public:
		Shader(const std::string& verSrc, const std::string& fragSrc);
		~Shader();

		void Bind() const;
		void UnBind() const;

	private:
		uint32_t m_RendererID;
	};
}