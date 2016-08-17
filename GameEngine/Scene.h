#pragma once

#include <forward_list>
#include <vector>
#include "Time.h"
#include "Keyboard.h"
#include "UpdateInfo.h"

namespace GameEngine
{
	// Forward declarations because of cyclic dependencies
	class GameObject;
	class Camera;
	class Light;

	class Scene
	{
	private:
		Camera* mainCamera;
		std::forward_list<GameObject*> gameObjects;
		std::vector<GameObject*> gameObjectsToDestroy;
		std::vector<Light*> lights;
	public:
		Scene();
		Camera* getMainCamera() const;
		void update(const UpdateInfo& updateInfo);
		void addGameObject(GameObject* gameObject);
		void addLight(Light* light);

		void destroyGameObject(GameObject* gameObject);
		void destroyAllGameObjects();
		GameObject* instantiateGameObject();

		// Called after the engine has initialized
		virtual void initialize(){};

		void mouseClick(int button, int action, int mods);
		virtual void onMouseClick(int button, int action, int mods){};
		void windowSizeChanged(int width, int height);
		virtual void onWindowSizeChanged(int width, int height){};
	};
}
