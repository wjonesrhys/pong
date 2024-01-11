#include <pausestate.hpp>

PauseState::PauseState(GameEngine* gameEngine) : State("pause"), gameEngine(gameEngine) {
    sf::RectangleShape* background = new sf::RectangleShape(sf::Vector2f(500,500));
    background->setFillColor(sf::Color::Red);
    background->setOrigin(background->getSize().x/2, background->getSize().y/2);
    background->setPosition(gameEngine->window.getSize().x/2, gameEngine->window.getSize().y/2);
    menu.addShape(background);
    isActive = true;

    menu.addItem("Resume", true, sf::Vector2f(300, 250));
    menu.addItem("Restart", false, sf::Vector2f(300, 350));
    menu.addItem("Exit Game", false, sf::Vector2f(300, 450));
    print("Pause state state created!");
}

PauseState::~PauseState() {
    print("Pause state destroyed!");
}

void PauseState::onEnter() {
    print("Pause state loaded!");
}

void PauseState::handleEvents() {
    print("handle??");
    if (gameEngine->event.type == sf::Event::Closed) {
        gameEngine->window.close();
    }
    if (gameEngine->event.type == sf::Event::KeyPressed) {
        if (gameEngine->event.key.code == sf::Keyboard::Escape) {
            gameEngine->window.close();
        }
        if (gameEngine->event.key.code == sf::Keyboard::P) {
            gameEngine->pop();
            isActive ? isActive = false : isActive = true;
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
                    break;
                case 1:
                    break;
                case 2:
                    gameEngine->close();
                    break;
                default:
                    print("nothing happened");
            }
        }
    }
}

void PauseState::update() {
    print("update?");
}

void PauseState::render() {
    if (isActive) {
        for (sf::Shape* shape : menu.getShapes()) {
            gameEngine->window.draw(*shape);
        }
        for (sf::Text text : menu.getTexts()) {
            gameEngine->window.draw(text);
        }
    }
}

void PauseState::pause() {

}

void PauseState::resume() {

}

void PauseState::onExit() {
    print("Pause state exited!");
}