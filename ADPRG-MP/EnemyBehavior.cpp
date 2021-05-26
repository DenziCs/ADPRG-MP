#include "EnemyBehavior.h"
#include "AGameObject.h"
#include <iostream>
#include "Game.h";
#include"GameObjectManager.h"

EnemyBehavior::EnemyBehavior(string name, EnemyMovementType type, bool isRunner) : AComponent(name, Script)
{
	movementType = type;
	if (isRunner) speed = 80.f;
	else speed = 40.f;
}

bool EnemyBehavior::hasCollided() {
	sf::FloatRect bounds = this->getOwner()->getGlobalBounds();

	switch (movementType) {
	case Vertical:
		if (direction) {
			if (bounds.top + bounds.height >= Game::WINDOW_HEIGHT - Game::TILE_SIZE) return true;
		}
		else {
			if (bounds.top <= Game::TILE_SIZE * 3) return true;
		}
		break;
	case Horizontal:
		if (direction) {
			if (bounds.left + bounds.width >= Game::WINDOW_WIDTH - Game::TILE_SIZE * 2) return true;
		}
		else {
			if (bounds.left <= Game::TILE_SIZE) return true; break;
		}
		break;
	}

	vector<AGameObject*> toSearch = GameObjectManager::getInstance()->getObjectsOfType(AGameObject::Hardblock);
	for (int i = 0; i < toSearch.size(); i++) {
		if (bounds.intersects(toSearch[i]->getGlobalBounds())) {
			toSearch.clear();
			return true;
		}
	}

	toSearch.clear();
	toSearch = GameObjectManager::getInstance()->getObjectsOfType(AGameObject::Softblock);
	for (int i = 0; i < toSearch.size(); i++) {
		if (bounds.intersects(toSearch[i]->getGlobalBounds())) {
			toSearch.clear();
			return true;
		}
	}

	toSearch.clear();
	toSearch = GameObjectManager::getInstance()->getObjectsOfType(AGameObject::Bomb);
	for (int i = 0; i < toSearch.size(); i++) {
		if (bounds.intersects(toSearch[i]->getGlobalBounds()) && toSearch[i]->isEnabled()) {
			toSearch.clear();
			return true;
		}
	}

	toSearch.clear();
	return false;
}

void EnemyBehavior::perform()
{
	sf::Transformable* transformable = this->getOwner()->getTransformable();

	switch (movementType) {
	case Vertical:
		if (direction) {
			transformable->move(0, this->deltaTime.asSeconds() * speed);
			if (hasCollided()) {
				transformable->move(0, -this->deltaTime.asSeconds() * speed);
				direction = !direction;
			}
		}
		else {
			transformable->move(0, -this->deltaTime.asSeconds() * speed);
			if (hasCollided()) {
				transformable->move(0, this->deltaTime.asSeconds() * speed);
				direction = !direction;
			}
		}
		break;
	case Horizontal:
		if (direction) {
			transformable->move(this->deltaTime.asSeconds() * speed, 0);
			if (hasCollided()) {
				transformable->move(-this->deltaTime.asSeconds() * speed, 0);
				direction = !direction;
			}
		}
		else {
			transformable->move(-this->deltaTime.asSeconds() * speed, 0);
			if (hasCollided()) {
				transformable->move(this->deltaTime.asSeconds() * speed, 0);
				direction = !direction;
			}
		}
		break;
	}
}