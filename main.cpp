#define GLEW_STATIC
#include "gl/glew.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "GLLog.h"
#include "ShaderUtil.h"
#include "Scenes/WarpTest.h"
#include "Scenes/WorldScene.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Matrix4x4.h"
#include "Quaternion.h"
#include "glm/ext.hpp"

using namespace std;
using namespace Math_ias;

int currentWindowWidth = 640;
int currentWindowHeight = 480;
IScene* scene;

void glfwErrorCallback(int error, const char* description)
{
	stringstream log;
	log << "GLFW ERROR: code " << error << " msg: " << description << endl;

	glLogErr(log.str());
}

void onWindowSizeChanged(GLFWwindow* window, int width, int height)
{
	currentWindowWidth = width;
	currentWindowHeight = height;
	scene->onWindowSizeChanged(width, height);
}

void onMouseClick(GLFWwindow* window, int button, int action, int mods)
{

}

GLFWwindow* createWindow(bool fullScreen)
{
	GLFWwindow* window;

	if (fullScreen)
	{
		GLFWmonitor* mon = glfwGetPrimaryMonitor();
		const GLFWvidmode* vmode = glfwGetVideoMode(mon);
		window = glfwCreateWindow(vmode->width, vmode->height, "OpenGL Playground", mon, nullptr);
	}
	else
	{
		window = glfwCreateWindow(currentWindowWidth, currentWindowHeight, "OpenGL Playground", nullptr, nullptr);
		glfwSetWindowSizeCallback(window, onWindowSizeChanged);
	}

	glfwSetMouseButtonCallback(window, onMouseClick);

	return window;
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
		printf(tmp, "opengl @ fps: %.2f", fps);
		glfwSetWindowTitle(window, tmp);
		frameCount = 0;
	}

	frameCount++;
}

void onKeyEvent(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	scene->onKeyEvent(window, key, scancode, action, mods);
}

void mathTest()
{
	using namespace Math_ias;

	auto mat = Matrix4x4f(
		1, 2, 3, 4,
		5, 6, 7, 8,
		9, 10, 11, 12,
		13, 14, 15, 16);

	std::cout << (mat*mat).toString() << std::endl;

	auto matT = mat.transposed();

	std::cout << "----- transposed:" << std::endl << mat.transposed().toString() << std::endl;

	auto test = Matrix4x4f::rotationX(0);

	std::cout << test.toString() << std::endl;

	auto q = Quaternionf(90, 0, 1, 0);

	cout << q.toString() << endl;

	auto q2 = Quaternionf(-90, 0, 1, 0);

	cout << q2.toString() << endl;

	cout << Quaternionf::slerp(q, q2, 0.5f).toString() << endl;

	cout << "From Euler: \n" << Quaternionf::fromEuler(0, 90, 0).getMatrix().toString() << endl;;
}

int main(int argc, char **argv)
{
	//mathTest();

	restartGlLog();

	glLog("Starting GLFW:", glfwGetVersionString());

	glfwSetErrorCallback(glfwErrorCallback);

	if (!glfwInit())
	{
		cerr << "Could not start GLFW3!" << endl;
		return 1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);

	// Disables all functionality that has been flagged for removal in future OpenGL versions
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Anti-Aliasing
	glfwWindowHint(GLFW_SAMPLES, 4);

	GLFWwindow* window = createWindow(false);
	if (!window)
	{
		cerr << "Could not open window with GLFW3!" << endl;
		glfwTerminate();
		return 1;
	}

	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	glewInit();

	glLogParams();

	cout << glGetString(GL_RENDERER) << endl;
	cout << glGetString(GL_VERSION) << endl;

	// Enable culling?
	/*glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);*/
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	scene = new WorldScene();
	scene->init(window, currentWindowWidth, currentWindowHeight);

	glfwSetKeyCallback(window, onKeyEvent);

	while (!glfwWindowShouldClose(window))
	{
		updateFpsCounter(window);

		// wipe the drawing surface clear
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glViewport(0, 0, currentWindowWidth, currentWindowHeight);

		scene->run(window);

		// update other events like input handling
		glfwPollEvents();

		// put the stuff we've been drawing onto the display
		glfwSwapBuffers(window);

		if (GLFW_PRESS == glfwGetKey(window, GLFW_KEY_ESCAPE))
		{
			glfwSetWindowShouldClose(window, 1);
		}
	}

	delete scene;

	glfwTerminate();

	return 0;
}