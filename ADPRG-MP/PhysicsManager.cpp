#include"PhysicsManager.h"
#include<iostream>

PhysicsManager* PhysicsManager::sharedInstance = NULL;
string PhysicsManager::PHYSICS_MANAGER_TAG = "Physics";

PhysicsManager* PhysicsManager::getInstance() {
	return sharedInstance;
}

void PhysicsManager::initialize(string name, AGameObject* parent) {
	sharedInstance = new PhysicsManager(name);
	parent->attachComponent(sharedInstance);
}

PhysicsManager::~PhysicsManager() {
	collisionList.clear();
	AComponent::~AComponent();
}

void PhysicsManager::addContact(ContactResolver* resolver) {
	collisionList.push_back(resolver);
}

/*
void PhysicsManager::getContacts() {
	PlayerObject* player = (PlayerObject*)GameObjectManager::getInstance()->getObjectsOfType(AGameObject::Player)[0];
	vector<AGameObject*> toCheck = GameObjectManager::getInstance()->getObjectsOfType(AGameObject::Enemy);
	int size = toCheck.size();
	for (int i = 0; i < size; i++) {
		if (player->getGlobalBounds().intersects(toCheck[i]->getGlobalBounds())) {
			ContactResolver* contact = new ContactResolver(player, toCheck[i]);
			addContact(contact);
		}
	}
}
*/

void PhysicsManager::perform() {
	// this->getContacts();
	iterator.resolveContacts(collisionList);
	collisionList.clear();
}