#pragma once

#include "Scene.h"
#include "Time.h"
#include <string>
#include <GLFW/glfw3.h>

namespace GameEngine
{
	class Engine
	{
		static Engine* instance;
		GLFWwindow* window;
		std::string gameTitle;
		Scene* scenes;
		GLint numScenes;
		GLint windowWidth;
		GLint windowHeight;
		Time time;
	public:
		Engine(std::string gameTitle, Scene* scenes, GLint numScenes);
		~Engine();
		static Engine* getInstance();
	private:
		bool initGLFW();
		GLFWwindow *createWindow(bool fullScreen);
		void onMouseClick(int button, int action, int mods);
		void onWindowSizeChanged(int width, int height);
	};
}

