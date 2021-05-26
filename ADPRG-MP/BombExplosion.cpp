#include "BombExplosion.h"
#include"GameObjectManager.h"

BombExplosion::BombExplosion(string name) : AComponent(name, Script) {
	this->reset();
}

BombExplosion::~BombExplosion()
{
	AComponent::~AComponent();
}

bool BombExplosion::hasCollided(ActiveBombObject* explosion) {
	sf::FloatRect bounds = explosion->getGlobalBounds();

	vector<AGameObject*> toSearch = GameObjectManager::getInstance()->getObjectsOfType(AGameObject::Hardblock);
	for (int i = 0; i < toSearch.size(); i++) {
		if (bounds.intersects(toSearch[i]->getGlobalBounds())) {
			toSearch.clear();
			return true;
		}
	}

	toSearch.clear();
	return false;
}

void BombExplosion::explode() {
	sf::Vector2f spawnpoint = this->getOwner()->getTransformable()->getPosition();
	GameObjectPool* activePool = ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::EXPLOSION_POOL_TAG);

	ActiveBombObject* bomb = (ActiveBombObject*)activePool->requestPoolable();
	bomb->setPosition(spawnpoint.x, spawnpoint.y);

	for (int i = 1; i <= range; i++) {
		// Upwards
		ActiveBombObject* bomb1 = (ActiveBombObject*)activePool->requestPoolable();
		bomb1->setPosition(spawnpoint.x, spawnpoint.y - i * Game::TILE_SIZE);
		if(hasCollided(bomb1))
			ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::EXPLOSION_POOL_TAG)->releasePoolable(bomb1);

		// To the right
		ActiveBombObject* bomb2 = (ActiveBombObject*)activePool->requestPoolable();
		bomb2->setPosition(spawnpoint.x + i * Game::TILE_SIZE, spawnpoint.y);
		if (hasCollided(bomb2))
			ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::EXPLOSION_POOL_TAG)->releasePoolable(bomb2);

		// Downwards
		ActiveBombObject* bomb3 = (ActiveBombObject*)activePool->requestPoolable();
		bomb3->setPosition(spawnpoint.x, spawnpoint.y + i * Game::TILE_SIZE);
		if (hasCollided(bomb3))
			ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::EXPLOSION_POOL_TAG)->releasePoolable(bomb3);

		// To the left
		ActiveBombObject* bomb4 = (ActiveBombObject*)activePool->requestPoolable();
		bomb4->setPosition(spawnpoint.x - i * Game::TILE_SIZE, spawnpoint.y);
		if (hasCollided(bomb4))
			ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::EXPLOSION_POOL_TAG)->releasePoolable(bomb4);
	}
}

void BombExplosion::perform()
{
	this->timer -= this->deltaTime.asSeconds();

	if (timer <= 0) {
		this->explode();
		ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::BOMB_POOL_TAG)->releasePoolable((APoolable*)this->getOwner());
	}
}

void BombExplosion::reset() {
	this->timer = 2.f;
}