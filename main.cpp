#include "gl/glew.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include <fstream>
#include "GameEngine/Engine.h"
#include "GameEngine/MeshRenderer.h"
#include "GameEngineTest/TestScene.h"

using namespace std;

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