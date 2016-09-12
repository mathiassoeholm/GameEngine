#include "Texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include "../stb_image.h"
#include <iostream>

namespace GameEngine
{
	Texture::Texture(const std::string& path)
	{
		int x,y,n;
		stbi_set_flip_vertically_on_load(true);
		unsigned char *data = stbi_load(path.c_str(), &x, &y, &n, 0);
		// NPOT Check
		if((x & (x-1)) != 0 || (y & (y - 1)) != 0)
		{
			std::cout << "WARNING: texture is not power-of-2 dimensions" << std::endl;
		}

		glGenTextures(1, &index);
		glBindTexture(GL_TEXTURE_2D, index);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_NEAREST);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, x, y, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

		glGenerateMipmap(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	void Texture::bind()
	{
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, index);
	}
}
