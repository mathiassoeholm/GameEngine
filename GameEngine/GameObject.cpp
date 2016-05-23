#include <iostream>
#include "GameObject.h"

namespace GameEngine
{
	GameObject::GameObject() :
			modelMatrix(glm::mat4()),
			components(std::multiset<Component*>())
	{

	}

	void GameObject::update(Time& time)
	{
		for (auto component : components)
		{
			component->update(time);
		}
	}

	void GameObject::addComponent(Component* component)
	{
		components.insert(component);
		component->initialize(this);
	}

	void GameObject::destroy()
	{
		for (auto component : components)
		{
			delete component;
		}
	}

	const glm::mat4& GameObject::getModelMatrix() const
	{
		return modelMatrix;
	}

	void GameObject::translate(const glm::vec3 translation)
	{
		modelMatrix = modelMatrix * glm::transpose(glm::translate(translation));
	}
}

