#pragma once

#include "Event.h"

#include "Atlas/Core/MouseButtonCodes.h"

#include <utility>

namespace Atlas
{
	class MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float x, float y)
			: m_MouseX(x), m_MouseY(y)
		{}

		inline std::pair<float, float> Get() const { return { m_MouseX, m_MouseY }; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
			return ss.str();
		}
		
		EVENT_CLASS_TYPE(MouseMoved)
	private:
		float m_MouseX, m_MouseY;
	};

	class MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float xOffset, float yOffset)
			:m_XOffset(xOffset), m_YOffset(yOffset)
		{}

		inline std::pair<float, float> Get() { return { m_XOffset, m_YOffset }; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << m_XOffset << ", " << m_YOffset;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
	private:
		float m_XOffset, m_YOffset;
	};

	class MouseButtonEvent : public Event
	{
	public:
		inline Mouse::Button GetMouseButton() { return m_Button; }
	
	protected:
		MouseButtonEvent(Mouse::Button button)
			: m_Button(button)
		{}

		Mouse::Button m_Button;
	};

	class MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(Mouse::Button button, float x, float y)
			:MouseButtonEvent(button), m_MouseX(x), m_MouseY(y)
		{}

		inline std::pair<float, float> Get() { return { m_MouseX, m_MouseY }; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << Mouse::ToString(m_Button) << 
				" " << m_MouseX << ", " << m_MouseY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	private:
		float m_MouseX, m_MouseY;
	};

	class MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(Mouse::Button button)
			: MouseButtonEvent(button)
		{}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << Mouse::ToString(m_Button);
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};

}