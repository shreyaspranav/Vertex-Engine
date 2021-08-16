#pragma once
#include <pch.h>
#include <event/Event.h>
#include "Core.h"


namespace Vertex {
	class VERTEX_API Layer
	{
	public:
		Layer(std::string name = "Layer"):m_debugname(name) {}
		virtual ~Layer() = default;

		virtual void OnAttach(){}
		virtual void OnDetach(){}
		virtual void OnUpdate(float timestep){}
		virtual void OnEvent(Event& event){}

		virtual std::string GetName() { return m_debugname; }
	protected:
		std::string m_debugname;

	};
}
