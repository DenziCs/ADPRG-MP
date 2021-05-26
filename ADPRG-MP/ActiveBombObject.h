#pragma once
#include "APoolable.h"

class ActiveBombObject : public APoolable
{
public:
	ActiveBombObject(string name);
	void initialize();
	sf::FloatRect getGlobalBounds();
	void onRelease() {}
	void onActivate();
	APoolable* clone();
private:
	sf::Sprite* sprite;
	float timer = 0.8f;
};