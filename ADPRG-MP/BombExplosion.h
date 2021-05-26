#pragma once
#include "AComponent.h"
#include"APoolable.h"
#include"ObjectPoolHolder.h"
#include"Game.h"
#include"ActiveBombObject.h"
#include<iostream>

class BombExplosion : public AComponent
{
public:
	BombExplosion(string name);
	~BombExplosion();
	void perform();
	void reset();
private:
	void explode();
	bool hasCollided(ActiveBombObject* explosion);

	float timer = 0.8f;
	int range = 1;
};