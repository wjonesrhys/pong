#pragma once
#include "SFML/Graphics.hpp"
#include "collision.hpp"

class Ball {
    private:
        
        sf::CircleShape circle;
        sf::Texture texture;
        Collision collision;

        double speed;
        sf::Vector2f direction;

    public:
        Ball();
        ~Ball();

        void move(float deltaTime, float multiplier);
        void draw(sf::RenderWindow &window);
        void setStartingPosition(sf::RenderWindow &window);
};