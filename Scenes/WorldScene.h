#pragma once
#include "../IScene.h"
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#include "../Camera.h"

class WorldScene : public IScene
{
	GLuint _vao;
	GLuint _shaderProgram;
	GLint _viewMatLocation;
	GLint _modelMatLocation;
	GLint _colorLocation;
	Matrix4x4f _modelMat;
	Camera * _camera;
	Vector4f * _triangleColor;
public:
	~WorldScene();
	WorldScene() : _camera{ nullptr }, _triangleColor{ nullptr }, _modelMat(Matrix4x4f())
	{

	};
	void init(GLFWwindow* window, int screenWidth, int screenHeight) override;
	void run(GLFWwindow* window) override;
	void onWindowSizeChanged(int width, int height) override;
	void onKeyEvent(GLFWwindow* window, int key, int scancode, int action, int mods) override;
};

