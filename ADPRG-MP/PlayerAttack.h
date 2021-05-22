#pragma once
#include "AComponent.h"
#include"PlayerInputController.h"
#include"Projectile.h"
#include"GameObjectPool.h"
#include"ObjectPoolHolder.h"
#include<iostream>

class PlayerAttack : public AComponent
{
public:
	PlayerAttack(string name) : AComponent(name, Script) {}
	~PlayerAttack();
	void setUpPool(int numRounds);
	void perform();
private:
	const float FIRE_INTERVAL = 0.1f;
	float ticks = 0.0f;
};