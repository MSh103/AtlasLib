#include "Window.h"

#include <GLFW/glfw3.h>

#include "Log.h"

namespace Atlas
{
	void errorCallback(int error, const char* desc)
	{
		Log::Core::Error("GLFW error {}: {}", error, desc);
	}

	Window::Window(const WindowProps& props)
		: m_Props(props)
	{
		glfwSetErrorCallback(errorCallback);
		if (!glfwInit())
		{
			AT_ASSERT(false, "Failed to initialize GLFW!");
			Log::Core::Error("Failed to initialize GLFW!");
			return;
		}
		Log::Core::Trace("Initialized GLFW!");

		m_Window = glfwCreateWindow(props.Width, props.Height, props.Title.c_str(), nullptr, nullptr);
		if (!m_Window)
		{
			AT_ASSERT(false, "Failed to create Window!");
			Log::Core::Error("Failed to create Window!");
			glfwTerminate();
			return;
		}

		Log::Core::Trace("Created Window {}: {}x{}", props.Title, props.Width, props.Height);

		glfwMakeContextCurrent(m_Window);

	}

	Window::~Window()
	{
		Log::Core::Trace("Terminating GLFW...");
		glfwTerminate();
	}

	void Window::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	bool Window::ShouldClose() const
	{
		return static_cast<bool>(glfwWindowShouldClose(m_Window));
	}

	void Window::Close()
	{
		glfwWindowShouldClose(m_Window);
	}

	float Window::GetTime()
	{
		return static_cast<float>(glfwGetTime());
	}

}
