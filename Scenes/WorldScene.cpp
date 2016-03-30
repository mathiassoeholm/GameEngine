#include "WorldScene.h"
#include "../ShaderUtil.h"
#include "glm/ext.hpp"
#include "../GLLog.h"
#include "../Vertex.h"
#include "../MeshFactory.h"

#define ONE_DEG_IN_RAD 0.017444444

using namespace Math_ias;

float camSpeed = 1.0f;
float camYawSpeed = 50.0f;
float camYaw = 0.0f;
Vector3f camPos = Vector3f(0.0f, 0.0f, 2.0f);
Quaternionf camRotation = Quaternionf();
float deltaTime;
int lastPressedKey = -1;
float triRotation = 0;

void WorldScene::init(GLFWwindow* window, int screenWidth, int screenHeight)
{
	auto triangle = MeshFactory::createTriangle();

	GLuint verticesVBO = 0;
	glGenBuffers(1, &verticesVBO);
	glBindBuffer(GL_ARRAY_BUFFER, verticesVBO);
	glBufferData(GL_ARRAY_BUFFER, triangle.verticesBufferSize(), triangle.vertices, GL_STATIC_DRAW);

	_vao = 0;
	glGenVertexArrays(1, &_vao);
	glBindVertexArray(_vao);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, verticesVBO);

	// Position
	glVertexAttribPointer(0, triangle.numVertices, GL_FLOAT, GL_FALSE, sizeof(Vertex), nullptr);

	// Normals
	glVertexAttribPointer(1, triangle.numVertices, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void *)3);

	triangle.cleanup();

	_shaderProgram = ShaderUtil::createProgram("Shaders/WorldVertexShader.vert", "Shaders/FragmentShader2.frag");

	_camera = new Camera(window, camPos, camRotation);

	glUseProgram(_shaderProgram);

	std::cout << _camera->getViewMatrix().toString() << std::endl;
	std::cout << _camera->getProjMatrix().toString() << std::endl;

	_viewMatLocation = glGetUniformLocation(_shaderProgram, "viewMat");
	glUniformMatrix4fv(_viewMatLocation, 1, GL_TRUE, _camera->getViewMatrix().valuePtr());

	_modelMatLocation = glGetUniformLocation(_shaderProgram, "modelMat");
	glUniformMatrix4fv(_modelMatLocation, 1, GL_TRUE, _modelMat.valuePtr());

	GLint projMatrixLoc = glGetUniformLocation(_shaderProgram, "projMat");
	glUniformMatrix4fv(projMatrixLoc, 1, GL_TRUE, _camera->getProjMatrix().valuePtr());

	_triangleColor = new Vector4f(1, 0, 0, 1);
	_colorLocation = glGetUniformLocation(_shaderProgram, "color");
	glUniform4fv(_colorLocation, 1, _triangleColor->valuePtr());
}

void handleInput()
{
	switch (lastPressedKey)
	{
	case GLFW_KEY_A:
		camPos = camPos - Vector3f::right() * camSpeed * deltaTime;
		break;
	case GLFW_KEY_D:
		camPos = camPos + Vector3f::right() * camSpeed * deltaTime;
		break;
	case GLFW_KEY_UP:
		camPos = camPos + Vector3f::up() * camSpeed * deltaTime;
		break;
	case GLFW_KEY_DOWN:
		camPos = camPos - Vector3f::up() * camSpeed * deltaTime;
		break;
	case GLFW_KEY_W:
		camPos = camPos - Vector3f::forward() * camSpeed * deltaTime;
		break;
	case GLFW_KEY_S:
		camPos = camPos + Vector3f::forward() * camSpeed * deltaTime;
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

		_camera->setPosition(camPos);
		_camera->setRotation(Quaternionf::fromEuler(0, camYaw, 0));

		glUniformMatrix4fv(_viewMatLocation, 1, GL_TRUE, _camera->getViewMatrix().valuePtr());
	}
	
	glBindVertexArray(_vao);
	glDrawArrays(GL_TRIANGLES, 0, 3);

	triRotation = (float)(sin(currentTime) * 0.5f);
	_modelMat = Matrix4x4f::rotationY(triRotation);
	if (_modelMatLocation != -1)
	{
		glUniformMatrix4fv(_modelMatLocation, 1, GL_TRUE, _modelMat.valuePtr());
	}

	// Plane
	auto planeNormal = Vector3f(0, 0, -1);
	auto d = 0.0f;

	// Ray-plane intersection
	float t = -(_camera->getPosition().dot(planeNormal) + d) / (_camera->mouseRay().dot(planeNormal));
	auto P = _camera->getPosition() + _camera->mouseRay() * t;

	bool hoveringTriangle = false;

	if(abs(P[0]) <= 0.5 && abs(P[1]) <= 0.5)
	{
		if((P[0] < 0 && P[1] <= 2 * P[0] + 0.5)
			|| (P[0] > 0 && P[1] <= -2 * P[0] + 0.5))
		{
			hoveringTriangle = true;
		}
	}

	if(hoveringTriangle)
	{
		_triangleColor = new Vector4f(0, 1, 0, 1);
		if (_colorLocation != -1)
		{
			glUniform4fv(_colorLocation, 1, _triangleColor->valuePtr());
		}
	}
	else
	{
		_triangleColor = new Vector4f(1, 0, 0, 1);
		if (_colorLocation != -1)
		{
			glUniform4fv(_colorLocation, 1, _triangleColor->valuePtr());
		}
	}

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
