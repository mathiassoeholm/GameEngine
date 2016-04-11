#pragma once

#include "Scene.h"
#include <string>
#include <GLFW/glfw3.h>

namespace GameEngine
{
	class Engine
	{
		std::string gameTitle;
		Scene* scenes;
		GLint numScenes;
	public:
		Engine(std::string gameTitle, Scene* scenes, GLint numScenes);
		~Engine();
		static Engine* getInstance();
	private:
		bool initGLFW();
		GLFWwindow *createWindow(bool fullScreen);
		void onMouseClick(int button, int action, int mods);
	};
}

