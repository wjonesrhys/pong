#include <iostream>
#include "ball.hpp"

Ball::Ball(sf::RenderWindow &renderWindow) : window(renderWindow) {
    this->circle = sf::CircleShape(20.f);
    this->circle.setFillColor(sf::Color::Blue);

    this->speed = 5.0f;
    this->direction=setRandomDirection();

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

void Ball::reflect() {
    std::cout << "reflected" << std::endl;
    this->direction.x *= -1;
    this->direction.y *= -1;
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

void Ball::draw() {
    window.draw(this->circle);
}

sf::Vector2f Ball::setRandomDirection() {
    return sf::Vector2f(leftOrRight(),randomHeight());
}

int Ball::leftOrRight() {
    int randNum = rand() * 2 / RAND_MAX;
    std::cout << randNum << std::endl;

    if (randNum == 0) {
        return -1;
    } 

    return 1;
}

float Ball::floatBetweenInts(int lower, int higher) {
    bool wasMinus = false;
    int temp=0;

    if ((lower < 0) && (higher < 0)) {
        wasMinus =true;
        if (lower < higher) {
            temp=lower*-1;
        } else {
            temp=higher*-1;
        }
        lower+=temp;
        higher+=temp;
    }

    if ((lower >= 0) && (higher < 0)) {
        temp=higher;
        higher=lower;
        lower=temp;
    }

    if ((lower < 0) && (higher >= 0)) {
        temp=lower*-1;
        higher+=temp;
        lower+=temp;
        wasMinus=true;
    }

    int range = higher - lower;
    float randNum = (float) rand() / (float) RAND_MAX;

    if (wasMinus) {
        return (randNum * range) - temp;
    }
    return (randNum * range) + lower;
}


float Ball::randomHeight() {
    int randNum = rand() * 2 / RAND_MAX;
    std::cout << randNum << std::endl;

    sf::Vector2u windowSize = this->window.getSize();
    float ballRadius = circle.getRadius();
    

    //calculate the y component of screen vector to the corner - considering radius
    float yScreenComponent = (windowSize.y/2 - ballRadius/2)/(windowSize.x/2 - ballRadius);

    std::cout << "yscreen: " << yScreenComponent << std::endl;
    if (randNum == 0) {
        return rand() * yScreenComponent / RAND_MAX;
    } 

    return rand() * yScreenComponent * -1 / RAND_MAX;
}
