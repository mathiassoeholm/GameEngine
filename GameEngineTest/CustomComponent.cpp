#include "CustomComponent.h"

void CustomComponent::update(Time& time)
{
	getGameObject()->translate(glm::vec3(0.1f, 0.05f, 0) * time.getDeltaTime());
}