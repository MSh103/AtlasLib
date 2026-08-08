#include "Input.h"

#include "Application.h"

#include <GLFW/glfw3.h>

namespace Atlas
{
	Input* Input::s_Instance;

	bool Input::IsKeyPressedImpl(Keyboard::Key key)
	{
		GLFWwindow* window = Application::Get().GetWindow()->GetNativeHandle();
		int state = glfwGetKey(window, (int)key);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool Input::IsMouseButtonPressedImpl(Mouse::Button button)
	{
		GLFWwindow* window = Application::Get().GetWindow()->GetNativeHandle();
		int state = glfwGetMouseButton(window, (int)button);
		return state == GLFW_PRESS;
	}

	std::pair<float, float> Input::GetMousePositionImpl()
	{
		GLFWwindow* window = Application::Get().GetWindow()->GetNativeHandle();
		double xPos, yPos;
		glfwGetCursorPos(window, &xPos, &yPos);
		return { (float)xPos, (float)yPos };
	}

}