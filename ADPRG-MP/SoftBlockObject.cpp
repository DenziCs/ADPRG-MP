#include "SoftBlockObject.h"
#include "TextureManager.h"
#include "Game.h"
#include "EnemyBehavior.h"
#include <iostream>
#include "Renderer.h"

SoftBlockObject::SoftBlockObject(string name) : APoolable(name)
{
	this->objectType = Softblock;
	this->sprite = NULL;
}

void SoftBlockObject::initialize()
{
	//assign texture
	this->sprite = new sf::Sprite();
	this->sprite->setTexture(*TextureManager::getInstance()->getTexture("sheet"));
	sf::IntRect textureSize(40, 80, 40, 40);
	this->sprite->setTextureRect(textureSize);

	//sf::Vector2u textureSize = sprite->getTexture()->getSize();
	this->sprite->setOrigin(textureSize.width / 2, textureSize.height / 2);
	this->transformable = *sprite;

	Renderer* renderer = new Renderer("BlockRenderer");
	renderer->assignDrawable(this->sprite);
	this->attachComponent(renderer);
}

sf::FloatRect SoftBlockObject::getGlobalBounds() {
	sf::FloatRect bounds = this->sprite->getGlobalBounds();
	bounds = this->getGlobalTransform().transformRect(bounds);
	return bounds;
}

void SoftBlockObject::onActivate()
{
}

APoolable* SoftBlockObject::clone()
{
	APoolable* copyObj = new SoftBlockObject(this->name);
	return copyObj;
}