#include <iostream>
#include "ball.hpp"

Ball::Ball(sf::RenderWindow &renderWindow) : window(renderWindow) {
    this->circle = sf::CircleShape(20.f);
    this->circle.setFillColor(sf::Color::Blue);

    this->speed = 5.0f;
    this->direction = sf::Vector2f(1, 0);

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
    this->circle.move(speed*direction.x * deltaTime * multiplier, speed*direction.y * deltaTime * multiplier);
}

bool Ball::checkScored() {
    return false;
}

void Ball::reflect() {
    std::cout << "reflected" << std::endl;
    this->direction.x *= -1;
    this->direction.y *= -1;
}

void Ball::resetPosition() {
    setStartingPosition();
}

sf::FloatRect Ball::getBounds() {
    return this->circle.getGlobalBounds();
}

void Ball::draw() {
    window.draw(this->circle);
}