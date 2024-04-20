#include <iostream>
#include <player.hpp>

Player::Player(int playerNum, sf::Vector2u windowSize) 
    : windowSize(windowSize),
      playerNum(playerNum),
      speed(200)
{
    std::cout << "Player created!" << std::endl;
    this->shape.setFillColor(sf::Color::Green);
    this->shape.setSize(sf::Vector2f(20, 50));
    setStartingPosition();
}

Player::~Player() {
    std::cout << "Player destroyed!" << std::endl;
}

/**
 * GAME LOOP
*/

void Player::draw(sf::RenderWindow& window) {
    window.draw(this->shape);
}

void Player::move(float deltaTime)
{
    if (this->playerNum==1) {
        moveVertical(sf::Keyboard::Up, sf::Keyboard::Down, deltaTime);
    }
    if (this->playerNum==2) {
        moveVertical(sf::Keyboard::W, sf::Keyboard::S, deltaTime);
    }
}

void Player::moveVertical(sf::Keyboard::Key up, sf::Keyboard::Key down, float deltaTime) {
    // --- Vertical Movement --- //
    if (sf::Keyboard::isKeyPressed(up)) {
        this->velocity=sf::Vector2f(0,-1.f);
        shape.move(this->velocity*deltaTime*speed);
    }

    if (sf::Keyboard::isKeyPressed(down)) {
        this->velocity=sf::Vector2f(0,1.f);
        shape.move(this->velocity*deltaTime*speed);
    }
}

/**
 * SETTERS
*/


void Player::setPosition(float x_coord, float y_coord) { 
    this->shape.setPosition(sf::Vector2f(x_coord, y_coord));
}

void Player::setStartingPosition() {

    sf::Vector2f shapeSize = this->shape.getSize();
    this->shape.setOrigin(sf::Vector2f(shapeSize.x/2,shapeSize.y/2));

    if (this->playerNum==1) {
        this->shape.setPosition(shapeSize.x, windowSize.y/2);
    }

    if (this->playerNum==2) {
        this->shape.setPosition(windowSize.x - shapeSize.x,windowSize.y/2);
    }

}

void Player::setVelocity(sf::Vector2f newVelocity) {
    this->velocity = newVelocity;
}

/**
 * GETTERS
*/

sf::Vector2f Player::getPosition() {
    return this->shape.getPosition();
}

float Player::getLowestPoint() {
    return shape.getGlobalBounds().top;
}

float Player::getHighestPoint() {
    sf::FloatRect rect = shape.getGlobalBounds();
    return rect.top + rect.height;
}

sf::Vector2f Player::getVelocity() {
    return this->velocity;
}

float Player::getHeight() {
    return shape.getGlobalBounds().height;
}

float Player::getWidth() {
    return shape.getGlobalBounds().width;
}

int Player::getPlayerNum() {
    return playerNum;
}