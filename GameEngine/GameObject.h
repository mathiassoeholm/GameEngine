#pragma once

#include "glm/ext.hpp"
#include <set>
#include <memory>
#include "gl/glew.h"
#include "Component.h"

namespace GameEngine
{
	// Forward declaration because of cyclic dependency
	class Component;

	class GameObject
	{
		glm::mat4 modelMatrix;

		// We keep components in a multiset, so that they are executed in order
		std::multiset<Component*> components;
	public:
		GameObject();
		void update();
		void addComponent(Component* component);
		void destroy();
		void translate(const glm::vec3 translation);
		const glm::mat4& getModelMatrix() const;
	};
}