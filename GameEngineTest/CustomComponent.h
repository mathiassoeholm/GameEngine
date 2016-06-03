#pragma once

#include "../GameEngine/Component.h"
#include "../GameEngine/Time.h"

using namespace GameEngine;

class CustomComponent : public Component
{
	Time* time;
public:
	void update(Time& time) override;
	void onInitialize() override;
	void onKey(int key) override;
};