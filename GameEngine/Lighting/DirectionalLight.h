#pragma once

#include "Light.h"

namespace GameEngine
{
	class DirectionalLight : public Light
	{
	private:
		glm::vec3 direction;

	};
}
