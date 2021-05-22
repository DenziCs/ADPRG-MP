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
	trackedObjects.clear();
	forCleaningObjects.clear();
	AComponent::~AComponent();
}

void PhysicsManager::destroy() {
}

void PhysicsManager::trackObject(Collider* object) {
	trackedObjects.push_back(object);
}

void PhysicsManager::untrackObject(Collider* object) {
	int oldSize = trackedObjects.size();
	for (int i = 0; i < oldSize; i++) {
		if (trackedObjects[i] == object) {
			trackedObjects.erase(trackedObjects.begin() + i);
			break;
		}
	}
}

void PhysicsManager::cleanUpObjects() {

}

void PhysicsManager::perform() {
	for (int i = 0; i < trackedObjects.size(); i++) {
		for (int j = i + 1; j < trackedObjects.size(); j++) {
			CollisionListener* listener1 = (CollisionListener*)trackedObjects[i]->getOwner();
			CollisionListener* listener2 = (CollisionListener*)trackedObjects[j]->getOwner();
			if (listener1->colliderType != listener2->colliderType) {
				if (trackedObjects[i]->willCollide(trackedObjects[j])) {
					trackedObjects[i]->setAlreadyCollided(true);
					trackedObjects[j]->setAlreadyCollided(true);
				}
			}
		}

		trackedObjects[i]->perform();
	}
}