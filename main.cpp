#include <gameengine.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <iostream>


int main() {
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Ping Pong");
    window.setFramerateLimit(60);

    sf::Image icon;
    if (!icon.loadFromFile("resources/images/cuppatea.png")) {
        std::cout << "file didn't load" << std::endl;
    } else {
        window.setIcon(32,32,icon.getPixelsPtr());
        std::cout << "loaded" << std::endl;
    }

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