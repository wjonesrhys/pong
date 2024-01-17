#ifndef BALL_H
#define BALL_H

#include "SFML/Graphics.hpp"
#include <random>

class Ball {
    private:
        std::random_device rd;
        sf::RenderWindow &window;

        sf::CircleShape circle;
        sf::Texture texture;

        sf::Vector2f prevPosition;
        
        double speed;
        sf::Vector2f direction;

    public:
        Ball(sf::RenderWindow &renderWindow);
        ~Ball();

        void setUp();

        void move(float deltaTime, float multiplier);
        void draw();

        void setStartingPosition();
        void setPosition(sf::Vector2f position);
        void setSize(float size);
        void setSpeed(float speed);

        sf::FloatRect getBounds();
        sf::Vector2f getPosition();
        float getRadius();

        void startPosition();
        void resetPosition();
        void setRandomDirection();
};

#endif


float randHeight();
int leftOrRight();
bool checkScored();

int Ball::leftOrRight() {
    int randNum = rd() * 2 / RAND_MAX;
    return randNum == 0 ? -1 : 1;
}

float Ball::randHeight() {
    int randNum = rd() * 2 / RAND_MAX;
    // std::cout << randNum << std::endl;

    sf::Vector2u windowSize = this->window.getSize();
    float ballRadius = circle.getRadius();
    
    //calculate the y component of screen vector to the corner - considering radius
    float yScreenComponent = (windowSize.y/2 - ballRadius/2) / (windowSize.x/2 - ballRadius);

    if (randNum == 0) {
        return rand() * yScreenComponent / RAND_MAX;
    } 

    return rand() * yScreenComponent * -1 / RAND_MAX;
}


bool Ball::checkScored() {
    return false;
}