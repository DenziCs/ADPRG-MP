#pragma once
#include "AComponent.h"

class EnemySwarmHandler : public AComponent
{
public:
	EnemySwarmHandler(int level, string name);
	~EnemySwarmHandler();
	void perform();

private:
	float timer = 10.f;
	bool timeUp = false;
};