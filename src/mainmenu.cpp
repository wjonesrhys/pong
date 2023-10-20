#include <mainmenu.hpp>
#include <util.hpp>

MainMenu::MainMenu(sf::RenderWindow &window, int maxItems) : 
    Menu(window, maxItems) {
    
    addItem("Play", true, sf::Vector2f(300, 300));
    addItem("About", false, sf::Vector2f(300, 350));
    addItem("Options", false, sf::Vector2f(300, 400));
    addItem("Exit", false, sf::Vector2f(300, 450));

    SetMenuSelected(-1);
}

MainMenu::~MainMenu() {
    
}