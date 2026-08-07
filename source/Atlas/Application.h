#pragma once

#include "Core.h"
#include "Log.h"
#include "Window.h"

namespace Atlas
{
	struct ApplicationSpecification
	{
		WindowProps Window;
	};

	class Application
	{
	public:
		Application(const ApplicationSpecification& spec);
		~Application();

		void OnEvent(Event& e);

		int Run();

		static Application* Get() { return s_Instance; }

	private:
		bool OnCloseEvent(WindowCloseEvent& e);

	private:
		Window m_Window;

		//ApplicationSpecification m_Spec;

		bool m_Running = true;
	private:
		static Application* s_Instance;
	};

	Application* CreateApplication();
}
