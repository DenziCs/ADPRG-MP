#pragma once
#include"AGameObject.h"

class ContactResolver {
public:
	enum ContactType {
		PlayerBomb = 0,
		PlayerEnemy = 1,
		PlayerPowerup = 2,
		EnemyBomb = 3,
		SoftblockBomb = 4
	};

	ContactResolver() {};
	ContactResolver(AGameObject*, AGameObject*, ContactType);
	void resolve();

	AGameObject* objects[2];
	ContactType contactType;
};