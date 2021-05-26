#pragma once
#include "AComponent.h"
#include "CollisionListener.h"
#include "AGameObject.h"
#include"PhysicsManager.h"
#include"GameObjectManager.h"
#include<vector>

class Collider : public AComponent {

public:
	Collider(string name) : AComponent(name, Script) {}
	void perform();
};