#include "GameScene.h"
#include "BGObject.h"
#include "PlayerObject.h"
#include "AirplaneSupport.h"
#include "EnemyObject.h"
#include"PillarObject.h"
#include "GameObjectPool.h"
#include "ObjectPoolHolder.h"
#include "EmptyGameObject.h"
#include "EnemySwarmHandler.h"
#include "HUDScreen.h"
#include"PhysicsManager.h"
#include"Game.h"
#include "SoftBlockObject.h"

GameScene::GameScene() : AScene("GameScene")
{

}

GameScene::~GameScene()
{
}

void GameScene::onLoadResources()
{
}

void GameScene::onLoadObjects()
{
    BGObject* bgObject = new BGObject("BGObject");
    this->registerObject(bgObject);

    for (int i = 0; i < 40; i++) {
        PillarObject* pillar = new PillarObject("HardBlock");
        this->registerObject(pillar);
        pillar->setPosition(80 * ((i % 8) + 1), 80 * ((i / 8) + 2));
    }

    std::vector<sf::Vector2i> blockPos;
    blockPos.push_back(sf::Vector2i(3, 6));
    blockPos.push_back(sf::Vector2i(2, 6));
    blockPos.push_back(sf::Vector2i(4, 6));
    blockPos.push_back(sf::Vector2i(5, 8));

    placeSoftBlocks(blockPos);

    PlayerObject* planeObject = new PlayerObject("PlaneObject");
    this->registerObject(planeObject);
    planeObject->setPosition(Game::TILE_SIZE * 1.5, Game::TILE_SIZE * 3.5);

    srand(time(NULL));
    EmptyGameObject* enemiesManager = new EmptyGameObject("EnemiesManager");
    EnemySwarmHandler* swarmHandler = new EnemySwarmHandler(1, "SwarmHandler");
    enemiesManager->attachComponent(swarmHandler);
    this->registerObject(enemiesManager);

    HUDScreen* hudScreen = new HUDScreen("HUDScreen");
    this->registerObject(hudScreen);

    EmptyGameObject* physics = new EmptyGameObject("physics");
    this->registerObject(physics);
    PhysicsManager::getInstance()->initialize(PhysicsManager::PHYSICS_MANAGER_TAG, physics);
}

void GameScene::onUnloadObjects()
{
    /*
	GameObjectPool* enemyPool = ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::ENEMY_POOL_TAG);
	ObjectPoolHolder::getInstance()->unregisterObjectPool(enemyPool);

    GameObjectPool* bulletPool = ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::BULLET_POOL_TAG);
    ObjectPoolHolder::getInstance()->unregisterObjectPool(bulletPool);
    */

	AScene::onUnloadObjects();
}


void GameScene::onUnloadResources()
{
}

void GameScene::placeSoftBlocks(std::vector<sf::Vector2i> blockPos) {
    for (int i = 0; i < blockPos.size(); i++) {
        SoftBlockObject* block = new SoftBlockObject("SoftBlock");
        this->registerObject(block);
        block->setPosition(Game::TILE_SIZE * blockPos[i].x, Game::TILE_SIZE * blockPos[i].y);
    }
}