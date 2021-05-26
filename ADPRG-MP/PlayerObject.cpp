#include "PlayerObject.h"
#include <iostream>
#include "Game.h"
#include "PlayerInputController.h"
#include "PlayerMovement.h"
#include"PlayerAttack.h"
#include "TextureManager.h"
#include "Renderer.h"
#include "SpriteRenderer.h"
#include "RendererFactory.h"
#include "DebugRendererFactory.h"
#include<iostream>

PlayerObject::PlayerObject(string name) : AGameObject(name) {
    this->objectType = Player;
    sprite = NULL;
}

void PlayerObject::initialize() {
    this->sprite = new sf::Sprite();
    this->sprite->setTexture(*TextureManager::getInstance()->getTexture("player"));
    sf::Vector2u textureSize = this->sprite->getTexture()->getSize();
    this->sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);

    PlayerInputController* inputController = new PlayerInputController("MyPlayerInput");
    this->attachComponent(inputController);

    PlayerMovement* movement = new PlayerMovement("MyMovement");
    this->attachComponent(movement);

    PlayerAttack* attack = new PlayerAttack("MyBombDrop");
    this->attachComponent(attack);

    Renderer* renderer = new Renderer("PlayerRenderer");
    renderer->assignDrawable(this->sprite);
    this->attachComponent(renderer);
}

sf::FloatRect PlayerObject::getGlobalBounds() {
    sf::FloatRect bounds = this->sprite->getGlobalBounds();
    bounds = this->getGlobalTransform().transformRect(bounds);
    return bounds;
}