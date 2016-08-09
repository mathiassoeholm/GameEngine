#include "MeshRenderer.h"
#include "Camera.h"

namespace GameEngine
{
	MeshRenderer::MeshRenderer(const Mesh& mesh, const Material& material) :
		material(material),
		mesh(mesh)
	{
		this->mesh.incrementRefCount();
	}

	void MeshRenderer::update(const UpdateInfo& updateInfo)
	{
		material.use();

		auto model = getGameObject()->getModelMatrix();
		auto view = getGameObject()->getCamera()->getViewMatrix();
		auto proj = getGameObject()->getCamera()->getProjMatrix();

		material.setUniform("modelMatrix", model);
		material.setUniform("viewMatrix", view);
		material.setUniform("projMatrix", proj);
		material.setUniform("mvpMatrix", proj * view * model);

		mesh.bind();
		glDrawElements(GL_TRIANGLES, mesh.getNumIndices(), GL_UNSIGNED_SHORT, 0);
	}

	void MeshRenderer::onDestroy()
	{
		mesh.decrementRefCount();
	}

	int MeshRenderer::getOrder() const
	{
		// Rendering happens late in the update loop
		return 1000;
	}
}