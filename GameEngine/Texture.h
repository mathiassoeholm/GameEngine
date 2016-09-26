#pragma once

#include <GL/glew.h>
#include <string>
#include <iostream>

namespace GameEngine
{
	class Texture
	{
		GLuint index;
	public:
		Texture(const std::string& path);
		void bind();
		~Texture(){
			std::cout << "Destroyed" << std::endl;
		}
	};
}
