#pragma once


#include <GLFW/glfw3.h>

namespace GameEngine
{
	class Keyboard
	{
		bool* keys;
	public:
		Keyboard();
		~Keyboard();
		void setKeyDown(int key);
		void setKeyUp(int key);
		bool isKeyDown(int key) const;
	};
}