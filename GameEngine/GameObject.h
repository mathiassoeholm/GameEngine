#pragma once

#include "glm/ext.hpp"
#include <vector>
#include <set>
#include "gl/glew.h"
#include "Component.h"

namespace GameEngine
{
	class GameObject
	{
		glm::mat4 modelMatrix;

		// We keep components in a multiset, so that they are executed in order
		std::multiset<Component> components;
	public:
		GameObject();
		void update();
		void addComponent(Component component);
	};
}