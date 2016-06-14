#include "Keyboard.h"

namespace GameEngine
{
	Keyboard::Keyboard()
	{
		keys = new bool[GLFW_KEY_LAST];

		for (int i = 0; i < GLFW_KEY_LAST; i++)
		{
			keys[i] = false;
		}
	}

	void Keyboard::setKeyDown(int key)
	{
		keys[key] = true;
	}

	void Keyboard::setKeyUp(int key)
	{
		keys[key] = false;
	}

	bool Keyboard::isKeyDown(int key) const
	{
		return keys[key];
	}

	Keyboard::~Keyboard()
	{
		delete [] keys;
	}
}