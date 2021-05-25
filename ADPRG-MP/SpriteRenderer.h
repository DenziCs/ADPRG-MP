#pragma once
#include "Renderer.h"
class SpriteRenderer : public Renderer
{
public:
	SpriteRenderer(string name, string textureName);
	sf::Sprite* getSprite();
private:
	sf::Sprite* sprite;
};