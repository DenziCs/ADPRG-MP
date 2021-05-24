#pragma once
#include"AGameObject.h"

class ContactResolver {
public:
	enum ContactType {
		PlayerBomb = 0,
		PlayerEnemy = 1,
		EnemyBomb = 2,
		SoftblockBomb = 3
	};

	ContactResolver() {};
	ContactResolver(AGameObject*, AGameObject*, ContactType);
	void resolve();

	AGameObject* objects[2];
	ContactType contactType;
};