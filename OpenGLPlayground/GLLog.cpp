#include "GLLog.h"
#include <fstream>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <gl/glew.h>
#include <sstream>
using namespace std;

bool restartGlLog()
{
	fstream file(GL_LOG_FILE, ofstream::out | ofstream::trunc);

	if (!file.good())
	{
		cerr << "ERROR: could not open gl log file for writing!" << endl;
		return false;
	}

	struct tm timeinfo;
	auto now = time(nullptr);
	localtime_s(&timeinfo, &now);

	file << "local time " << put_time(&timeinfo, "%d-%m-%Y %H-%M-%S") << endl;
	file.close();

	return true;
}

void glLogParams()
{
	GLenum params[] = {
		GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS,
		GL_MAX_CUBE_MAP_TEXTURE_SIZE,
		GL_MAX_DRAW_BUFFERS,
		GL_MAX_FRAGMENT_UNIFORM_COMPONENTS,
		GL_MAX_TEXTURE_IMAGE_UNITS,
		GL_MAX_TEXTURE_SIZE,
		GL_MAX_VARYING_FLOATS,
		GL_MAX_VERTEX_ATTRIBS,
		GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS,
		GL_MAX_VERTEX_UNIFORM_COMPONENTS,
		GL_MAX_VIEWPORT_DIMS
	};
	const char* names[] = {
		"GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS",
		"GL_MAX_CUBE_MAP_TEXTURE_SIZE",
		"GL_MAX_DRAW_BUFFERS",
		"GL_MAX_FRAGMENT_UNIFORM_COMPONENTS",
		"GL_MAX_TEXTURE_IMAGE_UNITS",
		"GL_MAX_TEXTURE_SIZE",
		"GL_MAX_VARYING_FLOATS",
		"GL_MAX_VERTEX_ATTRIBS",
		"GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS",
		"GL_MAX_VERTEX_UNIFORM_COMPONENTS",
		"GL_MAX_VIEWPORT_DIMS"
	};
	glLog("GL Context Params:");

	for (int i = 0; i < 10; i++)
	{
		int v = 0;
		glGetIntegerv(params[i], &v);
		stringstream msg;
		msg << names[i] << " " << v;
		glLog(msg.str());
	}
	glLog("-----------------------------");
}

