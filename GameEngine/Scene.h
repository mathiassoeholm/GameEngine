#pragma once

#include <vector>
#include "GameObject.h"

namespace GameEngine
{
	class Scene
	{
	private:
		std::vector<GameObject> gameObjects;
	public:
		Scene();
		void update();
		void addGameObject(GameObject gameObject);
		virtual void onMouseClick(int button, int action, int mods){};
	};
}
