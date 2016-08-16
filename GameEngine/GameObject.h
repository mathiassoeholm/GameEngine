#pragma once

#include "glm/ext.hpp"
#include <set>
#include <memory>
#include "gl/glew.h"
#include "Time.h"
#include "Scene.h"

namespace GameEngine
{
	// Forward declarations because of cyclic dependencies
	class Component;

	class GameObject
	{
		glm::mat4 rotationMatrix;
		glm::mat4 translationMatrix;
		glm::mat4 scaleMatrix;
		glm::mat4 modelMatrix;
		Scene& parentScene;
		bool isDestroyed;

		// We keep components in a multiset, so that they are executed in order
		std::multiset<Component*> components;
	public:
		GameObject(Scene& parentScene);
		~GameObject();
		void update(const UpdateInfo& updateInfo);
		void addComponent(Component* component);
		void destroy();
		Camera* getCamera() const;

		// Transformation functions
		glm::vec3 getPosition() const;
		glm::vec3 getScale() const;
		void setPosition(const glm::vec3& position);
		void translate(const glm::vec3& translation);
        void rotate(const glm::vec3& rotation);
        void setScale(const glm::vec3& scale);
		const glm::mat4& getModelMatrix() const;

		glm::vec3 getUp() const;
		glm::vec3 getForward() const;
		glm::vec3 getRight() const;
	private:
		void updateModelMatrix();
	};
}