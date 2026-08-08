#pragma once

#include "Atlas/Core/Core.h"
#include "Atlas/Events/Event.h"

#include <string>
#include <functional>
struct GLFWwindow;

namespace Atlas
{
	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Atlas", unsigned int width = 1920, unsigned int height = 1080)
			: Title(title), Width(width), Height(height)
		{}
	};

	using EventCallbackFn = std::function<void(Event&)>;

	class Window
	{
	public:
		Window(const WindowProps& props);
		~Window();

		void OnUpdate();

		//unsigned int GetWidth();
		//unsigned int GetHeight();

		//void SetVSync(const bool& s);
		//bool IsVSync();

		inline void SetEventCallback(const EventCallbackFn& cb) { m_WindowData.EventCallback = cb; }

		bool ShouldClose() const;
		void Close();
		float GetTime();

	private:
		void OnResize(int width, int height);
	private:
		GLFWwindow* m_Window = nullptr;
		
		struct WindowData
		{
			WindowProps Props;
			EventCallbackFn EventCallback;
		} m_WindowData;
	};
}
