#pragma once
#include "SFML/Graphics.hpp"

#include <vector>
#include "player.hpp"
#include "ball.hpp"
#include "score.hpp"
#include "collision.hpp"

class OldGame {
    private:
        sf::RenderWindow &window;

        sf::Font font;

        std::vector<Score*> scores;
        std::vector<Player*> players;
        std::vector<Ball*> balls;

    public:

        OldGame(sf::RenderWindow &renderWindow);
        ~OldGame();

        void adjustScore(std::vector<sf::Vector2i> results);
        
        void setUpMenus();
        void setUpEntities();        
        void setIcon();

        void moveEntities(float dt);
        void drawEntities();
        void destroyEntities();

        void setupGame();
        void updateGame(Collision collision, float dt);
        void startGame();
};