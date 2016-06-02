#include <iostream>
#include "GameObject.h"
#include "Component.h"

namespace GameEngine
{
	GameObject::GameObject(Scene& parentScene) :
			modelMatrix(glm::mat4(1.0f)),
			scaleMatrix(glm::mat4(1.0f)),
			translationMatrix(glm::mat4(1.0f)),
			rotationMatrix(glm::mat4(1.0f)),
			components(std::multiset<Component*>()),
			parentScene(parentScene),
			isDestroyed(false)
	{

	}

	void GameObject::update(Time& time)
	{
		for (auto component : components)
		{
			component->update(time);

			if(isDestroyed)
			{
				return;
			}
		}
	}

	void GameObject::addComponent(Component* component)
	{
		components.insert(component);
		component->initialize(this);
	}

	const glm::mat4& GameObject::getModelMatrix() const
	{
		return modelMatrix;
	}

	void GameObject::translate(const glm::vec3& translation)
	{
		translationMatrix = glm::translate(translation) * translationMatrix;
		updateModelMatrix();
	}

	glm::vec3 GameObject::getPosition() const
	{
		return glm::vec3(modelMatrix[3][0], modelMatrix[3][1], modelMatrix[3][2]);
	}

	void GameObject::setPosition(const glm::vec3& position)
	{
		translationMatrix[3][0] = position.x;
		translationMatrix[3][1] = position.y;
		translationMatrix[3][2] = position.z;
		updateModelMatrix();
	}

	void GameObject::destroy()
	{
		isDestroyed = true;
		parentScene.destroyGameObject(this);
	}

	GameObject::~GameObject()
	{
		for (auto component : components)
		{
			delete component;
		}

		components.clear();
	}

    void GameObject::rotate(const glm::vec3 &rotation)
    {
		rotationMatrix = glm::rotate(rotationMatrix, rotation.x, glm::vec3(1, 0 ,0));
		rotationMatrix = glm::rotate(rotationMatrix, rotation.y, glm::vec3(0, 1 ,0));
		rotationMatrix = glm::rotate(rotationMatrix, rotation.z, glm::vec3(0, 0 ,1));

		updateModelMatrix();
    }

	Camera* GameObject::getCamera() const
	{
		return parentScene.getMainCamera();
	}

	void GameObject::updateModelMatrix()
	{
		modelMatrix = translationMatrix * rotationMatrix * scaleMatrix;
	}
}
