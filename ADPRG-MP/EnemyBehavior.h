
#pragma once
#include "AComponent.h"

class EnemyBehavior : public AComponent
{
public:
	enum EnemyMovementType {
		Vertical = 0,
		Horizontal = 1
	};

	EnemyBehavior(string name, EnemyMovementType type, bool isRunner);
	void perform();
	bool hasCollided();

private:
	float speed;
	// float timer = 5.f;
	EnemyMovementType movementType;
	bool direction = true;
		// denotes direction of movement. true = positive direction, false = negative direction
};