#include "WorldScene.h"
#include <gl/glew.h>
#include "../ShaderUtil.h"
#include "glm/ext.hpp"
#include "../GLLog.h"
#include <GLFW/glfw3.h>
#include "Matrix4x4.h"


#define ONE_DEG_IN_RAD 0.017444444

using namespace Math_ias;

float camSpeed = 1.0f;
float camYawSpeed = 1.0f;
float camYaw = 0.0f;
Vector3f camPos = Vector3f(0.0f, 0.0f, 2.0f);
Quaternionf camRotation = Quaternionf();
float deltaTime;
int lastPressedKey = -1;

void WorldScene::init(GLFWwindow* window, int screenWidth, int screenHeight)
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

	_camera = new Camera(window, camPos, camRotation);

	glUseProgram(_shaderProgram);

	std::cout << _camera->getViewMatrix().toString() << std::endl;
	std::cout << _camera->getProjMatrix().toString() << std::endl;

	_viewMatLocation = glGetUniformLocation(_shaderProgram, "viewMat");
	if (_viewMatLocation != -1)
	{
		glUniformMatrix4fv(_viewMatLocation, 1, GL_FALSE, _camera->getViewMatrix().valuePtr());
	}

	GLuint projMatrixLoc = glGetUniformLocation(_shaderProgram, "projMat");
	if (projMatrixLoc != -1)
	{
		glUniformMatrix4fv(projMatrixLoc, 1, GL_FALSE, _camera->getProjMatrix().valuePtr());
	}
}

void handleInput()
{
	switch (lastPressedKey)
	{
	case GLFW_KEY_A:
		camPos = camPos - Vector3f::right() * camSpeed * deltaTime;
		break;
	/*case GLFW_KEY_D:
		camPos[0] += camSpeed * deltaTime;
		break;
	case GLFW_KEY_UP:
		camPos[1] += camSpeed * deltaTime;
		break;
	case GLFW_KEY_DOWN:
		camPos[1] -= camSpeed * deltaTime;
		break;
	case GLFW_KEY_W:
		camPos[2] -= camSpeed * deltaTime;
		break;
	case GLFW_KEY_S:
		camPos[2] += camSpeed * deltaTime;
		break;
	case GLFW_KEY_LEFT:
		camYaw += camYawSpeed * deltaTime;
		break;
	case GLFW_KEY_RIGHT:
		camYaw -= camYawSpeed * deltaTime;
		break;*/
	}
}

void WorldScene::run(GLFWwindow* window)
{
	static auto prevTime = static_cast<float>(glfwGetTime());

	auto currentTime = static_cast<float>(glfwGetTime());
	deltaTime = currentTime - prevTime;

	glUseProgram(_shaderProgram);

	if (lastPressedKey != -1)
	{
		handleInput();

		/*auto T = Matrix4x4<float>::translation(-camPos[0], -camPos[1], -camPos[2]);
		auto R = Matrix4x4<float>::rotationY(-camYaw);
		auto viewMatrix = R*T;*/

		_camera->setPosition(camPos);

		std::cout << _camera->getViewMatrix().toString() << std::endl;

		glUniformMatrix4fv(_viewMatLocation, 1, GL_FALSE, _camera->getViewMatrix().valuePtr());
	}
	
	glBindVertexArray(_vao);
	glDrawArrays(GL_TRIANGLES, 0, 3);

	prevTime = currentTime;
}

void WorldScene::onWindowSizeChanged(int width, int height)
{
	_camera->calculateProjMatrix();
}

void WorldScene::onKeyEvent(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_REPEAT || action == GLFW_PRESS)
	{
		lastPressedKey = key;
	}
	else if (action == GLFW_RELEASE)
	{
		lastPressedKey = -1;
	}
}

WorldScene::~WorldScene()
{
	delete _camera;
}
