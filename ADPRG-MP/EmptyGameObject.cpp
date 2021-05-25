#include "EmptyGameObject.h"

EmptyGameObject::EmptyGameObject(string name) : AGameObject(name)
{
	this->objectType = Misc;
}

EmptyGameObject::~EmptyGameObject()
{
	AGameObject::~AGameObject();
}

void EmptyGameObject::initialize()
{
}