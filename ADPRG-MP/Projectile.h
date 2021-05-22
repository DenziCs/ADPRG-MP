#include "APoolable.h"
#include "Renderer.h"
#include"TextureManager.h"
#include"ProjectileMovement.h"
#include"PhysicsManager.h"
#include"Collider.h"
#include"ObjectPoolHolder.h"
#pragma once

class Projectile : public APoolable, public CollisionListener
{
public:
	Projectile(string name) : APoolable(name), CollisionListener(Bullet) {}
	void initialize();
	void onRelease() {}
	void onActivate();
	void onCollisionEnter(Collider* collider);
	APoolable* clone();
private:
	const float BULLET_SPEED = 500.f;
};