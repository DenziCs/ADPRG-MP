
#pragma once
#include "AGameObject.h"
#include <iostream>

using namespace std;

class PlayerObject : public AGameObject
{
public:
	PlayerObject(string name);
	void initialize();
	sf::FloatRect getGlobalBounds();
private:
	sf::Sprite* sprite;
	/*
	const float SPEED_MULTIPLIER = 300.0f;
	bool moveUp = false;
	bool moveDown = false;
	bool moveLeft = false;
	bool moveRight = false;
	*/
};