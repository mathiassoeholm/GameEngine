#pragma once

namespace GameEngine
{
	// Forward declaration, because of circular dependency
	class Light;

	class LightManager
	{
	private:
		std::vector<Light*> lights;
		int lightCount;
	public:
		const static int MAX_LIGHT_COUNT = 10;

		static LightManager& getInstance()
		{
			static LightManager instance;
			return instance;
		}

		void addLight(Light* light);
		void removeLight(Light* light);
	private:
		LightManager();
		LightManager(LightManager const&){} // Don't implement
		void operator=(LightManager const&){} // Don't implement
	};
}