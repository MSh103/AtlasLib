#pragma once

#include <string>
#include <sstream>

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }


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

		void SetHandled(bool s) { m_Handled = s; }
		bool Handled() { return m_Handled; }
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


	/// /////////////// EVENTS //////////////////////

	class WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() = default;

		EVENT_CLASS_TYPE(WindowClose)
	};

	class WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(int width, int height) 
			:m_Width(width), m_Height(height)
		{}
		
		int GetWidth() const { return m_Width; }
		int GetHeight() const { return m_Height; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResize: " << m_Width << ", " << m_Height;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
	protected:
		int m_Width, m_Height;
	};

}
