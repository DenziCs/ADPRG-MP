#pragma once
#include "APoolable.h"
#include"Collider.h"
#include"PhysicsManager.h"

class EnemyAirplane : public APoolable, public CollisionListener
{
public:
	EnemyAirplane(string name);
	void initialize();
	void onRelease();
	void onActivate();
	void onCollisionEnter(Collider* collider);
	APoolable* clone();

private:
	int counter = 0;
};