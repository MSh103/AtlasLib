#pragma once

#include <string>

#define EVENT_CLASS_TYPE(type) virtual const char* GetName() const override { return #type; }

namespace Atlas
{

	enum class EventType
	{
		None,
		WindowResize, WindowClose, WindowMinimize,
	};

	class Event
	{
	public:
		virtual ~Event() = default;

		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual std::string ToString() const { return GetName(); }

		bool Handled() { return m_Handled; }
	protected:
		bool m_Handled = false;
	};

	class WindowCloseEvent : public Event
	{
	public:
virtual EventType GetEventType() const override
		{
			return EventType::WindowClose;
		}

		EVENT_CLASS_TYPE(WindowClose)
	};

}
