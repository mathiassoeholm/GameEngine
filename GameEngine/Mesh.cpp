#include <string.h>
#include "Mesh.h"

namespace GameEngine
{
	static const size_t COMPONENTS_PER_VERTEX_ATTR = 3;

	void Mesh::bind()
	{
		glBindVertexArray(vao);
	}

	int Mesh::getNumIndices() const
	{
		return numIndices;
	}

	Mesh::Mesh() :
		vertices(nullptr),
		numVertices(0),
		indices(nullptr),
		numIndices(0),
		references(0)
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
		vao = source.vao;
		vbo = source.vbo;
		ibo = source.ibo;
		references = source.references;

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
		references = 0;
		vao = 0;
		vbo = 0;
		ibo = 0;
		delete[] vertices;
		delete[] indices;
	}

	void Mesh::incrementRefCount()
	{
		references++;
	}

	void Mesh::decrementRefCount()
	{
		references--;

		if(references == 0)
		{
			glDeleteBuffers(1, &vbo);
			glDeleteBuffers(1, &ibo);
		}
	}

	GLsizeiptr Mesh::verticesBufferSize() const
	{
		return sizeof(Vertex) * numVertices;
	}

	GLsizeiptr Mesh::indicesBufferSize() const
	{
		return sizeof(GLushort) * numIndices;
	}

	void Mesh::sendToBuffer()
	{
		vbo = 0;
		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, verticesBufferSize(), vertices, GL_STATIC_DRAW);

		ibo = 0;
		glGenBuffers(1, &ibo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesBufferSize(), indices, GL_STATIC_DRAW);

		vao = 0;
		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

		// Position
		glVertexAttribPointer(0, COMPONENTS_PER_VERTEX_ATTR, GL_FLOAT, GL_FALSE, sizeof(Vertex), nullptr);

		// Normals
		glVertexAttribPointer(1, COMPONENTS_PER_VERTEX_ATTR, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void *)(3*sizeof(float)));
	}



}