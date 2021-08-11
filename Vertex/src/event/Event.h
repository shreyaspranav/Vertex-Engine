#pragma once

#include <pch/pch.h>
#include <core/Core.h>

namespace Vertex
{
	enum class EventType
	{
		None = 0,

		// Window Events:
		WindowClose, WindowResize, WindowFocus, WindowLostFocus,

		// App Events: TODO: Implement them asap
		AppFixedUpdate, AppUpdate,

		// Key Events:
		KeyPressed, KeyReleased,

		// Mouse Events:
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication	 = BIT(0),
		EventCategoryInput			 = BIT(1),
		EventCategoryKeyBoard		 = BIT(2),
		EventCategoryMouse			 = BIT(3),
		EventCategoryMouseButton	 = BIT(4)
	};

	#define DEFINE_EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; }  \
										  virtual EventType GetEventType() const override { return GetStaticType(); }  \
										  virtual std::string GetName() const override { return #type; }

	#define DEFINE_EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override {return category;}

	class VERTEX_API Event
	{
	public:
		bool event_handled;

		virtual EventType GetEventType() const = 0;
		virtual int GetCategoryFlags() const = 0;

		virtual std::string GetName() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory cat) { return GetCategoryFlags() & cat; }
	};
}