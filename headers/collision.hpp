#pragma once
#include "SFML/Graphics.hpp"

#include <player.hpp>
#include <ball.hpp>

class Collision {
    private:
        std::vector<Player*> players;
        std::vector<Ball*> balls;

    public:
        Collision();
        ~Collision();

        void setPlayers(std::vector<Player*> players);
        void printPlayers();

        void setBalls(std::vector<Ball*> balls);
        void printBalls();
        
        static void checkForCollisions();

        bool ballCollidingBall();
        bool ballCollidingWall();
        bool ballCollidingPaddle();

        bool ballHittingTopBottom();
        bool ballHittingLeftRight();

        bool paddleCollidingWall();

        bool intersectsTop(sf::FloatRect rect);
        bool intersectsBottom(sf::FloatRect rect, int height);

        bool intersectsLeft(sf::FloatRect circle);
        bool intersectsRight(sf::FloatRect circle, int width);

        bool intersects(sf::FloatRect rect1, sf::FloatRect rect2);
};