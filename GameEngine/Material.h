#pragma once

#include <string>
#include <GL/glew.h>

namespace GameEngine
{
	class Material
	{
		GLuint shaderProgramIndex;
	public:
		Material(const std::string& vertexShaderSource, const std::string& fragmentShaderSource);
		void use() const;
	private:
		GLuint createShader(const std::string& source, GLenum shaderType);
	};
}