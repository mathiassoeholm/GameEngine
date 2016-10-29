#pragma once

#include "../Component.h"
#include "LightManager.h"

namespace GameEngine
{
	class Light : public Component
	{
	public:
		glm::vec3 color;
		Light(const glm::vec3& color);
		Light();
		glm::vec3 getColor() const;
		~Light();
	};
}