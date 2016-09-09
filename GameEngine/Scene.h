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
	public:
		const static int MAX_LIGHT_COUNT;
	private:
		Camera* mainCamera;
		std::forward_list<GameObject*> gameObjects;
		std::vector<GameObject*> gameObjectsToDestroy;
		std::vector<Light*> lights;
		Light* lightData;
	public:
		Scene();
		Camera* getMainCamera() const;
		Light* getLightData() const;
		void update(const UpdateInfo& updateInfo);
		void addGameObject(GameObject* gameObject);

		// This is called automatically when creating a new light component
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
	private:
		void setLightData();
	};
}
