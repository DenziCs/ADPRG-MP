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
#include"UIText.h"
#include"PhysicsManager.h"
#include"Game.h"
#include"TimerUpdate.h"

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

    UIText* timerText1 = new UIText("Timer");
    this->registerObject(timerText1);
    timerText1->setPosition(50, 40);
    timerText1->setSize(30);
    timerText1->setText("TIME");

    UIText* timerText2 = new UIText("Timer");
    this->registerObject(timerText2);
    timerText2->setPosition(150, 40);
    timerText2->setSize(30);
    timerText2->setText(to_string(int(this->timer)));
    
    // Added here for access to timer, as well as to avoid circular dependency.
    TimerUpdate* updater = new TimerUpdate("timerUpdater", timer);
    timerText2->attachComponent(updater);

    EmptyGameObject* physics = new EmptyGameObject("physics");
    this->registerObject(physics);
    PhysicsManager::getInstance()->initialize(PhysicsManager::PHYSICS_MANAGER_TAG, physics);
}

void GameScene::onUnloadObjects()
{
	GameObjectPool* bombPool = ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::BOMB_POOL_TAG);
	ObjectPoolHolder::getInstance()->unregisterObjectPool(bombPool);

    GameObjectPool* activePool = ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::EXPLOSION_POOL_TAG);
    ObjectPoolHolder::getInstance()->unregisterObjectPool(activePool);

	AScene::onUnloadObjects();
}


void GameScene::onUnloadResources()
{
}