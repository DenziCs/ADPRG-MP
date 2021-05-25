#include "BombObject.h"
#include "TextureManager.h"
#include "Game.h"
#include "EnemyBehavior.h"
#include <iostream>
#include "Renderer.h"


BombObject::BombObject(string name, bool exploded) : APoolable(name)
{
	this->objectType = Bomb;
	this->hasExploded = exploded;
	this->sprite = NULL;
}

void BombObject::initialize()
{
	//assign texture
	this->sprite = new sf::Sprite();
	if (hasExploded) this->sprite->setTexture(*TextureManager::getInstance()->getTexture("avenger"));
	else this->sprite->setTexture(*TextureManager::getInstance()->getTexture("avenger"));

	sf::Vector2u textureSize = sprite->getTexture()->getSize();
	this->sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);
	this->transformable = *sprite;

	Renderer* renderer = new Renderer("BombRenderer");
	renderer->assignDrawable(this->sprite);
	this->attachComponent(renderer);
}

sf::FloatRect BombObject::getGlobalBounds() {
	sf::FloatRect bounds = this->sprite->getGlobalBounds();
	bounds = this->getGlobalTransform().transformRect(bounds);
	return bounds;
}

void BombObject::onActivate()
{
}

APoolable* BombObject::clone()
{
	APoolable* copyObj = new BombObject(this->name, this->hasExploded);
	return copyObj;
}