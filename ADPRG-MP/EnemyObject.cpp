#include "EnemyObject.h"
#include "TextureManager.h"
#include "Game.h"
#include "EnemyBehavior.h"
#include <iostream>
#include "Renderer.h"


EnemyObject::EnemyObject(string name, EnemyType type) : APoolable(name)
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
		break;
	case Jogger:
		break;
	case Runner:
		break;
	}

	this->sprite->setTexture(*TextureManager::getInstance()->getTexture("avenger"));
	sf::Vector2u textureSize = sprite->getTexture()->getSize();
	this->sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);
	this->transformable = *sprite;

	Renderer* renderer = new Renderer("EnemySprite");
	renderer->assignDrawable(this->sprite);
	this->attachComponent(renderer);

	/*
	EnemyBehavior* behavior = new EnemyBehavior("EnemyBehavior");
	this->attachComponent(behavior);
	behavior->configure(1.0f);
	*/
}

sf::FloatRect EnemyObject::getGlobalBounds() {
	sf::FloatRect bounds = this->sprite->getGlobalBounds();
	bounds = this->getGlobalTransform().transformRect(bounds);
	return bounds;
}

void EnemyObject::onActivate()
{
	//reset state
	/*
	EnemyBehavior* behavior = (EnemyBehavior*)this->findComponentByName("EnemyBehavior");
	behavior->reset();
	*/
}

APoolable* EnemyObject::clone()
{
	APoolable* copyObj = new EnemyObject(this->name, this->enemyType);
	return copyObj;
}