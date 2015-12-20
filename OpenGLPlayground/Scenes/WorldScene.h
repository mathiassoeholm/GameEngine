#pragma once
#include "../IScene.h"
#include <gl/glew.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

class WorldScene : public IScene
{
	GLuint _vao;
	GLuint _shaderProgram;
	GLuint _viewMatLocation;
	float * _projMatrix;
public:
	~WorldScene();
	WorldScene() : _projMatrix{ nullptr }
	{

	};
	void init(int screenWidth, int screenHeight) override;
	void run(GLFWwindow* window) override;
	void onWindowSizeChanged(int width, int height) override;
	void onKeyEvent(GLFWwindow* window, int key, int scancode, int action, int mods) override;
private:
	void calculateProjMatrix(int width, int height);
};

