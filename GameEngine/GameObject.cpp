#include "GameObject.h"

namespace GameEngine
{
	GameObject::GameObject() :
			modelMatrix{glm::mat4()},
			components{std::multiset<Component>()}
	{

	}

	void GameObject::update()
	{
		for (auto component : components)
		{
			component.update();
		}
	}

	void GameObject::addComponent(Component component)
	{
		components.insert(component);
	}
}

