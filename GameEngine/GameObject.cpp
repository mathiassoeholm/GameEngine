#include "GameObject.h"

namespace GameEngine
{
	GameObject::GameObject() :
			modelMatrix{glm::mat4()},
			components{std::vector<Component>()}
	{

	}

	void GameObject::update()
	{
		// TODO: Render MeshRenders
	}

	void GameObject::addComponent(Component component)
	{
		components.push_back(component);
	}
}

