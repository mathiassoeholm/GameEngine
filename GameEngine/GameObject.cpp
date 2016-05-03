#include <iostream>
#include "GameObject.h"

namespace GameEngine
{
	GameObject::GameObject() :
			modelMatrix{glm::mat4()},
			components{std::multiset<std::unique_ptr<Component>>()}
	{

	}

	void GameObject::update()
	{
		for (auto component : components)
		{
			component->update();
		}
	}

	void GameObject::addComponent(const std::unique_ptr<Component>& component)
	{
		components.insert(component);
	}
}

