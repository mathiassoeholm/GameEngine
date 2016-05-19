#include "MeshRenderer.h"

namespace GameEngine
{
	MeshRenderer::MeshRenderer(const Mesh& mesh, const Material& material) :
		material(material),
		mesh(mesh)
	{

	}

	void MeshRenderer::update()
	{
		material.setUniform("modelMatrix", getGameObject()->getModelMatrix());
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