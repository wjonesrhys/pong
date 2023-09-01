#include <iostream>
#include <vector>
#include <string>

#include <collision.hpp>
#include <player.hpp>

#include <SFML/Graphics.hpp>

Collision::Collision() {

}

Collision::~Collision() {

}

void Collision::setPlayers(std::vector<Player*> players) {
    this->players=players;
}

void Collision::printPlayers() {
    sf::Vector2f position;
    int count = 1;
    for (Player* player : this->players) {
        position = player->getRect().getPosition();
        std::cout << "Player: " << count << ", x: " << position.x << ", y: " << position.y << std::endl;
        count++;
    }
}


void Collision::checkForCollisions() {
    
}

bool Collision::ballCollideBall() {
    return true;
}

bool Collision::ballCollideWall() {
    return true;
}

bool Collision::ballCollidePaddle() {
    return true;
}

bool Collision::ballHittingTopBottom() {
    return true;
}

bool Collision::ballHittingLeftRight() {
    return true;
}

bool Collision::paddleCollideWall() {
    return true;
}

bool Collision::intersectsTop(sf::FloatRect rect) {
    if (rect.top < 0) {
        return true;
    }
    return false;
}

bool Collision::intersectsBottom(sf::FloatRect rect, int height) {
    if (rect.top + rect.height > height) {
        return true;
    }
    return false;
}

bool Collision::intersectsLeft(sf::FloatRect rect) {
    if (rect.left < rect.width/2) {
        return true;
    }
    return false;
}

bool Collision::intersectsRight(sf::FloatRect rect, int width) {
    if (rect.left+rect.width > width-rect.width/2) {
        return true;
    }
    return false;
}

bool Collision::intersects(sf::RectangleShape rect1, sf::RectangleShape rect2) {
    return false;
}

bool Collision::intersects(sf::CircleShape circle1, sf::CircleShape circle2) {
    return true;
}

bool Collision::intersects(sf::FloatRect rect, sf::FloatRect circle) {
    if (rect.intersects(circle)) {
        return true;
    }
    return false;
}

bool Collision::intersects(sf::RectangleShape rect, sf::CircleShape circle) {
    return true;
}


