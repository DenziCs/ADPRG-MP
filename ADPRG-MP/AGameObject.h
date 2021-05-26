#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "AComponent.h"

using namespace std;

class AGameObject
{
public:
	enum ObjectType {
		Misc = 0,
		Player = 1,
		Enemy = 2,
		Hardblock = 3,
		Softblock = 4,
		Powerup = 5,
		Bomb = 6,
		ActiveBomb = 7
	};

	AGameObject(std::string  name);
	virtual ~AGameObject();
	virtual void initialize() = 0;
	virtual void processInput(sf::Event event);
	virtual void update(sf::Time deltaTime);
	void draw(sf::RenderWindow* targetWindow, sf::RenderStates renderStates);
	std::string getName();
	ObjectType getObjectType();
	void attachChild(AGameObject* child);
	void detachChild(AGameObject* child);
	void setPosition(float x, float y);

	void attachComponent(AComponent* component);
	void detachComponent(AComponent* component);

	AComponent* findComponentByName(string name);
	AComponent* findComponentOfType(AComponent::ComponentType type, string name);
	std::vector <AComponent*> getComponentsOfType(AComponent::ComponentType type);
	std::vector <AComponent*> getComponentsOfTypeRecursive(AComponent::ComponentType type);

	sf::Transformable* getTransformable();

	virtual sf::FloatRect getLocalBounds();
	virtual sf::FloatRect getGlobalBounds();
	sf::Transform getGlobalTransform();

	AGameObject* getParent();

	void setEnabled(bool flag);
	bool isEnabled();

protected:
	sf::Transformable transformable;
	std::string name;
	ObjectType objectType;
	std::vector<AGameObject*> childList;
	std::vector<AComponent*> componentList;
	AGameObject* parent;

private:
	std::vector <AComponent*> getComponentsRecursiveProper(AGameObject* object, AComponent::ComponentType type, std::vector<AComponent*> foundList);
	bool enabled = true;
};

