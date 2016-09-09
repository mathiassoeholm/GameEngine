#pragma once

#include "../Component.h"

namespace GameEngine
{
	class Light : public Component
	{
	private:
		glm::vec3 color;
		glm::vec3 position;
	public:
		Light(const glm::vec3& color, const glm::vec3& position);
	};
}



