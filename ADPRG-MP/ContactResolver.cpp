#include "ContactResolver.h"

ContactResolver::ContactResolver(AGameObject* object1, AGameObject* object2, ContactType type) {
	objects[0] = object1;
	objects[1] = object2;
	contactType = type;
}

void ContactResolver::resolve() {
	switch (contactType) {
	case PlayerBomb:
	case PlayerEnemy:
		break;
	case PlayerPowerup:
		break;
	case EnemyBomb:
		break;
	case SoftblockBomb:
		break;
	}
}