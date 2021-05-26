#include <stddef.h>
#include <iostream>
#include "TextureManager.h"

TextureManager* TextureManager::sharedInstance = NULL;

TextureManager* TextureManager::getInstance() {
		//initialize only when we need it
		if (sharedInstance == NULL) {
			sharedInstance = new TextureManager();
		}
		return sharedInstance;
}

void TextureManager::loadAll() {

	loadTexture("stageBG", "Media/Textures/stageBG.png");
	sf::Texture* bgTex;
	bgTex = getTexture("stageBG");
	bgTex->setRepeated(true);

	loadTexture("sheet", "Media/Textures/spriteSheet.png");
	loadTexture("ui_bg", "Media/Textures/f.png");
	loadTexture("btn_normal", "Media/Textures/b_4.png");
	loadTexture("btn_pressed", "Media/Textures/b_5.png");
	loadTexture("hud_bg", "Media/Textures/bar_1.png");
	loadTexture("title_bg", "Media/Textures/TitleScreenBG.png");
}

void TextureManager::loadTexture(std::string key, std::string path) {
	sf::Texture* texture = new sf::Texture();
	texture->loadFromFile(path);
	textureMap[key] = texture;
}

sf::Texture* TextureManager::getTexture(std::string key) {
	if (textureMap[key] != NULL) {
		return textureMap[key];
	}
	else {
		std::cout << "No texture found for " << key;
		return NULL;
	}
}

void TextureManager::testFunction() {
	std::cout << "Hi, I'm single-ton ;D";
}