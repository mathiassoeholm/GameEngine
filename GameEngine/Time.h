#pragma once

#include <GL/glew.h>

namespace GameEngine
{
	class Time
	{
		GLdouble timeScale;
		GLdouble elapsedTime;
		GLdouble deltaTime;
		GLdouble unscaledDeltaTime;
		GLdouble lastGLFWTime;
	public:
		Time();
		GLdouble getElapsedTime();
		GLdouble getDeltaTime();
		GLdouble getUnscaledDeltaTime();
		GLdouble getTimeScale();
		void setTimeScale(GLdouble value);
		void update();
	};
}
