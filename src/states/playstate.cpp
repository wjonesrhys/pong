#include <playstate.hpp>
#include <pausestate.hpp>
#include <stdlib.h>

PlayState::PlayState(GameEngine* gameEngine) : State("play"), gameEngine(gameEngine) {
    menu.addItem("other 1", true, sf::Vector2f(300, 250));
    menu.addItem("other 2", false, sf::Vector2f(300, 350));
    print("Game state created!");

    //framerate independent calculations
    float multiplier = 60.f;

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
}

void PlayState::handleEvents() {

}

void PlayState::update() {
    sf::Event event;
    while (gameEngine->window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            gameEngine->window.close();
        
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) {
                
                break;
            }
            if (event.key.code == sf::Keyboard::Up) {
                menu.moveUp();
                break;
            }
            if (event.key.code == sf::Keyboard::Down) {
                menu.moveDown();
                break;
            }
            if (event.key.code == sf::Keyboard::P || event.key.code == sf::Keyboard::Escape) {
                pause();
                // gameEngine.change("pause");
                break;
            }

            if (event.key.code == sf::Keyboard::Enter) {
                print(menu.menuPressed());
                switch (menu.menuPressed()) {
                    case 0:
                        // gameEngine.change("mainmenu");
                        break;
                    default:
                        print("nothing happened");
                }
            }
        }
    }
    dt = clock.restart().asSeconds();
    updateGame(dt);       
}

void PlayState::render() {
    // for (sf::Text text : menu.getItems()) {
    //     window.draw(text);
    // }
    drawEntities();
}

void PlayState::pause() {

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