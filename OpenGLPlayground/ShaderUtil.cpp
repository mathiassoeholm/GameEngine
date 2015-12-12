#include <string>
#include <gl/glew.h>
#include <fstream>
#include <sstream>
#include "GLLog.h""

namespace ShaderUtil
{
	using namespace std;

	class ShaderException : public exception
	{
		GLuint _shaderIndex;

	public:
		explicit ShaderException(GLuint shaderIndex)
		{
			_shaderIndex = shaderIndex;
		}

		GLuint getShaderIndex()
		{
			return _shaderIndex;
		}
	};

	void printShaderInfoLog(GLuint shaderIndex)
	{
		int maxLength = 2048;
		int actualLength = 0;
		char log[2048];
		glGetShaderInfoLog(shaderIndex, maxLength, &actualLength, log);

		stringstream msg;
		msg << "Shader info for GL index " << shaderIndex << ":" << endl << log;
		glLogErr(msg.str());
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

		GLuint shaderIndex = glCreateShader(shaderType);
		glShaderSource(shaderIndex, 1, &source, nullptr);
		glCompileShader(shaderIndex);

		int params = -1;
		glGetShaderiv(shaderIndex, GL_COMPILE_STATUS, &params);

		if (params != GL_TRUE)
		{
			stringstream msg;
			msg << "ERROR: GL shader index " << shaderIndex << " did not compile";
			glLogErr(msg.str());
			throw ShaderException(shaderIndex);
		}

		return shaderIndex;
	}

	GLuint createProgram(const string& vertexShader, const string& fragmentShader)
	{
		try
		{
			GLuint v = createShader(vertexShader, GL_VERTEX_SHADER);
			GLuint f = createShader(fragmentShader, GL_FRAGMENT_SHADER);

			GLuint p = glCreateProgram();

			glAttachShader(p, v);
			glAttachShader(p, f);
			glLinkProgram(p);

			return p;
		}
		catch (ShaderException s)
		{
			printShaderInfoLog(s.getShaderIndex());

			return -1;
		}
	}
}