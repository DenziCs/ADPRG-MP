#pragma once
#include "APoolable.h"

class SoftBlockObject : public APoolable
{
public:
	SoftBlockObject(string name);
	void initialize();
	sf::FloatRect getGlobalBounds();
	void onRelease() {}
	void onActivate();
	APoolable* clone();
private:
	sf::Sprite* sprite;
	int counter = 0;
};