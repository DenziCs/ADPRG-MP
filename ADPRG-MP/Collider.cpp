#include"Collider.h"
#include<iostream>

void Collider::setCollisionListener(CollisionListener* listener) {
	this->listener = listener;
}

void Collider::setChecked(bool flag) {
	this->checked = flag;
}

bool Collider::isChecked() {
	return this->checked;
}

bool Collider::willCollide(Collider* another) {
	return this->getGlobalBounds().intersects(another->getGlobalBounds());
}

bool Collider::alreadyCollided() {
	return this->collided;
}

void Collider::setAlreadyCollided(bool flag) {
	this->collided = flag;
}

sf::FloatRect Collider::getGlobalBounds() {
	AGameObject* object = this->getOwner();
	sf::Sprite* sprite = (sf::Sprite*)(object->getTransformable());
	sf::FloatRect bounds = sprite->getGlobalBounds();
	bounds = object->getGlobalTransform().transformRect(bounds);
	return bounds;
}

void Collider::setLocalBounds(sf::FloatRect localBounds) {
	this->localBounds = localBounds;
}

void Collider::collisionEnter(AGameObject* gameObjects) {
	this->listener->onCollisionEnter(this);
}

void Collider::collisionExit(AGameObject* gameObjects) {

}

void Collider::perform() {
	if (this->collided) {
		collisionEnter(this->getOwner());
	}
}