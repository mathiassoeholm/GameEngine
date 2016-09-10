#include "MeshRenderer.h"
#include "Camera.h"
#include "Lighting/Light.h"

namespace GameEngine
{
	MeshRenderer::MeshRenderer(const Mesh& mesh, const Material& material) :
		material(material),
		mesh(mesh)
	{
		this->mesh.incrementRefCount();
		this->material.incrementRefCount();
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

		//auto lights = getGameObject()->getParentScene().getLightData();

		//material.setUniform("lights", Scene::MAX_LIGHT_COUNT, reinterpret_cast<GLfloat*>(lights));

		mesh.bind();
		glDrawElements(GL_TRIANGLES, mesh.getNumIndices(), GL_UNSIGNED_SHORT, 0);
	}

	void MeshRenderer::onDestroy()
	{
		mesh.decrementRefCount();
		material.decrementRefCount();
	}

	int MeshRenderer::getOrder() const
	{
		// Rendering happens late in the update loop
		return 1000;
	}
}