#include "PillarObject.h"
#include "TextureManager.h"
#include "Game.h"
#include "EnemyBehavior.h"
#include <iostream>
#include "Renderer.h"

PillarObject::PillarObject(string name) : AGameObject(name) {
	this->objectType = Hardblock;
	this->sprite = NULL;
}

void PillarObject::initialize() {
	this->sprite = new sf::Sprite();
	this->sprite->setTexture(*TextureManager::getInstance()->getTexture("sheet"));
	this->sprite->setTextureRect(sf::IntRect(0, 80, 40, 40));
	// this->transformable = *sprite;

	Renderer* renderer = new Renderer("BlockRenderer");
	renderer->assignDrawable(this->sprite);
	this->attachComponent(renderer);
}

sf::FloatRect PillarObject::getGlobalBounds() {
	sf::FloatRect bounds = this->sprite->getGlobalBounds();
	bounds = this->getGlobalTransform().transformRect(bounds);
	return bounds;
}