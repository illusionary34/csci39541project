#include "pch.h"
#include "OpenGLShader.h"
#include <cassert>
#include <sstream>
#include <fstream>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Hunter {
	bool OpenGLShader::Load(const std::string& vertexFile, const std::string& fragmentfile)
	{
		std::ifstream vertexSrc(vertexFile);
		std::ifstream fragSrc(fragmentfile);

		std::stringstream vShaderStream, fShaderStream;
		vShaderStream << vertexSrc.rdbuf();
		fShaderStream << fragSrc.rdbuf();

		vertexSrc.close();
		fragSrc.close();

		unsigned int vShader{ CompileVertexShader(vShaderStream.str()) };
		if (!vShader) {
			glDeleteShader(vShader);
			return false;
		}
		unsigned int fShader{ CompileFragmentShader(fShaderStream.str()) };
		if (!fShader) {
			glDeleteShader(fShader);
			return false;
		}

		if (mShaderProgram)
			glDeleteProgram(mShaderProgram);
		mShaderProgram = glCreateProgram();
		glAttachShader(mShaderProgram, vShader);
		glAttachShader(mShaderProgram, fShader);
		glLinkProgram(mShaderProgram);

		int success{ 0 };
		glGetProgramiv(mShaderProgram, GL_LINK_STATUS, &success);
		if (!success) {
			char infolog[512];
			glGetProgramInfoLog(mShaderProgram, 512, NULL, infolog);
			HLOG("ERROR LINKING SHADER PROGRAM");
			HLOG(infolog);

			glDeleteShader(vShader);
			glDeleteShader(fShader);
			return false;
		}

		glDeleteShader(vShader);
		glDeleteShader(fShader);
		return true;
	}

	void OpenGLShader::Use()
	{
		assert(mShaderProgram);

		glUseProgram(mShaderProgram);
	}

	void OpenGLShader::SetVec2Int(const std::string& uniformName, int val1, int val2)
	{
		assert(mShaderProgram);

		int uniformID{ glGetUniformLocation(mShaderProgram, uniformName.c_str()) };
		glUniform2i(uniformID, val1, val2);
	}

	OpenGLShader::~OpenGLShader()
	{
		if (mShaderProgram)
			glDeleteProgram(mShaderProgram);
	}

	unsigned int OpenGLShader::CompileVertexShader(const std::string& vertexCode)
	{
		unsigned int vShader;
		vShader = glCreateShader(GL_VERTEX_SHADER);

		const char* cstring = vertexCode.c_str();
		glShaderSource(vShader, 1, &cstring, 0);
		glCompileShader(vShader);

		int success{ 0 };
		glGetShaderiv(vShader, GL_COMPILE_STATUS, &success);
		if (!success) {
			char infoLog[512];
			glGetShaderInfoLog(vShader, 512, NULL, infoLog);
			HLOG("ERROR COMPILING VERTEX SHADER:")
				HLOG(infoLog)
		}
		return vShader;
	}

	unsigned int OpenGLShader::CompileFragmentShader(const std::string& fragCode)
	{
		unsigned int fShader;
		fShader = glCreateShader(GL_FRAGMENT_SHADER);

		const char* cstring = fragCode.c_str();
		glShaderSource(fShader, 1, &cstring, 0);
		glCompileShader(fShader);

		int success{ 0 };
		glGetShaderiv(fShader, GL_COMPILE_STATUS, &success);
		if (!success) {
			char infoLog[512];
			glGetShaderInfoLog(fShader, 512, NULL, infoLog);
			HLOG("ERROR COMPILING FRAGMENT SHADER:")
				HLOG(infoLog)
		}
		return fShader;
	}

}