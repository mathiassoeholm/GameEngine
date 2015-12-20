#pragma once

#include <gl/glew.h>
#include <GLFW/glfw3.h>

class IScene
{
public:
	virtual ~IScene() {}
	virtual void init(int screenHeight, int screenWidth) = 0;
	virtual void run(const GLFWwindow& window) = 0;
};