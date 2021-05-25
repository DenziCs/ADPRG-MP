#pragma once
#include "APoolable.h"

class BombObject : public APoolable
{
public:
	BombObject(string name, bool exploded);
	void initialize();
	sf::FloatRect getGlobalBounds();
	void onRelease() {}
	void onActivate();
	APoolable* clone();
	bool hasExploded;
private:
	sf::Sprite* sprite;
	int counter = 0;
};