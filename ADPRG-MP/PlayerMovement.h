
#pragma once
#include "AComponent.h"
class PlayerMovement : public AComponent
{
public:
	PlayerMovement(string name);
	~PlayerMovement();

	void perform();
	// bool hasCollided();
private:
	const float SPEED_MULTIPLIER = 60.0f;
};