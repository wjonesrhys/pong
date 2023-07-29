#pragma once
#include "SFML/Graphics.hpp"
#include "collision.hpp"

class Ball {
    private:
        sf::RenderWindow &window;

        sf::CircleShape circle;
        sf::Texture texture;
        Collision collision;
        
        double speed;
        sf::Vector2f direction;

    public:
        Ball(sf::RenderWindow &renderWindow);
        ~Ball();

        void move(float deltaTime, float multiplier);
        void draw();
        void setStartingPosition();

        sf::FloatRect getBounds();
        bool checkScored();
        void resetPosition();
};