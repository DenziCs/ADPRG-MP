
#include "PlayerInputController.h"
#include "QuitScreen.h"
#include "GameObjectManager.h"

PlayerInputController::PlayerInputController(string name) : GenericInputController(name)
{

}

PlayerInputController::~PlayerInputController()
{
	GenericInputController::~GenericInputController();
}

void PlayerInputController::perform()
{
	bool keyFlag = false;
	if (event.type == sf::Event::KeyPressed) {
		keyFlag = true;
	}
	else if (event.type == sf::Event::KeyReleased) {
		keyFlag = false;
	}
	switch (event.key.code) {
	case sf::Keyboard::W:
		this->moveUp = keyFlag;
		break;
	case sf::Keyboard::A:
		this->moveLeft = keyFlag;
		break;
	case sf::Keyboard::S:
		this->moveDown = keyFlag;
		break;
	case sf::Keyboard::D:
		this->moveRight = keyFlag;
		break;
	case sf::Keyboard::Space:
		this->firing = keyFlag;
		break;
	}
	//will create multiple if escape key is released multiple times
	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape) {
		QuitScreen* quitScreen = new QuitScreen("quitScreen");
		quitScreen->markGameQuit();
		GameObjectManager::getInstance()->addObject(quitScreen);
	}
}

bool PlayerInputController::isUp()
{
	return this->moveUp;
}

bool PlayerInputController::isDown()
{
	return this->moveDown;
}

bool PlayerInputController::isLeft()
{
	return this->moveLeft;
}

bool PlayerInputController::isRight()
{
	return this->moveRight;
}

bool PlayerInputController::isFiring() {
	return this->firing;
}