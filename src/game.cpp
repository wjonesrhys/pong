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

void Game::increaseScore(int playerNum) {
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

    sf::Vector2u windowSize = window.getSize();

    p1ScoreText.setPosition(window.getSize().x/2 - p1ScoreText.getGlobalBounds().width, p1ScoreText.getGlobalBounds().width);
    p2ScoreText.setPosition(window.getSize().x/2 + p1ScoreText.getGlobalBounds().width, p1ScoreText.getGlobalBounds().width);

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
        }

        dt = clock.restart().asSeconds();

        this->window.clear();

        //players
        player1.draw();
        player1.move(dt, 60);

        player2.draw();
        player2.move(dt, 60);

        //ball
        ball.draw();
        ball.move(dt, 60);

        if (collision.intersectsLeft(ball.getBounds())) {
            ball.resetPosition();
            increaseScore(2);
        }

        if (collision.intersectsRight(ball.getBounds(), windowSize.x)) {
            ball.resetPosition();
            increaseScore(1);
        }

        window.draw(this->p1ScoreText);
        window.draw(this->p2ScoreText);

        this->window.display();

        //framerate
        // std::cout << "fps: " << dt << std::endl;

    }
}


