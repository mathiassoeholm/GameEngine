#pragma once
#include "../IScene.h"
#include <gl/glew.h>
#include <glm/glm.hpp>

class WorldScene : public IScene
{
	GLuint _vao;
	GLuint _shaderProgram;
	glm::mat4 _modelMatrix;
public:
	void init() override;
	void run() override;
};
