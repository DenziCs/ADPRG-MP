#pragma once
#include "AGameObject.h"

class PillarObject : public AGameObject
{
public:
	PillarObject(string name);
	void initialize();
	sf::FloatRect getGlobalBounds();
private:
	sf::Sprite* sprite;
};