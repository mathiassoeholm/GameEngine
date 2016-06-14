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
		GLdouble getElapsedTime() const;
		GLdouble getDeltaTime()  const;
		GLdouble getUnscaledDeltaTime() const;
		GLdouble getTimeScale() const;
		void setTimeScale(GLdouble value);
		void update();
	};
}
