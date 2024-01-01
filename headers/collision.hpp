#pragma once
#include "SFML/Graphics.hpp"

#include <player.hpp>
#include <ball.hpp>

class Collision {
    private:
        std::vector<Player*> players;
        std::vector<Ball*> balls;
        sf::Vector2u windowSize;

    public:
        Collision(sf::Vector2u windowSize);
        Collision() = default;
        ~Collision();

        void setPlayers(std::vector<Player*> players);
        void printPlayers();

        void setBalls(std::vector<Ball*> balls);
        void printBalls();
        
        void checkForCollisions();

        void ballCollidingBall();
        void ballCollidingPaddle();

        void ballHittingTopBottom();
        std::vector<sf::Vector2i> ballsHittingLeftRight();

        void paddleCollidingWall();
        void correctVerticalPosition(Player* player);

        bool intersectsTopWall(sf::FloatRect rect);
        bool intersectsBottomWall(sf::FloatRect rect, int height);

        float distanceBetweenPoints(sf::Vector2f p1, sf::Vector2f p2);
};