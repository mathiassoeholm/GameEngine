#include <iostream>
#include <vector>
#include "Material.h"

namespace GameEngine
{
	void Material::use() const
	{
		glUseProgram(shaderProgramIndex);

		if(texture != nullptr)
		{
			texture->bind();
		}
	}

	Material::Material(const std::string &vertexShaderSource, const std::string &fragmentShaderSource) :
		uniformLocationCache(std::unordered_map<std::string, GLint>()),
		texture(nullptr)
	{
		GLuint vertexIndex = createShader(vertexShaderSource, GL_VERTEX_SHADER);
		GLuint fragmentIndex = createShader(fragmentShaderSource, GL_FRAGMENT_SHADER);

		shaderProgramIndex = glCreateProgram();

		if(shaderProgramIndex == 0)
		{
			std::cerr << "ERROR: Could not create shader program" << std::endl;
		}

		glAttachShader(shaderProgramIndex, vertexIndex);
		glAttachShader(shaderProgramIndex, fragmentIndex);
		glLinkProgram(shaderProgramIndex);

		int linkStatus = -1;
		glGetProgramiv(shaderProgramIndex, GL_LINK_STATUS, &linkStatus);

		if (linkStatus == GL_FALSE)
		{
			std::cerr << "ERROR: Could not link shader GL index " << shaderProgramIndex << std::endl;
		}

		// We don't need these anymore
		glDeleteShader(vertexIndex);
		glDeleteShader(fragmentIndex);
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

			GLint maxLength = 0;
			glGetShaderiv(shaderIndex, GL_INFO_LOG_LENGTH, &maxLength);

			GLchar* log_string = new char[maxLength + 1];
			glGetShaderInfoLog(shaderIndex, maxLength, 0, log_string);

			std::cerr << log_string << std::endl;

			delete log_string;
		}

		return shaderIndex;
	}

	void Material::setUniform(const std::string &name, const GLint integer)
	{
		GLint location = getUniformLocation(name);

		if(location != -1)
		{
			glUniform1i(location, integer);
		}
	}

	void Material::setUniform(const std::string &name, const glm::mat4 &matrix)
	{
		GLint location = getUniformLocation(name);

		if(location != -1)
		{
			glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
		}
	}

	void Material::setUniform(const std::string &name, const glm::mat3 &matrix)
	{
		GLint location = getUniformLocation(name);

		if(location != -1)
		{
			glUniformMatrix3fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
		}
	}

	void Material::setUniform(const std::string &name, const GLint dataLength, const GLfloat* data)
	{
		GLint location = getUniformLocation(name);

		if(location != -1)
		{
			glUniform3fv(location, dataLength, data);
		}
	}

	void Material::assignTexture(std::shared_ptr<Texture> texture)
	{
		std::cout << texture.use_count() << std::endl;
		this->texture = texture;
	}

	GLint Material::getUniformLocation(const std::string &name)
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

		return location;
	}

	Material::~Material()
	{
		texture.reset();
		glDeleteProgram(shaderProgramIndex);
	}
}
