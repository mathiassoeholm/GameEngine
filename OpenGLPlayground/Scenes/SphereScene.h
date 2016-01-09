#pragma once
#include "../IScene.h"
#include <gl/glew.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#include "../Camera.h"
#include "../SolidSphere.h"

class SphereScene : public IScene
{
	SolidSphere _sphere;
	GLuint _shaderProgram;
public:
	SphereScene() : _sphere(1, 12, 24)
	{
		
	}
	void init(GLFWwindow* window, int screenWidth, int screenHeight) override;
	void run(GLFWwindow* window) override;
	void onWindowSizeChanged(int width, int height) override;
	void onKeyEvent(GLFWwindow* window, int key, int scancode, int action, int mods) override;
};

