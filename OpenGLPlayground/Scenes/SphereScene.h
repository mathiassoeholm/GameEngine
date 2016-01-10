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
	Camera * _camera;
	GLuint _vao;
public:
	SphereScene() : _sphere(0.5, 4, 8), _shaderProgram(-1), _camera(nullptr)
	{
		
	}
	void init(GLFWwindow* window, int screenWidth, int screenHeight) override;
	void run(GLFWwindow* window) override;
	void onWindowSizeChanged(int width, int height) override;
	void onKeyEvent(GLFWwindow* window, int key, int scancode, int action, int mods) override;
};

