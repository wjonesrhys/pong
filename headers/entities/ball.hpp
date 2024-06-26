#ifndef BALL_H
#define BALL_H

#include "SFML/Graphics.hpp"

class Ball {
    private:
        sf::Vector2u windowSize;

        sf::CircleShape circle;  

        sf::Vector2f direction;
        sf::Vector2f prevPosition;
        float speed;
        
    public:
        Ball(sf::Vector2u windowSize, float radius);
        ~Ball();

        void setUp();

        void move(float deltaTime);
        void draw(sf::RenderWindow& window);

        void reverseDirectionVertical();
        void reverseDirectionHorizontal();
        void bounce();
        
        void setLastPosition();
        void setStartingPosition();
        
        void setPosition(sf::Vector2f position);
        void setRadius(float size);
        void setSpeed(float speed);

        void setDirection(sf::Vector2f direction);
        void setRandomDirection();

        float getRadius();
        sf::FloatRect getBounds();
        sf::Vector2f getPosition();
};

#endif