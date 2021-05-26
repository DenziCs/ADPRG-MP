#pragma once
#include "AScene.h"
class GameScene2 : public AScene
{
public:
	GameScene2();
	~GameScene2();

	void onLoadResources();
	void onLoadObjects();
	void onUnloadObjects();
	void onUnloadResources();
	void placeSoftBlocks(std::vector<sf::Vector2i>);

	float timer = 200.f;
};