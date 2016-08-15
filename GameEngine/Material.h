#pragma once

#include <string>
#include <GL/glew.h>
#include <unordered_map>
#include "glm/ext.hpp"

namespace GameEngine
{
	class Material
	{
		GLuint shaderProgramIndex;
		std::unordered_map<std::string, GLint> uniformLocationCache;
		GLuint references;
	public:
		Material(const std::string& vertexShaderSource, const std::string& fragmentShaderSource);
		void use() const;
		void setUniform(const std::string& name, const glm::mat4& matrix);
		void incrementRefCount();
		void decrementRefCount();
	private:
		GLuint createShader(const std::string& source, GLenum shaderType);
	};
}