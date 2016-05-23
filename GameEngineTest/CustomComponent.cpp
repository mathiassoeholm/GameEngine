#include "CustomComponent.h"

void CustomComponent::update(Time& time)
{
	double s = sin(time.getElapsedTime()) * 0.5;
	double c = cos(time.getElapsedTime()) * 0.5;
	getGameObject()->setPosition(glm::vec3(s, c, 0));
}