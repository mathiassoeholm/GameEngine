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
float camPos[] = {0.0f, 0.0f, 2.0f};
float camYaw = 0.0f;
float deltaTime;
int lastPressedKey = -1;

void WorldScene::init(int screenWidth, int screenHeight)
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

	auto T = translate(glm::mat4(), glm::vec3(-camPos[0], -camPos[1], -camPos[2]));
	auto R = rotate(glm::mat4(), -camYaw, glm::vec3(0, 1, 0));
	auto viewMatrix = R*T;

	_projMatrix = new float[4 * 4]{0};
	calculateProjMatrix(screenWidth, screenHeight);

	glUseProgram(_shaderProgram);

	_viewMatLocation = glGetUniformLocation(_shaderProgram, "viewMat");
	if (_viewMatLocation != -1)
	{
		glUniformMatrix4fv(_viewMatLocation, 1, GL_FALSE, value_ptr(viewMatrix));
	}

	GLuint projMatrixLoc = glGetUniformLocation(_shaderProgram, "projMat");
	if (projMatrixLoc != -1)
	{
		glUniformMatrix4fv(projMatrixLoc, 1, GL_FALSE, _projMatrix);
	}
}

void handleInput()
{
	switch (lastPressedKey)
	{
	case GLFW_KEY_A:
		camPos[0] -= camSpeed * deltaTime;
		break;
	case GLFW_KEY_D:
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
		break;
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

		auto T = translate(glm::mat4(), glm::vec3(-camPos[0], -camPos[1], -camPos[2]));
		auto R = rotate(glm::mat4(), -camYaw, glm::vec3(0, 1, 0));
		auto viewMatrix = R*T;



		glUniformMatrix4fv(_viewMatLocation, 1, GL_FALSE, value_ptr(viewMatrix));
	}
	
	glBindVertexArray(_vao);
	glDrawArrays(GL_TRIANGLES, 0, 3);

	prevTime = currentTime;
}

void WorldScene::onWindowSizeChanged(int width, int height)
{
	calculateProjMatrix(width, height);
}

void WorldScene::onKeyEvent(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	std::cout << key << std::endl;

	if (action == GLFW_REPEAT || action == GLFW_PRESS)
	{
		lastPressedKey = key;
	}
	else if (action == GLFW_RELEASE)
	{
		lastPressedKey = -1;
	}
}

void WorldScene::calculateProjMatrix(int width, int height)
{
	printf("%d\n", width);

	float near = 0.1f;
	float far = 100.0f;
	float fov = 67.0f * static_cast<float>(ONE_DEG_IN_RAD);
	float aspect = static_cast<float>(width) / static_cast<float>(height);


	float range = tan(fov * 0.5f) * near;
	float Sx = (2.0f * near) / (range * aspect + range * aspect);
	float Sy = near / range;
	float Sz = -(far + near) / (far - near);
	float Pz = -(2.0f * far * near) / (far - near);

	_projMatrix[0] = Sx;
	_projMatrix[5] = Sy;
	_projMatrix[10] = Sz;
	_projMatrix[11] = -1;
	_projMatrix[14] = Pz;
}

WorldScene::~WorldScene()
{
	delete _projMatrix;
}
