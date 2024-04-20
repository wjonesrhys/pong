#include <iostream>
#include <random.hpp>
#include <rectangle.hpp>

Rectangle::Rectangle(sf::Vector2u windowSize) : windowSize(windowSize) {
    std::cout << "Ball created!" << std::endl;
    setUp();
}

Rectangle::~Rectangle() {
    std::cout << "Ball destroyed!" << std::endl;
}

void Rectangle::setUp() {
    this->speed = 400.0f;

    this->rectangle = sf::RectangleShape(sf::Vector2f(40.0f, 40.0f));
    this->rectangle.setFillColor(sf::Color(255, 165, 0, 255));
    this->rectangle.setOrigin(rectangle.getSize()/2.0f);
    this->rectangle.setPosition(windowSize.x/2, windowSize.y/2);

    setStartingPosition();
    setRandomDirection();
}

/**
 * GAME LOOP
*/

void Rectangle::move(float deltaTime) {
    this->prevPosition = this->rectangle.getPosition();
    this->rectangle.move(direction*speed*deltaTime);
}

void Rectangle::draw(sf::RenderWindow& window) {
    window.draw(this->rectangle);
}

void Rectangle::reverseDirectionVertical() {
    this->direction.y *= -1;
}

void Rectangle::reverseDirectionHorizontal() {
    this->direction.x *= -1;
}

void Rectangle::bounce() {
    
}

/**
 * SETTERS
*/

void Rectangle::setLastPosition() {
    this->rectangle.setPosition(this->prevPosition);
}

void Rectangle::setStartingPosition() {
    this->rectangle.setPosition(windowSize.x/2, windowSize.y/2);
}

void Rectangle::setPosition(sf::Vector2f position) {
    this->rectangle.setPosition(position);
}

void Rectangle::setSpeed(float speed) {
    this->speed = speed;
}

void Rectangle::setDirection(sf::Vector2f direction) {
    this->direction = direction;
}

void Rectangle::setRandomDirection() {
    this->direction=sf::Vector2f(Random::randomLeftOrRight(), Random::randomHeight(windowSize, rectangle.getSize().x/2));
}

/**
 * GETTERS
*/

sf::FloatRect Rectangle::getBounds() {
    return this->rectangle.getGlobalBounds();
}

sf::Vector2f Rectangle::getPosition() {
    return this->rectangle.getPosition();
}

float Rectangle::getWidth() {
    // std::cout << this->rectangle.getGlobalBounds().width << std::endl;
    return this->rectangle.getGlobalBounds().width;
}

float Rectangle::getHeight() {
    return this->rectangle.getGlobalBounds().height;
}