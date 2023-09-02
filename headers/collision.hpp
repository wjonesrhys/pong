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
        bool ballCollidingPaddle();

        bool ballHittingTopBottom();
        bool ballHittingLeftRight();

        void paddleCollidingWall();
        void correctVerticalPosition(Player* player);

        bool intersectsTop(sf::FloatRect rect);
        bool intersectsBottom(sf::FloatRect rect, int height);

        bool intersectsLeft(sf::FloatRect circle);
        bool intersectsRight(sf::FloatRect circle, int width);

        bool intersects(sf::FloatRect rect1, sf::FloatRect rect2);
};