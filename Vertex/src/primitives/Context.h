#pragma once

#include "core/Core.h"
#include <GLFW/glfw3.h>


namespace Vertex {
	
	class Context
	{
	public:
		virtual void Init() = 0;
		virtual void Update() = 0;
	};
}