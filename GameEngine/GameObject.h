#pragma once

#include "glm/ext.hpp"
#include <vector>
#include "gl/glew.h"
#include "Component.h"

namespace GameEngine
{
	class GameObject
	{
		glm::mat4 modelMatrix;
		std::vector<Component> components;
	public:
		GameObject();
		void render();
		void addComponent(Component component);
	};
}