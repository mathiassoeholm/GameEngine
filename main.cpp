#include "gl/glew.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "GLLog.h"
#include "glm/ext.hpp"
#include "GameEngine/Engine.h"
#include "GameEngine/MeshRenderer.h"
#include "GameEngineTest/TestScene.h"

using namespace std;

int currentWindowWidth = 640;
int currentWindowHeight = 480;

void glfwErrorCallback(int error, const char* description)
{
	stringstream log;
	log << "GLFW ERROR: code " << error << " msg: " << description << endl;

	glLogErr(log.str());
}

void updateFpsCounter(GLFWwindow* window)
{
	static double previousSeconds = glfwGetTime();
	static int frameCount;
	double currentSeconds = glfwGetTime();
	double elapsedSeconds = currentSeconds - previousSeconds;

	if (elapsedSeconds > 0.25)
	{
		previousSeconds = currentSeconds;
		auto fps = static_cast<double>(frameCount) / elapsedSeconds;
		char tmp[128];
		sprintf(tmp, "opengl @ fps: %.2f", fps);
		glfwSetWindowTitle(window, tmp);
		frameCount = 0;
	}

	frameCount++;
}

void engineTest()
{
	using namespace GameEngine;

	Scene* testScene = new TestScene[1];

	GameEngine::Engine* e = new GameEngine::Engine("Test", testScene, 1);

	delete e;
}

int main(int argc, char **argv)
{
	engineTest();

	return 0;
}