#include "MeshRenderer.h"
#include "gl/glew.h"

namespace GameEngine
{
	MeshRenderer::MeshRenderer(Mesh &mesh, Material &material) :
		mesh(mesh),
		material(material)
	{

	}

	void MeshRenderer::update()
	{
		material.use();
		mesh.bind();
		glDrawElements(GL_TRIANGLES, mesh.getNumIndices(), GL_UNSIGNED_SHORT, 0);
	}

	int MeshRenderer::getOrder() const
	{
		// Rendering happens late in the update loop
		return 1000;
	}


}

