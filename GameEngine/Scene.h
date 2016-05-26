#pragma once

#include <forward_list>
#include <vector>
#include "Time.h"

namespace GameEngine
{
	// Forward declarations because of cyclic dependencies
	class GameObject;
	class Camera;

	class Scene
	{
	private:
		Camera* mainCamera;
		std::forward_list<GameObject*> gameObjects;
		std::vector<GameObject*> gameObjectsToDestroy;
	public:
		Scene();
		Camera* getMainCamera() const;
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
