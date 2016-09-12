#pragma once

#include <GL/glew.h>
#include <string>

namespace GameEngine
{
	class Texture
	{
		GLuint index;
	public:
		Texture(const std::string& path);
		void bind();
	};
}
