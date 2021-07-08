#pragma once
#include "HunterCentral.h"

namespace Hunter
{
	class HUNTER_API Window
	{
	public:
		virtual bool CreateWindow(unsigned int width, unsigned int height) = 0;
		virtual void DeleteWindow() = 0;
		virtual void SwapBuffers() = 0;
		virtual void PollEvents() = 0;
	};
};