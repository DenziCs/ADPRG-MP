#include "ActiveBombObject.h"
#include"ActiveBombTimer.h"
#include "TextureManager.h"
#include "Game.h"
#include "EnemyBehavior.h"
#include <iostream>
#include "Renderer.h"

ActiveBombObject::ActiveBombObject(string name) : APoolable(name)
{
	this->objectType = ActiveBomb;
	this->sprite = NULL;
}

void ActiveBombObject::initialize()
{
	//assign texture
	this->sprite = new sf::Sprite();
	this->sprite->setTexture(*TextureManager::getInstance()->getTexture("sheet"));
	sf::IntRect textureSize(70, 40, 40, 40);
	this->sprite->setTextureRect(textureSize);

	//sf::Vector2u textureSize = sprite->getTexture()->getSize();
	this->sprite->setOrigin(textureSize.width / 2, textureSize.height / 2);

	ActiveBombTimer* timer = new ActiveBombTimer("ActiveTimer");
	this->attachComponent(timer);

	Renderer* renderer = new Renderer("BombRenderer");
	renderer->assignDrawable(this->sprite);
	this->attachComponent(renderer);
}

sf::FloatRect ActiveBombObject::getGlobalBounds() {
	sf::FloatRect bounds = this->sprite->getGlobalBounds();
	bounds = this->getGlobalTransform().transformRect(bounds);
	return bounds;
}

void ActiveBombObject::onActivate()
{
	ActiveBombTimer* timer = (ActiveBombTimer*)this->findComponentByName("ActiveTimer");
	timer->reset();
}

APoolable* ActiveBombObject::clone()
{
	APoolable* copyObj = new ActiveBombObject(this->name);
	return copyObj;
}