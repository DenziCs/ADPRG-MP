#pragma once
#include "AGameObject.h"

class Collider;
class CollisionListener {

public:
	enum ColliderType {
		Bullet = 0,
		Enemy = 1
	};

	virtual ~CollisionListener() {}
	virtual void onCollisionEnter(Collider* collider) = 0;

	ColliderType colliderType;
protected:
	CollisionListener(ColliderType type) { this->colliderType = type; }
};