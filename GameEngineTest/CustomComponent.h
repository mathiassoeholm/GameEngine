#pragma once

#include "../GameEngine/Component.h"
#include "../GameEngine/Time.h"

using namespace GameEngine;

class CustomComponent : public Component
{
public:
	void update(const UpdateInfo& updateInfo) override;
	void onInitialize() override;
};