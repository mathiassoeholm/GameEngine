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

	return tri;
}
