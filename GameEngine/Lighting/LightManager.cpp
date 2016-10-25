#include <iostream>
#include <algorithm>
#include "LightManager.h"

namespace GameEngine
{
	LightManager::LightManager() :
		lights(std::vector<Light*>()),
		lightCount(0)
	{

	}

	void LightManager::removeLight(Light *light)
	{
		lights.erase(std::remove(lights.begin(), lights.end(), light), lights.end());
	}

	void LightManager::addLight(Light* light)
	{
		if(lights.size() >= MAX_LIGHT_COUNT)
		{
			std::cout << "There's too many lights, ignoring new light" << std::endl;
			return;
		}

		lights.push_back(light);
	}
}

