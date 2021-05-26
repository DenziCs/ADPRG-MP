#pragma once
#include "AScene.h"
#include"SceneManager.h"
#include"UIText.h"
#include"EmptyGameObject.h"
#include"TransitionUpdate.h"
#include"Game.h"
#include<SFML/Audio.hpp>

class TransitionScene : public AScene
{
public:
	TransitionScene();
	~TransitionScene() {}

	void onLoadResources() {}
	void onLoadObjects();
	void onUnloadObjects();
	void onUnloadResources();

	string nextScene;
private:
	float timer = 2.5f;
	sf::Sound* sound;
};