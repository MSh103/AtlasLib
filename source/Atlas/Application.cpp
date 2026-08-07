#include "Application.h"

#include <glad/glad.h>

namespace Atlas
{

	Application* Application::s_Instance = nullptr;

	Application::Application(const ApplicationSpecification& spec)
		: m_Window(spec.Window)
	{
		AT_ASSERT(s_Instance == nullptr, "Application already exists!");
		s_Instance = this;

		Log::Core::Trace("Hello, World from Application!");
	}

	Application::~Application()
	{
		s_Instance = nullptr;

		Log::Core::Trace("Shutting down...");
	}

	int Application::Run()
	{
		while (m_Running)
		{
			if (m_Window.ShouldClose())
				m_Running = false;

			glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);


			m_Window.OnUpdate();
		}

		return 0;
	}

}