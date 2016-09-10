#pragma once

#include "Light.h"

namespace GameEngine
{
	class LightManager
	{
	private:
		Light* lights;
		int lightCount;
	public:
		const static int MAX_LIGHT_COUNT = 10;

		static LightManager& getInstance()
		{
			static LightManager instance;
			return instance;
		}
	private:
		LightManager();
		LightManager(LightManager const&){} // Don't implement
		void operator=(LightManager const&){} // Don't implement
	};
}