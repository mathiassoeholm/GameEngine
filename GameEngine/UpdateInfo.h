#pragma once

#include "Time.h"
#include "Keyboard.h"

namespace GameEngine
{
	struct UpdateInfo
	{
		const Time& time;
		const Keyboard& keyboard;

		UpdateInfo(const Time& t, const Keyboard& k) :
			time(t),
			keyboard(k)
		{}
	};
}
