#include <string>
#include <gl/glew.h>
#include <fstream>
#include <sstream>

namespace ShaderUtil
{
	using namespace std;

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

	GLuint createProgram(const string& vertexShader, const string& fragmentShader)
	{
		GLuint v = createShader(vertexShader, GL_VERTEX_SHADER);
		GLuint f = createShader(fragmentShader, GL_FRAGMENT_SHADER);
		GLuint p = glCreateProgram();

		glAttachShader(p, v);
		glAttachShader(p, f);
		glLinkProgram(p);

		return p;
	}
}