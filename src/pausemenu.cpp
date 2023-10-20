#include <pausemenu.hpp>
#include <util.hpp>

PauseMenu::PauseMenu(sf::RenderWindow &window, int maxItems) : 
    Menu(window, maxItems) {
    
    addItem("Restart", true, sf::Vector2f(300, 300));
    addItem("Main Menu", false, sf::Vector2f(300, 400));
    addItem("Quit Game", false, sf::Vector2f(300, 500));

    SetMenuSelected(-1);
}

PauseMenu::~PauseMenu() {
    
}

void PauseMenu::draw() {
    sf::Vector2u size = window.getSize();

    sf::RectangleShape bRect = sf::RectangleShape(sf::Vector2f(450,450));
    sf::Vector2f bRectSize = bRect.getSize();
    bRect.setOrigin(bRectSize.x/2, bRectSize.y/2);
    bRect.setFillColor(sf::Color::Black);
    bRect.setPosition(size.x/2, size.y/2);

    sf::RectangleShape wRect = sf::RectangleShape(sf::Vector2f(500,500));
    sf::Vector2f wRectSize = wRect.getSize();
    wRect.setOrigin(wRectSize.x/2, wRectSize.y/2);
    wRect.setFillColor(sf::Color::White);
    wRect.setPosition(size.x/2, size.y/2);

    window.draw(wRect);
    window.draw(bRect);
    Menu::draw(this->window);
}