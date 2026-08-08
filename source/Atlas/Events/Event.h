#pragma once

#include <string>
#include <sstream>

#define EVENT_CLASS_TYPE(type) static ::Atlas::EventType GetStaticType() { return ::Atlas::EventType::type; }\
								virtual ::Atlas::EventType GetEventType() const override { return GetStaticType(); }\

namespace Atlas
{

	enum class EventType
	{
		None,
		WindowResize, WindowClose,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	class Event
	{
	public:
		virtual ~Event() = default;

		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual std::string ToString() const { return GetName(); }

		void SetHandled(bool s) { m_Handled = s; }
		bool Handled() const { return m_Handled; }
	protected:
		bool m_Handled = false;
	};


	class EventDispatcher
	{
	public:
		EventDispatcher(Event& e)
			: m_Event(e)
		{}

		template<typename T, typename F>
		bool Dispatch(const F& func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.SetHandled(func(static_cast<T&>(m_Event)));
				return true;
			}

			return false;
		}

	private:
		Event& m_Event;
	};
}
