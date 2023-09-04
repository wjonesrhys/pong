#include <iostream>
#include <cmath>

#include <collision.hpp>
#include <util.hpp>
#include <SFML/Graphics.hpp>

Collision::Collision(sf::RenderWindow& window) : window(window) {

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
        position = player->getPosition();
        // std::cout << "Player: " << count << ", x: " << position.x << ", y: " << position.y << std::endl;
        count++;
    }
}

void Collision::setBalls(std::vector<Ball*> balls) {
    this->balls=balls;
}

void Collision::printBalls() {
    sf::Vector2f position;
    int count = 1;
    for (Ball* ball : this->balls) {
        position = ball->getPosition();
        // std::cout << "Player: " << count << ", x: " << position.x << ", y: " << position.y << std::endl;
        count++;
    }
}

void Collision::checkForCollisions() {
    paddleCollidingWall();
    ballCollidingPaddle();
}

bool Collision::ballCollidingBall() {
    //speed calculation
    //momentum calc?
    //choose directions to send both in
    return true;
}

bool Collision::ballCollidingWall() {
    //     ball.reflectOnWall();
    return true;
}

bool Collision::ballCollidingPaddle() {
    for (Ball* ball : balls) {
        for (Player* player : players) {
            if (distanceBetweenPoints(player->getPosition(), ball->getPosition()) < ball->getBounds().width/2) {
                print(distanceBetweenPoints(player->getPosition(), ball->getPosition()));
                ball->resetPosition();
                ball->reflectOnPaddle();
            }
        }
    }
}

bool Collision::ballHittingTopBottom() {
    return true;
}

bool Collision::ballHittingLeftRight() {
        //     ball.startPosition();
        //     increaseScoreForPlayer(2);

                //     ball.startPosition();
        //     increaseScoreForPlayer(1);
    return true;
}

void Collision::paddleCollidingWall() {  
    sf::FloatRect rect;
    for (Player* player : players) {
        rect = player->getBounds();
        if(intersectsBottomWall(rect,window.getSize().y) || intersectsTopWall(rect)) {
            correctVerticalPosition(player);
        } 
    }
}

bool Collision::intersectsTopWall(sf::FloatRect rect) {
    if (rect.top < 0) {
        return true;
    }
    return false;
}

bool Collision::intersectsBottomWall(sf::FloatRect rect, int height) {
    if (rect.top + rect.height > height) {
        return true;
    }
    return false;
}

void Collision::correctVerticalPosition(Player* player) {
    sf::Vector2f position = player->getPosition();
    sf::Vector2f velocity = player->getVelocity();

    float height = player->getBounds().height;
    // printCoords(position);

    if (velocity.y < 0) { // object came from the top
        player->setPosition(position.x, height/2);
    }

    if (velocity.y > 0) {// object came from the bottom
        player->setPosition(position.x, this->window.getSize().y-height/2);
    }
}

float Collision::distanceBetweenPoints(sf::Vector2f p1, sf::Vector2f p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}