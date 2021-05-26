
#pragma once
#include "AComponent.h"
class PlayerMovement : public AComponent
{
public:
	PlayerMovement(string name);
	~PlayerMovement();

	void perform();
private:
	enum Direction {
		Up = 0,
		Right = 1,
		Down = 2,
		Left = 3
	};

	bool hasCollided(Direction direction);
	const float SPEED_MULTIPLIER = 60.0f;
};