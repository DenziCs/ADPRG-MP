#include "GameScene.h"
#include "BGObject.h"
#include "PlayerObject.h"
#include "AirplaneSupport.h"
#include "EnemyAirplane.h"
#include "GameObjectPool.h"
#include "ObjectPoolHolder.h"
#include "EmptyGameObject.h"
#include "EnemySwarmHandler.h"
#include "HUDScreen.h"

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

    PlayerObject* planeObject = new PlayerObject("PlaneObject");
    this->registerObject(planeObject);

    AirplaneSupport* support1 = new AirplaneSupport("AirSupport_1");
    planeObject->attachChild(support1);
    support1->setPosition(50, 100);

    AirplaneSupport* support2 = new AirplaneSupport("AirSupport_2");
    planeObject->attachChild(support2);
    support2->setPosition(-50, 100);

    HUDScreen* hudScreen = new HUDScreen("HUDScreen");
    this->registerObject(hudScreen);

    //create N enemies via object pooling
    srand(time(NULL));
    EmptyGameObject* enemiesManager = new EmptyGameObject("EnemiesManager");
    EnemySwarmHandler* swarmHandler = new EnemySwarmHandler(10, "SwarmHandler");
    enemiesManager->attachComponent(swarmHandler);
    this->registerObject(enemiesManager);

    EmptyGameObject* physics = new EmptyGameObject("physics");
    this->registerObject(physics);
    PhysicsManager::getInstance()->initialize(PhysicsManager::PHYSICS_MANAGER_TAG, physics);
}

void GameScene::onUnloadObjects()
{
	GameObjectPool* enemyPool = ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::ENEMY_POOL_TAG);
	ObjectPoolHolder::getInstance()->unregisterObjectPool(enemyPool);

    GameObjectPool* bulletPool = ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::BULLET_POOL_TAG);
    ObjectPoolHolder::getInstance()->unregisterObjectPool(bulletPool);

	AScene::onUnloadObjects();
}


void GameScene::onUnloadResources()
{
}