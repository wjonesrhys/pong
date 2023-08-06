#pragma once
#include "SFML/Graphics.hpp"

#include "player.hpp"
#include "ball.hpp"


class Game {
    private:
        sf::RenderWindow &window;

        sf::Text p1ScoreText;
        sf::Text p2ScoreText;
        sf::Font font;

        std::vector<Player*> players;
        std::vector<Ball*> balls;

        int p1Score;
        int p2Score;

    public:

        Game(sf::RenderWindow &renderWindow);
        ~Game();

        void setUpEntities();
        void destroyEntities();

        sf::Text setUpText();

        void setIcon();
        void increaseScoreForPlayer(int playerNum);
        
        void setup();
        void start();
};