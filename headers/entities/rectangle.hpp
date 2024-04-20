#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "SFML/Graphics.hpp"

class Rectangle {
    private:
        sf::Vector2u windowSize;

        sf::RectangleShape rectangle;

        sf::Vector2f direction;
        sf::Vector2f prevPosition;
        float speed;

    public:
        Rectangle(sf::Vector2u windowSize);
        ~Rectangle();

        void setUp();

        void move(float deltaTime);
        void draw(sf::RenderWindow& window);

        void reverseDirectionVertical();
        void reverseDirectionHorizontal();
        void bounce();
        
        void setLastPosition();
        void setStartingPosition();
        
        void setPosition(sf::Vector2f position);
        void setSpeed(float speed);

        void setDirection(sf::Vector2f direction);
        void setRandomDirection();

        sf::FloatRect getBounds();
        sf::Vector2f getPosition();
        float getWidth();
        float getHeight();
};

#endif