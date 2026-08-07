#include "Application.h"

#include <glad/glad.h>

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
			glClear(GL_COLOR_BUFFER_BIT);
			glClearColor(0.3f, 0.3f, 0.3f, 1.0f);


		}

		return 0;
	}

}