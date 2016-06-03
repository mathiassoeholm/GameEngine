#include <math.h>
#include "CustomComponent.h"
#include "../GameEngine/Camera.h"
#include <GLFW/glfw3.h>

void CustomComponent::update(Time& time)
{
	this->time = &time;

	double s = sin(time.getElapsedTime()) * 0.5;
	double c = cos(time.getElapsedTime()) * 0.5;
    //getGameObject()->translate(glm::vec3(0.5f * time.getDeltaTime(), 0, 0));
    //getGameObject()->setPosition(glm::vec3(-0.4f, 0, 0));
	//getGameObject()->rotate(glm::vec3(0, 0, 10 * time.getDeltaTime()));
	//getGameObject()->getCamera()->getGameObject()->setPosition(glm::vec3(s, 0, 5));
	//getGameObject()->getCamera()->getGameObject()->rotate(glm::vec3(0, 0, 0.2 * time.getDeltaTime()));
}

void CustomComponent::onInitialize()
{
	getGameObject()->getCamera()->getGameObject()->setPosition(glm::vec3(0, 0, 5));
}

void CustomComponent::onKey(int key)
{
	// TODO: We shouldn't have to use GLFW directly in client code
	if(key == GLFW_KEY_D)
	{
		getGameObject()->translate(glm::vec3(time->getDeltaTime(), 0, 0));
	}
	else if(key == GLFW_KEY_A)
	{
		getGameObject()->translate(glm::vec3(-time->getDeltaTime(), 0, 0));
	}
}
