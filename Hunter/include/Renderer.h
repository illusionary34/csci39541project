#pragma once

#include "Sprite.h"
#include "RendererImplementation.h"
#include "OpenGLImplementation.h"

namespace Hunter {
	class Renderer
	{
	public:
		static void init();
		static void draw(const Sprite& image, int x_pos, int y_pos, int width, int height);
		static void shutdown();

	private:
		Renderer();

		inline static Renderer* instance{ nullptr };
		RendererImplementation* mDrawingEngine{ nullptr };
	};
}