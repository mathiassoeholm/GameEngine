#pragma once

#include <GL/glew.h>
#include "GLFW/glfw3.h"
#include "Vertex.h"

struct Mesh
{
	Vertex* vertices;
	GLuint numVertices;
	GLushort* indices;
	GLuint numIndices;

	Mesh() :
		vertices{nullptr},
		numVertices{0},
		indices{nullptr},
		numIndices{0}
	{}

	void cleanup()
	{
		vertices = nullptr;
		indices = nullptr;
		numVertices = 0;
		numIndices = 0;
	}

	GLsizeiptr verticesBufferSize() const
	{
		return sizeof(Vertex) * numVertices;
	}
};
