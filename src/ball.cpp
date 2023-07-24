#include <iostream>
#include "ball.hpp"

Ball::Ball() {
    this->circle = sf::CircleShape(25.f);
    this->circle.setFillColor(sf::Color::Blue);

    this->speed = 10.0f;
    this->direction = sf::Vector2f(1, 0);
}

Ball::~Ball() {
    std::cout << "Ball destroyed!" << std::endl;
}

void Ball::setStartingPosition(sf::RenderWindow &window) {
    sf::Vector2u windowSize = window.getSize();
    float circleSize = this->circle.getRadius();
    this->circle.setOrigin(sf::Vector2f(circleSize, circleSize));
    this->circle.setPosition(windowSize.x/2, windowSize.y/2);
}

void Ball::move(float deltaTime, float multiplier) {
    this->circle.move(speed*direction.x * deltaTime * multiplier, speed*direction.y * deltaTime * multiplier);
}

void Ball::draw(sf::RenderWindow &window) {
    window.draw(this->circle);
}