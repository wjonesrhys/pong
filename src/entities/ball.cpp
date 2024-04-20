#include <iostream>
#include <random.hpp>
#include "ball.hpp"

Ball::Ball(sf::Vector2u windowSize, float radius) : windowSize(windowSize) {
    std::cout << "Ball created!" << std::endl;
    this->circle.setRadius(radius);
    setUp();
}

Ball::~Ball() {
    std::cout << "Ball destroyed!" << std::endl;
}

void Ball::setUp() {
    this->speed = 200.0f;

    this->circle = sf::CircleShape(20.f);
    this->circle.setFillColor(sf::Color(255, 165, 0, 255));
    this->circle.setOrigin(sf::Vector2f(this->circle.getRadius(), this->circle.getRadius()));


    setStartingPosition();
    setRandomDirection();
}

/**
 * GAME LOOP
*/

void Ball::move(float deltaTime) {
    this->prevPosition = this->circle.getPosition();
    this->circle.move(direction*speed*deltaTime);
}

void Ball::draw(sf::RenderWindow& window) {
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

void Ball::setDirection(sf::Vector2f direction) {
    this->direction = direction;
}

void Ball::setRandomDirection() {
    this->direction=sf::Vector2f(Random::randomLeftOrRight(), Random::randomHeight(windowSize, circle.getRadius()));
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