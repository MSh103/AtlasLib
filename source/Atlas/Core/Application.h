#pragma once

#include "Core.h"
#include "Log.h"
#include "Atlas/Window/Window.h"
#include "Atlas/Layers/LayerStack.h"
#include "TimeStep.h"
#include "Atlas/Events/Event.h"
#include "Atlas/Events/WindowEvents.h"
#include "Atlas/ImGui/ImGuiLayer.h"

#include <memory>

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

		inline bool IsRunning() { return m_Running; }

		static Application& Get() { return *s_Instance; }

		inline const std::unique_ptr<Window>& GetWindow() { return m_Window; }

	private:
		bool OnCloseEvent(WindowCloseEvent& e);

	private:
		std::unique_ptr<Window> m_Window;
		LayerStack m_LayerStack;
		ImGuiLayer* m_ImGuiLayer;

		TimeStep m_Time;
		float m_LastFrame = 0.f;

		bool m_Running = true;
	private:
		static Application* s_Instance;
	};

	Application* CreateApplication();
}
