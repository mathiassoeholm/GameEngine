#pragma once
#include <gl/glew.h>

class WarpTest
{
private:
	GLuint _vao;
	GLuint _shaderProgram;
	GLuint _timeLocation;
public:
	void initWarpTest();
	void runWarpTest();
};
