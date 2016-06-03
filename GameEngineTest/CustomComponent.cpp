#include <math.h>
#include "CustomComponent.h"
#include "../GameEngine/Camera.h"

void CustomComponent::update(Time& time)
{
	double s = sin(time.getElapsedTime()) * 0.5;
	double c = cos(time.getElapsedTime()) * 0.5;
    //getGameObject()->translate(glm::vec3(0.5f * time.getDeltaTime(), 0, 0));
    //getGameObject()->setPosition(glm::vec3(-0.4f, 0, 0));
	//getGameObject()->rotate(glm::vec3(0, 0, 10 * time.getDeltaTime()));
	getGameObject()->getCamera()->getGameObject()->setPosition(glm::vec3(s, 0, 5));
	//getGameObject()->getCamera()->getGameObject()->rotate(glm::vec3(0, 0, 0.2 * time.getDeltaTime()));
}

void CustomComponent::onInitialize()
{
	getGameObject()->getCamera()->getGameObject()->setPosition(glm::vec3(0, 0, 5));
}
