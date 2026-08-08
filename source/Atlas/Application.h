#pragma once

#include "Core.h"
#include "Log.h"
#include "Window.h"
#include "LayerStack.h"

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

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		void PopLayer(Layer* layer);
		void PopOverlay(Layer* overlay);

		void OnEvent(Event& e);
		int Run();

		static Application* Get() { return s_Instance; }

	private:
		bool OnCloseEvent(WindowCloseEvent& e);

	private:
		Window m_Window;
		LayerStack m_LayerStack;

		//ApplicationSpecification m_Spec;

		bool m_Running = true;
	private:
		static Application* s_Instance;
	};

	Application* CreateApplication();
}
