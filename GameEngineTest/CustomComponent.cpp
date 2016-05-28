#include <math.h>
#include "CustomComponent.h"
#include "../GameEngine/Camera.h"

void CustomComponent::update(Time& time)
{
	double s = sin(time.getElapsedTime()) * 0.5;
	double c = cos(time.getElapsedTime()) * 0.5;
    //getGameObject()->setPosition(glm::vec3(s, c, 0));
	getGameObject()->rotate(glm::vec3(0, 0, 0.8 * time.getDeltaTime()));
}

void CustomComponent::onInitialize()
{
	getGameObject()->getCamera()->getGameObject()->setPosition(glm::vec3(0, 0, 5));
}
