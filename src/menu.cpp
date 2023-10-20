#include <menu.hpp>
#include <util.hpp>

Menu::Menu(sf::RenderWindow &window, int maxItems) : window(window) {
    if (!font.loadFromFile("fonts/arial.ttf")) {
        std::cout << "not loaded";
    }
}

Menu::~Menu() {

}

void Menu::draw(sf::RenderWindow& window) {
    for (int i=0; i<menuItems.size(); ++i) {
        window.draw(menuItems.at(i));
    }
}

void Menu::addItem(std::string text, bool isOn, sf::Vector2f position) {
    sf::Text menuText;
    isOn ? menuText.setFillColor(sf::Color::Blue) : menuText.setFillColor(sf::Color::White);
    menuText.setFont(font);
    menuText.setString(text);
    menuText.setCharacterSize(70);
    menuText.setPosition(position);
    menuItems.push_back(menuText);
}

void Menu::MoveUp() {
    if (menuSelected - 1 >=-1) {
        menuItems.at(menuSelected).setFillColor(sf::Color::White);
    }
    menuSelected--;
    if (menuSelected == -1) {
        menuSelected=3;
        menuItems.at(menuSelected).setFillColor(sf::Color::White);
    }
    menuItems.at(menuSelected).setFillColor(sf::Color::Blue);
}

void Menu::MoveDown() {
    if (menuSelected + 1 <=4) {
        menuItems.at(menuSelected).setFillColor(sf::Color::White);
    }    
    menuSelected++;
    if (menuSelected == 4) {
        menuSelected=0;
    }
    menuItems.at(menuSelected).setFillColor(sf::Color::Blue);
}

int Menu::MenuPressed() {
    return menuSelected;
}

void Menu::SetMenuSelected(int index) {
    menuSelected = 0;
}
