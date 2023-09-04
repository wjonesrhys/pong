#include <iostream>

#include <player.hpp>
#include <util.hpp>

Player::Player(int playerNum, std::string imgPath, sf::RenderWindow& renderWindow) : window(renderWindow) {
    // this->collision = Collision();

    std::cout << "Player created!" << std::endl;
    this->playerNum = playerNum;

    if (this->texture.loadFromFile(imgPath)){
        std::cout << "Texture for player " << this->playerNum << " loaded!" << std::endl;
        this->sprite.setTexture(texture);
    } else {
        std::cout << "Texture for player not loaded!" << std::endl;
    }
}

Player::Player(int playerNum, sf::RenderWindow& renderWindow) : window(renderWindow) {
    // this->collision = Collision();

    std::cout << "Player created!" << std::endl;
    this->playerNum = playerNum;

    this->rect.setFillColor(sf::Color::Green);
    this->rect.setSize(sf::Vector2f(20, 50));
    setStartingPosition();
}

Player::~Player() {
    std::cout << "Player destroyed!" << std::endl;
}

void Player::draw() {
    // window.draw(this->sprite);
    window.draw(this->rect);
}

void Player::setStartingPosition() {

    sf::Vector2f rectSize = this->rect.getSize();
    this->rect.setOrigin(sf::Vector2f(rectSize.x/2,rectSize.y/2));

    sf::Vector2u windowSize = window.getSize();

    if (this->playerNum==1) {
        this->rect.setPosition(rectSize.x, windowSize.y/2);
    }

    if (this->playerNum==2) {
        this->rect.setPosition(windowSize.x - rectSize.x,windowSize.y/2);
    }

}

void Player::move(float deltaTime, float multiplier)
{
    this->deltaTime = deltaTime;
    this->multiplier = multiplier;

    if (this->playerNum==1) {
        moveVertical(sf::Keyboard::Up, sf::Keyboard::Down);
    }
    if (this->playerNum==2) {
        moveVertical(sf::Keyboard::W, sf::Keyboard::S);
    }
}

void Player::moveVertical(sf::Keyboard::Key up, sf::Keyboard::Key down) {
    // --- Vertical Movement --- //
    if (sf::Keyboard::isKeyPressed(up)) {
        this->velocity=sf::Vector2f(0,-5.f);
        rect.move(sf::Vector2f(0.f,-5.0f * deltaTime * multiplier));
    }

    if (sf::Keyboard::isKeyPressed(down)) {
        this->velocity=sf::Vector2f(0,5.f);
        rect.move(sf::Vector2f(0.f,5.0f * deltaTime * multiplier));
    }
}

void Player::setPosition(float x_coord, float y_coord) { 
    this->rect.setPosition(sf::Vector2f(x_coord, y_coord));
}

sf::Vector2f Player::getPosition() {
    return this->rect.getPosition();
}

sf::FloatRect Player::getBounds(){
    return this->rect.getGlobalBounds();
}

sf::RectangleShape Player::getRect(){
    return this->rect;
}

sf::Vector2f Player::getVelocity() {
    return this->velocity;
}