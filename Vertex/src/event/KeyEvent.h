#pragma once

#include <core/Core.h>
#include <core/KeyCodes.h>
#include <event/Event.h>

namespace Vertex
{
	class KeyPressedEvent : public Event
	{
	private:
		KeyCode code;
		bool repeat;

	public:
		KeyPressedEvent(KeyCode code, bool repeat) : code(code), repeat(repeat) {}

		inline KeyCode GetKey() { return code; }
		inline bool IsRepeating() { return repeat; }

		std::string ToString() const override 
		{ 
			std::stringstream ss;
			ss << "KeyPressed: " << (int)code << ", Repeat: " << repeat;
			return ss.str();
		}

		DEFINE_EVENT_CLASS_TYPE(KeyPressed)
		DEFINE_EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeyBoard)
	};

	class KeyReleasedEvent : public Event
	{
	private:
		KeyCode code;
	public:
		KeyReleasedEvent(KeyCode code) : code(code) {}

		inline KeyCode GetKey() { return code; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleased: " << (int)code;
			return ss.str();
		}

		DEFINE_EVENT_CLASS_TYPE(KeyReleased)
		DEFINE_EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeyBoard)
	};
}