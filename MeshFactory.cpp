#include <string.h>
#include "MeshFactory.h"

Mesh MeshFactory::createTriangle()
{
	Mesh tri;
	tri.numVertices = 3;

	Vertex vertices[] =
	{
		glm::vec3(0.0f, 0.5f, 0.0f), // Position
		glm::vec3(0.0f, 0.0f, 1.0f), // Normal
		glm::vec3(5.0f, 5.0f, 5.0f), // Color

		glm::vec3(0.5f, -0.5f, 0.0f),
		glm::vec3(0.0f, 0.0f, 1.0f),
		glm::vec3(5.0f, 5.0f, 5.0f),

		glm::vec3(-0.5f, -0.5f, 0.0f),
		glm::vec3(0.0f, 0.0f, 1.0f),
		glm::vec3(5.0f, 5.0f, 5.0f)
	};
	tri.vertices = new Vertex[tri.numVertices];
	memcpy(tri.vertices, vertices, sizeof(vertices));

	tri.numIndices = 3;

	GLushort indices[] =
	{
		0, 1, 2
	};
	tri.indices = new GLushort[tri.numIndices];
	memcpy(tri.indices, indices, sizeof(indices));

	return tri;
}

Mesh MeshFactory::createCube()
{
	Mesh cube;
	cube.numVertices = 24;

	Vertex vertices[] =
	{
			// FRONT
			glm::vec3(-0.5f, -0.5f, 0.5f), // Position
			glm::vec3(0.0f, 0.0f, 1.0f), // Normal
			glm::vec3(5.0f, 5.0f, 5.0f), // Color

			glm::vec3(-0.5f, 0.5f, 0.5f),
			glm::vec3(0.0f, 0.0f, 1.0f),
			glm::vec3(5.0f, 5.0f, 5.0f),

			glm::vec3(0.5f, 0.5f, 0.5f),
			glm::vec3(0.0f, 0.0f, 1.0f),
			glm::vec3(5.0f, 5.0f, 5.0f),

			glm::vec3(0.5f, -0.5f, 0.5f),
			glm::vec3(0.0f, 0.0f, 1.0f),
			glm::vec3(5.0f, 5.0f, 5.0f),

			// BACK
			glm::vec3(-0.5f, -0.5f, -0.5f),
			glm::vec3(0.0f, 0.0f, -1.0f),
			glm::vec3(5.0f, 5.0f, 5.0f),

			glm::vec3(-0.5f, 0.5f, -0.5f),
			glm::vec3(0.0f, 0.0f, -1.0f),
			glm::vec3(5.0f, 5.0f, 5.0f),

			glm::vec3(0.5f, 0.5f, -0.5f),
			glm::vec3(0.0f, 0.0f, -1.0f),
			glm::vec3(5.0f, 5.0f, 5.0f),

			glm::vec3(0.5f, -0.5f, -0.5f),
			glm::vec3(0.0f, 0.0f, -1.0f),
			glm::vec3(5.0f, 5.0f, 5.0f),

			// BOTTOM
			glm::vec3(-0.5f, -0.5f, 0.5f),
			glm::vec3(0.0f, -1.0f, 0.0f),
			glm::vec3(5.0f, 5.0f, 5.0f),

			glm::vec3(-0.5f, -0.5f, -0.5f),
			glm::vec3(0.0f, -1.0f, 0.0f),
			glm::vec3(5.0f, 5.0f, 5.0f),

			glm::vec3(0.5f, -0.5f, -0.5f),
			glm::vec3(0.0f, -1.0f, 0.0f),
			glm::vec3(5.0f, 5.0f, 5.0f),

			glm::vec3(0.5f, -0.5f, 0.5f),
			glm::vec3(0.0f, -1.0f, 0.0f),
			glm::vec3(5.0f, 5.0f, 5.0f),

			// TOP
			glm::vec3(-0.5f, 0.5f, 0.5f),
			glm::vec3(0.0f, 1.0f, 0.0f),
			glm::vec3(5.0f, 5.0f, 5.0f),

			glm::vec3(-0.5f, 0.5f, -0.5f),
			glm::vec3(0.0f, 1.0f, 0.0f),
			glm::vec3(5.0f, 5.0f, 5.0f),

			glm::vec3(0.5f, 0.5f, -0.5f),
			glm::vec3(0.0f, 1.0f, 0.0f),
			glm::vec3(5.0f, 5.0f, 5.0f),

			glm::vec3(0.5f, 0.5f, 0.5f),
			glm::vec3(0.0f, 1.0f, 0.0f),
			glm::vec3(5.0f, 5.0f, 5.0f),

			// LEFT
			glm::vec3(-0.5f, 0.5f, 0.5f),
			glm::vec3(-1.0f, 0.0f, 0.0f),
			glm::vec3(5.0f, 5.0f, 5.0f),

			glm::vec3(-0.5f, 0.5f, -0.5f),
			glm::vec3(-1.0f, 0.0f, 0.0f),
			glm::vec3(5.0f, 5.0f, 5.0f),

			glm::vec3(-0.5f, -0.5f, -0.5f),
			glm::vec3(-1.0f, 0.0f, 0.0f),
			glm::vec3(5.0f, 5.0f, 5.0f),

			glm::vec3(-0.5f, -0.5f, 0.5f),
			glm::vec3(-1.0f, 0.0f, 0.0f),
			glm::vec3(5.0f, 5.0f, 5.0f),

			// RIGHT
			glm::vec3(0.5f, 0.5f, 0.5f),
			glm::vec3(1.0f, 0.0f, 0.0f),
			glm::vec3(5.0f, 5.0f, 5.0f),

			glm::vec3(0.5f, 0.5f, -0.5f),
			glm::vec3(1.0f, 0.0f, 0.0f),
			glm::vec3(5.0f, 5.0f, 5.0f),

			glm::vec3(0.5f, -0.5f, -0.5f),
			glm::vec3(1.0f, 0.0f, 0.0f),
			glm::vec3(5.0f, 5.0f, 5.0f),

			glm::vec3(0.5f, -0.5f, 0.5f),
			glm::vec3(1.0f, 0.0f, 0.0f),
			glm::vec3(5.0f, 5.0f, 5.0f)
	};
	cube.vertices = new Vertex[cube.numVertices];
	memcpy(cube.vertices, vertices, sizeof(vertices));

	cube.numIndices = 36;

	GLushort indices[] =
	{
			0, 1, 2,		2, 3, 0, // Front
			4, 5, 6,		6, 7, 4, // Back
			8, 9, 10,		10, 11, 8, // Bottom
			12, 13, 14,		14, 15, 12, // Top
			16, 17, 18,		18, 19, 16, // Left
			20, 21, 22,		22, 23, 20 // Right
	};
	cube.indices = new GLushort[cube.numIndices];
	memcpy(cube.indices, indices, sizeof(indices));

	return cube;
}