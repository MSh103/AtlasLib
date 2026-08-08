#include "MouseButtonCodes.h"

#include "Log.h"

namespace Atlas
{
	namespace Mouse
	{
		std::string ToString(Button button)
		{
			switch (button)
			{
			case Button::Button1: return "Left"; break;
			case Button::Button2: return "Right"; break;
			case Button::Button3: return "Middle"; break;
			case Button::Button4: return "Button4"; break;
			case Button::Button5: return "Button5"; break;
			case Button::Button6: return "Button6"; break;
			case Button::Button7: return "BUtton7"; break;
			case Button::Button8: return "Last"; break;
			default:
			{
				int code = (int)button;
				::Atlas::Log::Core::Error("Unknown Mouse Button Type! raw={}", code);
				return "Unknown";
			}
			}
		}

		std::ostream& operator<<(std::ostream& os, const Button& button)
		{
			os << ToString(button);
			return os;
		}
	}
}