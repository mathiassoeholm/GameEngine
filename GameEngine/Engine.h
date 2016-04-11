#pragma once

#include "Scene.h"
#include <string>

namespace GameEngine
{
	class Engine
	{
	public:
		Engine(std::string gameTitle, Scene* scenes, GLint numScenes);
	private:
		bool initGLFW();
	};
}

