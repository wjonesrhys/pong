#include <aboutstate.hpp>
#include <mainmenustate.hpp>

AboutState::AboutState(GameEngine* gameEngine) : State("about"), gameEngine(gameEngine) {    
    menu.addText("Created by:", sf::Vector2f(300, 150), "static");
    menu.addText("   Ster    ", sf::Vector2f(300, 250), "static");
    menu.addText("    And    ", sf::Vector2f(300, 350), "static");
    menu.addText(" Ster Only ", sf::Vector2f(300, 450), "static");
    menu.addText("Back to main menu", sf::Vector2f(300, 550), "option");
    print("About state created!");
}

AboutState::~AboutState() {
    print("About state destroyed!");
}

void AboutState::onEnter() {
    print("About state loaded!");
}

void AboutState::handleEvents() {
    if (gameEngine->event.type == sf::Event::Closed) {
        gameEngine->window.close();
    }
    if (gameEngine->event.type == sf::Event::KeyPressed) {
        if (gameEngine->event.key.code == sf::Keyboard::Up) {
            menu.moveUp();
        }
        if (gameEngine->event.key.code == sf::Keyboard::Down) {
            menu.moveDown();
        }
        if (gameEngine->event.key.code == sf::Keyboard::Enter) {
            switch (menu.menuPressed()) {
                case 0:
                    gameEngine->push(new MainMenuState(gameEngine));
                    break;
                default:
                    print("nothing happened");
            }
        }
    }
}

void AboutState::update() {

}

void AboutState::render() {
    for (sf::Text text : menu.getStaticTexts()) {
        gameEngine->window.draw(text);
    }
    for (sf::Text text : menu.getOptionTexts()) {
        gameEngine->window.draw(text);
    }
}

void AboutState::pause() {

}

void AboutState::resume() {

}

void AboutState::onExit() {
    print("About state exited!");
}