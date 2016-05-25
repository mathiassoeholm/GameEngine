#include "Engine.h"
#include <iostream>

namespace GameEngine
{
	const static int DEFAULT_SCREEN_WIDTH = 768;
	const static int DEFAULT_SCREEN_HEIGHT = 768;

	Engine* Engine::instance = nullptr;

	Engine::Engine(std::string gameTitle, Scene *scenes, GLint numScenes) :
		gameTitle (gameTitle),
		scenes (scenes),
		numScenes(numScenes),
		window (nullptr),
		windowWidth(DEFAULT_SCREEN_WIDTH),
		windowHeight(DEFAULT_SCREEN_HEIGHT),
		time(Time())
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

		glewExperimental = GL_TRUE;
		glewInit();

		glEnable(GL_DEPTH_TEST);

		for (int i = 0; i < numScenes; ++i)
		{
			scenes[i].initialize();
		}

		while (!glfwWindowShouldClose(window))
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glViewport(0, 0, windowWidth, windowHeight);

			time.update();

			for (int i = 0; i < numScenes; ++i)
			{
				// TODO: Only update selected scene
				scenes[i].update(time);
			}

			glfwPollEvents();
			glfwSwapBuffers(window);

			if (GLFW_PRESS == glfwGetKey(window, GLFW_KEY_ESCAPE))
			{
				glfwSetWindowShouldClose(window, 1);
			}
		}
	}

	void glfwErrorCallback(int error, const char* description)
	{
		std::cerr << "GLFW ERROR: code " << error << " msg: " << description << std::endl;
	}

	bool Engine::initGLFW()
	{
		glfwSetErrorCallback(glfwErrorCallback);

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

		window = createWindow(false);
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
			glfwSetWindowSizeCallback(window, [=](GLFWwindow* w, int width, int height)
			{
				getInstance()->onWindowSizeChanged(width, height);
			});
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
		glfwTerminate();

		for (int i = 0; i < numScenes; ++i)
		{
			scenes[i].destroyAllGameObjects();
		}

		if(scenes != nullptr)
		{
			delete[] scenes;
		}
	}

	Engine* Engine::getInstance()
	{
		return instance;
	}

	void Engine::onWindowSizeChanged(int width, int height)
	{
		windowHeight = height;
		windowWidth = width;

		for (int i = 0; i < numScenes; ++i)
		{
			scenes[i].onWindowSizeChanged(width, height);
		}
	}
}