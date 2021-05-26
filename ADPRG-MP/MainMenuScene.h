#pragma once
#include "AScene.h"
#include<SFML/Audio.hpp>

class MainMenuScene : public AScene
{
public:
	MainMenuScene();
	~MainMenuScene();

	void onLoadResources();
	void onLoadObjects();

	void onUnloadResources();
private:
	sf::Sound* sound;
};