#pragma once
#include "AComponent.h"
#include "AGameObject.h"
#include"APoolable.h"
#include <unordered_map>
#include <vector>
#include "Collider.h"
#include"ObjectPoolHolder.h"

typedef std::vector<Collider*> CollisionList;

class PhysicsManager : public AComponent
{
public:
	static string PHYSICS_MANAGER_TAG;

	static void initialize(string name, AGameObject* parent);
	static void destroy();
	static PhysicsManager* getInstance();
	~PhysicsManager();

	void trackObject(Collider* object);
	void untrackObject(Collider* object);

	void perform();

private:
	PhysicsManager(string name) : AComponent(name, Script) {};
	PhysicsManager(PhysicsManager const&) : AComponent(name, Script) {};             // copy constructor is private
	PhysicsManager& operator=(PhysicsManager const&) {};  // assignment operator is private
	static PhysicsManager* sharedInstance;

	CollisionList trackedObjects;
	CollisionList forCleaningObjects;

	void cleanUpObjects();
};