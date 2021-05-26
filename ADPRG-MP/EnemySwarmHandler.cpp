#include "EnemySwarmHandler.h"
#include "GameObjectManager.h"
#include "ObjectPoolHolder.h"
#include "EnemyObject.h"

EnemySwarmHandler::EnemySwarmHandler(int level, string name) : AComponent(name, Script)
{
	int enemyCount = 5;
	switch (level) {
	case 1:
		enemyCount = 5;
		break;
	case 2:
		enemyCount = 6;
		break;
	case 3:
		enemyCount = 8;
	}

	for (int i = 0; i < enemyCount; i++) {
		EnemyObject* enemy = new EnemyObject("enemy", EnemyObject::Walker);
		GameObjectManager::getInstance()->addObject(enemy);
		switch (i) {
		case 0:
			enemy->setPosition(50, 100);
			break;
		case 1:
			enemy->setPosition(80, 200);
			break;
		case 2:
			enemy->setPosition(200, 80);
			break;
		case 3:
			enemy->setPosition(100, 50);
			break;
		case 4:
			enemy->setPosition(175, 300);
			break;
		case 5:
			enemy->setPosition(300, 175);
			break;
		case 6:
			enemy->setPosition(190, 100);
			break;
		case 7:
			enemy->setPosition(80, 40);
			break;
		}
	}
}

EnemySwarmHandler::~EnemySwarmHandler()
{
	AComponent::~AComponent();
}

void EnemySwarmHandler::perform()
{
	if (!timeUp) this->timer -= this->deltaTime.asSeconds();

	if (timer <= 0 && !timeUp) {
		vector<AGameObject*> enemies = GameObjectManager::getInstance()->getObjectsOfType(AGameObject::Enemy);
		int size = enemies.size();
		for (int i = 0; i < size; i++) {
			GameObjectManager::getInstance()->deleteObject(enemies[i]);
		}

		for (int i = 0; i < 8; i++) {
			EnemyObject* enemy = new EnemyObject("enemy", EnemyObject::Runner);
			GameObjectManager::getInstance()->addObject(enemy);
			switch (i) {
			case 0:
				enemy->setPosition(50, 100);
				break;
			case 1:
				enemy->setPosition(80, 200);
				break;
			case 2:
				enemy->setPosition(200, 80);
				break;
			case 3:
				enemy->setPosition(100, 50);
				break;
			case 4:
				enemy->setPosition(175, 300);
				break;
			case 5:
				enemy->setPosition(300, 175);
				break;
			case 6:
				enemy->setPosition(190, 100);
				break;
			case 7:
				enemy->setPosition(80, 40);
				break;
			}
		}

		timeUp = true;
	}
}