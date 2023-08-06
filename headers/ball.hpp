#pragma once
#include "SFML/Graphics.hpp"
#include "collision.hpp"

class Ball {
    private:
        sf::RenderWindow &window;

        sf::CircleShape circle;
        sf::Texture texture;
        Collision collision;

        sf::Vector2f prevPosition;
        
        double speed;
        sf::Vector2f direction;

    public:
        Ball(sf::RenderWindow &renderWindow);
        ~Ball();

        void move(float deltaTime, float multiplier);
        void reflect();
        void draw();
        void setStartingPosition();

        sf::FloatRect getBounds();
        bool checkScored();
        void startPosition();
        void resetPosition();
};