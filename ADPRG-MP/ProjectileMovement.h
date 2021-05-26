#pragma once
#include "AComponent.h"
#include"APoolable.h"
#include"ObjectPoolHolder.h"
#include"Game.h"
#include<iostream>

class ProjectileMovement : public AComponent
{
public:
	ProjectileMovement(string name);
	~ProjectileMovement();
	void perform();
	void reset();
private:
	void explode();

	const float BULLET_SPEED = 500.f;
	float range = 300.f;
};