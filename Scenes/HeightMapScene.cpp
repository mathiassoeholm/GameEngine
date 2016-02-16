#include "HeightMapScene.h"
#include "../stb_image.h"
#include "../ShaderUtil.h"

static const int SEGMENTS = 100;

HeightMapScene::HeightMapScene() : _camera{0, Vector3f(), Quaternionf()}
{

}

void HeightMapScene::init(GLFWwindow *window, int screenWidth, int screenHeight)
{
	_camera = Camera(window, Vector3f(), Quaternionf());
	GLfloat vertices[SEGMENTS * SEGMENTS * 3];

	int x,y,n;
	unsigned char *texData = stbi_load("Images/gaben.jpg", &x, &y, &n, 0);
	int index = 0;

	for (int z = 0; z < SEGMENTS; ++z)
	{
		for (int x = 0; x < SEGMENTS; ++x)
		{
			float xPos = static_cast<float>(x) / (SEGMENTS - 1);
			float zPos = static_cast<float>(z) / (SEGMENTS - 1);

			// Set position
			vertices[index++] = xPos;
			vertices[index++] = 0;
			vertices[index++] = zPos;
		}
	}

	GLushort indices[(SEGMENTS - 1) * (SEGMENTS - 1) * 6];
	index = 0;

	for (int z = 0; z < SEGMENTS - 1; z++)
	{
		for (int x = 0; x < SEGMENTS - 1; x++)
		{
			int i = SEGMENTS*z + x;

			// Tri 1
			indices[index++] = i;
			indices[index++] = i + SEGMENTS + 1;
			indices[index++] = i + SEGMENTS;

			// Tri 2
			indices[index++] = i;
			indices[index++] = i + 1;
			indices[index++] = i + SEGMENTS + 1;
		}
	}

	glUseProgram(ShaderUtil::createProgram("Shaders/BasicVertexShader.vert", "Shaders/BasicFragmentShader.frag"));

	GLuint vbo = 0;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	GLuint ibo;
	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glGenVertexArrays(1, &_vao);
	glBindVertexArray(_vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), nullptr);

	// Load image
	// Generate vertices
}

void HeightMapScene::run(GLFWwindow *window)
{
	glBindVertexArray(_vao);
	glDrawElements(GL_TRIANGLES, (SEGMENTS - 1)*(SEGMENTS - 1) * 6, GL_UNSIGNED_SHORT, nullptr);
	glBindVertexArray(0);
}


