#include <mainmenustate.hpp>
#include <playstate.hpp>

MainMenuState::MainMenuState(GameEngine* gameEngine) : State("mainmenu"), gameEngine(gameEngine) {    
    menu.addItem("Play", true, sf::Vector2f(300, 250));
    menu.addItem("About", false, sf::Vector2f(300, 350));
    menu.addItem("Options", false, sf::Vector2f(300, 450));
    menu.addItem("Exit", false, sf::Vector2f(300, 550));
    print("Main menu state created!");
}

MainMenuState::~MainMenuState() {
    print("Main menu destroyed!");
}

void MainMenuState::onEnter() {
    print("Main menu loaded!");
}

void MainMenuState::handleEvents() {

}

void MainMenuState::update() {
    sf::Event event;
    print("here");
    while (gameEngine->window.pollEvent(event))
    {
        print("next here");
        if (event.type == sf::Event::Closed)
            gameEngine->window.close();
        
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) {
                gameEngine->close();
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
                print(menu.menuPressed());
                switch (menu.menuPressed()) {
                    case 0:
                        gameEngine->push(new PlayState(gameEngine));
                        break;
                    default:
                        print("nothing happened");
                }
            }
        }
    }
}

void MainMenuState::render() {
    print("not even there yet");
    for (sf::Text text : menu.getTexts()) {
        print("before");
        gameEngine->window.draw(text);
        print("after");
    }
}

void MainMenuState::pause() {

}

void MainMenuState::resume() {

}

void MainMenuState::onExit() {
    print("Main menu exited!");
}