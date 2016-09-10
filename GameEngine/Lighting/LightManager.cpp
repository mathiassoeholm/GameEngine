#include "LightManager.h"

namespace GameEngine
{
	LightManager::LightManager() :
		lights(new Light[MAX_LIGHT_COUNT]),
		lightCount(0)
	{

	}
}

