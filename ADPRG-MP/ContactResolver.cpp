#include "ContactResolver.h"
#include"ApplicationManager.h"
#include"GameObjectManager.h"
#include"ObjectPoolHolder.h"
#include"APoolable.h"

ContactResolver::ContactResolver(AGameObject* object1, AGameObject* object2) {
	objects[0] = object1;
	objects[1] = object2;
}

void ContactResolver::resolve() {
	switch (objects[0]->getObjectType()) {
	case AGameObject::Player:
		switch (objects[1]->getObjectType()) {
		case AGameObject::Enemy:
		case AGameObject::ActiveBomb:
			ApplicationManager::getInstance()->applicationQuit();
			break;
		}
	break;
	case AGameObject::Enemy:
		switch (objects[1]->getObjectType()) {
		case AGameObject::Enemy:
			break;
		case AGameObject::ActiveBomb:
			GameObjectManager::getInstance()->deleteObject(objects[0]);
			break;
		}
	break;
	}
}