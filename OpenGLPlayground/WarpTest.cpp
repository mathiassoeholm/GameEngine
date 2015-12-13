#include "WarpTest.h"
#include "ShaderUtil.h"

static const int pointsX = 10;
static const int pointsY = 8;

void WarpTest::initWarpTest()
{
	float vertices[pointsX * pointsY * 3];

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
		}
	}

	GLuint vbo = 0;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices)* sizeof(float), vertices, GL_STATIC_DRAW);

	_vao = 0;
	glGenVertexArrays(1, &_vao);
	glBindVertexArray(_vao);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

	_shaderProgram = ShaderUtil::createProgram("Shaders/VertexShader.vert", "Shaders/FragmentShader.frag");
}

void WarpTest::runWarpTest()
{
	glUseProgram(_shaderProgram);
	glBindVertexArray(_vao);
	glDrawArrays(GL_POINTS, 0, pointsX * pointsY);
}