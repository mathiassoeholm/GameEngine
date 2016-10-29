#include "DirectionalLight.h"

namespace GameEngine
{
    DirectionalLight::DirectionalLight(glm::vec3 direction, glm::vec3 color) : Light(color),
        direction(direction)
    {

    }

	glm::vec3 DirectionalLight::getDirection() const
	{
		return direction;
	}
}
