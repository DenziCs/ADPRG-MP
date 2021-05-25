#pragma once
#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <vector>

class Game {
    public:
        static const int TILE_SIZE = 40;
        static const int WINDOW_WIDTH = 800;
        static const int WINDOW_HEIGHT = 600;
        const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);

        Game();
        void run();
    private:
        void processEvents();
        void update(sf::Time);
        void render();
    private:
        sf::RenderWindow mWindow;
        std::vector<Entity*> entityList;
};