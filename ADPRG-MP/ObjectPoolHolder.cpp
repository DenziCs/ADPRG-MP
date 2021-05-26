
#include "ObjectPoolHolder.h"

string ObjectPoolHolder::BOMB_POOL_TAG = "BombPool";
string ObjectPoolHolder::EXPLOSION_POOL_TAG = "ExplosionPool";

ObjectPoolHolder* ObjectPoolHolder::sharedInstance = NULL;

ObjectPoolHolder* ObjectPoolHolder::getInstance()
{
	if (sharedInstance == NULL) {
		sharedInstance = new ObjectPoolHolder();
	}

	return sharedInstance;
}

void ObjectPoolHolder::registerObjectPool(GameObjectPool* pool)
{
	this->poolMap[pool->getTag()] = pool;
}

void ObjectPoolHolder::unregisterObjectPool(GameObjectPool* pool)
{
	this->poolMap.erase(pool->getTag());
	delete pool;
}

GameObjectPool* ObjectPoolHolder::getPool(string tag)
{
	return this->poolMap[tag];
}