#include "Scene.h"

namespace GameEngine
{
	void Scene::update(Time& time)
	{
		for (auto gameObject : gameObjects)
		{
			gameObject->update(time);
		}

		// GameObjects are destroyed at the end of the update loop
		for (auto gameObject : gameObjectsToDestroy)
		{
			gameObjects.remove(gameObject);
			delete gameObject;
		}

		gameObjectsToDestroy.clear();
	}

	Scene::Scene() : gameObjectsToDestroy(std::vector<GameObject*>()),
					 gameObjects(std::forward_list<GameObject*>())
	{
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
		gameObjectsToDestroy.push_back(gameObject);
	}

	GameObject* Scene::instantiateGameObject()
	{
		auto go = new GameObject(*this);
		addGameObject(go);
		return go;
	}
}

