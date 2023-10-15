#include <iostream>
#include <string>
#include <vector>

#include <game.hpp>
#include <player.hpp>
#include <ball.hpp>
#include <collision.hpp>
#include <util.hpp>
#include <menu.hpp>

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
    // Ball* ball2 = new Ball(window);
    // this->balls.push_back(ball2);
    // Ball* ball3 = new Ball(window);
    // this->balls.push_back(ball3);
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

void Game::updateGame(Collision collision, float dt) {
    moveEntities(dt);
    collision.checkForCollisions();
    adjustScore(collision.ballsHittingLeftRight());
    drawEntities();
}

void Game::startGame() {

    setupGame();
    print("game set up");

    Collision collision = Collision(window);
    collision.setPlayers(this->players);
    collision.setBalls(this->balls);
    print("collision set up");


    //framerate independent calculations
    this->window.setFramerateLimit(60);
    sf::Clock clock;
    float multiplier = 60.f;
    float dt;

    Menu mainMenu(window.getSize().x, window.getSize().y);

    sf::RectangleShape background;
    background.setSize(sf::Vector2f(960,720));
    sf::Texture mainTexture;
    mainTexture.loadFromFile("images/cuppatea.png");
    background.setTexture(&mainTexture);
    int screenNumber = -1;
    bool inScreen = false;

    while (this->window.isOpen()) {
        sf::Event event;
        while (this->window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                this->window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (inScreen && event.key.code == sf::Keyboard::Escape) {
                    inScreen = false;
                    screenNumber = -1;
                } else if (event.key.code == sf::Keyboard::Escape) {
                    this->window.close();
                }
            }
            if (event.type == sf::Event::KeyReleased && !inScreen) {
                if (event.key.code == sf::Keyboard::Up) {
                    mainMenu.MoveUp();
                    break;
                }
                if (event.key.code == sf::Keyboard::Down) {
                    mainMenu.MoveDown();
                    break;
                }
                if (event.key.code == sf::Keyboard::Return) {
                    screenNumber = mainMenu.MenuPressed();
                    inScreen = true;
                    print(screenNumber);
                }
            }
        }

        this->window.clear();
        print(screenNumber);
        switch (screenNumber) {
            case 0:
                dt = clock.restart().asSeconds();
                updateGame(collision, dt);
                break;
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            default:
                this->window.draw(background);
                mainMenu.draw(this->window);
                break;
        }
        this->window.display();
    }

    destroyEntities();
}