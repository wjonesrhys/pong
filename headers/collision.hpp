#pragma once
#include "SFML/Graphics.hpp"

#include "player.hpp"
#include "ball.hpp"

class Collision {
    private:
        std::vector<Player*> players;
        std::vector<Ball*> balls;

    public:
        Collision(std::vector<Player*> players, std::vector<Ball*> balls);
        ~Collision();

        static void checkForCollisions();

        bool intersectsTop(sf::FloatRect rect);
        bool intersectsBottom(sf::FloatRect rect, int height);

        bool intersectsLeft(sf::FloatRect circle);
        bool intersectsRight(sf::FloatRect circle, int width);

        bool intersects(sf::FloatRect rect1, sf::FloatRect rect2);
        bool intersects(sf::RectangleShape rect1, sf::RectangleShape rect2);
        bool intersects(sf::CircleShape circle1, sf::CircleShape circle2);
        bool intersects(sf::RectangleShape rect, sf::CircleShape circle);
};