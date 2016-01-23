#include <string>
#include <gl/glew.h>
#include <fstream>
#include <sstream>
#include "GLLog.h"

namespace ShaderUtil
{
	using namespace std;

	class ShaderException : public exception
	{
	public:
		GLuint shaderIndex;


		explicit ShaderException(GLuint shaderIndex)
		{
			this->shaderIndex = shaderIndex;
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

	void printProgramInfoLog(GLuint programIndex)
	{
		int maxLength = 2048;
		int actualLength = 0;
		char log[2048];
		glGetProgramInfoLog(programIndex, maxLength, &actualLength, log);

		stringstream msg;
		msg << "Program info for GL index " << programIndex << ":" << endl << log;
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

			int params = -1;
			glGetProgramiv(p, GL_LINK_STATUS, &params);

			if (params != GL_TRUE)
			{
				stringstream msg;
				msg << "ERROR: Could not link shader GL index " << p;
				glLogErr(msg.str());

				printProgramInfoLog(p);
				return -1;
			}

			return p;
		}
		catch (ShaderException s)
		{
			printShaderInfoLog(s.shaderIndex);

			return -1;
		}
	}

	const char* GL_type_to_string(GLenum type) {
		switch (type) {
		case GL_BOOL: return "bool";
		case GL_INT: return "int";
		case GL_FLOAT: return "float";
		case GL_FLOAT_VEC2: return "vec2";
		case GL_FLOAT_VEC3: return "vec3";
		case GL_FLOAT_VEC4: return "vec4";
		case GL_FLOAT_MAT2: return "mat2";
		case GL_FLOAT_MAT3: return "mat3";
		case GL_FLOAT_MAT4: return "mat4";
		case GL_SAMPLER_2D: return "sampler2D";
		case GL_SAMPLER_3D: return "sampler3D";
		case GL_SAMPLER_CUBE: return "samplerCube";
		case GL_SAMPLER_2D_SHADOW: return "sampler2DShadow";
		default: break;
		}
		return "other";
	}

	// Source: http://antongerdelan.net/opengl/shaders.html
	void printAll(GLuint programIndex) {
		printf("--------------------\nshader programme %i info:\n", programIndex);
		int params = -1;
		glGetProgramiv(programIndex, GL_LINK_STATUS, &params);
		printf("GL_LINK_STATUS = %i\n", params);

		glGetProgramiv(programIndex, GL_ATTACHED_SHADERS, &params);
		printf("GL_ATTACHED_SHADERS = %i\n", params);

		glGetProgramiv(programIndex, GL_ACTIVE_ATTRIBUTES, &params);
		printf("GL_ACTIVE_ATTRIBUTES = %i\n", params);
		for (int i = 0; i < params; i++) {
			char name[64];
			int max_length = 64;
			int actual_length = 0;
			int size = 0;
			GLenum type;
			glGetActiveAttrib(
				programIndex,
				i,
				max_length,
				&actual_length,
				&size,
				&type,
				name
				);
			if (size > 1) {
				for (int j = 0; j < size; j++) {
					char long_name[64];
					sprintf_s(long_name, "%s[%i]", name, j);
					int location = glGetAttribLocation(programIndex, long_name);
					printf("  %i) type:%s name:%s location:%i\n",
						i, GL_type_to_string(type), long_name, location);
				}
			}
			else {
				int location = glGetAttribLocation(programIndex, name);
				printf("  %i) type:%s name:%s location:%i\n",
					i, GL_type_to_string(type), name, location);
			}
		}

		glGetProgramiv(programIndex, GL_ACTIVE_UNIFORMS, &params);
		printf("GL_ACTIVE_UNIFORMS = %i\n", params);
		for (int i = 0; i < params; i++) {
			char name[64];
			int max_length = 64;
			int actual_length = 0;
			int size = 0;
			GLenum type;
			glGetActiveUniform(
				programIndex,
				i,
				max_length,
				&actual_length,
				&size,
				&type,
				name
				);
			if (size > 1) {
				for (int j = 0; j < size; j++) {
					char long_name[64];
					sprintf_s(long_name, "%s[%i]", name, j);
					int location = glGetUniformLocation(programIndex, long_name);
					printf("  %i) type:%s name:%s location:%i\n",
						i, GL_type_to_string(type), long_name, location);
				}
			}
			else {
				int location = glGetUniformLocation(programIndex, name);
				printf("  %i) type:%s name:%s location:%i\n",
					i, GL_type_to_string(type), name, location);
			}
		}

		printProgramInfoLog(programIndex);
	}

	
}