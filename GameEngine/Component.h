#pragma once

namespace GameEngine
{
	class Component
	{
		bool enabled;
	public:
		void setEnabled(bool value);
		bool getEnabled() const;
		virtual void update() {}

		// Components with lower order will run first, default order is 0
		virtual int getOrder() const;

		bool operator<(const Component& other) const;
	};
}