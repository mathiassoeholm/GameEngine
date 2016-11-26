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

	std::shared_ptr<Mesh> Primitives::createTriangle()
	{
		auto tri = std::make_shared<Mesh>();
		tri->numVertices = VERTS_PER_TRIANGLE;

		Vertex vertices[] =
		{
				glm::vec3(0.0f, 0.5f, 0.0f), // Position
				glm::vec2(0.5f, 1.0f), // Tex coordinate
				glm::vec3(0.0f, 0.0f, 1.0f), // Normal
				glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), // Color

				glm::vec3(0.5f, -0.5f, 0.0f),
				glm::vec2(1.0f, 0.0f),
				glm::vec3(0.0f, 0.0f, 1.0f),
				glm::vec4(1.0f, 1.0f, 1.0f, 1.0f),

				glm::vec3(-0.5f, -0.5f, 0.0f),
				glm::vec2(0.0f, 0.0f),
				glm::vec3(0.0f, 0.0f, 1.0f),
				glm::vec4(1.0f, 1.0f, 1.0f, 1.0f)
		};

		tri->vertices = new Vertex[tri->numVertices];
		memcpy(tri->vertices, vertices, sizeof(vertices));

		tri->numIndices = INDICES_PER_TRIANGLE;

		GLushort indices[] =
		{
			0, 1, 2
		};

		tri->indices = new GLushort[tri->numIndices];
		memcpy(tri->indices, indices, sizeof(indices));

		tri->sendToBuffer();

		return tri;
	}

	std::shared_ptr<Mesh> Primitives::createQuad()
	{
		std::shared_ptr<Mesh> quad = std::make_shared<Mesh>();
		quad->numVertices = VERTS_PER_QUAD;

		Vertex vertices[] =
		{
				glm::vec3(-0.5f, 0.5f, 0.0f), // Position
				glm::vec2(0.0f, 1.0f), // Tex coordinate
				glm::vec3(0.0f, 0.0f, 1.0f), // Normal
				glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), // Color

				glm::vec3(0.5f, 0.5f, 0.0f),
				glm::vec2(1.0f, 1.0f),
				glm::vec3(0.0f, 0.0f, 1.0f),
				glm::vec4(1.0f, 1.0f, 1.0f, 1.0f),

				glm::vec3(0.5f, -0.5f, 0.0f),
				glm::vec2(1.0f, 0.0f),
				glm::vec3(0.0f, 0.0f, 1.0f),
				glm::vec4(1.0f, 1.0f, 1.0f, 1.0f),

				glm::vec3(-0.5f, -0.5f, 0.0f),
				glm::vec2(0.5f, 0.0f),
				glm::vec3(0.0f, 0.0f, 1.0f),
				glm::vec4(1.0f, 1.0f, 1.0f, 1.0f),
		};

		quad->vertices = new Vertex[quad->numVertices];
		memcpy(quad->vertices, vertices, sizeof(vertices));

		quad->numIndices = INDICES_PER_QUAD;

		GLushort indices[] =
		{
			0, 1, 3,
			1, 2, 3
		};

		quad->indices = new GLushort[quad->numIndices];
		memcpy(quad->indices, indices, sizeof(indices));

		quad->sendToBuffer();

		return quad;
	}

	std::shared_ptr<Mesh> Primitives::createCube()
	{
		std::shared_ptr<Mesh> cube = std::make_shared<Mesh>();
		cube->numVertices = VERTS_PER_CUBE;

		Vertex vertices[] =
		{
			// TOP
			glm::vec3(-1.0f, 1.0f, 1.0f), // 0
			glm::vec2(0.0f, 1.0f), // Tex coordinate
			glm::vec3(0.0f, 1.0f, 0.0f), // Normal
			glm::vec4(1.0f, 0, 0.0f, 1.0f), // Color
			glm::vec3(1.0f, 1.0f, 1.0f), // 1
			glm::vec2(1.0f, 1.0f), // Tex coordinate
			glm::vec3(0.0f, 1.0f, 0.0f), // Normal
			glm::vec4(1.0f, 0, 0.0f, 1.0f), // Color
			glm::vec3(1.0f, 1.0f, -1.0f), // 2
			glm::vec2(1.0f, 0.0f), // Tex coordinate
			glm::vec3(0.0f, 1.0f, 0.0f), // Normal
			glm::vec4(1.0f, 0, 0.0f, 1.0f), // Color
			glm::vec3(-1.0f, 1.0f, -1.0f), // 3
			glm::vec2(0.0f, 0.0f), // Tex coordinate
			glm::vec3(0.0f, 1.0f, 0.0f), // Normal
			glm::vec4(1.0f, 0, 0.0f, 1.0f), // Color

			// Front
			glm::vec3(-1.0f, 1.0f, -1.0f), // 4
			glm::vec2(0.0f, 1.0f), // Tex coordinate
			glm::vec3(0.0f, 0.0f, 1.0f), // Normal
			glm::vec4(0, 0, 1.0f, 1.0f), // Color
			glm::vec3(1.0f, 1.0f, -1.0f), // 5
			glm::vec2(1.0f, 1.0f), // Tex coordinate
			glm::vec3(0.0f, 0.0f, 1.0f), // Normal
			glm::vec4(0, 0, 1.0f, 1.0f), // Color
			glm::vec3(1.0f, -1.0f, -1.0f), // 6
			glm::vec2(1.0f, 0.0f), // Tex coordinate
			glm::vec3(0.0f, 0.0f, 1.0f), // Normal
			glm::vec4(0, 0, 1.0f, 1.0f), // Color
			glm::vec3(-1.0f, -1.0f, -1.0f), // 7
			glm::vec2(0.0f, 0.0f), // Tex coordinate
			glm::vec3(0.0f, 0.0f, 1.0f), // Normal
			glm::vec4(0, 0, 1.0f, 1.0f), // Color

			// Right
			glm::vec3(1.0f, 1.0f, -1.0f), // 8
			glm::vec2(0.0f, 1.0f), // Tex coordinate
			glm::vec3(1.0f, 0, 0), // Normal
			glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), // Color
			glm::vec3(1.0f, 1.0f, 1.0f), // 9
			glm::vec2(1.0f, 1.0f), // Tex coordinate
			glm::vec3(1.0f, 0, 0), // Normal
			glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), // Color
			glm::vec3(1.0f, -1.0f, 1.0f), // 10
			glm::vec2(1.0f, 0.0f), // Tex coordinate
			glm::vec3(1.0f, 0, 0), // Normal
			glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), // Color
			glm::vec3(1.0f, -1.0f, -1.0f), // 11
			glm::vec2(0.0f, 0.0f), // Tex coordinate
			glm::vec3(1.0f, 0, 0), // Normal
			glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), // Color

			// Left
			glm::vec3(-1.0f, 1.0f, 1.0f), // 12
			glm::vec2(0.0f, 1.0f), // Tex coordinate
			glm::vec3(-1.0f, 0, 0), // Normal
			glm::vec4(1.0f, 1.0f, 0.0f, 1.0f), // Color
			glm::vec3(-1.0f, 1.0f, -1.0f), // 13
			glm::vec2(1.0f, 1.0f), // Tex coordinate
			glm::vec3(-1.0f, 0, 0), // Normal
			glm::vec4(1.0f, 1.0f, 0.0f, 1.0f), // Color
			glm::vec3(-1.0f, -1.0f, -1.0f), // 14
			glm::vec2(1.0f, 0.0f), // Tex coordinate
			glm::vec3(-1.0f, 0, 0), // Normal
			glm::vec4(1.0f, 1.0f, 0.0f, 1.0f), // Color
			glm::vec3(-1.0f, -1.0f, 1.0f), // 15
			glm::vec2(0.0f, 0.0f), // Tex coordinate
			glm::vec3(-1.0f, 0, 0), // Normal
			glm::vec4(1.0f, 1.0f, 0.0f, 1.0f), // Color

			// Back
			glm::vec3(1.0f, 1.0f, 1.0f), // 16
			glm::vec2(0.0f, 1.0f), // Tex coordinate
			glm::vec3(0, 0, -1.0f), // Normal
			glm::vec4(0, 0, 1.0f, 1.0f), // Color
			glm::vec3(-1.0f, 1.0f, 1.0f), // 17
			glm::vec2(1.0f, 1.0f), // Tex coordinate
			glm::vec3(0, 0, -1.0f), // Normal
			glm::vec4(0, 0, 1.0f, 1.0f), // Color
			glm::vec3(-1.0f, -1.0f, 1.0f), // 18
			glm::vec2(1.0f, 0.0f), // Tex coordinate
			glm::vec3(0, 0, -1.0f), // Normal
			glm::vec4(0, 0, 1.0f, 1.0f), // Color
			glm::vec3(1.0f, -1.0f, 1.0f), // 19
			glm::vec2(0.0f, 0.0f), // Tex coordinate
			glm::vec3(0, 0, -1.0f), // Normal
			glm::vec4(0, 0, 1.0f, 1.0f), // Color

			// Bottom
			glm::vec3(1.0f, -1.0f, -1.0f), // 20
			glm::vec2(0.0f, 1.0f), // Tex coordinate
			glm::vec3(0, -1.0f, 0), // Normal
			glm::vec4(0, 0, 2.0f, 1.0f), // Color
			glm::vec3(-1.0f, -1.0f, -1.0f), // 21
			glm::vec2(1.0f, 1.0f), // Tex coordinate
			glm::vec3(0, -1.0f, 0), // Normal
			glm::vec4(0, 0, 2.0f, 1.0f), // Color
			glm::vec3(-1.0f, -1.0f, 1.0f), // 22
			glm::vec2(1.0f, 0.0f), // Tex coordinate
			glm::vec3(0, -1.0f, 0), // Normal
			glm::vec4(0, 0, 2.0f, 1.0f), // Color
			glm::vec3(1.0f, -1.0f, 1.0f), // 23
			glm::vec2(0.0f, 0.0f), // Tex coordinate
			glm::vec3(0, -1.0f, 0), // Normal
			glm::vec4(0, 0, 2.0f, 1.0f), // Color
		};

		cube->vertices = new Vertex[cube->numVertices];
		memcpy(cube->vertices, vertices, sizeof(vertices));

		cube->numIndices = INDICES_PER_CUBE;

		GLushort indices[] =
		{
				0,   1,  2,  0,  2,  3, // Top
				4,   5,  6,  4,  6,  7, // Front
				8,   9, 10,  8, 10, 11, // Right
				12, 13, 14, 12, 14, 15, // Left
				16, 17, 18, 16, 18, 19, // Back
				20, 22, 21, 20, 23, 22, // Bottom
		};

		cube->indices = new GLushort[cube->numIndices];
		memcpy(cube->indices, indices, sizeof(indices));

		cube->sendToBuffer();

		return cube;
	}
}
