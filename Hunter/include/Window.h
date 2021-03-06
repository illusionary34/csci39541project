#pragma once
#include "HunterCentral.h"
#include "KeyboardEvents.h"

namespace Hunter
{
	class HUNTER_API Window
	{
	public:
		virtual bool CreateWindow(unsigned int width, unsigned int height) = 0;
		virtual void DeleteWindow() = 0;
		virtual void SwapBuffers() = 0;
		virtual void PollEvents() = 0;

		virtual int GetWidth() = 0;
		virtual int GetHeight() = 0;

		virtual void SetKeyPressedCallback(std::function<void(KeyPressedEvent&)> newCallback) = 0;
		virtual void SetKeyReleasedCallback(std::function<void(KeyReleasedEvent&)> newCallback) = 0;
	};
};