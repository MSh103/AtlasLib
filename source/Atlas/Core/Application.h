#pragma once

#include "Core.h"
#include "Log.h"
#include "Atlas/Window/Window.h"
#include "Atlas/Layers/LayerStack.h"
#include "TimeStep.h"

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

		TimeStep m_Time;
		float m_LastFrame = 0.f;

		bool m_Running = true;
	private:
		static Application* s_Instance;
	};

	Application* CreateApplication();
}
