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
#include"TimerUpdate.h"
#include"UIText.h"
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

    std::vector<sf::Vector2i> blockPos;
    blockPos.push_back(sf::Vector2i(3, 6));
    blockPos.push_back(sf::Vector2i(2, 6));
    blockPos.push_back(sf::Vector2i(4, 6));
    blockPos.push_back(sf::Vector2i(5, 8));
    blockPos.push_back(sf::Vector2i(3, 8));
    blockPos.push_back(sf::Vector2i(4, 7));
    blockPos.push_back(sf::Vector2i(6, 10));
    blockPos.push_back(sf::Vector2i(12, 4));
    blockPos.push_back(sf::Vector2i(2, 12));
    blockPos.push_back(sf::Vector2i(2, 10));
    blockPos.push_back(sf::Vector2i(2, 11));
    blockPos.push_back(sf::Vector2i(3, 10));
    blockPos.push_back(sf::Vector2i(10, 14));
    blockPos.push_back(sf::Vector2i(11, 14));
    blockPos.push_back(sf::Vector2i(18, 14));
    blockPos.push_back(sf::Vector2i(17, 14));
    blockPos.push_back(sf::Vector2i(14, 7));
    blockPos.push_back(sf::Vector2i(8, 7));
    blockPos.push_back(sf::Vector2i(10, 9));
    blockPos.push_back(sf::Vector2i(11, 10));
    blockPos.push_back(sf::Vector2i(15, 10));
    blockPos.push_back(sf::Vector2i(16, 10));
    blockPos.push_back(sf::Vector2i(12, 8));
    blockPos.push_back(sf::Vector2i(14, 8));
    blockPos.push_back(sf::Vector2i(12, 7));
    blockPos.push_back(sf::Vector2i(13, 6));
    blockPos.push_back(sf::Vector2i(2, 14));
    blockPos.push_back(sf::Vector2i(2, 13));
    blockPos.push_back(sf::Vector2i(3, 14));
    blockPos.push_back(sf::Vector2i(4, 14));
    blockPos.push_back(sf::Vector2i(4, 13));
    blockPos.push_back(sf::Vector2i(8, 6));
    blockPos.push_back(sf::Vector2i(8, 5));

    placeSoftBlocks(blockPos);

    PlayerObject* planeObject = new PlayerObject("PlaneObject2");
    this->registerObject(planeObject);
    planeObject->setPosition(Game::TILE_SIZE * 1.5, Game::TILE_SIZE * 3.5);

    srand(time(NULL));
    EmptyGameObject* enemiesManager = new EmptyGameObject("EnemiesManager2");
    EnemySwarmHandler* swarmHandler = new EnemySwarmHandler(2, "SwarmHandler2");
    enemiesManager->attachComponent(swarmHandler);
    this->registerObject(enemiesManager);

    HUDScreen* hudScreen = new HUDScreen("HUDScreen2");
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

    TimerUpdate* updater = new TimerUpdate("timerUpdater", timer);
    timerText2->attachComponent(updater);

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

void GameScene2::placeSoftBlocks(std::vector<sf::Vector2i> blockPos) {
    for (int i = 0; i < blockPos.size(); i++) {
        SoftBlockObject* block = new SoftBlockObject("SoftBlock");
        this->registerObject(block);
        block->setPosition(Game::TILE_SIZE * blockPos[i].x, Game::TILE_SIZE * blockPos[i].y);
    }
}