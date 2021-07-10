#include "pch.h"

#include "HunterApp.h"
#include "OpenGLImplementation.h"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Hunter {
	OpenGLImplementation::OpenGLImplementation()
	{
		init();
	}
	void OpenGLImplementation::init()
	{
		mShaderDefault.Load(
			"../Hunter/assets/shaders/defaultVertexShader.glsl",
			"../Hunter/assets/shaders/defaultFragShader.glsl"
		);

		mShaderDefault.Use();

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}
	void OpenGLImplementation::shutdown()
	{

	}
	void OpenGLImplementation::draw(const Sprite& image, int xpos, int ypos, int width, int height)
	{
		float vertices[] = {
			(float)xpos				,(float)ypos,			0.0f, 0.0f,
			(float)xpos				,(float)(ypos+height),	0.0f, 1.0f,
			(float)(xpos + width)	,(float)ypos,			1.0f, 0.0f,
			(float)(xpos+width)		,(float)(ypos+height),	1.0f, 1.0f
		};

		unsigned int VBO, VAO;
		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);

		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
		glEnableVertexAttribArray(1);

		unsigned int picture;
		glGenTextures(1, &picture);
		glBindTexture(GL_TEXTURE_2D, picture);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image.GetImagePtr());

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		mShaderDefault.SetVec2Int("windowSize", HunterApp::GetWindowWidth(), HunterApp::GetWindowHeight());

		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	}
	void OpenGLImplementation::clearFrame()
	{
		glClearColor(0.0, 0.0, 0.0, 1.0);
		glClear(GL_COLOR_BUFFER_BIT);
	}
	OpenGLImplementation::~OpenGLImplementation()
	{

	}
}