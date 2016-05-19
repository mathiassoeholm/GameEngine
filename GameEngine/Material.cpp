#include <iostream>
#include "Material.h"

namespace GameEngine
{
	void Material::use() const
	{
		glUseProgram(shaderProgramIndex);
	}

	Material::Material(const std::string &vertexShaderSource, const std::string &fragmentShaderSource) :
		uniformLocationCache(std::unordered_map<std::string, GLint>())
	{
		GLuint vertexIndex = createShader(vertexShaderSource, GL_VERTEX_SHADER);
		GLuint fragmentIndex = createShader(fragmentShaderSource, GL_FRAGMENT_SHADER);

		shaderProgramIndex = glCreateProgram();
		glAttachShader(shaderProgramIndex, vertexIndex);
		glAttachShader(shaderProgramIndex, fragmentIndex);
		glLinkProgram(shaderProgramIndex);

		int linkStatus = -1;
		glGetProgramiv(shaderProgramIndex, GL_LINK_STATUS, &linkStatus);

		if (linkStatus != GL_TRUE)
		{
			std::cerr << "ERROR: Could not link shader GL index " << shaderProgramIndex << std::endl;
		}
	}

	GLuint Material::createShader(const std::string &source, GLenum shaderType)
	{
		GLuint shaderIndex = glCreateShader(shaderType);

		const char* adapter = source.c_str();
		glShaderSource(shaderIndex, 1, &adapter, nullptr);

		glCompileShader(shaderIndex);

		GLint compileStatus = -1;
		glGetShaderiv(shaderIndex, GL_COMPILE_STATUS, &compileStatus);

		if (compileStatus != GL_TRUE)
		{
			std::cerr << "ERROR: GL shader index " << shaderIndex << " did not compile" << std::endl;
		}

		return shaderIndex;
	}

	void Material::setUniform(const std::string &name, const glm::mat4 &matrix)
	{
		GLint location;
		auto locationPtr = uniformLocationCache.find(name);

		if(locationPtr == uniformLocationCache.end())
		{
			location = glGetUniformLocation(shaderProgramIndex, name.c_str());
			uniformLocationCache[name] = location;
		}
		else
		{
			location = locationPtr->second;
		}

		if(location != -1)
		{
			glUniformMatrix4fv(location, 1, GL_TRUE, glm::value_ptr(matrix));
		}
	}
}
