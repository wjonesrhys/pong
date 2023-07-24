#include <iostream>
#include "player.hpp"
#include "collision.hpp"

Player::Player(int playerNum, std::string imgPath, sf::RenderWindow& renderWindow) : window(renderWindow) {
    this->collision = Collision();

    std::cout << "Player created!" << std::endl;
    this->playerNum = playerNum;

    if (this->texture.loadFromFile(imgPath)){
        std::cout << "Texture for player " << this->playerNum << " loaded!" << std::endl;
        this->sprite.setTexture(texture);
    } else {
        std::cout << "Texture for player not loaded!" << std::endl;
    }
}

Player::~Player() {
    std::cout << "Player destroyed!" << std::endl;
}

sf::Sprite Player::getSprite() {
    return this->sprite;
}


void Player::draw() {
    window.draw(this->sprite);
}

void Player::setStartingPosition() {
    sf::Vector2u textureSize = this->texture.getSize();
    this->sprite.setOrigin(sf::Vector2f(textureSize.x/2,textureSize.y/2));

    sf::Vector2u windowSize = window.getSize();

    if (this->playerNum==1) {
        this->sprite.setPosition(textureSize.x, windowSize.y/2);
    }

    if (this->playerNum==2) {
        this->sprite.setPosition(windowSize.x - textureSize.x,windowSize.y/2);
    }
}

void Player::move(float deltaTime, float multiplier)
{
    sf::Vector2f movement;

    this->deltaTime = deltaTime;
    this->multiplier = multiplier;

    if (this->playerNum==1) {
        // moveHorizontal(sf::Keyboard::Left, sf::Keyboard::Right);
        moveVertical(sf::Keyboard::Up, sf::Keyboard::Down);
    }
    if (this->playerNum==2) {
        // moveHorizontal(sf::Keyboard::A, sf::Keyboard::D);
        moveVertical(sf::Keyboard::W, sf::Keyboard::S);
    }

    //if its stepping over border
    if(isCollidingWithWall()) {
        //reset to be up against the wall
        correctVerticalPosition();
    }
    
}

void Player::moveHorizontal(sf::Keyboard::Key left, sf::Keyboard::Key right) {
    if (sf::Keyboard::isKeyPressed(left)) {
        this->velocity=sf::Vector2f(-5.f,0);
        sprite.move(sf::Vector2f(-5.f * deltaTime * multiplier, 0.0f));
    }
    if (sf::Keyboard::isKeyPressed(right)) {
        this->velocity=sf::Vector2f(5.f,0);
        sprite.move(sf::Vector2f(5.f * deltaTime * multiplier, 0.0f));
    }
}

void Player::moveVertical(sf::Keyboard::Key up, sf::Keyboard::Key down) {
    // --- Vertical Movement --- //=
    if (sf::Keyboard::isKeyPressed(up)) {
        this->velocity=sf::Vector2f(0,-5.f);
        sprite.move(sf::Vector2f(0.f,-5.0f * deltaTime * multiplier));
    }
    if (sf::Keyboard::isKeyPressed(down)) {
        this->velocity=sf::Vector2f(0,5.f);
        sprite.move(sf::Vector2f(0.f,5.0f * deltaTime * multiplier));
    }
}

void Player::correctVerticalPosition() {
    sf::Vector2u textureSize = this->texture.getSize();
    std::cout << "this velocity: " << this->velocity.y << std::endl;

    if (this->velocity.y < 0) { // object came from the top
        this->sprite.setPosition(this->sprite.getPosition().x, textureSize.x/2);
        std::cout << "x: " << this->sprite.getPosition().x << ", y: " << textureSize.x/2 << std::endl;
    }

    if (this->velocity.y > 0) {// object came from the bottom
        this->sprite.setPosition(this->sprite.getPosition().x, this->window.getSize().y-textureSize.x/2);
        std::cout << "x: " << this->sprite.getPosition().x << ", y: " << this->window.getSize().y-textureSize.x/2 << std::endl;
    }
}

bool Player::isCollidingWithWall() {
    bool isCollisionTop = collision.intersectsTop(this->sprite.getGlobalBounds());
    bool isCollisionBottom = collision.intersectsBottom(this->sprite.getGlobalBounds(),window.getSize().y);

    if (isCollisionBottom || isCollisionTop) {
        return true;
    } 
    
    return false;
}



