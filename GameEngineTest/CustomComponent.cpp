#include <math.h>
#include "CustomComponent.h"
#include "../GameEngine/Camera.h"
#include <GLFW/glfw3.h>

void CustomComponent::update(const UpdateInfo& updateInfo)
{
	double s = sin(updateInfo.time.getElapsedTime()) * 0.5;
	double c = cos(updateInfo.time.getElapsedTime()) * 0.5;

	if(updateInfo.keyboard.isKeyDown(GLFW_KEY_W))
	{
		getGameObject()->translate(glm::vec3(0, 3 * updateInfo.time.getDeltaTime(), 0));
	}

	if(updateInfo.keyboard.isKeyDown(GLFW_KEY_A))
	{
		getGameObject()->translate(glm::vec3(-3 * updateInfo.time.getDeltaTime(), 0, 0));
	}

	if(updateInfo.keyboard.isKeyDown(GLFW_KEY_S))
	{
		getGameObject()->translate(glm::vec3(0, -3 * updateInfo.time.getDeltaTime(), 0));
	}

	if(updateInfo.keyboard.isKeyDown(GLFW_KEY_D))
	{
		getGameObject()->translate(glm::vec3(3 * updateInfo.time.getDeltaTime(), 0, 0));
	}


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
