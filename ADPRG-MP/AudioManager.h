#include<SFML/Audio.hpp>
#include<unordered_map>
#pragma once

class AudioManager {
public:
	static AudioManager* getInstance();
	void testFunction();
	void loadAll();
	sf::SoundBuffer* getSound(std::string);

private:
	AudioManager() {};
	AudioManager(AudioManager const&) {};
	AudioManager& operator=(AudioManager const&) {};
	static AudioManager* sharedInstance;

	void loadSound(std::string, std::string);
	std::unordered_map<std::string, sf::SoundBuffer*> soundMap;
};