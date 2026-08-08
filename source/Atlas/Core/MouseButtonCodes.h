#pragma once

#include <string>
#include <ostream>

namespace Atlas
{
	namespace Mouse
	{
		enum class Button : int
		{
			Button1 = 0,
			Button2 = 1,
			Button3 = 2,
			Button4 = 3,
			Button5 = 4,
			Button6 = 5,
			Button7 = 6,
			Button8 = 7,
			Last = Button8,
			Left = Button1,
			Right = Button2,
			Middle = Button3
		};

		std::string ToString(Button button);
		std::ostream& operator <<(std::ostream& os, const Button& button);
	}
}