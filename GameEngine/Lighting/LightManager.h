#pragma once

#include <glm/vec3.hpp>

namespace GameEngine
{
	// Forward declaration, because of circular dependency
	class Light;

	class LightManager
	{
	private:
		glm::vec3 ambientColor;
		std::vector<Light*> lights;
		int lightCount;
	public:
		const static int MAX_LIGHT_COUNT = 10;

		static LightManager& getInstance()
		{
			static LightManager instance;
			return instance;
		}

        std::vector<Light*> getAllLights() const
        {
            return lights;
        }

		void addLight(Light* light);
		void removeLight(Light* light);
		glm::vec3 getAmbientColor();
		void setAmbientColor(glm::vec3);
	private:
		LightManager();
		LightManager(LightManager const&){} // Don't implement
		void operator=(LightManager const&){} // Don't implement
	};
}