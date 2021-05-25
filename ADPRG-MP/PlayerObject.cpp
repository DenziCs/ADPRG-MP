#include "PlayerObject.h"
#include <iostream>
#include "Game.h"
#include "PlayerInputController.h"
#include "PlayerMovement.h"
#include"PlayerAttack.h"
#include "TextureManager.h"
#include "Renderer.h"
#include "RendererFactory.h"
#include "DebugRendererFactory.h"
#include<iostream>

PlayerObject::PlayerObject(string name) : AGameObject(name) {
    this->objectType = Player;
}

void PlayerObject::initialize() {
    this->transformable.setPosition(Game::WINDOW_WIDTH / 2, Game::WINDOW_HEIGHT / 2);

    PlayerInputController* inputController = new PlayerInputController("MyPlayerInput");
    this->attachComponent(inputController);

    PlayerMovement* movement = new PlayerMovement("MyMovement");
    this->attachComponent(movement);

    // Renderer* renderer = Renderer::Create("AirplanePlayerRenderer", "eagle", RendererType::Sprite);
    ARendererFactory* factory = new RendererFactory();
    Renderer* renderer = factory->createSprite("PlayerRenderer", "eagle");
    this->attachComponent(renderer);

    PlayerAttack* attack = new PlayerAttack("MyAttack");
    this->attachComponent(attack);
    attack->setUpPool(20);
}