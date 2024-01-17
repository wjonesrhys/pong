#include <iostream>
#include <pausestate.hpp>
#include <mainmenustate.hpp>

PauseState::PauseState(GameEngine* gameEngine) : State("pause"), gameEngine(gameEngine) {
    sf::RectangleShape* background = new sf::RectangleShape(sf::Vector2f(500,500));
    background->setFillColor(sf::Color::Red);
    background->setOrigin(background->getSize().x/2, background->getSize().y/2);
    background->setPosition(gameEngine->window.getSize().x/2, gameEngine->window.getSize().y/2);
    menu.addShape(background);
    isActive = true;

    menu.addText("Resume", sf::Vector2f(300, 250), "option");
    menu.addText("Restart", sf::Vector2f(300, 350), "option");
    menu.addText("Exit Game", sf::Vector2f(300, 450), "option");
    std::cout << "Pause state state created!" << std::endl;
}

PauseState::~PauseState() {
    std::cout << "Pause state destroyed!" << std::endl;
}

void PauseState::onEnter() {
    std::cout << "Pause state loaded!" << std::endl;
}

void PauseState::handleEvents() {
    if (gameEngine->event.type == sf::Event::Closed) {
        gameEngine->window.close();
    }
    if (gameEngine->event.type == sf::Event::KeyPressed) {
        if (gameEngine->event.key.code == sf::Keyboard::P) {
            returnToGame();
        }
        if (gameEngine->event.key.code == sf::Keyboard::Up) {
            menu.moveUp();
        }
        if (gameEngine->event.key.code == sf::Keyboard::Down) {
            menu.moveDown();
        }
        if (gameEngine->event.key.code == sf::Keyboard::Enter) {
            switch (menu.menuPressed()) {
                case 0:
                    returnToGame();
                    break;
                case 1:
                    gameEngine->clear();
                    gameEngine->pushWithoutPop(new MainMenuState(gameEngine));
                    break;
                case 2:
                    gameEngine->close();
                    break;
                default:
                    std::cout << "nothing happened" << std::endl;
            }
        }
    }
}

void PauseState::update() {

}

void PauseState::render() {
    if (isActive) {
        for (sf::Shape* shape : menu.getShapes()) {
            gameEngine->window.draw(*shape);
        }
        for (sf::Text text : menu.getOptionTexts()) {
            gameEngine->window.draw(text);
        }
        for (sf::Text text : menu.getStaticTexts()) {
            gameEngine->window.draw(text);
        }
    }
}

void PauseState::pause() {

}

void PauseState::resume() {

}

void PauseState::onExit() {
    std::cout << "Pause state exited!" << std::endl;
}

void PauseState::returnToGame() {
    gameEngine->pop();
    isActive ? isActive = false : isActive = true;
}