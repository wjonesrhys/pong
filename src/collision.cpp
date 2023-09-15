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
    ballHittingTopBottom();
    ballCollidingBall();
}

void Collision::ballCollidingBall() {
    std::vector<Ball*> ballsCopy = this->balls;

    print("start collision analysis");
    for (Ball* ball : balls) {
        ballsCopy.erase(ballsCopy.begin());
        for (Ball* otherball : ballsCopy) {
            if (distanceBetweenPoints(ball->getPosition(), otherball->getPosition()) < ball->getRadius()) {
                print("colliding");
            } else {
                print ("not colliding");
            }
        }
    }
    //speed calculation
    //momentum calc?
    //choose directions to send both in
}

void Collision::ballCollidingPaddle() {
    for (Ball* ball : balls) {
        for (Player* player : players) {
            sf::Vector2f ballposition = ball->getPosition();
            sf::FloatRect playerRect = player->getBounds();

            sf::Vector2f first_pt = sf::Vector2f(playerRect.top, playerRect.left);
            sf::Vector2f sec_pt = sf::Vector2f(playerRect.top-playerRect.height, playerRect.left+playerRect.width);

            //check the ball point in one of the 9 areas
            //check for collision by using AABB for cross areas +
            //check for collision using a formula for diagonal areas ><

            // printCoords(first_pt);
            // printCoords(sec_pt);

            if (distanceBetweenPoints(player->getPosition(), ball->getPosition()) < ball->getBounds().width/2) {
                ball->resetPosition();
                ball->reflectOnPaddle();
            }
        }
    }
}

void Collision::ballHittingTopBottom() {
    sf::FloatRect ballRect;
    for (Ball* ball : balls) {
        ballRect = ball->getBounds();
        if(intersectsBottomWall(ballRect,window.getSize().y) || intersectsTopWall(ballRect)) {
            ball->resetPosition();
            ball->reflectOnWall();
        } 
    }
}

std::vector<sf::Vector2i> Collision::ballsHittingLeftRight() {
    sf::FloatRect ballRect;
    std::vector<sf::Vector2i> results;
    sf::Vector2i result;
    for (Ball* ball : balls) {
        ballRect = ball->getBounds();
        if (ballRect.left < players.at(0)->getBounds().width) {
            ball->startPosition();
            result.x = 1;
        } 
        
        if (ballRect.left + ballRect.width > window.getSize().x - players.at(0)->getBounds().width) {
            ball->startPosition();
            result.y = 1;
        }
        results.push_back(result);
        result = sf::Vector2i(0,0);
    }

    return results;
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