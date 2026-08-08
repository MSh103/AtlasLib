#pragma once

#include "Core.h"
#include "KeyCodes.h"
#include "MouseButtonCodes.h"

namespace Atlas
{
	class Input
	{
	public:
		inline static bool IsKeyPressed(Keyboard::Key key) { return s_Instance->IsKeyPressedImpl(key); }
		
		inline static bool IsMouseButtonPressed(Mouse::Button button) { return s_Instance->IsMouseButtonPressedImpl(button); }
		inline std::pair<float, float> GetMousePosition() { return s_Instance->GetMousePositionImpl(); }
	private:
		bool IsKeyPressedImpl(Keyboard::Key key);
		
		bool IsMouseButtonPressedImpl(Mouse::Button button);
		std::pair<float, float> GetMousePositionImpl();

	private:
		static Input* s_Instance;
	};
}