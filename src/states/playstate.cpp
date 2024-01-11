#include <playstate.hpp>
#include <pausestate.hpp>
#include <stdlib.h>

PlayState::PlayState(GameEngine* gameEngine) : State("play"), gameEngine(gameEngine) {
    menu.addItem("other 1", true, sf::Vector2f(300, 250));
    menu.addItem("other 2", false, sf::Vector2f(300, 350));
    print("Game state created!");

    //framerate independent calculations
    float multiplier = 60.f;
    paused = false;

    //set up the entities
    setUpEntities();
    print("Entities set up");

    collision = Collision(gameEngine->window.getSize());
    collision.setBalls(this->balls);
    collision.setPlayers(this->players);
    print("players and balls linked to collision detection");

}

PlayState::~PlayState() {
    print("Game state destroyed!");
}

void PlayState::onEnter() {
    print("Game state entered!");
    clock.restart();

    State* previousState = gameEngine->getPreviousState();

    if (previousState != nullptr) {
        if (previousState->getStateName() == "pause") {
            print("well it was trying here");
            pause();
        }
    }
}

void PlayState::handleEvents() {
    if (!paused) {
        if (gameEngine->event.type == sf::Event::Closed) {
            gameEngine->close();
            gameEngine->window.close();
        }
        if (gameEngine->event.type == sf::Event::KeyPressed) {
            if (gameEngine->event.key.code == sf::Keyboard::P || gameEngine->event.key.code == sf::Keyboard::Escape) {
                pause();
                gameEngine->pushWithoutPop(new PauseState(gameEngine));
            }
            if (gameEngine->event.key.code == sf::Keyboard::Enter) {
                switch (menu.menuPressed()) {
                    case 0:
                        break;
                    default:
                        print("nothing happened");
                }
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
    // for (sf::Text text : menu.getItems()) {
    //     window.draw(text);
    // }
    drawEntities();
}

void PlayState::pause() {
    paused ? paused = false : paused = true;
}

void PlayState::resume() {

}

void PlayState::onExit() {
    print("Game state exited!");
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