#pragma once
#include "SFML/Graphics.hpp"

#include <vector>
#include "player.hpp"
#include "ball.hpp"

class Game {
    private:
        sf::RenderWindow &window;
        
        sf::Text p1ScoreText;
        sf::Text p2ScoreText;

        int p1Score;
        int p2Score;

        sf::Font font;

        std::vector<Player*> players;
        std::vector<Ball*> balls;

    public:

        Game(sf::RenderWindow &renderWindow);
        ~Game();

        void resetScore();
        void setUpEntities();
        void destroyEntities();

        void setIcon();
        void loadFont();
        sf::Text setUpText(int playerNum);
        void increaseScoreForPlayer(int playerNum);
        
        void setupGame();
        void startGame();
};