#pragma once
#include "../IScene.h"
#include <gl/glew.h>

class WorldScene : public IScene
{
	GLuint _vao;
	GLuint _shaderProgram;
public:
	void init() override;
	void run() override;
};

