#pragma once
#include "../IScene.h"
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#include "../Camera.h"

class HeightMapScene : public IScene
{
	Camera _camera;
	GLuint _vao;
public:
	HeightMapScene();
	void init(GLFWwindow* window, int screenWidth, int screenHeight) override;
	void run(GLFWwindow* window) override;
	void onWindowSizeChanged(int width, int height) override;
	void onKeyEvent(GLFWwindow* window, int key, int scancode, int action, int mods) override;
};