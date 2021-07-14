#pragma once
#include "Window.h"
#include "HunterCentral.h"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Hunter {
	class HUNTER_API WindowsWindow : public Window
	{
	public:
		virtual bool CreateWindow(unsigned int width, unsigned int height) override;
		virtual void DeleteWindow() override;
		virtual void SwapBuffers() override;
		virtual void PollEvents() override;

		virtual int GetWidth() override;
		virtual int GetHeight() override;

		virtual void SetKeyPressedCallback(std::function<void(KeyPressedEvent&)> newCallback) override;
		virtual void SetKeyReleasedCallback(std::function<void(KeyReleasedEvent&)> newCallback) override;

	private:
		struct Callbacks {
			std::function<void(KeyPressedEvent&)> KeyPressedCallback;
			std::function<void(KeyReleasedEvent&)> KeyReleasedCallback;
		} mCallbacks;

		GLFWwindow* window;
	};
};