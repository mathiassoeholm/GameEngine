#include "Scene.h"
#include "GameObject.h"
#include "Camera.h"
#include <GLFW/glfw3.h>

namespace GameEngine
{
	Scene::Scene() : gameObjectsToDestroy(std::vector<GameObject*>()),
					 gameObjects(std::forward_list<GameObject*>())
	{
		auto camGameObject = instantiateGameObject();
		mainCamera = new Camera();
		camGameObject->addComponent(mainCamera);
	}

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

	void Scene::keyEvent(int key, int action)
	{
		for (auto gameObject : gameObjects)
		{
			if(action == GLFW_PRESS)
			{
				gameObject->onKeyPressed(key);
				gameObject->onKey(key);
			}
			else if(action == GLFW_RELEASE)
			{
				gameObject->onKeyReleased(key);
			}
			else if(action == GLFW_REPEAT)
			{
				gameObject->onKey(key);
			}
		}
	}
}

