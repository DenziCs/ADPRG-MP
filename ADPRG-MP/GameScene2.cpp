#include "GameScene2.h"
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

GameScene2::GameScene2() : AScene("GameScene2")
{

}

GameScene2::~GameScene2()
{
}

void GameScene2::onLoadResources()
{
}

void GameScene2::onLoadObjects()
{
    BGObject* bgObject = new BGObject("BGObject2");
    this->registerObject(bgObject);

    for (int i = 0; i < 40; i++) {
        PillarObject* pillar = new PillarObject("HardBlock2");
        this->registerObject(pillar);
        pillar->setPosition(80 * ((i % 8) + 1), 80 * ((i / 8) + 2));
    }

    SoftBlockObject* block = new SoftBlockObject("SoftBlock2");
    this->registerObject(block);
    block->setPosition(80 * 5, 80 * 5);

    PlayerObject* planeObject = new PlayerObject("PlaneObject2");
    this->registerObject(planeObject);
    planeObject->setPosition(Game::TILE_SIZE * 1.5, Game::TILE_SIZE * 3.5);

    srand(time(NULL));
    EmptyGameObject* enemiesManager = new EmptyGameObject("EnemiesManager2");
    EnemySwarmHandler* swarmHandler = new EnemySwarmHandler(1, "SwarmHandler2");
    enemiesManager->attachComponent(swarmHandler);
    this->registerObject(enemiesManager);

    HUDScreen* hudScreen = new HUDScreen("HUDScreen2");
    this->registerObject(hudScreen);

    EmptyGameObject* physics = new EmptyGameObject("physics2");
    this->registerObject(physics);
    PhysicsManager::getInstance()->initialize(PhysicsManager::PHYSICS_MANAGER_TAG, physics);
}

void GameScene2::onUnloadObjects()
{
    /*
    GameObjectPool* enemyPool = ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::ENEMY_POOL_TAG);
    ObjectPoolHolder::getInstance()->unregisterObjectPool(enemyPool);

    GameObjectPool* bulletPool = ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::BULLET_POOL_TAG);
    ObjectPoolHolder::getInstance()->unregisterObjectPool(bulletPool);
    */

    AScene::onUnloadObjects();
}


void GameScene2::onUnloadResources()
{
}