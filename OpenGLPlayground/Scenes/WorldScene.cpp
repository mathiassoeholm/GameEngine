#include "WorldScene.h"
#include <gl/glew.h>
#include "../ShaderUtil.h"
#include "glm/ext.hpp"
#include "../GLLog.h"

#define ONE_DEG_IN_RAD 0.017444444
#include <GLFW/glfw3.h>

float camSpeed = 1.0f;
float camYawSpeed = 1.0f;
float camPos[] = {0.0f, 0.0f, 2.0f};
float camYaw = 0.0f;

glm::mat4 lookAt(glm::vec3 camPos, glm::vec3 targetPos, glm::vec3 up)
{
	glm::mat4 translation(
		1, 0, 0, -camPos[0],
		0, 1, 0, -camPos[1],
		0, 0, 1, -camPos[2],
		0, 0, 0, 1
		);

	auto forward = normalize(targetPos - camPos);

	auto right = normalize(cross(forward, up));

	glm::mat4 rotation(
		right[0], up[0], -forward[0], 0,
		right[1], up[1], -forward[1], 0,
		right[2], up[2], -forward[2], 0,
		0, 0, 0, 1
		);

	return transpose(rotation*translation);
}

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

	_modelMatrix = glm::mat4(
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
		);

	auto T = translate(glm::mat4(), glm::vec3(-camPos[0], -camPos[1], -camPos[2]));
	auto R = rotate(glm::mat4(), -camYaw, glm::vec3(0, 1, 0));
	auto viewMatrix = R*T;

	float near = 0.1f;
	float far = 100.0f;
	float fov = 67.0f * ONE_DEG_IN_RAD;
	float aspect = static_cast<float>(screenWidth) / static_cast<float>(screenHeight);


	float range = tan(fov * 0.5f) * near;
	float Sx = (2.0f * near) / (range * aspect + range * aspect);
	float Sy = near / range;
	float Sz = -(far + near) / (far - near);
	float Pz = -(2.0f * far * near) / (far - near);

	float projMat[] = {
		Sx, 0, 0, 0,
		0, Sy, 0, 0,
		0, 0, Sz, -1,
		0, 0, Pz, 0
	};

	glUseProgram(_shaderProgram);
	//GLuint modelMatrixLoc = glGetUniformLocation(_shaderProgram, "modelMat");
	//if (modelMatrixLoc != -1)
	//{
	//	glUniformMatrix4fv(modelMatrixLoc, 1, GL_FALSE, value_ptr(_modelMatrix));
	//}

	_viewMatLocation = glGetUniformLocation(_shaderProgram, "viewMat");
	if (_viewMatLocation != -1)
	{
		glUniformMatrix4fv(_viewMatLocation, 1, GL_FALSE, value_ptr(viewMatrix));
	}

	GLuint projMatrixLoc = glGetUniformLocation(_shaderProgram, "projMat");
	if (projMatrixLoc != -1)
	{
		glUniformMatrix4fv(projMatrixLoc, 1, GL_FALSE, projMat);
	}
}

void WorldScene::run(GLFWwindow* window)
{
	static auto prevTime = static_cast<float>(glfwGetTime());

	auto currentTime = static_cast<float>(glfwGetTime());
	auto deltaTime = currentTime - prevTime;

	bool camMoved = false;
	if (glfwGetKey(window, GLFW_KEY_A)) {
		camPos[0] -= camSpeed * deltaTime;
		camMoved = true;
	}
	if (glfwGetKey(window, GLFW_KEY_D)) {
		camPos[0] += camSpeed * deltaTime;
		camMoved = true;
	}
	if (glfwGetKey(window, GLFW_KEY_PAGE_UP)) {
		camPos[1] += camSpeed * deltaTime;
		camMoved = true;
	}
	if (glfwGetKey(window, GLFW_KEY_PAGE_DOWN)) {
		camPos[1] -= camSpeed * deltaTime;
		camMoved = true;
	}
	if (glfwGetKey(window, GLFW_KEY_W)) {
		camPos[2] -= camSpeed * deltaTime;
		camMoved = true;
	}
	if (glfwGetKey(window, GLFW_KEY_S)) {
		camPos[2] += camSpeed * deltaTime;
		camMoved = true;
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT)) {
		camYaw += camYawSpeed * deltaTime;
		camMoved = true;
	}
	if (glfwGetKey(window, GLFW_KEY_RIGHT)) {
		camYaw -= camYawSpeed * deltaTime;
		camMoved = true;
	}

	glUseProgram(_shaderProgram);

	if (camMoved)
	{
		auto T = translate(glm::mat4(), glm::vec3(-camPos[0], -camPos[1], -camPos[2]));
		auto R = rotate(glm::mat4(), -camYaw, glm::vec3(0, 1, 0));
		auto viewMatrix = R*T;

		glUniformMatrix4fv(_viewMatLocation, 1, GL_FALSE, value_ptr(viewMatrix));
	}

	
	glBindVertexArray(_vao);
	glDrawArrays(GL_TRIANGLES, 0, 3);

	prevTime = currentTime;
}