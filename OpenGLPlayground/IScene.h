#pragma once

#include <gl/glew.h>
#include <GLFW/glfw3.h>

class IScene
{
public:
	virtual ~IScene() {}
	virtual void init(GLFWwindow* window, int screenHeight, int screenWidth) = 0;
	virtual void run(GLFWwindow* window) = 0;
	virtual void onKeyEvent(GLFWwindow* window, int key, int scancode, int action, int mods){};
	virtual void onWindowSizeChanged(int width, int height){};
};