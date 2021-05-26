#include "BombObject.h"
#include "TextureManager.h"
#include "Game.h"
#include "EnemyBehavior.h"
#include <iostream>
#include "Renderer.h"
#include"BombExplosion.h"


BombObject::BombObject(string name) : APoolable(name)
{
	this->objectType = Bomb;
	this->sprite = NULL;
}

void BombObject::initialize()
{
	//assign texture
	this->sprite = new sf::Sprite();
	this->sprite->setTexture(*TextureManager::getInstance()->getTexture("sheet"));
	sf::IntRect textureSize(0, 0, 40, 40);
	this->sprite->setTextureRect(textureSize);

	//sf::Vector2u textureSize = sprite->getTexture()->getSize();
	this->sprite->setOrigin(textureSize.width / 2, textureSize.height / 2);

	BombExplosion* exploder = new BombExplosion("Exploder");
	this->attachComponent(exploder);

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
	BombExplosion* exploder = (BombExplosion*)this->findComponentByName("Exploder");
	exploder->reset();
}

APoolable* BombObject::clone()
{
	APoolable* copyObj = new BombObject(this->name);
	return copyObj;
}