#pragma once

#include "glm/ext.hpp"
#include <set>
#include <memory>
#include "gl/glew.h"
#include "Component.h"
#include "Time.h"

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
		void update(Time& time);
		void addComponent(Component* component);
		void destroy();
		void setPosition(const glm::vec3& position);
		void translate(const glm::vec3& translation);
		const glm::mat4& getModelMatrix() const;
	};
}