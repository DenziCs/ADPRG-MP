#include "EnemyBehavior.h"
#include "AGameObject.h"
#include <iostream>
#include "Game.h";
#include "ObjectPoolHolder.h"

EnemyBehavior::EnemyBehavior(string name, EnemyMovementType type, bool isRunner) : AComponent(name, Script)
{
	movementType = type;
	if (isRunner) speed = 80.f;
	else speed = 40.f;
}

void EnemyBehavior::perform()
{
	sf::Transformable* transformable = this->getOwner()->getTransformable();
	this->timer -= this->deltaTime.asSeconds();
	if (timer <= 0) {
		direction = !direction;
		timer = 5.f;
	}
	switch (movementType) {
	case Vertical:
		if (direction) transformable->move(0, this->deltaTime.asSeconds() * speed);
		else transformable->move(0, -this->deltaTime.asSeconds() * speed);
		break;
	case Horizontal:
		if (direction) transformable->move(this->deltaTime.asSeconds() * speed, 0);
		else transformable->move(-this->deltaTime.asSeconds() * speed, 0);
		break;
	}
}