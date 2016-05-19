#include <iostream>
#include "GameObject.h"

namespace GameEngine
{


	GameObject::GameObject() :
			modelMatrix(glm::mat4()),
			components(std::multiset<Component*>())
	{

	}

	void GameObject::update()
	{
		for (auto component : components)
		{
			component->update();
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
}

