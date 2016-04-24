#include <string.h>
#include "Primitives.h"

namespace GameEngine
{
	Mesh Primitives::createTriangle()
	{
		Mesh tri;
		tri.numVertices = 3;

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

		tri.numIndices = 3;

		GLushort indices[] =
		{
			0, 1, 2
		};
		tri.indices = new GLushort[tri.numIndices];
		memcpy(tri.indices, indices, sizeof(indices));

		return tri;
	}

}
