#pragma once
#include "SFML/Graphics.hpp"

class Game {
    private:
        sf::RenderWindow &window;

        sf::Text p1ScoreText;
        sf::Text p2ScoreText;
        sf::Font font;

        int p1Score;
        int p2Score;

    public:

        Game(sf::RenderWindow &renderWindow);
        ~Game();

        void setIcon();
        sf::Text setUpText();
        void increaseScore(int playerNum);
        
        void setup();
        void start();
};