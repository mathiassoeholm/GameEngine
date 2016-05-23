#pragma once

#include <vector>
#include "GameObject.h"
#include "Time.h"

namespace GameEngine
{
	class Scene
	{
	private:
		std::vector<GameObject*> gameObjects;
	public:
		Scene();
		void update(Time& time);
		void addGameObject(GameObject* gameObject);
		void destroyAllGameObjects();

		// Called after the engine has initialized
		virtual void initialize(){};
		virtual void onMouseClick(int button, int action, int mods){};
		virtual void onWindowSizeChanged(int width, int height){};
	};
}
