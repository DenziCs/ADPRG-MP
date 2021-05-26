#pragma once
#include "AScene.h"
class GameScene3 : public AScene
{
public:
	GameScene3();
	~GameScene3();

	void onLoadResources();
	void onLoadObjects();
	void onUnloadObjects();
	void onUnloadResources();
	void placeSoftBlocks(std::vector<sf::Vector2i>);

	float timer = 200.f;
};