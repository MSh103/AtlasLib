#include "Window.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Log.h"

namespace Atlas
{

	Window::Window(const WindowProps& props)
	{
		m_WindowData.Props = props;
		glfwSetErrorCallback([](int error, const char* desc) {
			Log::Core::Error("GLFW error {}: {}", error, desc);
		});
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

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			AT_ASSERT(false, "Failed to load Glad!");
			Log::Core::Error("Failed to load Glad!");
			return;
		}

		Log::Core::Trace("OpenGL Info:");
		Log::Core::Trace("\tVendor:\t\t{}", reinterpret_cast<const char*>(glGetString(GL_VENDOR)));
		Log::Core::Trace("\tRenderer:\t{}", reinterpret_cast<const char*>(glGetString(GL_RENDERER)));
		Log::Core::Trace("\tVersion:\t{}", reinterpret_cast<const char*>(glGetString(GL_VERSION)));

		glfwSetWindowUserPointer(m_Window, this);

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window) {
			auto* self = static_cast<Window*>(glfwGetWindowUserPointer(window));
			WindowData& data = self->m_WindowData;
			WindowCloseEvent e;
			data.EventCallback(e);
		});

		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height) {
			auto* self = static_cast<Window*>(glfwGetWindowUserPointer(window));
			WindowData& data = self->m_WindowData;
			data.Props.Width = width;
			data.Props.Height = height;
			WindowResizeEvent e(width, height);
			data.EventCallback(e);
			self->OnResize(width, height);
		});

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
		glfwSetWindowShouldClose(m_Window, GLFW_TRUE);
	}

	float Window::GetTime()
	{
		return static_cast<float>(glfwGetTime());
	}

	void Window::OnResize(int width, int height)
	{
		glViewport(0, 0, width, height);
	}

}
