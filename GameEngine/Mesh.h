#pragma once

#include <GL/glew.h>
#include "Vertex.h"

namespace GameEngine
{
	struct Mesh
	{
		Vertex* vertices;
		GLuint numVertices;
		GLushort* indices;
		GLuint numIndices;

		Mesh();
		Mesh(const Mesh &source);
		~Mesh();

		void bind();
		int getNumIndices() const;

		Mesh& operator=(const Mesh &source);
	private:
		GLsizeiptr verticesBufferSize() const;
		GLsizeiptr indicesBufferSize() const;
		void copyValues(const Mesh &source);
	};
}