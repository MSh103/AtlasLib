#pragma once

#include "Event.h"

#include "Atlas/Core/KeyCodes.h"

namespace Atlas
{
	class KeyEvent : public Event
	{
	public:
		inline Keyboard::Key GetKeyCode() const { return m_KeyCode; }
	protected:
		KeyEvent(Keyboard::Key keycode)
			: m_KeyCode(keycode)
		{}

		Keyboard::Key m_KeyCode;
	};

	class KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(Keyboard::Key keycode, int repeatCount)
			: KeyEvent(keycode), m_RepeatCount(repeatCount)
		{}

		inline int GetRepeatCount() const { return m_RepeatCount; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << Keyboard::ToString(m_KeyCode) << " (" << m_RepeatCount << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int m_RepeatCount;
	};


	class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(Keyboard::Key keycode)
			: KeyEvent(keycode)
		{}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << Keyboard::ToString(m_KeyCode);
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased);
	};

	class KeyTypedEvent : public Event
	{
	public:
		KeyTypedEvent(uint32_t codePoint)
			: m_CodePoint(codePoint)
		{}

		std::string ToString() const override 
		{
			std::stringstream ss;
			ss << "KeyTypedEvent: " << m_CodePoint;
			return ss.str();
		}

		inline uint32_t GetCodePoint() const { return m_CodePoint; }

		EVENT_CLASS_TYPE(KeyTyped)
	private:
		uint32_t m_CodePoint;
	};
}