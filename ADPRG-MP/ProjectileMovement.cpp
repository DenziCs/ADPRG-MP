#include "ProjectileMovement.h"

ProjectileMovement::ProjectileMovement(string name) : AComponent(name, Script) {
	this->reset();
}

ProjectileMovement::~ProjectileMovement()
{
	AComponent::~AComponent();
}

void ProjectileMovement::perform()
{
	sf::Transformable* bulletTransformable = this->getOwner()->getTransformable();
	if (bulletTransformable == NULL) {
		cout << "Missing dependency!\n";
		return;
	}

	sf::Vector2f offset(0.0f, 0.0f);
	offset.y -= this->BULLET_SPEED;
	offset *= deltaTime.asSeconds();
	bulletTransformable->move(offset);
	range += offset.y;
	//cout << range << endl;

	if (range <= 0.f) {
		ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::BULLET_POOL_TAG)->releasePoolable((APoolable*)this->getOwner());
	}
}

void ProjectileMovement::reset() {
	this->range = 300.f;
}