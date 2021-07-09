#pragma once

#include "RendererImplementation.h"
#include "OpenGLShader.h"

namespace Hunter
{
	class OpenGLImplementation : public RendererImplementation
	{
	public:
		OpenGLImplementation();
		virtual void init() override;
		virtual void shutdown() override;
		virtual void draw(const Sprite& image, int xpos, int ypos, int width, int height) override;
		virtual ~OpenGLImplementation() override;

	private:
		OpenGLShader mShaderDefault;
	};
}