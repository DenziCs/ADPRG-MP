#include "PlayerAttack.h"

PlayerAttack::PlayerAttack(string name) : AComponent(name, Script) {
	this->setUpPools();
}

PlayerAttack::~PlayerAttack() {
	AComponent::~AComponent();
}

void PlayerAttack::setUpPools() {
	GameObjectPool* bombPool = new GameObjectPool(ObjectPoolHolder::BOMB_POOL_TAG, new BombObject("bomb"), 2, NULL);
	bombPool->initialize();
	ObjectPoolHolder::getInstance()->registerObjectPool(bombPool);

	GameObjectPool* activePool = new GameObjectPool(ObjectPoolHolder::EXPLOSION_POOL_TAG, new ActiveBombObject("activebomb"), 18, NULL);
	activePool->initialize();
	ObjectPoolHolder::getInstance()->registerObjectPool(activePool);
}

void PlayerAttack::perform() {
	PlayerInputController* inputController = (PlayerInputController*)this->getOwner()->getComponentsOfType(ComponentType::Input)[0];
	GameObjectPool* bombPool = ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::BOMB_POOL_TAG);

	if (inputController->isDropping()) {
		this->ticks += this->deltaTime.asSeconds();

		if (this->ticks > DROP_INTERVAL) {
			this->ticks = 0.0f;
			BombObject* bomb = (BombObject*)bombPool->requestPoolable();
			sf::Vector2f spawnPoint = this->getOwner()->getTransformable()->getPosition();
			spawnPoint.x = (int(spawnPoint.x / Game::TILE_SIZE)) * Game::TILE_SIZE * 1.5;
			spawnPoint.y = (int(spawnPoint.y / Game::TILE_SIZE)) * Game::TILE_SIZE * 1.5;
			bomb->getTransformable()->setPosition(spawnPoint);
		}
	}
}