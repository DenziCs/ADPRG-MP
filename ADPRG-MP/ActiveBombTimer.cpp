#include "ActiveBombTimer.h"
#include"GameObjectManager.h"

ActiveBombTimer::ActiveBombTimer(string name) : AComponent(name, Script) {
	this->reset();
}

ActiveBombTimer::~ActiveBombTimer()
{
	AComponent::~AComponent();
}

void ActiveBombTimer::perform()
{
	this->timer -= this->deltaTime.asSeconds();

	if (timer <= 0) {
		ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::BOMB_POOL_TAG)->releasePoolable((APoolable*)this->getOwner());
	}
}

void ActiveBombTimer::reset() {
	this->timer = 0.8f;
}