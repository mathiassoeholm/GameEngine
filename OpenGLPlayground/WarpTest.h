#pragma once
#include <gl/glew.h>

class WarpTest
{
private:
	GLuint _vao;
	GLuint _shaderProgram;
public:
	void initWarpTest();
	void runWarpTest();
};
