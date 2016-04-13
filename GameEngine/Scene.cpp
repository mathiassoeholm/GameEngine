#include "Scene.h"

namespace GameEngine
{
	void Scene::update()
	{
		for (auto gameObject : gameObjects)
		{
			gameObject.update();
		}
	}

	Scene::Scene()
	{
		gameObjects = std::vector<GameObject>();

		// TODO: Add Camera component and so on
		GameObject mainCamera;
		addGameObject(mainCamera);
	}

	void Scene::addGameObject(GameObject gameObject)
	{
		gameObjects.push_back(gameObject);
	}
}

