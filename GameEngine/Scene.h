#pragma once

#include <vector>
#include "GameObject.h"

namespace GameEngine
{
	class Scene
	{
	private:
		std::vector<GameObject> gameObjects;
		void render();

	public:
		Scene();
		void addGameObject(GameObject gameObject);
	};
}
