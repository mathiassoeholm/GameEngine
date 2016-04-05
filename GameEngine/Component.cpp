#include "Component.h"

namespace GameEngine
{
	void Component::setEnabled(bool value)
	{
		enabled = value;
	}

	bool Component::getEnabled()
	{
		return enabled;
	}
}