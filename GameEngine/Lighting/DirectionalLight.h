#pragma once

#include "Light.h"

namespace GameEngine
{
	class DirectionalLight : public Light
	{
    public:
        DirectionalLight(glm::vec3 direction, glm::vec3 color);
	private:
		glm::vec3 direction;

	};
}
