#include "MainMenuScene.h"
#include "MainMenuScreen.h"
#include "GameObjectManager.h"
#include"AudioManager.h"
#include <iostream>

MainMenuScene::MainMenuScene() : AScene("MainMenuScene")
{
	sound = new sf::Sound();
}

MainMenuScene::~MainMenuScene()
{

}

void MainMenuScene::onLoadResources()
{

}

void MainMenuScene::onLoadObjects()
{
	MainMenuScreen* menuScreen = new MainMenuScreen("MainMenuScreen");
	this->registerObject(menuScreen);

	sf::SoundBuffer* buffer = AudioManager::getInstance()->getSound("title");
	sound->setBuffer(*buffer);
	sound->play();
	sound->setLoop(true);
}

void MainMenuScene::onUnloadResources()
{
	sound->stop();
}