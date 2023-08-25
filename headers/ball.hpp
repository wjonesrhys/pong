#pragma once
#include "SFML/Graphics.hpp"

class Ball {
    private:
        sf::RenderWindow &window;

        sf::CircleShape circle;
        sf::Texture texture;

        sf::Vector2f prevPosition;
        
        double speed;
        sf::Vector2f direction;

    public:
        Ball(sf::RenderWindow &renderWindow);
        ~Ball();

        void move(float deltaTime, float multiplier);
        void reflectOnPaddle();
        void reflectOnWall();
        
        void draw();
        void setStartingPosition();

        sf::FloatRect getBounds();

        float randHeight();
        bool checkScored();
        void startPosition();
        void resetPosition();
        sf::Vector2f setRandomDirection();
};