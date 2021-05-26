#pragma once
#include "AGameObject.h"
#include"PhysicsManager.h"

class EnemyObject : public AGameObject
{
public:
	enum EnemyType {
		Walker = 0,
		Runner = 1
	};

	EnemyObject(string name, EnemyType type);
	void initialize();
	sf::FloatRect getGlobalBounds();
	EnemyType enemyType;
private:
	sf::Sprite* sprite;
};