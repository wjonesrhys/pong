#include <iostream>
#include <playstate.hpp>
#include <pausestate.hpp>

PlayState::PlayState(GameEngine* gameEngine) : State("play"), gameEngine(gameEngine) {
    std::cout << "Game state created!" << std::endl;

    //framerate independent calculations
    float multiplier = 60.f;
    paused = false;

    //set up the entities
    setUpEntities();
    std::cout << "Entities set up" << std::endl;

    collision = Collision(gameEngine->window.getSize());
    collision.setBalls(this->balls);
    collision.setPlayers(this->players);
    std::cout << "players and balls linked to collision detection" << std::endl;

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
    this->players.clear();
    this->scores.clear();
}

void PlayState::setUpEntities() {
    Score* score1 = new Score(1, gameEngine->window); 
    Score* score2 = new Score(2, gameEngine->window); 

    this->scores.push_back(score1);
    this->scores.push_back(score2);

    Player* player1 = new Player(1, gameEngine->window); 
    Player* player2 = new Player(2, gameEngine->window); 

    this->players.push_back(player1);
    this->players.push_back(player2);

    Ball* ball = new Ball(gameEngine->window);
    this->balls.push_back(ball);
}

void PlayState::destroyEntities() {
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

void PlayState::moveEntities(float dt) {
    //players
    for (Player* player : players) {
        player->move(dt, 60);
    }

    //balls
    for (Ball* ball : balls) {
        ball->move(dt, 60);
    }
}

void PlayState::drawEntities() {
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

void PlayState::adjustScore(std::vector<sf::Vector2i> results) {
    for (sf::Vector2i result : results) {
        if (result.x == 1) {
            scores.at(0)->increaseScore();
        }
        if (result.y == 1) {
            scores.at(1)->increaseScore();
        }
    }
}

void PlayState::updateGame(float dt) {
    moveEntities(dt);
    collision.checkForCollisions();
    adjustScore(collision.ballsHittingLeftRight());
}