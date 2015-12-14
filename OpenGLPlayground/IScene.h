#pragma once

class IScene
{
public:
	virtual ~IScene() {}
	virtual void init() = 0;
	virtual void run() = 0;
};