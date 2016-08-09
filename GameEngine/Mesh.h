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
		GLuint references;

		Mesh();
		Mesh(const Mesh &source);
		~Mesh();

		void incrementRefCount();
		void decrementRefCount();
		void bind();
		void sendToBuffer();
		int getNumIndices() const;

		Mesh& operator=(const Mesh &source);
	private:
		GLuint vao;
		GLuint vbo;
		GLuint ibo;
		GLsizeiptr verticesBufferSize() const;
		GLsizeiptr indicesBufferSize() const;
		void copyValues(const Mesh &source);
	};
}