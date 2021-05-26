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

GameScene::GameScene() :AScene("GameScene")
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

        if (i == 0) {
            cout << pillar->getGlobalBounds().left << endl;
            cout << pillar->getGlobalBounds().width << endl;
            cout << pillar->getGlobalBounds().top << endl;
            cout << pillar->getGlobalBounds().height << endl;
        }
    }

    PlayerObject* planeObject = new PlayerObject("PlaneObject");
    this->registerObject(planeObject);
    planeObject->setPosition(Game::TILE_SIZE + 20, (Game::TILE_SIZE*3) + 20);
    cout << planeObject->getTransformable()->getPosition().x << endl;
    cout << planeObject->getGlobalBounds().left << endl;
    cout << planeObject->getGlobalBounds().width << endl;
    cout << planeObject->getGlobalBounds().top << endl;
    cout << planeObject->getGlobalBounds().height << endl;

    EmptyGameObject* enemiesManager = new EmptyGameObject("EnemiesManager");
    EnemySwarmHandler* swarmHandler = new EnemySwarmHandler(1, "SwarmHandler");
    enemiesManager->attachComponent(swarmHandler);
    this->registerObject(enemiesManager);

    HUDScreen* hudScreen = new HUDScreen("HUDScreen");
    this->registerObject(hudScreen);

    /*
    EmptyGameObject* physics = new EmptyGameObject("physics");
    this->registerObject(physics);
    PhysicsManager::getInstance()->initialize(PhysicsManager::PHYSICS_MANAGER_TAG, physics);
    */
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