#pragma once

#include <forward_list>
#include <vector>
#include "GameObject.h"
#include "Time.h"

namespace GameEngine
{
	// Forward declaration because of cyclic dependency
	class GameObject;

	class Scene
	{
	private:
		std::forward_list<GameObject*> gameObjects;
		std::vector<GameObject*> gameObjectsToDestroy;
	public:
		Scene();
		void update(Time& time);
		void addGameObject(GameObject* gameObject);
		void destroyGameObject(GameObject* gameObject);
		void destroyAllGameObjects();
		GameObject* instantiateGameObject();

		// Called after the engine has initialized
		virtual void initialize(){};
		virtual void onMouseClick(int button, int action, int mods){};
		virtual void onWindowSizeChanged(int width, int height){};
	};
}
