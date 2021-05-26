#pragma once
#include "AComponent.h"
#include "SceneManager.h"

class TransitionUpdate : public AComponent
{
public:
	TransitionUpdate(string, string, float);
	~TransitionUpdate();
	void perform();
private:
	string next;
	float timer;
};