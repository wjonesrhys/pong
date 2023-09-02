#include <iostream>

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

void Collision::paddleCollidingWall() {  
    sf::FloatRect rect;
    for (Player* player : players) {
        rect = player->getBounds();
        printCoords(player->getPosition());
        if(intersectsBottom(rect,window.getSize().y) || intersectsTop(rect)) {
            std::cout << "colliding" << std::endl;
            correctVerticalPosition(player);
        } else {
            std::cout << "not colliding" << std::endl;
        }
    }
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

void Collision::correctVerticalPosition(Player* player) {
    sf::Vector2f position = player->getPosition();
    sf::Vector2f velocity = player->getVelocity();

    float height = player->getBounds().height;
    printCoords(position);

    if (velocity.y < 0) { // object came from the top
        player->setPosition(position.x, height/2);
    }

    if (velocity.y > 0) {// object came from the bottom
        player->setPosition(position.x, this->window.getSize().y-height/2);
    }
}