#include <sstream>
#include "MeshRenderer.h"
#include "Camera.h"
#include "Lighting/Light.h"
#include "Lighting/DirectionalLight.h"

namespace GameEngine
{
	MeshRenderer::MeshRenderer(std::shared_ptr<Mesh> mesh, std::shared_ptr<Material> material) :
		material(material),
		mesh(mesh)
	{
	}

	void MeshRenderer::update(const UpdateInfo& updateInfo)
	{
		material->use();

		auto model = getGameObject()->getModelMatrix();
		auto view = getGameObject()->getCamera()->getViewMatrix();
		auto proj = getGameObject()->getCamera()->getProjMatrix();

		material->setUniform("modelMatrix", model);
		material->setUniform("viewMatrix", view);
		material->setUniform("projMatrix", proj);
		material->setUniform("mvpMatrix", proj * view * model);

		// TODO: I'm not at all sure if this is correct
		glm::mat3 normalMatrix = glm::mat3(view * model);
		material->setUniform("normalMatrix", glm::inverse(normalMatrix));

		auto lights = LightManager::getInstance().getAllLights();
		int dirLightsCount = 0;

        for (int i = 0; i < lights.size(); ++i)
        {
            auto light = lights[i];
			auto dirLight = dynamic_cast<DirectionalLight*>(light);
            if (dirLight)
            {
				std::stringstream colorName;
				colorName << "dirLights[" << i << "].color";

				std::stringstream dirName;
				dirName << "dirLights[" << i << "].direction";

                material->setUniform(colorName.str(), 1, reinterpret_cast<GLfloat*>(&light->color));
                material->setUniform(dirName.str(), 1, reinterpret_cast<GLfloat*>(&dirLight->direction));
				dirLightsCount++;
            }
        }

		auto ambientColor = LightManager::getInstance().getInstance().getAmbientColor();
		material->setUniform("ambientColor", 1, reinterpret_cast<GLfloat*>(&ambientColor));
		material->setUniform("dirLightsCount", dirLightsCount);

		mesh->bind();
		glDrawElements(GL_TRIANGLES, mesh->getNumIndices(), GL_UNSIGNED_SHORT, 0);
	}

	void MeshRenderer::onDestroy()
	{
		material.reset();
		mesh.reset();
	}

	int MeshRenderer::getOrder() const
	{
		// Rendering happens late in the update loop
		return 1000;
	}
}