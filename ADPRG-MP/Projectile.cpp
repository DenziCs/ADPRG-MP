#include "Projectile.h"

void Projectile::initialize()
{
	//assign texture
	sf::Sprite* sprite = new sf::Sprite();
	sprite->setTexture(*TextureManager::getInstance()->getTexture("bullet"));
	sf::Vector2u textureSize = sprite->getTexture()->getSize();
	sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);

	ProjectileMovement* movement = new ProjectileMovement("ItsMovement");
	this->attachComponent(movement);

	Renderer* renderer = new Renderer("Bullet");
	renderer->assignDrawable(sprite);
	this->attachComponent(renderer);

	Collider* collider = new Collider("BulletCollider");
	this->attachComponent(collider);
	collider->setCollisionListener(this);
	collider->setLocalBounds(sprite->getLocalBounds());
}

void Projectile::onActivate()
{
	ProjectileMovement* movement = (ProjectileMovement*)this->findComponentByName("ItsMovement");
	movement->reset();

	Collider* collider = (Collider*)this->findComponentByName("BulletCollider");
	PhysicsManager::getInstance()->trackObject(collider);
}

void Projectile::onCollisionEnter(Collider* collider) {
	GameObjectPool* pool = ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::BULLET_POOL_TAG);
	pool->releasePoolable(this);
}

APoolable* Projectile::clone()
{
	APoolable* copyObj = new Projectile(this->name);
	return copyObj;
}