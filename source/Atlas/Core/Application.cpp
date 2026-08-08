#include "Application.h"

#include <glfw/glfw3.h>

namespace Atlas
{

	Application* Application::s_Instance = nullptr;

	Application::Application(const ApplicationSpecification& spec)
	{
		AT_ASSERT(s_Instance == nullptr, "Application already exists!");
		s_Instance = this;

		m_Window = std::make_unique<Window>(spec.Window);
		m_Window->SetEventCallback(AT_BIND_EVENT_FN(Application::OnEvent));
		m_ImGuiLayer = new ImGuiLayer();
		PushOverlay(m_ImGuiLayer);

		Log::Core::Trace("Hello, World from Application!");
	}

	Application::~Application()
	{
		Log::Core::Trace("Shutting down...");
		s_Instance = nullptr;
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		Atlas::Log::Core::Trace("Pushing {} into LayerStack", layer->GetName());
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushOverlay(overlay);
		Atlas::Log::Core::Trace("Pushing {} into LayerStack", overlay->GetName());
		overlay->OnAttach();
	}

	void Application::PopLayer(Layer* layer)
	{
		Atlas::Log::Core::Trace("Popping {} from LayerStack", layer->GetName());
		layer->OnDetach();
		m_LayerStack.PopLayer(layer);
	}

	void Application::PopOverlay(Layer* overlay)
	{
		Atlas::Log::Core::Trace("Popping {} from LayerStack", overlay->GetName());
		overlay->OnDetach();
		m_LayerStack.PopOverlay(overlay);
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(AT_BIND_EVENT_FN(Application::OnCloseEvent));

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
		{
			(*--it)->OnEvent(e);
			if (e.Handled())
				break;
		}
	}

	bool Application::OnCloseEvent(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

	int Application::Run()
	{
		while (m_Running)
		{
			float currentFrame = static_cast<float>(glfwGetTime());
			m_Time = currentFrame - m_LastFrame;
			m_LastFrame = currentFrame;


			for (Layer* layer : m_LayerStack)
				layer->OnUpdate(m_Time);

			for (Layer* layer : m_LayerStack)
				layer->OnRender();

			m_ImGuiLayer->Begin();
			for (Layer* layer : m_LayerStack)
				layer->OnImGuiRender();
			m_ImGuiLayer->End();

			m_Window->OnUpdate();
		}

		return 0;
	}

}