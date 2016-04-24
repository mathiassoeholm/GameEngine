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

		// Called after the engine has initialized
		virtual void initialize(){};
		virtual void onMouseClick(int button, int action, int mods){};
		virtual void onWindowSizeChanged(int width, int height){};
	};
}
