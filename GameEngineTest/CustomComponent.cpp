//
// Created by Mathias on 20-05-2016.
//

#include "CustomComponent.h"

void CustomComponent::update()
{
	getGameObject()->translate(glm::vec3(0.005f, 0.005f, 0));
}
