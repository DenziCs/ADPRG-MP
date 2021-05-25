#include "EnemySwarmHandler.h"
#include "GameObjectPool.h"
#include "ObjectPoolHolder.h"
#include "EnemyObject.h"

EnemySwarmHandler::EnemySwarmHandler(int numEnemies, string name) : AComponent(name, Script)
{
	GameObjectPool* enemyPool = new GameObjectPool(ObjectPoolHolder::ENEMY_POOL_TAG, new EnemyObject("enemy", EnemyObject::Walker), numEnemies, NULL);
	enemyPool->initialize();
	ObjectPoolHolder::getInstance()->registerObjectPool(enemyPool);
}

EnemySwarmHandler::~EnemySwarmHandler()
{

}

void EnemySwarmHandler::perform()
{
	/*
	GameObjectPool* enemyPool = ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::ENEMY_POOL_TAG);
	this->ticks += this->deltaTime.asSeconds();

	if (this->ticks > SPAWN_INTERVAL) {
		this->ticks = 0.0f;
		enemyPool->requestPoolable();
	}
	*/
	GameObjectPool* enemyPool = ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::ENEMY_POOL_TAG);
	if (timer <= 0) {
		//enemyPool->releasePoolableBatch();
	}
}