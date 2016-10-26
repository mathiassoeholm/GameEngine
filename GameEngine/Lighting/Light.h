#pragma once

#include "../Component.h"
#include "LightManager.h"

namespace GameEngine
{
	class Light : public Component
	{
	private:
		glm::vec3 color;
	public:
		Light(const glm::vec3& color);
		Light();
		~Light();
	};
}