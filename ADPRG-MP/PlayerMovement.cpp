#include "PlayerMovement.h"
#include "AGameObject.h"
#include "PlayerInputController.h"
#include"GameObjectManager.h"
#include"Game.h"
#include <iostream>

PlayerMovement::PlayerMovement(string name) : AComponent(name, Script)
{
}

PlayerMovement::~PlayerMovement()
{
	AComponent::~AComponent();
}

bool PlayerMovement::hasCollided(Direction direction) {
	sf::Transformable* playerTransformable = this->getOwner()->getTransformable();
	sf::FloatRect bounds = this->getOwner()->getGlobalBounds();

	switch (direction) {
	case Up:
		if (bounds.top <= Game::TILE_SIZE * 3) return true; break;
	case Right:
		if (bounds.left + bounds.width >= Game::WINDOW_WIDTH - Game::TILE_SIZE * 2) return true; break;
	case Down:
		if (bounds.top + bounds.height >= Game::WINDOW_HEIGHT - Game::TILE_SIZE) return true;  break;
	case Left:
		if (bounds.left <= Game::TILE_SIZE) return true; break;
	}

	vector<AGameObject*> toSearch = GameObjectManager::getInstance()->getObjectsOfType(AGameObject::Hardblock);
	for (int i = 0; i < toSearch.size(); i++) {
		if (bounds.intersects(toSearch[i]->getGlobalBounds())) {
			toSearch.clear();
			return true;
		}
	}

	toSearch.clear();
	return false;
}

void PlayerMovement::perform()
{
	PlayerInputController* inputController = (PlayerInputController*)this->getOwner()->getComponentsOfType(ComponentType::Input)[0];
	sf::Transformable* playerTransformable = this->getOwner()->getTransformable();
	if (playerTransformable == NULL || inputController == NULL) {
		cout << "One or more of the needed dependencies are missing!\n";
		return;
	}

	sf::Vector2f offset(0.0f, 0.0f);
	if (inputController->isUp()) {
		offset.y -= this->SPEED_MULTIPLIER;
		playerTransformable->move(offset * deltaTime.asSeconds());

		if (hasCollided(Up)) {
			playerTransformable->move(-offset * deltaTime.asSeconds());
		}
	}

	else if (inputController->isDown()) {
		offset.y += this->SPEED_MULTIPLIER;
		playerTransformable->move(offset * deltaTime.asSeconds());

		if (hasCollided(Down)) {
			playerTransformable->move(-offset * deltaTime.asSeconds());
		}
	}

	else if (inputController->isRight()) {
		offset.x += this->SPEED_MULTIPLIER;
		playerTransformable->move(offset * deltaTime.asSeconds());

		if (hasCollided(Right)) {
			playerTransformable->move(-offset * deltaTime.asSeconds());
		}
	}

	else if (inputController->isLeft()) {
		offset.x -= this->SPEED_MULTIPLIER;
		playerTransformable->move(offset * deltaTime.asSeconds());

		if (hasCollided(Left)) {
			playerTransformable->move(-offset * deltaTime.asSeconds());
		}
	}
}