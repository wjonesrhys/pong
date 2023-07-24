#include <iostream>
#include <string>

#include "game.hpp"
#include "player.hpp"
#include "ball.hpp"
#include "collision.hpp"

#include <SFML/Graphics.hpp>

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

void Game::setUpScores() {
    if (!this->font.loadFromFile("fonts/arial.ttf")) {
        std::cout << "Error loading font!" << std::endl;
    }




    this->p1ScoreText.setFont(font); // font is a sf::Font
    this->p1ScoreText.setString("Hello world");
    this->p1ScoreText.setCharacterSize(24); // in pixels, not points!
    this->p1ScoreText.setFillColor(sf::Color::Red);
    this->p1ScoreText.setStyle(sf::Text::Bold | sf::Text::Underlined);
    this->p1ScoreText.setPosition(500,400);

    float halfWidthp1 = this->p1ScoreText.getGlobalBounds().width/2;
    float halfHeightp1 = this->p2ScoreText.getGlobalBounds().height/2;
    this->p1ScoreText.setOrigin(halfWidthp1,halfHeightp1);
    this->p1ScoreText.setPosition(window.getSize().x/2, window.getSize().y/2);

    this->p2ScoreText.setFont(font); // font is a sf::Font
    this->p2ScoreText.setString("Hello world");
    this->p2ScoreText.setCharacterSize(24); // in pixels, not points!
    this->p2ScoreText.setFillColor(sf::Color::Red);
    this->p2ScoreText.setStyle(sf::Text::Bold | sf::Text::Underlined);
    this->p2ScoreText.setPosition(500,400);
}

void Game::setup() {

}

void Game::start() {
    setIcon();
    setUpScores();
    this->window.setFramerateLimit(60);

    sf::Font font;
    if (font.loadFromFile("fonts/arial.ttf")) {
        std::cout << "Font Loaded!" << std::endl;
    }

    Collision collision = Collision();

    //framerate independent calculations
    sf::Clock clock;
    float multiplier = 60.f;
    float dt;

    Player player1 = Player(1, "images/cuppatea.png", window);
    Player player2 = Player(2, "images/cuppatea.png", window);

    player1.setStartingPosition();
    player2.setStartingPosition();

    Ball ball = Ball();
    ball.setStartingPosition(window);

    bool ballMoving = false;



    while (this->window.isOpen())
    {
        sf::Event event;
        while (this->window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                this->window.close();
        }

        dt = clock.restart().asSeconds();

        this->window.clear();

        //players
        player1.draw();
        player1.move(dt, 60);

        player2.draw();
        player2.move(dt, 60);

        //ball
        ball.draw(this->window);
        ball.move(dt, 60);

        window.draw(this->p1ScoreText);

        this->window.display();

        //framerate
        // std::cout << "fps: " << dt << std::endl;

    }
}


