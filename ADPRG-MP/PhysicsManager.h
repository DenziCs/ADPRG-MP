#pragma once
#include "AComponent.h"
#include "AGameObject.h"
#include"APoolable.h"
#include <unordered_map>
#include <vector>
#include "ContactResolver.h"
#include"ContactResolverIterator.h"
#include"ObjectPoolHolder.h"
#include"GameObjectManager.h"
#include"PlayerObject.h"
#include"ActiveBombObject.h"
#include"BombObject.h"
#include"EnemyObject.h"
#include"SoftBlockObject.h"

typedef std::vector<ContactResolver*> CollisionList;

class PhysicsManager : public AComponent
{
public:
	static string PHYSICS_MANAGER_TAG;

	static void initialize(string name, AGameObject* parent);
	static PhysicsManager* getInstance();
	~PhysicsManager();

	void addContact(ContactResolver* object);
	void perform();
private:
	PhysicsManager(string name) : AComponent(name, Script) { iterator.max_iterations = 25; };
	PhysicsManager(PhysicsManager const&) : AComponent(name, Script) {};             // copy constructor is private
	PhysicsManager& operator=(PhysicsManager const&) {};  // assignment operator is private
	static PhysicsManager* sharedInstance;

	CollisionList collisionList;
	ContactResolverIterator iterator;
};