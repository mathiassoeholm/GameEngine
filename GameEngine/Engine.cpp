#include "Engine.h"
#include <iostream>

namespace GameEngine
{
	const static int DEFAULT_SCREEN_WIDTH = 1024;
	const static int DEFAULT_SCREEN_HEIGHT = 768;

	Engine* Engine::instance = nullptr;

	Engine::Engine(std::string gameTitle, Scene *scenes, GLint numScenes) :
		gameTitle {gameTitle},
		scenes {scenes},
		numScenes{numScenes}
	{
		if(instance == nullptr)
		{
			instance = this;
		}
		else
		{
			std::cerr << "Can't instantiate more than one Engine" << std::endl;
		}

		initGLFW();
	}

	bool Engine::initGLFW()
	{
		if (!glfwInit())
		{
			std::cerr << "Could not start GLFW3" << std::endl;
			return false;
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);

		// Disables all functionality that has been flagged for removal in future OpenGL versions
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		// Anti-Aliasing
		glfwWindowHint(GLFW_SAMPLES, 4);

		GLFWwindow* window = createWindow(false);
		if (!window)
		{
			std::cerr << "Could not open window with GLFW3" << std::endl;
			glfwTerminate();
			return false;
		}

		glfwMakeContextCurrent(window);

		return true;
	}

	GLFWwindow* Engine::createWindow(bool fullScreen)
	{
		GLFWwindow* window;

		if (fullScreen)
		{
			GLFWmonitor* mon = glfwGetPrimaryMonitor();
			const GLFWvidmode* vidmode = glfwGetVideoMode(mon);
			window = glfwCreateWindow(vidmode->width, vidmode->height, gameTitle.c_str(), mon, nullptr);
		}
		else
		{
			window = glfwCreateWindow(DEFAULT_SCREEN_WIDTH, DEFAULT_SCREEN_HEIGHT, gameTitle.c_str(), nullptr, nullptr);
		}

		glfwSetMouseButtonCallback(window, [=](GLFWwindow* w, int button, int action, int mods)
		{
			getInstance()->onMouseClick(button, action, mods);
		});

		return window;
	}

	void Engine::onMouseClick(int button, int action, int mods)
	{
		for (int i = 0; i < numScenes; ++i)
		{
			scenes[i].onMouseClick(button, action, mods);
		}
	}

	Engine::~Engine()
	{
		delete[] scenes;
	}

	Engine* Engine::getInstance()
	{
		return instance;
	}
}