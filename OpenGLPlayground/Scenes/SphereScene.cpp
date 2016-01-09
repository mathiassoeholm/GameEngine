#include "SphereScene.h"
#include "../ShaderUtil.h"
#include <GLFW/glfw3.h>

static const int pointsX = 10;
static const int pointsY = 8;


void SphereScene::init(GLFWwindow* window, int screenWidth, int screenHeight)
{
}

void SphereScene::run(GLFWwindow* window)
{
	int windowWidth, windowHeight;
	glfwGetWindowSize(window, &windowWidth, &windowHeight);

	auto winAspect = static_cast<float>(windowWidth) / static_cast<float>(windowHeight);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, winAspect, 1, 10);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	_sphere.draw(0, 0, -5);
}

void SphereScene::onWindowSizeChanged(int width, int height)
{
}

void SphereScene::onKeyEvent(GLFWwindow* window, int key, int scancode, int action, int mods)
{
}
