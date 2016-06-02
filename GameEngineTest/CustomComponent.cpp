#include <math.h>
#include "CustomComponent.h"
#include "../GameEngine/Camera.h"

void CustomComponent::update(Time& time)
{
	double s = sin(time.getElapsedTime()) * 6;
	double c = cos(time.getElapsedTime()) * 0.5;
    //getGameObject()->setPosition(glm::vec3(0.5f, 0, 0));
    //getGameObject()->setPosition(glm::vec3(-0.4f, 0, 0));
	//getGameObject()->rotate(glm::vec3(0, 0, 10 * time.getDeltaTime()));
	getGameObject()->getCamera()->getGameObject()->setPosition(glm::vec3(s, 0, 5)); // Acts weird because camera is always looking at triangle
}

void CustomComponent::onInitialize()
{
	getGameObject()->getCamera()->getGameObject()->setPosition(glm::vec3(3, 0, 5));
}
