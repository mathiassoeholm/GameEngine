#include "WarpTest.h"
#include "../ShaderUtil.h"
#define STB_IMAGE_IMPLEMENTATION
#include "../stb_image.h"
#include <GLFW/glfw3.h>

static const int pointsX = 10;
static const int pointsY = 8;

void WarpTest::init(GLFWwindow* window, int screenWidth, int screenHeight)
{
	float vertices[pointsX * pointsY * 5];

	int index = 0;

	for (int y = 0; y < pointsY; y++)
	{
		for (int x = 0; x < pointsX; x++)
		{
			float xPos = static_cast<float>(x) / (pointsX-1);
			float yPos = static_cast<float>(y) / (pointsY - 1);

			// x, y, z
			vertices[index++] = (xPos - 0.5f) * 2;
			vertices[index++] = (yPos - 0.5f) * 2;
			vertices[index++] = 0;

			// tex coords
			vertices[index++] = xPos;
			vertices[index++] = 1-yPos;
		}
	}

	unsigned short indeces[(pointsX-1)*(pointsY-1)*6];
	index = 0;

	for (int y = 0; y < pointsY - 1; y++)
	{
		for (int x = 0; x < pointsX - 1; x++)
		{
			int i = pointsX*y + x;

			// Tri 1
			indeces[index++] = i;
			indeces[index++] = i + pointsX + 1;
			indeces[index++] = i + pointsX;

			// Tri 2
			indeces[index++] = i;
			indeces[index++] = i + 1;
			indeces[index++] = i + pointsX + 1;

			
		}
	}

	_shaderProgram = ShaderUtil::createProgram("Shaders/VertexShader.vert", "Shaders/FragmentShader.frag");
	_timeLocation = glGetUniformLocation(_shaderProgram, "time");

	GLuint vbo = 0;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	GLuint ibo;
	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indeces), indeces, GL_STATIC_DRAW);

	glGenVertexArrays(1, &_vao);
	glBindVertexArray(_vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5*sizeof(float), nullptr);
	

	GLint texAttrib = glGetAttribLocation(_shaderProgram, "texcoord");
	glEnableVertexAttribArray(texAttrib);

	glVertexAttribPointer(texAttrib, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), reinterpret_cast<void*>(3 * sizeof(float)));

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBindVertexArray(0);
	
	

	// -------------- Texture
	GLuint tex;
	glGenTextures(1, &tex);
	glBindTexture(GL_TEXTURE_2D, tex);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int x,y,n;
	unsigned char *data = stbi_load("Images/gaben.jpg", &x, &y, &n, 0);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, x, y, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	
}

void WarpTest::run(GLFWwindow* window)
{
	glUseProgram(_shaderProgram);

	if (_timeLocation != -1)
	{
		glUniform1f(_timeLocation, static_cast<float>(glfwGetTime()));
	}

	glBindVertexArray(_vao);
	glDrawElements(GL_TRIANGLES, (pointsX - 1)*(pointsY - 1) * 6, GL_UNSIGNED_SHORT, nullptr);
	glBindVertexArray(0);
}