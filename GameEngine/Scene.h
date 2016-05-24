#pragma once

#include <forward_list>
#include "GameObject.h"
#include "Time.h"

namespace GameEngine
{
	class Scene
	{
	private:
		std::forward_list<GameObject*> gameObjects;
	public:
		Scene();
		void update(Time& time);
		void addGameObject(GameObject* gameObject);
		void destroyGameObject(GameObject* gameObject);
		void destroyAllGameObjects();

		// Called after the engine has initialized
		virtual void initialize(){};
		virtual void onMouseClick(int button, int action, int mods){};
		virtual void onWindowSizeChanged(int width, int height){};
	};
}
