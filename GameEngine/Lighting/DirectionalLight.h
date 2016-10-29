#pragma once

#include "Light.h"

namespace GameEngine
{
	class DirectionalLight : public Light
	{
    public:
		glm::vec3 direction;
        DirectionalLight(glm::vec3 direction, glm::vec3 color);
		glm::vec3 getDirection() const;
	};
}
