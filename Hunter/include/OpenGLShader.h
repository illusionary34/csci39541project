#pragma once

#include "Shader.h"

namespace Hunter 
{
	class HUNTER_API OpenGLShader : public Shader {
	public:
		virtual bool Load(const std::string& vertexFile, const std::string& fragmentfile) override;
		virtual void Use() override;

		virtual void SetVec2Int(const std::string& uniformName, int val1, int val2) override;
		~OpenGLShader() override;

	private:
		unsigned int CompileVertexShader(const std::string& vertexCode);
		unsigned int CompileFragmentShader(const std::string& fragCode);

		unsigned int mShaderProgram{ 0 };
	};
}