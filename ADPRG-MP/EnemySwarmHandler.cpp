#include "EnemySwarmHandler.h"
#include "GameObjectManager.h"
#include "ObjectPoolHolder.h"
#include "EnemyObject.h"
#include"Game.h"
#include"SceneManager.h"

EnemySwarmHandler::EnemySwarmHandler(int level, string name) : AComponent(name, Script)
{
	this->currentLevel = level;

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
			enemy->setPosition(Game::TILE_SIZE * 4.5, Game::TILE_SIZE * 3.5);
			break;
		case 1:
			enemy->setPosition(Game::TILE_SIZE * 10.5, Game::TILE_SIZE * 5.5);
			break;
		case 2:
			enemy->setPosition(Game::TILE_SIZE * 12.5, Game::TILE_SIZE * 7.5);
			break;
		case 3:
			enemy->setPosition(Game::TILE_SIZE * 6.5, Game::TILE_SIZE * 9.5);
			break;
		case 4:
			enemy->setPosition(Game::TILE_SIZE * 3.5, Game::TILE_SIZE * 4.5);
			break;
		case 5:
			enemy->setPosition(Game::TILE_SIZE * 9.5, Game::TILE_SIZE * 6.5);
			break;
		case 6:
			enemy->setPosition(Game::TILE_SIZE * 5.5, Game::TILE_SIZE * 8.5);
			break;
		case 7:
			enemy->setPosition(Game::TILE_SIZE * 7.5, Game::TILE_SIZE * 10.5);
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
				enemy->setPosition(Game::TILE_SIZE * 4.5, Game::TILE_SIZE * 3.5);
				break;
			case 1:
				enemy->setPosition(Game::TILE_SIZE * 10.5, Game::TILE_SIZE * 5.5);
				break;
			case 2:
				enemy->setPosition(Game::TILE_SIZE * 12.5, Game::TILE_SIZE * 7.5);
				break;
			case 3:
				enemy->setPosition(Game::TILE_SIZE * 6.5, Game::TILE_SIZE * 9.5);
				break;
			case 4:
				enemy->setPosition(Game::TILE_SIZE * 3.5, Game::TILE_SIZE * 4.5);
				break;
			case 5:
				enemy->setPosition(Game::TILE_SIZE * 9.5, Game::TILE_SIZE * 6.5);
				break;
			case 6:
				enemy->setPosition(Game::TILE_SIZE * 5.5, Game::TILE_SIZE * 8.5);
				break;
			case 7:
				enemy->setPosition(Game::TILE_SIZE * 7.5, Game::TILE_SIZE * 10.5);
				break;
			}
		}

		timeUp = true;
	}

	vector<AGameObject*> enemies = GameObjectManager::getInstance()->getObjectsOfType(AGameObject::Enemy);
	if (enemies.size() == 0) {
		switch (this->currentLevel) {
		case 1:
			SceneManager::getInstance()->specifyNextScene(SceneManager::GAME_SCENE_2_NAME);
			break;
		case 2:
			SceneManager::getInstance()->specifyNextScene(SceneManager::GAME_SCENE_3_NAME);
			break;
		case 3:
			SceneManager::getInstance()->specifyNextScene(SceneManager::MAIN_MENU_SCENE_NAME);
			break;
		}
		SceneManager::getInstance()->loadScene(SceneManager::TRANSITION_SCENE_NAME);
	}
}