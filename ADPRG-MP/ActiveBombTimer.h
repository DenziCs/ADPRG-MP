#pragma once
#include "AComponent.h"
#include"APoolable.h"
#include"ObjectPoolHolder.h"
#include"Game.h"
#include<iostream>

class ActiveBombTimer : public AComponent
{
public:
	ActiveBombTimer(string name);
	~ActiveBombTimer();
	void perform();
	void reset();
private:
	float timer = 0.8f;
};