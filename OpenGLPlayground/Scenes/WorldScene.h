#pragma once
#include "../IScene.h"
#include <gl/glew.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

class WorldScene : public IScene
{
	GLuint _vao;
	GLuint _shaderProgram;
	glm::mat4 _modelMatrix;
public:
	void init(int screenWidth, int screenHeight) override;
	void run(const GLFWwindow& window) override;
};

