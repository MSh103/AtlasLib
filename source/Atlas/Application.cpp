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

		m_Window.SetEventCallback([this](Event& e) {
			OnEvent(e);
		});

		Log::Core::Trace("Hello, World from Application!");
	}

	Application::~Application()
	{
		s_Instance = nullptr;

		Log::Core::Trace("Shutting down...");
	}

	void Application::OnEvent(Event& e)
	{
		Log::Core::Trace("Event Fired: {}", e.ToString());
		if (e.GetEventType() == EventType::WindowClose)
			m_Running = false;
	}

	int Application::Run()
	{
		while (m_Running)
		{
			glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);


			m_Window.OnUpdate();
		}

		return 0;
	}

}