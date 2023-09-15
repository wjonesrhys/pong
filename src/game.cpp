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
    resetScore();
}

Game::~Game() {
    std::cout << "Game Closed";
}

void Game::resetScore() {
    this->p1Score=0;
    this->p2Score=0;
}

void Game::setIcon() {
    sf::Image icon;
    icon.loadFromFile("images/cuppatea.png");
    this->window.setIcon(32,32,icon.getPixelsPtr());
}

void Game::loadFont() {
    //load the font
    if (!this->font.loadFromFile("fonts/arial.ttf")) {
        std::cout << "Error loading font!" << std::endl;
    }
}

sf::Text Game::setUpText(int playerNum) {
    //create text object
    sf::Text text;

    text.setFont(font); // font is a sf::Font
    text.setString("0");
    text.setCharacterSize(72); // in pixels, not points!
    text.setFillColor(sf::Color::Green);
    text.setStyle(sf::Text::Bold);
    text.setOrigin(text.getGlobalBounds().width/2,text.getGlobalBounds().height/2);

    return updatePosition(playerNum, text);
}

void Game::setUpEntities() {
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
}

void Game::increaseScoreForPlayer(int playerNum) {
    if (playerNum==1) {
        this->p1Score += 1;
        std::string scoreToDisplay = std::to_string(this->p1Score);
        this->p1ScoreText.setString(scoreToDisplay);
    } else {
        this->p2Score += 1;
        std::string scoreToDisplay = std::to_string(this->p2Score);
        this->p2ScoreText.setString(scoreToDisplay);
    }
}

void Game::setupGame() {
    //set up game icon
    setIcon();
    loadFont();

    resetScore();
    
    //set up the ui
    this->p1ScoreText = setUpText(1);
    this->p2ScoreText = setUpText(2);

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

sf::Text Game::updatePosition(int playerNum, sf::Text text) {
    printCoords(text.getPosition());
    float xCoord = window.getSize().x/2;
    playerNum == 1 ? xCoord += text.getGlobalBounds().width : xCoord -= text.getGlobalBounds().width;
    text.setPosition(xCoord, text.getGlobalBounds().width);
    printCoords(text.getPosition());
    return text;
}

void Game::updateText() {
    updatePosition(1, this->p1ScoreText);
    updatePosition(2, this->p2ScoreText);
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
    
    window.draw(p1ScoreText);
    window.draw(p2ScoreText);
}

void Game::adjustScore(std::vector<sf::Vector2i> results) {
    for (sf::Vector2i result : results) {
        if (result.x == 1) {
            this->p1Score += 1;
            this->p1ScoreText.setString(std::to_string(this->p1Score));
        }

        if (result.y == 1) {
            this->p2Score += 1;
            this->p2ScoreText.setString(std::to_string(this->p2Score));
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
    this->window.setFramerateLimit(144);
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

        updateText();
        moveEntities(dt);

        collision.checkForCollisions();
        adjustScore(collision.ballsHittingLeftRight());

        drawEntities();

        window.draw(this->p1ScoreText);
        window.draw(this->p2ScoreText);

        this->window.display();

    }

    destroyEntities();
}


