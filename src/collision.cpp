#include <iostream>

#include <collision.hpp>
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
    
}

bool Collision::ballCollidingBall() {
    return true;
}

bool Collision::ballCollidingWall() {
    return true;
}

bool Collision::ballCollidingPaddle() {
    return true;
}

bool Collision::ballHittingTopBottom() {
    return true;
}

bool Collision::ballHittingLeftRight() {
    return true;
}

bool Collision::paddleCollidingWall() {
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

bool Collision::intersects(sf::FloatRect rect, sf::FloatRect circle) {
    if (rect.intersects(circle)) {
        return true;
    }
    return false;
}



        // if (collision.intersectsLeft(ball.getBounds())) {
        //     ball.startPosition();
        //     increaseScoreForPlayer(2);
        // }

        // if (collision.intersectsRight(ball.getBounds(), window.getSize().x)) {
        //     ball.startPosition();
        //     increaseScoreForPlayer(1);
        // }

        // if (collision.intersects(player2.getRect(), ball.getBounds()) || collision.intersects(player1.getRect(), ball.getBounds())){
        //     ball.resetPosition();
        //     ball.reflectOnPaddle();
        // } 

        // if (collision.intersectsTop(ball.getBounds()) || collision.intersectsBottom(ball.getBounds(), window.getSize().y)) {
        //     ball.reflectOnWall();
        // }