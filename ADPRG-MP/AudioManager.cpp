#include "AudioManager.h"
#include<iostream>
#include<SFML/Audio.hpp>
using namespace std;

AudioManager* AudioManager::sharedInstance = NULL;

AudioManager* AudioManager::getInstance() {
	if (sharedInstance == NULL) {
		sharedInstance = new AudioManager();
	}
	return sharedInstance;
}

void AudioManager::loadAll() {
	loadSound("title", "Media/Audio/Title_Theme.wav");
	loadSound("stage", "Media/Audio/Stage_Theme.wav");
	loadSound("transition", "Media/Audio/Transition_Theme.wav");
}

void AudioManager::loadSound(std::string key, std::string path) {
	sf::SoundBuffer* sfx = new sf::SoundBuffer();
	sfx->loadFromFile(path);
	soundMap[key] = sfx;
}

sf::SoundBuffer* AudioManager::getSound(std::string key) {
	if (soundMap[key] != NULL) {
		return soundMap[key];
	}
	else {
		return NULL;
	}
}