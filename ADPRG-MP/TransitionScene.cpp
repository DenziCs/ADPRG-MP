#include "TransitionScene.h"
#include"AudioManager.h"

TransitionScene::TransitionScene() : AScene("TransitionScene") {
	this->sound = new sf::Sound();
}

void TransitionScene::onLoadObjects() {
	UIText* text = new UIText("Text");
	this->registerObject(text);
	text->setPosition(Game::WINDOW_WIDTH / 2, Game::WINDOW_HEIGHT / 2);
	text->setSize(100);
	
	if (this->nextScene == SceneManager::MAIN_MENU_SCENE_NAME) text->setText("GAME OVER");
	if (this->nextScene == SceneManager::GAME_SCENE_NAME) text->setText("STAGE 1");
	if (this->nextScene == SceneManager::GAME_SCENE_2_NAME) text->setText("STAGE 2");
	if (this->nextScene == SceneManager::GAME_SCENE_3_NAME) text->setText("STAGE 3");

	EmptyGameObject* timerManager = new EmptyGameObject("timerManager");
	this->registerObject(timerManager);

	TransitionUpdate* updater = new TransitionUpdate("timerUpdater", nextScene, timer);
	timerManager->attachComponent(updater);

	sf::SoundBuffer* buffer = AudioManager::getInstance()->getSound("transition");
	sound->setBuffer(*buffer);
	sound->play();
}

void TransitionScene::onUnloadObjects() {
	sound->stop();
	AScene::onUnloadObjects();
}

void TransitionScene::onUnloadResources() {}