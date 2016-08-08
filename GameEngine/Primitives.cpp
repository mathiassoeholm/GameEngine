#include <string.h>
#include "Primitives.h"

namespace GameEngine
{
	static const size_t VERTS_PER_TRIANGLE = 3;
	static const size_t INDICES_PER_TRIANGLE = 3;
	static const size_t VERTS_PER_QUAD = 4;
	static const size_t INDICES_PER_QUAD = INDICES_PER_TRIANGLE * 2;
	static const size_t VERTS_PER_CUBE = 6 * VERTS_PER_QUAD; // A cube has 6 sides
	static const size_t INDICES_PER_CUBE = 6 * INDICES_PER_QUAD; // A cube has 6 sides

	Mesh Primitives::createTriangle()
	{
		Mesh tri;
		tri.numVertices = VERTS_PER_TRIANGLE;

		Vertex vertices[] =
		{
				glm::vec3(0.0f, 0.5f, 0.0f), // Position
				glm::vec3(0.0f, 0.0f, 1.0f), // Normal
				glm::vec3(1.0f, 1.0f, 1.0f), // Color

				glm::vec3(0.5f, -0.5f, 0.0f),
				glm::vec3(0.0f, 0.0f, 1.0f),
				glm::vec3(1.0f, 1.0f, 1.0f),

				glm::vec3(-0.5f, -0.5f, 0.0f),
				glm::vec3(0.0f, 0.0f, 1.0f),
				glm::vec3(1.0f, 1.0f, 1.0f)
		};

		tri.vertices = new Vertex[tri.numVertices];
		memcpy(tri.vertices, vertices, sizeof(vertices));

		tri.numIndices = INDICES_PER_TRIANGLE;

		GLushort indices[] =
		{
			0, 1, 2
		};

		tri.indices = new GLushort[tri.numIndices];
		memcpy(tri.indices, indices, sizeof(indices));

		tri.sendToBuffer();

		return tri;
	}

	Mesh Primitives::createQuad()
	{
		Mesh quad;
		quad.numVertices = VERTS_PER_QUAD;

		Vertex vertices[] =
		{
				glm::vec3(-0.5f, 0.5f, 0.0f), // Position
				glm::vec3(0.0f, 0.0f, 1.0f), // Normal
				glm::vec3(1.0f, 1.0f, 1.0f), // Color

				glm::vec3(0.5f, 0.5f, 0.0f),
				glm::vec3(0.0f, 0.0f, 1.0f),
				glm::vec3(1.0f, 1.0f, 1.0f),

				glm::vec3(0.5f, -0.5f, 0.0f),
				glm::vec3(0.0f, 0.0f, 1.0f),
				glm::vec3(1.0f, 1.0f, 1.0f),

				glm::vec3(-0.5f, -0.5f, 0.0f),
				glm::vec3(0.0f, 0.0f, 1.0f),
				glm::vec3(1.0f, 1.0f, 1.0f),
		};

		quad.vertices = new Vertex[quad.numVertices];
		memcpy(quad.vertices, vertices, sizeof(vertices));

		quad.numIndices = INDICES_PER_QUAD;

		GLushort indices[] =
		{
				0, 1, 3,
				1, 2, 3
		};

		quad.indices = new GLushort[quad.numIndices];
		memcpy(quad.indices, indices, sizeof(indices));

		quad.sendToBuffer();

		return quad;
	}

	Mesh Primitives::createCube()
	{
		Mesh cube;
		cube.numVertices = VERTS_PER_CUBE;

		Vertex vertices[] =
		{
				// Front
				glm::vec3(-0.5f, 0.5f, 0.0f), // Position
				glm::vec3(0.0f, 0.0f, 1.0f), // Normal
				glm::vec3(1.0f, 1.0f, 1.0f), // Color

				glm::vec3(0.5f, 0.5f, 0.0f),
				glm::vec3(0.0f, 0.0f, 1.0f),
				glm::vec3(1.0f, 1.0f, 1.0f),

				glm::vec3(0.5f, -0.5f, 0.0f),
				glm::vec3(0.0f, 0.0f, 1.0f),
				glm::vec3(1.0f, 1.0f, 1.0f),

				glm::vec3(-0.5f, -0.5f, 0.0f),
				glm::vec3(0.0f, 0.0f, 1.0f),
				glm::vec3(1.0f, 1.0f, 1.0f),

				// Back
				glm::vec3(-0.5f, 0.5f, 1.0f),
				glm::vec3(0.0f, 0.0f, 1.0f),
				glm::vec3(1.0f, 1.0f, 1.0f),

				glm::vec3(0.5f, 0.5f, 1.0f),
				glm::vec3(0.0f, 0.0f, 1.0f),
				glm::vec3(1.0f, 1.0f, 1.0f),

				glm::vec3(0.5f, -0.5f, 1.0f),
				glm::vec3(0.0f, 0.0f, 1.0f),
				glm::vec3(1.0f, 1.0f, 1.0f),

				glm::vec3(-0.5f, -0.5f, 1.0f),
				glm::vec3(0.0f, 0.0f, 1.0f),
				glm::vec3(1.0f, 1.0f, 1.0f),

				// Bottom
				glm::vec3(-0.5f, -0.5f, 1.0f),
				glm::vec3(0.0f, 0.0f, 1.0f),
				glm::vec3(1.0f, 1.0f, 1.0f),

				glm::vec3(0.5f, -0.5f, 0.0f),
				glm::vec3(0.0f, 0.0f, 1.0f),
				glm::vec3(1.0f, 1.0f, 1.0f),

				glm::vec3(0.5f, -0.5f, 0.0f),
				glm::vec3(0.0f, 0.0f, 1.0f),
				glm::vec3(1.0f, 1.0f, 1.0f),

				glm::vec3(-0.5f, -0.5f, 0.0f),
				glm::vec3(0.0f, 0.0f, 1.0f),
				glm::vec3(1.0f, 1.0f, 1.0f),

				// Top
				glm::vec3(-0.5f, 0.5f, 1.0f),
				glm::vec3(0.0f, 0.0f, 1.0f),
				glm::vec3(1.0f, 1.0f, 1.0f),

				glm::vec3(0.5f, 0.5f, 0.0f),
				glm::vec3(0.0f, 0.0f, 1.0f),
				glm::vec3(1.0f, 1.0f, 1.0f),

				glm::vec3(0.5f, 0.5f, 0.0f),
				glm::vec3(0.0f, 0.0f, 1.0f),
				glm::vec3(1.0f, 1.0f, 1.0f),

				glm::vec3(-0.5f, 0.5f, 0.0f),
				glm::vec3(0.0f, 0.0f, 1.0f),
				glm::vec3(1.0f, 1.0f, 1.0f),

				// Left
				glm::vec3(-0.5f, 0.5f, 0.0f),
				glm::vec3(0.0f, 0.0f, 1.0f),
				glm::vec3(1.0f, 1.0f, 1.0f),

				glm::vec3(-0.5f, 0.5f, -1.0f),
				glm::vec3(0.0f, 0.0f, 1.0f),
				glm::vec3(1.0f, 1.0f, 1.0f),

				glm::vec3(-0.5f, -0.5f, -1.0f),
				glm::vec3(0.0f, 0.0f, 1.0f),
				glm::vec3(1.0f, 1.0f, 1.0f),

				glm::vec3(-0.5f, -0.5f, 0.0f),
				glm::vec3(0.0f, 0.0f, 1.0f),
				glm::vec3(1.0f, 1.0f, 1.0f),

				// Right
				glm::vec3(0.5f, 0.5f, 0.0f),
				glm::vec3(0.0f, 0.0f, 1.0f),
				glm::vec3(1.0f, 1.0f, 1.0f),

				glm::vec3(0.5f, 0.5f, -1.0f),
				glm::vec3(0.0f, 0.0f, 1.0f),
				glm::vec3(1.0f, 1.0f, 1.0f),

				glm::vec3(0.5f, -0.5f, -1.0f),
				glm::vec3(0.0f, 0.0f, 1.0f),
				glm::vec3(1.0f, 1.0f, 1.0f),

				glm::vec3(0.5f, -0.5f, 0.0f),
				glm::vec3(0.0f, 0.0f, 1.0f),
				glm::vec3(1.0f, 1.0f, 1.0f)
		};

		cube.vertices = new Vertex[cube.numVertices];
		memcpy(cube.vertices, vertices, sizeof(vertices));

		cube.numIndices = INDICES_PER_CUBE;

		GLushort indices[] =
		{
			0, 1, 3,		1, 2, 3, // Front
			4, 5, 6,		6, 7, 4, // Back
			8, 9, 10,		10, 11, 8, // Bottom
			12, 13, 14,		14, 15, 12, // Top
			16, 17, 18,		18, 19, 16, // Left
			20, 21, 22,		22, 23, 20 // Right
		};

		cube.indices = new GLushort[cube.numIndices];
		memcpy(cube.indices, indices, sizeof(indices));

		cube.sendToBuffer();

		return cube;
	}
}
