#include "Scene.h"

namespace GameEngine
{
	void Scene::update(Time& time)
	{
		for (auto gameObject : gameObjects)
		{
			gameObject->update(time);
		}
	}

	Scene::Scene()
	{
		gameObjects = std::vector<GameObject*>();

		// TODO: Add Camera component and so on
		//GameObject mainCamera;
		//addGameObject(mainCamera);
	}

	void Scene::addGameObject(GameObject* gameObject)
	{
		gameObjects.push_back(gameObject);
	}

	void Scene::destroyAllGameObjects()
	{
		for (auto gameObject : gameObjects)
		{
			gameObject->destroy();
			delete gameObject;
		}
	}
}

