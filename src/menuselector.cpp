#include <menuselector.hpp>
#include <util.hpp>

enum season { about, options, pause };

MenuSelector::MenuSelector(sf::RenderWindow &window, std::string menuType) : window(window) {
    loadMenu(menuType);
    setUpBackground();
}

MenuSelector::~MenuSelector() {

}

void MenuSelector::setUpBackground() {
    sf::Vector2u windowSize = window.getSize();
    background.setTexture(&texture);
    
}

void MenuSelector::draw() {
    window.draw(this->background);
    for (sf::Text text : menu.getItems()) {
        window.draw(text);
    }
    menu.getItems();
    // for (int i=0; i<menuItems.size(); ++i) {
    //     window.draw(menuItems.at(i));
    // }
}

void MenuSelector::loadMenu(std::string menuType) {
    background.setSize(sf::Vector2f(1280, 720));
    if (menuType == "about") {
        texture.loadFromFile("images/background.png");
        setUpAboutMenu();
    } else if (menuType == "options") {
        texture.loadFromFile("images/background.png");
        setUpOptionsMenu();
    } else if (menuType == "pause") {
        background.setSize(sf::Vector2f(300, 300));
        texture.loadFromFile("images/background.png");
        setUpPauseMenu();
    } else if (menuType == "main") {
        texture.loadFromFile("images/cuppatea.png");
        setUpMainMenu();
    }
}

void MenuSelector::setUpPauseMenu() {
    menu.addItem("Restart", true, sf::Vector2f(300, 300));
    menu.addItem("Main Menu", false, sf::Vector2f(300, 400));
    menu.addItem("Quit Game", false, sf::Vector2f(300, 500));
}

void MenuSelector::setUpAboutMenu() {
    menu.addItem("credits", true, sf::Vector2f(300, 100));
    menu.addItem("programming and game logic", false, sf::Vector2f(300, 200));
    menu.addItem("music", false, sf::Vector2f(300, 300));
    menu.addItem("art", false, sf::Vector2f(300, 400));
    menu.addItem("return", false, sf::Vector2f(300, 500));
}

void MenuSelector::setUpOptionsMenu() {
    menu.addItem("Options", true, sf::Vector2f(300, 75));
    menu.addItem("Frame rate", false, sf::Vector2f(300, 150));
    menu.addItem("resolution", false, sf::Vector2f(300, 225));
    menu.addItem("volume", false, sf::Vector2f(300, 300));
    menu.addItem("windowed", false, sf::Vector2f(300, 375));
    menu.addItem("show fps", false, sf::Vector2f(300, 450));
    menu.addItem("return", false, sf::Vector2f(300, 525));
}

void MenuSelector::setUpMainMenu() {
    menu.addItem("Play", true, sf::Vector2f(300, 250));
    menu.addItem("About", false, sf::Vector2f(300, 350));
    menu.addItem("Options", false, sf::Vector2f(300, 450));
    menu.addItem("Exit", false, sf::Vector2f(300, 550));
}