#include <string.h>
#include "Mesh.h"

namespace GameEngine
{
	void Mesh::bind()
	{

	}

	int Mesh::getNumIndices() const
	{
		return 0;
	}

	Mesh::Mesh() :
		vertices(nullptr),
		numVertices(0),
		indices(nullptr),
		numIndices(0)
	{

	}

	Mesh::Mesh(const Mesh &source)
	{
		copyValues(source);
	}

	Mesh &Mesh::operator=(const Mesh &source)
	{
		if(this == &source)
		{
			return *this;
		}

		delete[] vertices;
		delete[] indices;

		copyValues(source);

		return *this;
	}

	void Mesh::copyValues(const Mesh &source)
	{
		numVertices = source.numVertices;
		numIndices = source.numIndices;

		if(source.vertices)
		{
			vertices = new Vertex[numVertices];
			memcpy(vertices, source.vertices, sizeof(Vertex) * numVertices);
		}

		if(source.indices)
		{
			indices = new GLushort[numIndices];
			memcpy(indices, source.indices, sizeof(GLushort) * numIndices);
		}
	}

	Mesh::~Mesh()
	{
		numIndices = 0;
		numVertices = 0;
		delete[] vertices;
		delete[] indices;
	}

	GLsizeiptr Mesh::verticesBufferSize() const
	{
		return sizeof(Vertex) * numVertices;
	}

	GLsizeiptr Mesh::indicesBufferSize() const
	{
		return sizeof(GLushort) * numIndices;
	}
}