#include <iostream>
#include <gameengine.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Ping Pong");
    window.setFramerateLimit(60);

    sf::Image icon;
    icon.loadFromFile("resources/images/cuppatea.png");
    window.setIcon(32,32,icon.getPixelsPtr());

    // create a random seed
    srand(time(nullptr));

    // start the engine
    GameEngine game = GameEngine(window);

    // start the game loop    
    while (game.isRunning())
    {
        window.clear();
        game.handleEvents();
        game.update();
        game.render();
        window.display();
    }

    game.clear();
    return 0;
}