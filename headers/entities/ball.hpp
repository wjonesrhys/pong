#ifndef BALL_H
#define BALL_H

#include "SFML/Graphics.hpp"

class Ball {
    private:
        sf::RenderWindow &window;

        sf::CircleShape circle;        
        sf::Vector2f direction;
        sf::Vector2f prevPosition;
        double speed;
        
    public:
        Ball(sf::RenderWindow &renderWindow, float radius);
        Ball(sf::RenderWindow &renderWindow);
        ~Ball();

        void setUp();

        void move(float deltaTime, float multiplier);
        void draw();
        
        void setLastPosition();
        void setStartingPosition();
        
        void setPosition(sf::Vector2f position);
        void setRadius(float size);
        void setSpeed(float speed);

        float getRadius();
        sf::FloatRect getBounds();
        sf::Vector2f getPosition();
};

#endif