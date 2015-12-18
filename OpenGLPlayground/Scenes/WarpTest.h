#pragma once
#include <gl/glew.h>
#include "../IScene.h"

class WarpTest : public IScene
{
	GLuint _vao;
	GLuint _shaderProgram;
	GLuint _timeLocation;
public:
	void init(int screenWidth, int screenHeight) override;
	void run() override;
};
