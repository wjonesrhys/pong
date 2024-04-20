#include <iostream>
#include <playstate.hpp>
#include <pausestate.hpp>
#include <util.hpp>

PlayState::PlayState(GameEngine* gameEngine) : State("play"), gameEngine(gameEngine) {
    std::cout << "Game state created!" << std::endl;

    //framerate independent calculations
    float multiplier = 60.f;
    paused = false;

    Util::print("here");
    //set up the entities
    setUpEntities();
    std::cout << "Entities set up" << std::endl;
}

PlayState::~PlayState() {
    std::cout << "Game state destroyed!" << std::endl;
}

void PlayState::onEnter() {
    std::cout << "Game state entered!" << std::endl;
    clock.restart();

    State* previousState = gameEngine->getPreviousState();

    if (previousState != nullptr) {
        if (previousState->getStateName() == "pause") {
            pause();
        }
    }
}

void PlayState::handleEvents() {
    if (!paused) {
        if (gameEngine->event.type == sf::Event::Closed) {
            gameEngine->close();
        }
        if (gameEngine->event.type == sf::Event::KeyPressed) {
            if (gameEngine->event.key.code == sf::Keyboard::P || gameEngine->event.key.code == sf::Keyboard::Escape) {
                pause();
                gameEngine->pushWithoutPop(new PauseState(gameEngine));
            }
        }
    }
}

void PlayState::update() {
    if (!paused) {
        dt = clock.restart().asSeconds();
        updateGame(dt);  
    }        
}

void PlayState::render() {
    drawEntities();
}

void PlayState::pause() {
    paused ? paused = false : paused = true;
    clock.restart();
}

void PlayState::resume() {

}

void PlayState::onExit() {
    std::cout << "Game state exited!" << std::endl;
    destroyEntities();
    this->balls.clear();
    this->rectangles.clear();
    this->players.clear();
    this->scores.clear();
}

void PlayState::setUpEntities() {
    Score* score1 = new Score(1, gameEngine->window.getSize());
    Score* score2 = new Score(2, gameEngine->window.getSize());

    this->scores.push_back(score1);
    this->scores.push_back(score2);

    Player* player1 = new Player(1, gameEngine->window.getSize());
    Player* player2 = new Player(2, gameEngine->window.getSize());

    this->players.push_back(player1);
    this->players.push_back(player2);

    Ball* ball = new Ball(gameEngine->window.getSize(), 20.0f);
    this->balls.push_back(ball);

    Rectangle* rectangle = new Rectangle(gameEngine->window.getSize());
    this->rectangles.push_back(rectangle);
}

void PlayState::destroyEntities() {
    for (Player* player : players) {
        delete player;
    }

    for (Ball* ball : balls) {
        delete ball;
    }

    for (Rectangle* rectangle : rectangles) {
        delete rectangle;
    }

    for (Score* score : scores) {
        delete score;
    }
}

void PlayState::moveEntities(float dt) {
    //players
    for (Player* player : players) {
        player->move(dt);
    }

    //balls
    for (Ball* ball : balls) {
        ball->move(dt);
    }

        //balls
    for (Rectangle* rectangle : rectangles) {
        rectangle->move(dt);
    }
}

void PlayState::drawEntities() {
    //players
    for (Player* player : players) {
        player->draw(gameEngine->window);
    }

    //balls
    for (Ball* ball : balls) {
        ball->draw(gameEngine->window);
    }

    //balls
    for (Rectangle* rectangle : rectangles) {
        rectangle->draw(gameEngine->window);
    }

    //scores
    for (Score* score : scores) {
        score->draw(gameEngine->window);
    }
}

void PlayState::updateGame(float dt) {
    Collision collision = Collision(gameEngine->window.getSize());
    moveEntities(dt);
    collision.checkForCollisions(balls, players, scores, rectangles);
}