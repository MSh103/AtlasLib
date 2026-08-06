#pragma once

#include "Core.h"

#include <string>
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

		bool ShouldClose() const;

		void Close();

		float GetTime();

	private:
		GLFWwindow* m_Window = nullptr;
		
		WindowProps m_Props;
	};
}
