#pragma once
#include "AComponent.h"

class TimerUpdate : public AComponent
{
public:
	TimerUpdate(string name, float timer) : AComponent(name, Script) { this->timer = timer;  }
	~TimerUpdate();
	void perform();
private:
	float timer;
};