#include "WorldScene.h"
#include <gl/glew.h>
#include "../ShaderUtil.h"
#include "glm/ext.hpp"

glm::mat4 lookAt(glm::vec3 camPos, glm::vec3 targetPos, glm::vec3 up)
{
	glm::mat4 translation(
		1, 0, 0, camPos[0],
		0, 1, 0, camPos[1],
		0, 0, 1, camPos[2],
		0, 0, 0, 1
		);

	auto d = targetPos - camPos;
	auto forward = d / sqrt(d[0]*d[0] + d[1]*d[1] + d[2]*d[2]);

	auto right = cross(forward, up);

	glm::mat4 rotation(
		right[0], right[1], right[2], 0,
		up[0], up[1], up[2], 0,
		-forward[0], -forward[1], -forward[2], 0,
		0, 0, 0, 1
		);

	return rotation*translation;
}

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

	auto viewMatrix = lookAt(
		glm::vec3(0, 0, -2),
		glm::vec3(0.5, 0, 0),
		glm::vec3(0, 1, 0)
		);

	auto CameraMatrix = glm::lookAt(
			glm::vec3(0, 0, -1),
			glm::vec3(0.5, 0, 0),
			glm::vec3(0, 1, 0)
		);

	std::cout << to_string(viewMatrix) << std::endl;

	glUseProgram(_shaderProgram);
	GLuint modelMatrixLoc = glGetUniformLocation(_shaderProgram, "modelMatrix");
	if (modelMatrixLoc != -1)
	{
		glUniformMatrix4fv(modelMatrixLoc, 1, GL_FALSE, value_ptr(_modelMatrix));
	}

	GLuint viewMatrixLoc = glGetUniformLocation(_shaderProgram, "viewMatrix");
	if (modelMatrixLoc != -1)
	{
		glUniformMatrix4fv(viewMatrixLoc, 1, GL_FALSE, value_ptr(CameraMatrix));
	}
}

void WorldScene::run()
{
	glUseProgram(_shaderProgram);
	glBindVertexArray(_vao);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}