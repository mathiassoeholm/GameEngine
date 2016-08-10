#pragma once

#include <glm/glm.hpp>

namespace GameEngine
{
	struct Vertex
	{
		glm::vec3 position;
		glm::vec3 normal;
		glm::vec4 color;
	};
}