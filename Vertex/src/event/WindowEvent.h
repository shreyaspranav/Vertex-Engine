#pragma once

#include <event/Event.h>

namespace Vertex {

	class WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() = default;

		DEFINE_EVENT_CLASS_TYPE(WindowClose)
		DEFINE_EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class WindowResizeEvent : public Event
	{
	private:
		unsigned int width, height;

	public:
		WindowResizeEvent(unsigned int width, unsigned int height) 
			: width(width), height(height) {}

		inline unsigned int GetWidth() const { return width; }
		inline unsigned int GetHeight() const { return height; }

		DEFINE_EVENT_CLASS_TYPE(WindowResize)
		DEFINE_EVENT_CLASS_CATEGORY(EventCategoryApplication)
		
		std::string ToString() const override 
		{
			std::stringstream ss;
			ss << "Window Resize Event: " << width << ", " << height;
			return ss.str();
		}

	};

	class WindowFocusEvent : public Event
	{
	public:
		WindowFocusEvent() = default;

		DEFINE_EVENT_CLASS_TYPE(WindowFocus)
		DEFINE_EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class WindowLostFocusEvent : public Event
	{
	public:
		WindowLostFocusEvent() = default;

		DEFINE_EVENT_CLASS_TYPE(WindowLostFocus)
		DEFINE_EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}