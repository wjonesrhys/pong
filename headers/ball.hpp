#pragma once
#include "SFML/Graphics.hpp"

class Ball {
    private:
        
        sf::CircleShape circle;
        sf::Texture texture;

        double speed;
        sf::Vector2f direction;

    public:
        Ball();
        ~Ball();

        void move(float deltaTime, float multiplier);
        void draw(sf::RenderWindow &window);
        void setStartingPosition(sf::RenderWindow &window);
};