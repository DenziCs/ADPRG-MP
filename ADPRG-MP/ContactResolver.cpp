#include "ContactResolver.h"
#include"ApplicationManager.h"

ContactResolver::ContactResolver(AGameObject* object1, AGameObject* object2) {
	objects[0] = object1;
	objects[1] = object2;
}

void ContactResolver::resolve() {
	switch (objects[0]->getObjectType()) {
	case AGameObject::Player:
		ApplicationManager::getInstance()->applicationQuit();
		break;
	}
}