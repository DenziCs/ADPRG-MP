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
	for (int i = 1; i <= 4; i++) {
		std::string str_i = std::to_string(i);
		loadSound("sfx_" + str_i, "Assets/SFX/SFX_000" + str_i + ".wav");
	}
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
		cout << "ERROR: No sound effect found for " << key << "." << endl;
		return NULL;
	}
}

void AudioManager::testFunction() {
	cout << "Success!" << endl;
}