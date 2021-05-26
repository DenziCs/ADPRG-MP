#pragma once
#include "AScene.h"
#include<SFML/Audio.hpp>

class GameScene : public AScene
{
public:
	GameScene();
	~GameScene();

	void onLoadResources();
	void onLoadObjects();
	void onUnloadObjects();
	void onUnloadResources();
	void placeSoftBlocks(std::vector<sf::Vector2i>);

	float timer = 200.f;
private:
	sf::Sound* sound;
};