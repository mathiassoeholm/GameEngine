#include "Keyboard.h"
#include <algorithm>

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
		keysPressedThisFrame.push_back(key);
	}

	void Keyboard::setKeyUp(int key)
	{
		keys[key] = false;
		keysReleasedThisFrame.push_back(key);
	}

	bool Keyboard::isKeyDown(int key) const
	{
		return keys[key];
	}

	Keyboard::~Keyboard()
	{
		delete [] keys;
	}

	bool Keyboard::isKeyReleased(int key) const
	{
		return std::find(keysReleasedThisFrame.begin(), keysReleasedThisFrame.end(), key) != keysReleasedThisFrame.end();
	}

	bool Keyboard::isKeyPressed(int key) const
	{
		return std::find(keysPressedThisFrame.begin(), keysPressedThisFrame.end(), key) != keysPressedThisFrame.end();
	}

	void Keyboard::clearReleasedAndPressed()
	{
 		keysPressedThisFrame.clear();
		keysReleasedThisFrame.clear();
	}
}