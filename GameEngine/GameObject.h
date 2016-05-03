#pragma once

#include "glm/ext.hpp"
#include <set>
#include <memory>
#include "gl/glew.h"
#include "Component.h"

namespace GameEngine
{
	class GameObject
	{
		glm::mat4 modelMatrix;

		// We keep components in a multiset, so that they are executed in order
		std::multiset<std::unique_ptr<Component>> components;
	public:
		GameObject();
		void update();
		void addComponent(const std::unique_ptr<Component>& component);
	};
}