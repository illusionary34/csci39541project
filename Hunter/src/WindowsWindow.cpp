#include "pch.h"
#include "..\include\WindowsWindow.h"
#include "KeyboardEvents.h"

namespace Hunter {
	bool WindowsWindow::CreateWindow(unsigned int width, unsigned int height)
	{
		glfwInit();
		window = glfwCreateWindow(width, height, "Hunter Window", NULL, NULL);

		if (window == nullptr)
			return false;

		glfwMakeContextCurrent(window);
		gladLoadGL();

		glfwSwapInterval(1);

		glfwSetWindowUserPointer(window, &mCallbacks);
		glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
			if (action == GLFW_PRESS || action == GLFW_REPEAT) {
				KeyPressedEvent event{ key };
				Callbacks* callbacks{ (Callbacks*)glfwGetWindowUserPointer(window) };
				callbacks->KeyPressedCallback(event);
			}
			});

		return true;
	}
	void WindowsWindow::DeleteWindow()
	{
		glfwDestroyWindow(window);
		glfwTerminate();
	}
	void WindowsWindow::SwapBuffers()
	{
		glfwSwapBuffers(window);
	}
	void WindowsWindow::PollEvents()
	{
		glfwPollEvents();
	}
	int WindowsWindow::GetWidth()
	{
		int width{ 0 }, height{0};
		glfwGetWindowSize(window, &width, &height);
		return width;
	}
	int WindowsWindow::GetHeight()
	{
		int width{ 0 }, height{ 0 };
		glfwGetWindowSize(window, &width, &height);
		return height;
	}
	void WindowsWindow::SetKeyPressedCallback(std::function<void(KeyPressedEvent&)> newCallback)
	{
		mCallbacks.KeyPressedCallback = newCallback;
	}
};