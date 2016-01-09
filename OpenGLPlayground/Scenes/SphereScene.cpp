#include "SphereScene.h"
#include "../ShaderUtil.h"
#include <GLFW/glfw3.h>

static const int pointsX = 10;
static const int pointsY = 8;


void SphereScene::init(GLFWwindow* window, int screenWidth, int screenHeight)
{
	GLuint vbo = 0;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, _sphere.vertices.size() * sizeof(float), &_sphere.vertices[0], GL_STATIC_DRAW);


	_vao = 0;
	glGenVertexArrays(1, &_vao);
	glBindVertexArray(_vao);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

	_shaderProgram = ShaderUtil::createProgram("Shaders/SphereVertexShader.vert", "Shaders/SphereFragmentShader.frag");
	_camera = new Camera(window, Vector3f(0, 0, 2), Quaternionf());

	GLuint viewMatLocation = glGetUniformLocation(_shaderProgram, "viewMat");
	if (viewMatLocation != -1)
	{
		glUniformMatrix4fv(viewMatLocation, 1, GL_TRUE, _camera->getViewMatrix().valuePtr());
	}

	GLuint projMatrixLoc = glGetUniformLocation(_shaderProgram, "projMat");
	if (projMatrixLoc != -1)
	{
		glUniformMatrix4fv(projMatrixLoc, 1, GL_TRUE, _camera->getProjMatrix().valuePtr());
	}
}

void SphereScene::run(GLFWwindow* window)
{
	glUseProgram(_shaderProgram);

	glBindVertexArray(_vao);
	glDrawElements(GL_QUADS, _sphere.indices.size(), GL_UNSIGNED_SHORT, &_sphere.indices[0]);
}

void SphereScene::onWindowSizeChanged(int width, int height)
{
}

void SphereScene::onKeyEvent(GLFWwindow* window, int key, int scancode, int action, int mods)
{
}
