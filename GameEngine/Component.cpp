#include "Component.h"

namespace GameEngine
{
	void Component::setEnabled(bool value)
	{
		enabled = value;
	}

	bool Component::getEnabled() const
	{
		return enabled;
	}

	int Component::getOrder() const
	{
		return 0;
	}

	bool Component::operator<(const Component &other) const
	{
		return getOrder() < other.getOrder();
	}
}