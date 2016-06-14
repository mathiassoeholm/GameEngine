#pragma once

#include <GLFW/glfw3.h>
#include <vector>

namespace GameEngine
{
	class Keyboard
	{
		bool* keys;
		std::vector<int> keysPressedThisFrame;
		std::vector<int> keysReleasedThisFrame;
	public:
		Keyboard();
		~Keyboard();
		void setKeyDown(int key);
		void setKeyUp(int key);
		void clearReleasedAndPressed();

		// Returns whether the key was pressed this frame
		bool isKeyPressed(int key) const;

		// Returns whether the key was released this frame
		bool isKeyReleased(int key) const;

		// Returns whether the key is currently down
		bool isKeyDown(int key) const;
	};
}