#include "Light.h"

namespace GameEngine
{
	Light::Light(const glm::vec3 &color) :
		color(color)
	{

	}

	Light::Light() : Light(glm::vec3(0, 0, 0))
	{

	}
}