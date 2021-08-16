#pragma once
#include <pch.h>
#include "Layer.h"
#include "Core.h"

namespace Vertex {
	class VERTEX_API LayerStack
	{
		using LayerVec = std::vector<Layer*>;

	private:
		LayerVec m_Layers;
		unsigned int layer_index = 0;

	public:
		LayerStack();
		virtual ~LayerStack();

		void PushLayer(Layer* layer);
		void PopLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		void PopOverlay(Layer* overlay);

		LayerVec::iterator LayerBegin()							{ return m_Layers.begin(); }
		LayerVec::iterator LayerEnd()							{ return m_Layers.end(); }
		LayerVec::reverse_iterator LayerRBegin()				{ return m_Layers.rbegin(); }
		LayerVec::reverse_iterator LayerREnd()					{ return m_Layers.rend(); }

		LayerVec::const_iterator LayerBeginConst()				{ return m_Layers.cbegin(); }
		LayerVec::const_iterator LayerEndConst()				{ return m_Layers.cend(); }
		LayerVec::const_reverse_iterator LayerRBeginConst()		{ return m_Layers.crbegin(); }
		LayerVec::const_reverse_iterator LayerREndConst()		{ return m_Layers.crend(); }
	};
}
