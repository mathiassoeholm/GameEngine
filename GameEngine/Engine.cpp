#include "Engine.h"
#include "GLFW/glfw3.h"
#include <iostream>

namespace GameEngine
{
	Engine::Engine(std::string gameTitle, Scene *scenes, GLint numScenes)
	{
		initGLFW();
	}

	bool Engine::initGLFW()
	{
		if (!glfwInit())
		{
			std::cerr << "Could not start GLFW3!" << std::endl;
			return false;
		}

		return true;
	}
}