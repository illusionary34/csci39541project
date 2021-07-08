#include "pch.h"
#include "..\include\WindowsWindow.h"

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
};