#include "Texture.h"

namespace GameEngine
{
	Texture::Texture()
	{
		glGenTextures(1, &index);
		glBindTexture(GL_TEXTURE_2D, index);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_NEAREST);

		// Black/white checkerboard
		float pixels[] = {
				0.0f, 0.0f, 0.0f,   1.0f, 1.0f, 1.0f,
				1.0f, 1.0f, 1.0f,   0.0f, 0.0f, 0.0f
		};
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 2, 2, 0, GL_RGB, GL_FLOAT, pixels);

		glGenerateMipmap(GL_TEXTURE_2D);
	}
}
