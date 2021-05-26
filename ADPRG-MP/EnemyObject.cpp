#include "EnemyObject.h"
#include "TextureManager.h"
#include "Game.h"
#include "EnemyBehavior.h"
#include <iostream>
#include "Renderer.h"


EnemyObject::EnemyObject(string name, EnemyType type) : AGameObject(name)
{
	this->objectType = Enemy;
	this->enemyType = type;
	this->sprite = NULL;
}

void EnemyObject::initialize()
{
	//assign texture
	this->sprite = new sf::Sprite();
	switch (enemyType) {
	case Walker:
		this->sprite->setTexture(*TextureManager::getInstance()->getTexture("player"));
		break;
	case Runner:
		this->sprite->setTexture(*TextureManager::getInstance()->getTexture("player"));
		break;
	}

	sf::Vector2u textureSize = sprite->getTexture()->getSize();
	this->sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);

	Renderer* renderer = new Renderer("EnemySprite");
	renderer->assignDrawable(this->sprite);
	this->attachComponent(renderer);

	int rando = rand() % 2;
	EnemyBehavior::EnemyMovementType type;
	if (rando == 0) type = EnemyBehavior::Vertical;
	else type = EnemyBehavior::Horizontal;

	bool runner;
	if (this->enemyType == Runner) runner = true;
	else runner = false;

	EnemyBehavior* behavior = new EnemyBehavior("EnemyBehavior", type, runner);
	this->attachComponent(behavior);
}

sf::FloatRect EnemyObject::getGlobalBounds() {
	sf::FloatRect bounds = this->sprite->getGlobalBounds();
	bounds = this->getGlobalTransform().transformRect(bounds);
	return bounds;
}