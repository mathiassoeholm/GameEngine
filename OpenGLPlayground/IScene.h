#pragma once

class IScene
{
public:
	virtual ~IScene() {}
	virtual void init(int screenHeight, int screenWidth) = 0;
	virtual void run() = 0;
};