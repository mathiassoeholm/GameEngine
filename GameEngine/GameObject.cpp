#include <iostream>
#include "GameObject.h"

namespace GameEngine
{
	GameObject::GameObject(Scene& parentScene) :
			modelMatrix(glm::mat4()),
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
		modelMatrix = modelMatrix * glm::transpose(glm::translate(translation));
	}

	void GameObject::setPosition(const glm::vec3& position)
	{
		modelMatrix[0][3] = position.x;
		modelMatrix[1][3] = position.y;
		modelMatrix[2][3] = position.z;
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
}
