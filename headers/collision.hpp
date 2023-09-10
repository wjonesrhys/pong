#pragma once
#include "SFML/Graphics.hpp"

#include <player.hpp>
#include <ball.hpp>

class Collision {
    private:
        std::vector<Player*> players;
        std::vector<Ball*> balls;

        sf::RenderWindow &window;

    public:
        Collision(sf::RenderWindow& window);
        ~Collision();

        void setPlayers(std::vector<Player*> players);
        void printPlayers();

        void setBalls(std::vector<Ball*> balls);
        void printBalls();
        
        void checkForCollisions();

        bool ballCollidingBall();
        bool ballCollidingWall();
        void ballCollidingPaddle();

        bool ballHittingTopBottom();
        bool ballHittingLeftRight();

        void paddleCollidingWall();
        void correctVerticalPosition(Player* player);

        bool intersectsTopWall(sf::FloatRect rect);
        bool intersectsBottomWall(sf::FloatRect rect, int height);

        float distanceBetweenPoints(sf::Vector2f p1, sf::Vector2f p2);
};