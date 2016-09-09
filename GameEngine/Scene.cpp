#include "Scene.h"
#include "GameObject.h"
#include "Camera.h"
#include "Lighting/Light.h"
#include <algorithm>
#include <GLFW/glfw3.h>

namespace GameEngine
{
	const int Scene::MAX_LIGHT_COUNT = 10;

	Scene::Scene() : gameObjectsToDestroy(std::vector<GameObject*>()),
					 gameObjects(std::forward_list<GameObject*>()),
					 lights(std::vector<Light*>()),
					 lightData(new Light[Scene::MAX_LIGHT_COUNT])
	{
		auto camGameObject = instantiateGameObject();
		mainCamera = new Camera();
		camGameObject->addComponent(mainCamera);
	}

	void Scene::update(const UpdateInfo& updateInfo)
	{
		setLightData();

		for (auto gameObject : gameObjects)
		{
			gameObject->update(updateInfo);
		}

		// GameObjects are destroyed at the end of the update loop
		for (auto gameObject : gameObjectsToDestroy)
		{
			gameObjects.remove(gameObject);
			delete gameObject;
		}

		gameObjectsToDestroy.clear();
	}

	void Scene::addGameObject(GameObject* gameObject)
	{
		gameObjects.push_front(gameObject);
	}

	void Scene::addLight(Light* light)
	{
		lights.push_back(light);
	}

	void Scene::destroyAllGameObjects()
	{
		for (auto gameObject : gameObjects)
		{
			delete gameObject;
		}

		gameObjects.clear();
	}

	void Scene::destroyGameObject(GameObject *gameObject)
	{
		gameObjectsToDestroy.push_back(gameObject);
	}

	GameObject* Scene::instantiateGameObject()
	{
		auto go = new GameObject(*this);
		addGameObject(go);
		return go;
	}

	Camera* Scene::getMainCamera() const
	{
		return mainCamera;
	}

	void Scene::windowSizeChanged(int width, int height)
	{
		mainCamera->setScreenDimensions(width, height);

		onWindowSizeChanged(width, height);
	}

	void Scene::mouseClick(int button, int action, int mods)
	{
		onMouseClick(button, action, mods);
	}

	void Scene::setLightData()
	{
		auto lightsToCopy = std::min(MAX_LIGHT_COUNT, static_cast<int>(lights.size()));
		memcpy(lightData, &lights[0], lightsToCopy*sizeof(Light));
	}

	Light* Scene::getLightData() const
	{
		return lightData;
	}
}

