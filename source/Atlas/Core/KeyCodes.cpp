#include "KeyCodes.h"

#include "Log.h"

namespace Atlas
{
	namespace Keyboard
	{
		std::string ToString(Key key)
		{
			switch (key)
			{
			case Key::Space:			return "Space"; break;
			case Key::Apostrophe:		return "'"; break;
			case Key::Comma:			return ","; break;
			case Key::Minus:			return "-"; break;
			case Key::Period:			return "."; break;
			case Key::Slash:			return "/"; break;
			case Key::K0:				return "0"; break;
			case Key::K1:				return "1"; break;
			case Key::K2:				return "2"; break;
			case Key::K3:				return "3"; break;
			case Key::K4:				return "4"; break;
			case Key::K5:				return "5"; break;
			case Key::K6:				return "6"; break;
			case Key::K7:				return "7"; break;
			case Key::K8:				return "8"; break;
			case Key::K9:				return "9"; break;
			case Key::Semicolon:		return ";"; break;
			case Key::Equal:			return "="; break;
			case Key::A:				return "A"; break;
			case Key::B:				return "B"; break;
			case Key::C:				return "C"; break;
			case Key::D:				return "D"; break;
			case Key::E:				return "E"; break;
			case Key::F:				return "F"; break;
			case Key::G:				return "G"; break;
			case Key::H:				return "H"; break;
			case Key::I:				return "I"; break;
			case Key::J:				return "J"; break;
			case Key::K:				return "K"; break;
			case Key::L:				return "L"; break;
			case Key::M:				return "M"; break;
			case Key::N:				return "N"; break;
			case Key::O:				return "O"; break;
			case Key::P:				return "P"; break;
			case Key::Q:				return "Q"; break;
			case Key::R:				return "R"; break;
			case Key::S:				return "S"; break;
			case Key::T:				return "T"; break;
			case Key::U:				return "U"; break;
			case Key::V:				return "V"; break;
			case Key::W:				return "W"; break;
			case Key::X:				return "X"; break;
			case Key::Y:				return "Y"; break;
			case Key::Z:				return "Z"; break;
			case Key::LBracket:			return "["; break;
			case Key::Backslash:		return "\\"; break;
			case Key::RBracket:			return "]"; break;
			case Key::GraveAccent:		return "`"; break;
			case Key::World1:			return "World1"; break;
			case Key::World2:			return "World2"; break;

			case Key::Escape:			return "Escape"; break;
			case Key::Enter:			return "Enter"; break;
			case Key::Tab:				return "Tab"; break;
			case Key::Backspace:		return "Backspace"; break;
			case Key::Insert:			return "Insert"; break;
			case Key::Delete:			return "Delete"; break;
			case Key::Right:			return "Right"; break;
			case Key::Left:				return "Left"; break;
			case Key::Down:				return "Down"; break;
			case Key::Up:				return "Up"; break;
			case Key::PageUp:			return "PageUp"; break;
			case Key::PageDown:			return "PageDown"; break;
			case Key::Home:				return "Home"; break;
			case Key::End:				return "End"; break;
			case Key::CapsLock:			return "CapsLock"; break;
			case Key::ScrollLock:		return "ScrollLock"; break;
			case Key::NumLock:			return "NumLock"; break;
			case Key::PrtScreen:		return "PrtScreen"; break;
			case Key::Pause:			return "Pause"; break;
			case Key::F1:				return "F1"; break;
			case Key::F2:				return "F2"; break;
			case Key::F3:				return "F3"; break;
			case Key::F4:				return "F4"; break;
			case Key::F5:				return "F5"; break;
			case Key::F6:				return "F6"; break;
			case Key::F7:				return "F7"; break;
			case Key::F8:				return "F8"; break;
			case Key::F9:				return "F9"; break;
			case Key::F10:				return "F10"; break;
			case Key::F11:				return "F11"; break;
			case Key::F12:				return "F12"; break;
			case Key::F13:				return "F13"; break;
			case Key::F14:				return "F14"; break;
			case Key::F15:				return "F15"; break;
			case Key::F16:				return "F16"; break;
			case Key::F17:				return "F17"; break;
			case Key::F18:				return "F18"; break;
			case Key::F19:				return "F19"; break;
			case Key::F20:				return "F20"; break;
			case Key::F21:				return "F21"; break;
			case Key::F22:				return "F22"; break;
			case Key::F23:				return "F23"; break;
			case Key::F24:				return "F24"; break;
			case Key::F25:				return "F25"; break;
			case Key::Num0:				return "Num0"; break;
			case Key::Num1:				return "Num1"; break;
			case Key::Num2:				return "Num2"; break;
			case Key::Num3:				return "Num3"; break;
			case Key::Num4:				return "Num4"; break;
			case Key::Num5:				return "Num5"; break;
			case Key::Num6:				return "Num6"; break;
			case Key::Num7:				return "Num7"; break;
			case Key::Num8:				return "Num8"; break;
			case Key::Num9:				return "Num9"; break;
			case Key::NumDecimal:		return "NumDecimal"; break;
			case Key::NumDivide:		return "NumDivide"; break;
			case Key::NumMultiply:		return "NumMultiply"; break;
			case Key::NumSubtract:		return "NumSubtract"; break;
			case Key::NumAdd:			return "NumAdd"; break;
			case Key::NumEnter:			return "NumEnter"; break;
			case Key::NumEqual:			return "NumEqual"; break;
			case Key::LShift:			return "LShift"; break;
			case Key::LControl:			return "LControl"; break;
			case Key::LAlt:				return "LAlt"; break;
			case Key::LSuper:			return "LSuper"; break;
			case Key::RShift:			return "RShift"; break;
			case Key::RControl:			return "RControl"; break;
			case Key::RAlt:				return "RAlt"; break;
			case Key::RSuper:			return "RSuper"; break;
			case Key::Menu:				return "Menu"; break;
			case Key::NONE:				return "NONE"; break;
			default:
			{
				int code = (int)key;
				::Atlas::Log::Core::Error("Unknown Key Type! raw={}", code);
				return "Unknown";
			}
			}
		}

		std::ostream& operator<<(std::ostream& os, const Key& key)
		{
			os << ToString(key);
			return os;
		}
	}
}