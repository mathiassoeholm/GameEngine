#pragma once

#include "Component.h"

namespace GameEngine
{
	class MeshRenderer : public Component
	{
		void update() override;
		int getOrder() const override;
	};
}
