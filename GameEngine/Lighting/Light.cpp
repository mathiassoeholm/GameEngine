#include "Light.h"

namespace GameEngine
{
	Light::Light(const glm::vec3 &color) :
		color(color)
	{
		LightManager::getInstance().addLight(this);
	}

	Light::Light() : Light(glm::vec3(0, 0, 0))
	{

	}

	Light::~Light()
	{
		LightManager::getInstance().removeLight(this);
	}

	glm::vec3 Light::getColor() const
	{
		return color;
	}
}