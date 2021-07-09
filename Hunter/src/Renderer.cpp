#include "pch.h"

#include "Renderer.h"

namespace Hunter
{
	void Renderer::init()
	{
		if (instance == nullptr)
			instance = new Renderer;
	}
	void Renderer::draw(const Sprite& image, int x_pos, int y_pos, int width, int height)
	{
		assert(instance != nullptr);
		instance->mDrawingEngine->draw(image, x_pos, y_pos, width, height);
	}
	void Renderer::shutdown()
	{
		if (instance != nullptr)
			delete instance;
	}
	void Renderer::clearFrame()
	{
		instance->mDrawingEngine->clearFrame();
	}
	Renderer::Renderer()
	{
		mDrawingEngine = new OpenGLImplementation;
	}
}