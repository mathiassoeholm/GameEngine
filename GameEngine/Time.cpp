#include "Time.h"
#include <GLFW/glfw3.h>

namespace GameEngine
{
	Time::Time() : lastGLFWTime(glfwGetTime()), timeScale(1), elapsedTime(0)
	{

	}

	GLdouble Time::getTimeScale()
	{
		return timeScale;
	}

	void Time::setTimeScale(GLdouble value)
	{
		timeScale = value;
	}

	GLdouble Time::getElapsedTime()
	{
		return elapsedTime;
	}

	GLdouble Time::getDeltaTime()
	{
		return deltaTime;
	}

	GLdouble Time::getUnscaledDeltaTime()
	{
		return unscaledDeltaTime;
	}

	void Time::update()
	{
		auto newTime = glfwGetTime();

		unscaledDeltaTime = newTime - lastGLFWTime;
		deltaTime = unscaledDeltaTime/timeScale;
		elapsedTime += deltaTime;
		lastGLFWTime = newTime;
	}
}

