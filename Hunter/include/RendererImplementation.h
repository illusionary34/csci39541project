#pragma once

#include "Sprite.h"

namespace Hunter {
	class RendererImplementation
	{
	public:
		virtual void init() = 0;
		virtual void shutdown() = 0;
		virtual void draw(const Sprite& image, int xpos, int ypos, int width, int height) = 0;
		virtual ~RendererImplementation() = 0 {};
	};
}