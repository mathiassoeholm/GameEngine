#include "WorldScene.h"
#include <gl/glew.h>
#include "../ShaderUtil.h"
#include "glm/ext.hpp"

void WorldScene::init()
{
	float points[] =
	{
		0.0f, 0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f
	};

	GLuint vbo = 0;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), points, GL_STATIC_DRAW);

	_vao = 0;
	glGenVertexArrays(1, &_vao);
	glBindVertexArray(_vao);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

	_shaderProgram = ShaderUtil::createProgram("Shaders/WorldVertexShader.vert", "Shaders/FragmentShader2.frag");

	_modelMatrix = glm::mat4(
		1, 0, 0, 0.5,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
		);

	glUseProgram(_shaderProgram);
	GLuint modelMatrixLoc = glGetUniformLocation(_shaderProgram, "modelMatrix");
	if (modelMatrixLoc != -1)
	{
		glUniformMatrix4fv(modelMatrixLoc, 1, GL_FALSE, value_ptr(_modelMatrix));
	}
}

void WorldScene::run()
{
	glUseProgram(_shaderProgram);
	glBindVertexArray(_vao);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}