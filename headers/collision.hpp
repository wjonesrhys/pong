#pragma once
#include "SFML/Graphics.hpp"

class Collision {
    private:

    public:
        Collision();
        ~Collision();

        bool intersectsTop(sf::FloatRect rect);
        bool intersectsBottom(sf::FloatRect rect, int height);

        bool intersectsLeft(sf::FloatRect circle);
        bool intersectsRight(sf::FloatRect circle, int width);

        bool intersects(sf::FloatRect rect1, sf::FloatRect rect2);
        bool intersects(sf::RectangleShape rect1, sf::RectangleShape rect2);
        bool intersects(sf::CircleShape circle1, sf::CircleShape circle2);
        bool intersects(sf::RectangleShape rect, sf::CircleShape circle);
};