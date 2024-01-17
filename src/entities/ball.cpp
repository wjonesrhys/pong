#include <iostream>
#include "ball.hpp"

Ball::Ball(sf::RenderWindow &renderWindow) : window(renderWindow) {
    std::cout << "Ball created!" << std::endl;
    setUp();
}

Ball::~Ball() {
    std::cout << "Ball destroyed!" << std::endl;
}

void Ball::setUp() {
    this->circle = sf::CircleShape(20.f);
    this->circle.setFillColor(sf::Color(255, 165, 0, 255));

    this->speed = 5.0f;

    setRandomDirection();
    setStartingPosition();
}

/**
 * SETTERS
*/
void Ball::setStartingPosition() {
    sf::Vector2u windowSize = window.getSize();
    float circleSize = this->circle.getRadius();
    this->circle.setOrigin(sf::Vector2f(circleSize, circleSize));
    this->circle.setPosition(windowSize.x/2, windowSize.y/2);
}

void Ball::setPosition(sf::Vector2f position) {
    
}

void Ball::setSize(float size) {

}

void Ball::setSpeed(float speed) {

}

/**
 * GETTERS
*/
//ADD GETTERS HERE

void Ball::move(float deltaTime, float multiplier) {
    this->prevPosition = this->circle.getPosition();
    this->circle.move(speed*direction.x * deltaTime * multiplier, speed*direction.y * deltaTime * multiplier);
}

void Ball::startPosition() {
    setStartingPosition();
    setRandomDirection();
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

void Ball::setRandomDirection() {
    this->direction = sf::Vector2f(leftOrRight(), randHeight());
}

