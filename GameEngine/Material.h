#pragma once

#include <string>
#include <GL/glew.h>
#include <unordered_map>
#include <memory>
#include "glm/ext.hpp"
#include "Texture.h"

namespace GameEngine
{
	class Material
	{
		GLuint shaderProgramIndex;
		std::unordered_map<std::string, GLint> uniformLocationCache;
		std::shared_ptr<Texture> texture;
	public:
		Material(const std::string& vertexShaderSource, const std::string& fragmentShaderSource);
		void use() const;
		void assignTexture(std::shared_ptr<Texture> texture);
		void setUniform(const std::string& name, const GLint integer);
		void setUniform(const std::string& name, const glm::mat4& matrix);
		void setUniform(const std::string& name, const glm::mat3& matrix);
		void setUniform(const std::string& name, const GLint dataLength, const GLfloat* data);
		~Material();
	private:
		GLuint createShader(const std::string& source, GLenum shaderType);
		GLint getUniformLocation(const std::string& name);
	};
}