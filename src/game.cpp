#include <iostream>
#include <string>

#include "game.hpp"
#include "player.hpp"
#include "ball.hpp"
#include "collision.hpp"

#include <SFML/Graphics.hpp>

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

sf::Text Game::setUpText() {
    sf::Text text;

    if (!this->font.loadFromFile("fonts/arial.ttf")) {
        std::cout << "Error loading font!" << std::endl;
    }

    text.setFont(font); // font is a sf::Font
    text.setString("0");
    text.setCharacterSize(72); // in pixels, not points!
    text.setFillColor(sf::Color::Green);
    text.setStyle(sf::Text::Bold);
    text.setOrigin(text.getGlobalBounds().width/2,text.getGlobalBounds().height/2);
    
    return text;
}

void Game::setUpEntities() {
    Player* player1 = new Player(1, window); 
    Player* player2 = new Player(2, window); 

    this->players.push_back(player1);
    this->players.push_back(player2);

    Ball* ball = new Ball(window); 
    this->balls.push_back(ball);
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

void Game::setup() {

}

void Game::start() {
    setIcon();
    
    p1ScoreText = setUpText();
    p2ScoreText = setUpText();

    setUpEntities();
    destroyEntities();

    sf::Vector2u windowSize = window.getSize();

    p1ScoreText.setPosition(window.getSize().x/2 - p1ScoreText.getGlobalBounds().width, p1ScoreText.getGlobalBounds().width);
    p2ScoreText.setPosition(window.getSize().x/2 + p2ScoreText.getGlobalBounds().width, p2ScoreText.getGlobalBounds().width);

    this->window.setFramerateLimit(60);
    Collision collision = Collision();

    //framerate independent calculations
    sf::Clock clock;
    float multiplier = 60.f;
    float dt;

    // Player player1 = Player(1, "images/cuppatea.png", window);
    // Player player2 = Player(2, "images/cuppatea.png", window);

    Player player1 = Player(1, window); 
    Player player2 = Player(2, window); 

    // Player* player = players[0];
    // int delta = 0;
    // int multiplier = 0;
    // player->move(delta, multiplier);



    player1.setStartingPosition();
    player2.setStartingPosition();

    Ball ball = Ball(window);
    ball.setStartingPosition();

    while (this->window.isOpen())
    {
        sf::Event event;
        while (this->window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                this->window.close();

            if (this->p1Score == 10 || this->p2Score == 10) {
                this->window.close();
            }
        }

        dt = clock.restart().asSeconds();

        this->window.clear();

        //players
        player1.draw();
        player1.move(dt, 60);

        player2.draw();
        player2.move(dt, 60);

        //ball
        ball.move(dt, 60);
        Util::print("hi");

        if (collision.intersectsLeft(ball.getBounds())) {
            ball.startPosition();
            increaseScoreForPlayer(2);
        }

        if (collision.intersectsRight(ball.getBounds(), windowSize.x)) {
            ball.startPosition();
            increaseScoreForPlayer(1);
        }

        if (collision.intersects(player2.getRect(), ball.getBounds()) || collision.intersects(player1.getRect(), ball.getBounds())){
            ball.resetPosition();
            ball.reflectOnPaddle();
        } 

        if (collision.intersectsTop(ball.getBounds()) || collision.intersectsBottom(ball.getBounds(), windowSize.y)) {
            ball.reflectOnWall();
        }

        //check for collisions for all balls
        //reset the position to the point before collision
        //calculate the position and velocity 
        //draw

        //collision.checkForCollisions(players, balls);
        ball.draw();

        window.draw(this->p1ScoreText);
        window.draw(this->p2ScoreText);

        this->window.display();

        //framerate
        std::cout << "fps: " << dt << std::endl;

    }
}


