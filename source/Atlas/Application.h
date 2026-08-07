#pragma once

#include "Core.h"
#include "Log.h"
#include "Window.h"

namespace Atlas
{

	class Application
	{
	public:
		Application(const WindowProps& props);
		~Application();

		int Run();
	private:
		Window m_Window;

		bool m_Running = true;
	};
}
