#pragma once
#include "SFML/Graphics.hpp"

#include <player.hpp>

class Collision {
    private:
        std::vector<Player*> players;

    public:
        Collision();
        ~Collision();

        // ball:
        // ball -> top and bottom
        // ball -> left and right
        // ball -> ball
        // ball -> paddle

        // paddle
        // to top and bottom

        void setPlayers(std::vector<Player*> players);
        void printPlayers();
        static void checkForCollisions();

        bool ballCollideBall();
        bool ballCollideWall();
        bool ballCollidePaddle();

        bool ballHittingTopBottom();
        bool ballHittingLeftRight();

        bool paddleCollideWall();

        bool intersectsTop(sf::FloatRect rect);
        bool intersectsBottom(sf::FloatRect rect, int height);

        bool intersectsLeft(sf::FloatRect circle);
        bool intersectsRight(sf::FloatRect circle, int width);

        bool intersects(sf::FloatRect rect1, sf::FloatRect rect2);
        bool intersects(sf::RectangleShape rect1, sf::RectangleShape rect2);
        bool intersects(sf::CircleShape circle1, sf::CircleShape circle2);
        bool intersects(sf::RectangleShape rect, sf::CircleShape circle);
};