#include "gl/glew.h"
#include "gl/freeglut.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "GLLog.h"

using namespace std;

void glfwErrorCallback(int error, const char* description)
{
	stringstream log;
	log << "GLFW ERROR: code " << error << " msg: " << description << endl;

	glLogErr(log.str());
}

string readFile(const string& fileName)
{
	ifstream t(fileName);
	stringstream buffer;
	buffer << t.rdbuf();

	return buffer.str();
}

GLuint createShader(const string& fileName, GLenum shaderType)
{
	string fileString = readFile(fileName);
	const char* source = fileString.c_str();

	GLuint i = glCreateShader(shaderType);
	glShaderSource(i, 1, &source, nullptr);
	glCompileShader(i);

	return i;
}

GLFWwindow* createWindow(bool fullScreen)
{
	if (fullScreen)
	{
		GLFWmonitor* mon = glfwGetPrimaryMonitor();
		const GLFWvidmode* vmode = glfwGetVideoMode(mon);
		return glfwCreateWindow(vmode->width, vmode->height, "OpenGL Playground", mon, nullptr);
	}
	else
	{
		return glfwCreateWindow(640, 480, "OpenGL Playground", nullptr, nullptr);
	}
}

int main(int argc, char **argv)
{
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

	GLFWwindow* window = createWindow(true);
	if (!window)
	{
		cerr << "Could not open window with GLFW3!" << endl;
		glfwTerminate();
		return 1;
	}

	glfwMakeContextCurrent(window);
	glewExperimental = GL_TRUE;
	glewInit();

	cout << glGetString(GL_RENDERER) << endl;
	cout << glGetString(GL_VERSION) << endl;

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	float quad_points[] = {
		-1, 0, 0,
		-1, -1, 0,
		0, 0, 0,
		0, -1, 0
	};

	GLuint vbo1 = 0;
	glGenBuffers(1, &vbo1);
	glBindBuffer(GL_ARRAY_BUFFER, vbo1);
	glBufferData(GL_ARRAY_BUFFER, 12 * sizeof (float), quad_points, GL_STATIC_DRAW);

	GLuint vao1 = 0;
	glGenVertexArrays(1, &vao1);
	glBindVertexArray(vao1);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo1);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

	float polygon[] = {
		-1, 1, 0,
		0, 0.5, 0,
		1, 1, 0,
		0.5, 0, 0,
		1, -1, 0,
		0, -0.5, 0,
		-1, -1, 0,
		-0.5, 0, 0,
	};

	GLuint vbo2 = 0;
	glGenBuffers(1, &vbo2);
	glBindBuffer(GL_ARRAY_BUFFER, vbo2);
	glBufferData(GL_ARRAY_BUFFER, 24 * sizeof (float), polygon, GL_STATIC_DRAW);

	GLuint vao2 = 0;
	glGenVertexArrays(1, &vao2);
	glBindVertexArray(vao2);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo2);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

	GLuint vertexShader = createShader("Shaders/VertexShader.vert", GL_VERTEX_SHADER);
	GLuint fragmentShader1 = createShader("Shaders/FragmentShader.frag", GL_FRAGMENT_SHADER);
	GLuint fragmentShader2 = createShader("Shaders/FragmentShader2.frag", GL_FRAGMENT_SHADER);

	GLuint shader_program = glCreateProgram();
	glAttachShader(shader_program, fragmentShader1);
	glAttachShader(shader_program, vertexShader);
	glLinkProgram(shader_program);

	GLuint shader_program_2 = glCreateProgram();
	glAttachShader(shader_program_2, fragmentShader2);
	glAttachShader(shader_program_2, vertexShader);
	glLinkProgram(shader_program_2);

	while (!glfwWindowShouldClose(window))
	{
		// wipe the drawing surface clear
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glUseProgram(shader_program_2);
		glBindVertexArray(vao2);
		glDrawArrays(GL_LINE_LOOP, 0, 8);

		glUseProgram(shader_program);
		glBindVertexArray(vao1);
		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

		// update other events like input handling 
		glfwPollEvents();

		// put the stuff we've been drawing onto the display
		glfwSwapBuffers(window);

		if (GLFW_PRESS == glfwGetKey(window, GLFW_KEY_ESCAPE))
		{
			glfwSetWindowShouldClose(window, 1);
		}
	}

	glfwTerminate();

	return 0;
}