#pragma once
#include "APoolable.h"
#include"PhysicsManager.h"

class EnemyObject : public APoolable
{
public:
	enum EnemyType {
		Walker = 0,
		Jogger = 1,
		Runner = 2
	};

	EnemyObject(string name, EnemyType type);
	void initialize();
	sf::FloatRect getGlobalBounds();
	void onRelease() {}
	void onActivate();
	APoolable* clone();
	EnemyType enemyType;
private:
	sf::Sprite* sprite;
	int counter = 0;
};