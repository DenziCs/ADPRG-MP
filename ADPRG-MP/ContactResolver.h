#pragma once
#include"AGameObject.h"

class ContactResolver {
public:
	ContactResolver() {};
	ContactResolver(AGameObject*, AGameObject*);
	void resolve();

	AGameObject* objects[2];
};