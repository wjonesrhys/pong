#pragma once
#include "SFML/Graphics.hpp"
#include <vector>

class Game {
    private:
        sf::RenderWindow &window;

    public:
        Game(sf::RenderWindow &renderWindow);
        ~Game();

        void startGame();
        void drawGame();
};