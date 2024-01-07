#include <pausestate.hpp>

PauseState::PauseState(GameEngine* gameEngine) : State("pause") {
    sf::RectangleShape* background = new sf::RectangleShape(sf::Vector2f(1000,1000));
    background->setOrigin(background->getSize().x/2, background->getSize().y/2);
    background->setPosition(gameEngine->window.getSize().x/2, gameEngine->window.getSize().y/2);
    menu.addShape(background);

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

}

void PauseState::update() {
    sf::Event event;
    while (gameEngine->window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            gameEngine->window.close();
        
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) {
                gameEngine->window.close();
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
                switch (menu.menuPressed()) {
                    case 0:
                        gameEngine->pop();
                        break;
                    case 1:
                        break;
                    case 2:
                        // gameEngine->changeState("mainmenu");
                        gameEngine->clear();
                        break;
                    default:
                        print("nothing happened");
                }
            }
        }
    }


}

void PauseState::render() {
    for (sf::Shape* shape : menu.getShapes()) {
        gameEngine->window.draw(*shape);
    }

    for (sf::Text text : menu.getTexts()) {
        gameEngine->window.draw(text);
    }
}

void PauseState::pause() {

}

void PauseState::resume() {

}

void PauseState::onExit() {
    print("Pause state exited!");
}