#include "Window.h"

#include <GLFW/glfw3.h>

namespace Atlas
{

	Window::Window(const WindowProps& props)
		: m_Props(props)
	{
		if (!glfwInit())
		{
			AT_ASSERT(false, "Failed to initliaze GLFW!");
			return;
		}

		m_Window = glfwCreateWindow(props.Width, props.Height, props.Title.c_str(), nullptr, nullptr);
		if (!m_Window)
		{
			AT_ASSERT(false, "Failed to create Window!");
			glfwTerminate();
			return;
		}

		glfwMakeContextCurrent(m_Window);

	}

	Window::~Window()
	{
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
