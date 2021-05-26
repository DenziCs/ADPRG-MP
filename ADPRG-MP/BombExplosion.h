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
	enum Direction {
		Up = 0,
		Right = 1,
		Down = 2,
		Left = 3
	};

	void explode();
	bool hasCollided(ActiveBombObject* explosion, Direction direction);

	float timer = 0.8f;
	int range = 1;
};