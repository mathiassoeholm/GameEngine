#pragma once

#include "../GameEngine/Component.h"

using namespace GameEngine;

class CustomComponent : public Component
{
public:
	void update(Time& time) override;
	void onInitialize() override;
};