#pragma once

#include "glm/ext.hpp"
#include <set>
#include <memory>
#include "gl/glew.h"
#include "Component.h"
#include "Time.h"
#include "Scene.h"

namespace GameEngine
{
	// Forward declarations because of cyclic dependencies
	class Component;
	class Scene;

	class GameObject
	{
		glm::mat4 modelMatrix;
		Scene& parentScene;
		bool isDestroyed;

		// We keep components in a multiset, so that they are executed in order
		std::multiset<Component*> components;
	public:
		GameObject(Scene& parentScene);
		~GameObject();
		void update(Time& time);
		void addComponent(Component* component);
		void setPosition(const glm::vec3& position);
		void translate(const glm::vec3& translation);
		void destroy();
		const glm::mat4& getModelMatrix() const;
	};
}