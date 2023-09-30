#include <iostream>
#include <string>
#include <vector>

#include <game.hpp>
#include <player.hpp>
#include <ball.hpp>
#include <collision.hpp>
#include <util.hpp>

#include "SFML/Graphics.hpp"

Game::Game(sf::RenderWindow& renderWindow) : window(renderWindow) {

}

Game::~Game() {
    std::cout << "Game Closed";
}

void Game::setIcon() {
    sf::Image icon;
    icon.loadFromFile("images/cuppatea.png");
    this->window.setIcon(32,32,icon.getPixelsPtr());
}

void Game::setUpEntities() {
    Score* score1 = new Score(1, window); 
    Score* score2 = new Score(2, window); 

    this->scores.push_back(score1);
    this->scores.push_back(score2);

    Player* player1 = new Player(1, window); 
    Player* player2 = new Player(2, window); 

    this->players.push_back(player1);
    this->players.push_back(player2);

    Ball* ball = new Ball(window);
    this->balls.push_back(ball);
    Ball* ball2 = new Ball(window);
    this->balls.push_back(ball2);
    Ball* ball3 = new Ball(window);
    this->balls.push_back(ball3);
}

void Game::destroyEntities() {
    for (Player *player : this->players) {
        player->~Player();
    }

    for (Ball *ball : this->balls) {
        ball->~Ball();
    }

    for (Score *score : this->scores) {
        score->~Score();
    }
}

void Game::setupGame() {
    //set up game icon
    setIcon();

    //set up the entities
    setUpEntities();
}

void Game::moveEntities(float dt) {
    //players
    for (Player* player : players) {
        player->move(dt, 60);
    }

    //balls
    for (Ball* ball : balls) {
        ball->move(dt, 60);
    }
}

void Game::drawEntities() {
    //players
    for (Player* player : players) {
        player->draw();
    }

    //balls
    for (Ball* ball : balls) {
        ball->draw();
    }

    //scores
    for (Score* score : scores) {
        score->draw();
    }
}

void Game::adjustScore(std::vector<sf::Vector2i> results) {
    for (sf::Vector2i result : results) {
        if (result.x == 1) {
            scores.at(0)->increaseScore();
        }
        if (result.y == 1) {
            scores.at(1)->increaseScore();
        }
    }
}

void Game::startGame() {

    setupGame();
    print("game set up");

    Collision collision = Collision(window);
    collision.setPlayers(this->players);
    collision.setBalls(this->balls);
    print("collision set up");

    collision.ballCollidingBall();

    //framerate independent calculations
    this->window.setFramerateLimit(60);
    sf::Clock clock;
    float multiplier = 60.f;
    float dt;

    print("game about to start");
    while (this->window.isOpen())
    {
        sf::Event event;
        while (this->window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                this->window.close();

            // if (this->p1Score == 10 || this->p2Score == 10) {
            //     this->window.close();
            // }
        }

        dt = clock.restart().asSeconds();

        this->window.clear();

        moveEntities(dt);

        collision.checkForCollisions();
        adjustScore(collision.ballsHittingLeftRight());

        drawEntities();

        this->window.display();

    }

    destroyEntities();
}


