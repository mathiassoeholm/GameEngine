#pragma once

namespace GameEngine
{
	class Component
	{
		bool enabled;
	public:
		void setEnabled(bool value);
		bool getEnabled();
	};
}