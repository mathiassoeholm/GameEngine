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
		gameObjects = std::forward_list<GameObject*>();

		// TODO: Add Camera component and so on
		//GameObject mainCamera;
		//addGameObject(mainCamera);
	}

	void Scene::addGameObject(GameObject* gameObject)
	{
		gameObjects.push_front(gameObject);
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
		gameObjects.remove(gameObject);
		delete gameObject;
	}
}

