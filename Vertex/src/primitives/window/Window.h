#pragma once
#include "core/Core.h"
#include "core/Log.h"

#include <event/Event.h>

namespace Vertex
{
	enum GraphicsAPI
	{
		VT_OPENGL = 0,
		VT_VULKAN = 1,
		VT_DIRECTX = 2,

		VT_OPENGL_ES = 3,
		VT_VULKAN_MOBILE = 4
	};

	struct WindowProperties
	{
		unsigned int width, height;
		std::string title;
		bool vsync;

		GraphicsAPI api;

		WindowProperties(GraphicsAPI api, unsigned int width = 1280,
			unsigned int height = 720,
			std::string title = "Vertex Engine",
			bool vsync = 0)
			:api(api), width(width), height(height), title(title), vsync(vsync) {}
	};

	using EventCallbackFn = std::function<void(Event&)>;

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
	};
}