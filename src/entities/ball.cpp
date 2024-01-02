#include <iostream>
#include "ball.hpp"
#include "util.hpp"

Ball::Ball(sf::RenderWindow &renderWindow) : window(renderWindow) {
    this->circle = sf::CircleShape(20.f);
    this->circle.setFillColor(sf::Color::Blue);

    this->speed = 5.0f;
    this->direction=setRandomDirection();
    setStartingPosition();

    std::cout << "Ball created!" << std::endl;
}

Ball::~Ball() {
    std::cout << "Ball destroyed!" << std::endl;
}

void Ball::setStartingPosition() {
    sf::Vector2u windowSize = window.getSize();
    float circleSize = this->circle.getRadius();
    this->circle.setOrigin(sf::Vector2f(circleSize, circleSize));
    this->circle.setPosition(windowSize.x/2, windowSize.y/2);
}

void Ball::move(float deltaTime, float multiplier) {
    this->prevPosition = this->circle.getPosition();
    this->circle.move(speed*direction.x * deltaTime * multiplier, speed*direction.y * deltaTime * multiplier);
}

bool Ball::checkScored() {
    return false;
}

void Ball::reflectOnWall() {
    this->direction.y *= -1;
}

void Ball::reflectOnPaddle() {
    this->direction.x *= -1;
}

void Ball::startPosition() {
    setStartingPosition();
    this->direction=setRandomDirection();
}

void Ball::resetPosition() {
    this->circle.setPosition(this->prevPosition);
}

sf::FloatRect Ball::getBounds() {
    return this->circle.getGlobalBounds();
}


sf::Vector2f Ball::getPosition() {
    return this->circle.getPosition();
}

float Ball::getRadius() {
    return this->circle.getRadius();
}

void Ball::draw() {
    window.draw(this->circle);
}

sf::Vector2f Ball::setRandomDirection() {
    return sf::Vector2f(zeroOrOne(), randHeight());
}

float Ball::randHeight() {
    int randNum = rand() * 2 / RAND_MAX;
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
