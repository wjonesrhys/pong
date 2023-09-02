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

    float xCoord = window.getSize().x/2;
    playerNum == 1 ? xCoord += text.getGlobalBounds().width : xCoord -= text.getGlobalBounds().width;
    text.setPosition(xCoord, text.getGlobalBounds().width);

    return text;
}

void Game::setUpEntities() {
    Player* player1 = new Player(1, window); 
    Player* player2 = new Player(2, window); 

    players.push_back(player1);
    players.push_back(player2);

    Ball* ball = new Ball(window); 
    Ball* ball2 = new Ball(window); 
    Ball* ball3 = new Ball(window); 
    Ball* ball4 = new Ball(window); 
    Ball* ball5 = new Ball(window); 
    Ball* ball6 = new Ball(window); 
    Ball* ball7 = new Ball(window); 
    Ball* ball8 = new Ball(window); 
    this->balls.push_back(ball);
    this->balls.push_back(ball2);
    this->balls.push_back(ball3);
    this->balls.push_back(ball4);
    this->balls.push_back(ball5);
    this->balls.push_back(ball6);
    this->balls.push_back(ball7);
    this->balls.push_back(ball8);
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
    
    //set up the ui
    p1ScoreText = setUpText(1);
    p2ScoreText = setUpText(2);

    //set up the entities
    setUpEntities();
    // destroyEntities();

}

void Game::startGame() {

    setupGame();

    //framerate independent calculations
    this->window.setFramerateLimit(60);
    sf::Clock clock;
    float multiplier = 60.f;
    float dt;
    
    Collision collision = Collision();

    while (this->window.isOpen())
    {
        sf::Event event;
        while (this->window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                // destroyEntities();
                this->window.close();

            if (this->p1Score == 10 || this->p2Score == 10) {
                // destroyEntities();
                this->window.close();
            }
        }

        dt = clock.restart().asSeconds();

        this->window.clear();

        //players
        for (Player* player : players) {
            player->move(dt, 60);
            player->draw();
        }

        //balls
        for (Ball* ball : balls) {
            ball->move(dt, 60);
            ball->draw();
        }

        window.draw(this->p1ScoreText);
        window.draw(this->p2ScoreText);

        this->window.display();

    }
}


