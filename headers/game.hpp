#pragma once
#include "SFML/Graphics.hpp"

class Game {
    private:
        sf::RenderWindow &window;

    public:

        Game(sf::RenderWindow &renderWindow);
        ~Game();

        void setIcon();
        void setUpScores();
        
        void setup();
        void start();
};