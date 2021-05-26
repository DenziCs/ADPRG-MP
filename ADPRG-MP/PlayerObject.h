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
};