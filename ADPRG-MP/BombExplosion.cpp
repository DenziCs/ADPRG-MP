#include "BombExplosion.h"
#include"GameObjectManager.h"

BombExplosion::BombExplosion(string name) : AComponent(name, Script) {
	this->reset();
}

BombExplosion::~BombExplosion()
{
	AComponent::~AComponent();
}

bool BombExplosion::hasCollided(ActiveBombObject* explosion, Direction direction) {
	sf::FloatRect bounds = explosion->getGlobalBounds();

	switch (direction) {
	case Up:
		if (bounds.top <= Game::TILE_SIZE * 3) return true; break;
	case Right:
		if (bounds.left + bounds.width >= Game::WINDOW_WIDTH - Game::TILE_SIZE * 2) return true; break;
	case Down:
		if (bounds.top + bounds.height >= Game::WINDOW_HEIGHT - Game::TILE_SIZE) return true;  break;
	case Left:
		if (bounds.left <= Game::TILE_SIZE) return true; break;
	}

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
		if(hasCollided(bomb1, Up))
			ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::EXPLOSION_POOL_TAG)->releasePoolable(bomb1);

		// To the right
		ActiveBombObject* bomb2 = (ActiveBombObject*)activePool->requestPoolable();
		bomb2->setPosition(spawnpoint.x + i * Game::TILE_SIZE, spawnpoint.y);
		if (hasCollided(bomb2, Right))
			ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::EXPLOSION_POOL_TAG)->releasePoolable(bomb2);

		// Downwards
		ActiveBombObject* bomb3 = (ActiveBombObject*)activePool->requestPoolable();
		bomb3->setPosition(spawnpoint.x, spawnpoint.y + i * Game::TILE_SIZE);
		if (hasCollided(bomb3, Down))
			ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::EXPLOSION_POOL_TAG)->releasePoolable(bomb3);

		// To the left
		ActiveBombObject* bomb4 = (ActiveBombObject*)activePool->requestPoolable();
		bomb4->setPosition(spawnpoint.x - i * Game::TILE_SIZE, spawnpoint.y);
		if (hasCollided(bomb4, Left))
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