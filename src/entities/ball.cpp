#include <iostream>
#include "ball.hpp"

Ball::Ball(sf::RenderWindow &renderWindow, float radius) : window(renderWindow) {
    std::cout << "Ball created!" << std::endl;
    this->circle.setRadius(radius);
    setUp();
}

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

    sf::Vector2u windowSize = window.getSize();
    this->circle.setOrigin(sf::Vector2f(this->circle.getRadius(), this->circle.getRadius()));
    setStartingPosition();
}

/**
 * GAME LOOP
*/

void Ball::move(float deltaTime, float multiplier) {
    this->prevPosition = this->circle.getPosition();
    this->circle.move(speed*direction.x * deltaTime * multiplier, speed*direction.y * deltaTime * multiplier);
}

void Ball::draw() {
    window.draw(this->circle);
}

void Ball::reverseDirectionVertical() {
    this->direction.y *= -1;
}

void Ball::reverseDirectionHorizontal() {
    this->direction.x *= -1;
}

void Ball::bounce() {
    
}

/**
 * SETTERS
*/

void Ball::setLastPosition() {
    this->circle.setPosition(this->prevPosition);
}

void Ball::setStartingPosition() {
    sf::Vector2u windowSize = window.getSize();
    this->circle.setPosition(windowSize.x/2, windowSize.y/2);
}

void Ball::setPosition(sf::Vector2f position) {
    this->circle.setPosition(position);
}

void Ball::setRadius(float radius) {
    this->circle.setRadius(radius);
}

void Ball::setSpeed(float speed) {
    this->speed = speed;
}

/**
 * GETTERS
*/

sf::FloatRect Ball::getBounds() {
    return this->circle.getGlobalBounds();
}

sf::Vector2f Ball::getPosition() {
    return this->circle.getPosition();
}

float Ball::getRadius() {
    return this->circle.getRadius();
}