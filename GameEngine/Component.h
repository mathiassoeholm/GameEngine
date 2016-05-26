#pragma once

#include "Time.h"
#include "GameObject.h"

namespace GameEngine
{
	class Component
	{
		bool enabled;

		// The game object that this component is attached to
		GameObject* gameObject;
	public:
		void initialize(GameObject* gameObject);
		GameObject* getGameObject() const;
		void setEnabled(bool value);
		bool getEnabled() const;
		virtual void update(Time& time) {}

		// Components with lower order will run first, default order is 0
		virtual int getOrder() const;

		bool operator<(const Component& other) const;
	};
}