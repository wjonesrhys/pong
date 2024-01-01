#include <playstate.hpp>
#include <stdlib.h>

PlayState::PlayState(sf::RenderWindow& renderWindow, StateMachine& stateMachine) : window(renderWindow), stateMachine(stateMachine) {
    menu.addItem("other 1", true, sf::Vector2f(300, 250));
    menu.addItem("other 2", false, sf::Vector2f(300, 350));
    print("Game state created!");

    //set up PlayState icon
    setIcon();

    clock.restart();
    print("Game set up");

    collision = Collision(window.getSize());
    collision.setBalls(this->balls);
    collision.setPlayers(this->players);

    //framerate independent calculations
    this->window.setFramerateLimit(60);
    float multiplier = 60.f;
}

PlayState::~PlayState() {
    print("Game state destroyed!");
}

void PlayState::onEnter() {
    print("Game state loaded!");
    clock.restart();

    //set up the entities
    setUpEntities();
    
    print("Entities set up");

    collision.setBalls(this->balls);
    collision.setPlayers(this->players);
    print("here");
}

void PlayState::onExit() {
    print("Game state exited!");
    destroyEntities();
    this->balls.clear();
    this->players.clear();
    this->scores.clear();
}

void PlayState::update() {
    print("in update");
    dt = clock.restart().asSeconds();
    print("updating game");
    updateGame(dt);
    print("game updated");

    sf::Event event;
    while (this->window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            this->window.close();
        
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) {
                this->window.close();
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
            if (event.key.code == sf::Keyboard::Enter) {
                print(menu.menuPressed());
                switch (menu.menuPressed()) {
                    case 0:
                        stateMachine.change("mainmenu");
                        break;
                    default:
                        print("nothing happened");
                }
            }
        }
        
    }          
}

void PlayState::render() {
    // for (sf::Text text : menu.getItems()) {
    //     window.draw(text);
    // }
    drawEntities();
}

void PlayState::setIcon() {
    sf::Image icon;
    icon.loadFromFile("images/cuppatea.png");
    this->window.setIcon(32,32,icon.getPixelsPtr());
}

void PlayState::setUpEntities() {
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
    print("updating game");
    moveEntities(dt);
    print("moved entities");
    collision.checkForCollisions();
    print("checked for collisions");
    adjustScore(collision.ballsHittingLeftRight());
    print("adjusted score");
}