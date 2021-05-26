#pragma once
#include "AComponent.h"
#include"PlayerInputController.h"
#include"BombObject.h"
#include"ActiveBombObject.h"
#include"GameObjectPool.h"
#include"ObjectPoolHolder.h"
#include"Game.h"
#include<iostream>

class PlayerAttack : public AComponent
{
public:
	PlayerAttack(string name);
	~PlayerAttack();
	void perform();
private:
	void setUpPools();

	const float DROP_INTERVAL = 0.8f;
	float ticks = 0.0f;
};