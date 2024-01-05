#include <pausestate.hpp>

// int PauseState::count = 0;

PauseState::PauseState(sf::RenderWindow& renderWindow, StateMachine& stateMachine) : window(renderWindow), stateMachine(stateMachine){
    menu.addItem("Play", true, sf::Vector2f(300, 250));
    menu.addItem("About", false, sf::Vector2f(300, 350));
    menu.addItem("Options", false, sf::Vector2f(300, 450));
    menu.addItem("Exit", false, sf::Vector2f(300, 550));
    print("Main menu state created!");
    // count++;
}

PauseState::~PauseState() {
    print("Main menu destroyed!");
    // count--;
}

void PauseState::onEnter() {
    print("Main menu loaded!");
}

void PauseState::onExit() {
    print("Main menu exited!");
}

void PauseState::update() {
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
                        stateMachine.change("play");
                        break;
                    default:
                        print("nothing happened");
                }
            }
        }
    }


}

void PauseState::render() {
    for (sf::Text text : menu.getItems()) {
        window.draw(text);
    }
}

// int PauseState::getCounter() {
//     return count;
// }
