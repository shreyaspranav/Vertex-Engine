#pragma once
#include "core/Core.h"
#include "core/Log.h"

#include <event/Event.h>
#include "Context.h"

namespace Vertex
{
	struct WindowProperties
	{
		unsigned int width, height;
		std::string title;
		bool vsync;

		WindowProperties(unsigned int width = 1280,
			unsigned int height = 720,
			std::string title = "Vertex Engine",
			bool vsync = 0)
			:width(width), height(height), title(title), vsync(vsync) {}
	};

	using EventCallbackFn = std::function<void(Event&)>;

	enum GraphicsAPI
	{
		VT_OPENGL = 0,
		VT_VULKAN = 1,
		VT_DIRECTX = 2,
	};

	class VERTEX_API Window
	{
	public:
		static Window* GetWindow(WindowProperties& properties);

		virtual ~Window() {}

		virtual inline unsigned int GetWidth() = 0;
		virtual inline unsigned int GetHeight() = 0;

		virtual void Init() = 0;
		virtual void Update() = 0;
		virtual void CleanUp() = 0;

		virtual inline void* GetNativeWindow() = 0;

		virtual void SetEventCallbackFn(EventCallbackFn fn) = 0;

		virtual void SetGraphicsAPI(GraphicsAPI api) = 0;

	protected:
		GraphicsAPI m_Api;
	};
}