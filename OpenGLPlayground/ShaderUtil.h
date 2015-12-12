#pragma once

#include "gl/glew.h"
#include <iostream>

namespace ShaderUtil
{
	GLuint createProgram(const std::string& vertexShader, const std::string& fragmentShader);
}
