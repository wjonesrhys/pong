#include "menu.hpp"
#include "util.hpp"

Menu::Menu(float width, float height) {
    if (!font.loadFromFile("fonts/arial.ttf")) {
        std::cout << "not loaded";
    }

    std::cout << "loaded menu config";
    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::Blue);
    menu[0].setString("Play");
    menu[0].setCharacterSize(70);
    menu[0].setPosition(400,200);

    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("Options");
    menu[1].setCharacterSize(70);
    menu[1].setPosition(400,300);

    menu[2].setFont(font);
    menu[2].setFillColor(sf::Color::White);
    menu[2].setString("About");
    menu[2].setCharacterSize(70);
    menu[2].setPosition(400,400);

    menu[3].setFont(font);
    menu[3].setFillColor(sf::Color::White);
    menu[3].setString("Exit");
    menu[3].setCharacterSize(70);
    menu[3].setPosition(400,500);

    menuSelected = 0;
}

Menu::~Menu() {

}

void Menu::draw(sf::RenderWindow& window) {
    for (int i=0; i<MAX_MAIN_MENU; ++i) {
        window.draw(menu[i]);
    }
}

void Menu::MoveUp() {
    if (menuSelected - 1 >=-1) {
        menu[menuSelected].setFillColor(sf::Color::White);
    }
    menuSelected--;
    if (menuSelected == -1) {
        menuSelected=3;
        menu[menuSelected].setFillColor(sf::Color::White);
    }
    menu[menuSelected].setFillColor(sf::Color::Blue);
}

void Menu::MoveDown() {
    if (menuSelected + 1 <=4) {
        menu[menuSelected].setFillColor(sf::Color::White);
    }    
    menuSelected++;
    if (menuSelected == 4) {
        menuSelected=0;
    }
    menu[menuSelected].setFillColor(sf::Color::Blue);
}

int Menu::MenuPressed() {
    return menuSelected;
}