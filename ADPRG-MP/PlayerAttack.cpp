#include "PlayerAttack.h"

PlayerAttack::~PlayerAttack() {
	AComponent::~AComponent();
}

void PlayerAttack::setUpPool(int numRounds) {
	GameObjectPool* bulletPool = new GameObjectPool(ObjectPoolHolder::BULLET_POOL_TAG, new Projectile("bullet"), numRounds, NULL);
	bulletPool->initialize();
	ObjectPoolHolder::getInstance()->registerObjectPool(bulletPool);
}

void PlayerAttack::perform() {
	PlayerInputController* inputController = (PlayerInputController*)this->getOwner()->getComponentsOfType(ComponentType::Input)[0];
	GameObjectPool* bulletPool = ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::BULLET_POOL_TAG);

	if (inputController->isFiring()) {
		this->ticks += this->deltaTime.asSeconds();

		if (this->ticks > FIRE_INTERVAL) {
			this->ticks = 0.0f;
			Projectile* bullet = (Projectile*)bulletPool->requestPoolable();
			sf::Vector2f spawnPoint = this->getOwner()->getTransformable()->getPosition();
			spawnPoint.y -= 20;
			bullet->getTransformable()->setPosition(spawnPoint);
		}
	}
}