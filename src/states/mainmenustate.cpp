#include <mainmenustate.hpp>
#include <playstate.hpp>
#include <aboutstate.hpp>

MainMenuState::MainMenuState(GameEngine* gameEngine) : State("mainmenu"), gameEngine(gameEngine) {    
    menu.addText("Play", sf::Vector2f(300, 250), "option");
    menu.addText("About", sf::Vector2f(300, 350), "option");
    menu.addText("Options", sf::Vector2f(300, 450), "option");
    menu.addText("Exit", sf::Vector2f(300, 550), "option");
    print("Main menu state created!");
}

MainMenuState::~MainMenuState() {
    print("Main menu destroyed!");
}

void MainMenuState::onEnter() {
    print("Main menu loaded!");
}

void MainMenuState::handleEvents() {
    if (gameEngine->event.type == sf::Event::Closed)
        gameEngine->window.close();
    
    if (gameEngine->event.type == sf::Event::KeyPressed) {
        if (gameEngine->event.key.code == sf::Keyboard::Escape) {
            gameEngine->close();
            gameEngine->window.close();
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
                    gameEngine->push(new PlayState(gameEngine));
                    break;
                case 1:
                    gameEngine->push(new AboutState(gameEngine));
                    break;
                case 2:
                    break;
                case 3:
                    gameEngine->close();
                    break;
                default:
                    print("nothing happened");
            }
        }
    }
}

void MainMenuState::update() {

}

void MainMenuState::render() {
    for (sf::Text text : menu.getOptionTexts()) {
        gameEngine->window.draw(text);
    }
}

void MainMenuState::pause() {

}

void MainMenuState::resume() {

}

void MainMenuState::onExit() {
    print("Main menu exited!");
}