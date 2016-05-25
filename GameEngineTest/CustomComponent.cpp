#include "CustomComponent.h"

void CustomComponent::update(Time& time)
{
	double s = sin(time.getElapsedTime()) * 0.5;
	double c = cos(time.getElapsedTime()) * 0.5;
    getGameObject()->setPosition(glm::vec3(s, c, 0));
	getGameObject()->rotate(glm::vec3(0, 0, c * 0.004));
}