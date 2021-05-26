#include"Collider.h"
#include<iostream>

void Collider::perform() {
	sf::FloatRect bounds = this->getOwner()->getGlobalBounds();

	vector<AGameObject*> toCheck = GameObjectManager::getInstance()->getObjectsOfType(AGameObject::Enemy);
	int size = toCheck.size();
	for (int i = 0; i < size; i++) {
		if (bounds.intersects(toCheck[i]->getGlobalBounds())) {
			ContactResolver* contact = new ContactResolver(this->getOwner(), toCheck[i]);
			PhysicsManager::getInstance()->addContact(contact);
		}
	}

	toCheck = GameObjectManager::getInstance()->getObjectsOfType(AGameObject::ActiveBomb);
	size = toCheck.size();
	for (int i = 0; i < size; i++) {
		if (bounds.intersects(toCheck[i]->getGlobalBounds())) {
			ContactResolver* contact = new ContactResolver(this->getOwner(), toCheck[i]);
			PhysicsManager::getInstance()->addContact(contact);
		}
	}
}