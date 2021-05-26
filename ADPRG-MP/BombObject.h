#pragma once
#include "APoolable.h"

class BombObject : public APoolable
{
public:
	BombObject(string name);
	void initialize();
	sf::FloatRect getGlobalBounds();
	void onRelease() {}
	void onActivate();
	APoolable* clone();
private:
	sf::Sprite* sprite;
};