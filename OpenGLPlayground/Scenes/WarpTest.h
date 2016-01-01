#pragma once
#include <gl/glew.h>
#include "../IScene.h"

class WarpTest : public IScene
{
	GLuint _vao;
	GLuint _shaderProgram;
	GLuint _timeLocation;
	
public:
	void init(GLFWwindow* window, int screenWidth, int screenHeight) override;
	void run(GLFWwindow* window) override;
};
