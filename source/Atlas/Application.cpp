#include "Application.h"

namespace Atlas
{

	Application::Application(const WindowProps& props)
		: m_Window(props)
	{
		Log::Core::Trace("Hello, World from Application!");
	}

	Application::~Application()
	{
		Log::Core::Trace("Shutting down...");
	}

	int Application::Run()
	{
		while (m_Running)
		{
			if (m_Window.ShouldClose())
				m_Running = false;

			m_Window.OnUpdate();
		}

		return 0;
	}

}