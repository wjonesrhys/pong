#include <iostream>
#include "headers/game.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Ping Pong");
    // sf::RenderWindow window(sf::VideoMode(1920, 1080), "Ping Pong");

    Game game = Game(window);
    game.start();

    return 0;
}