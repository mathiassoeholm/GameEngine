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

	std::cout << std::endl;

	unsigned short indeces[(pointsX-1)*(pointsY-1)*6];
	index = 0;

	for (int y = 0; y < pointsY - 1; y++)
	{
		for (int x = 0; x < pointsX - 1; x++)
		{
			int i = pointsX*y + x;

			indeces[index++] = i;
			indeces[index++] = i + pointsX + 1;
			indeces[index++] = i + pointsX;

			indeces[index++] = i;
			indeces[index++] = i + 1;
			indeces[index++] = i + pointsX + 1;

			
		}
	}

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
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBindVertexArray(0);
	

	_shaderProgram = ShaderUtil::createProgram("Shaders/VertexShader.vert", "Shaders/FragmentShader.frag");
}

void WarpTest::runWarpTest()
{
	glUseProgram(_shaderProgram);
	glBindVertexArray(_vao);
	glDrawElements(GL_TRIANGLES, (pointsX - 1)*(pointsY - 1) * 6, GL_UNSIGNED_SHORT, nullptr);
	glBindVertexArray(0);
}