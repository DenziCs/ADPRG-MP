#include "SpriteRenderer.h"
#include "TextureManager.h"

SpriteRenderer::SpriteRenderer(string name, string textureName) : Renderer(name) {
	sf::Sprite* newSprite = new sf::Sprite();
	newSprite->setTexture(*TextureManager::getInstance()->getTexture(textureName));
	sf::Vector2u textureSize = newSprite->getTexture()->getSize();
	newSprite->setOrigin(textureSize.x / 2, textureSize.y / 2);
	this->assignDrawable(newSprite);
	sprite = newSprite;
}

sf::Sprite* SpriteRenderer::getSprite() {
	return sprite;
}