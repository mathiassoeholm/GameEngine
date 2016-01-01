#pragma once
#include "../IScene.h"
#include <gl/glew.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#include "../Camera.h"

class WorldScene : public IScene
{
	GLuint _vao;
	GLuint _shaderProgram;
	GLuint _viewMatLocation;
	Camera * _camera;
public:
	~WorldScene();
	WorldScene() : _camera{ nullptr }
	{

	};
	void init(GLFWwindow* window, int screenWidth, int screenHeight) override;
	void run(GLFWwindow* window) override;
	void onWindowSizeChanged(int width, int height) override;
	void onKeyEvent(GLFWwindow* window, int key, int scancode, int action, int mods) override;
};

