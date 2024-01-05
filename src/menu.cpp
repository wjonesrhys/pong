#include <menu.hpp>
#include <util.hpp>

Menu::Menu() {
    if (!font.loadFromFile("resources/fonts/arial.ttf")) {
        std::cout << "not loaded";
    }
    setMenuSelected(0);
}

Menu::~Menu() {

}

std::vector<sf::Text> Menu::getItems() {
    return this->texts;
}

void Menu::addItem(std::string text, bool isOn, sf::Vector2f position) {
    sf::Text textItem;
    textItem.setFont(font);
    textItem.setString(text);
    textItem.setCharacterSize(70);
    textItem.setPosition(position);
    texts.push_back(textItem);
}

void Menu::moveUp() {
    if (menuSelected - 1 >=-1) {
        texts.at(menuSelected).setFillColor(sf::Color::White);
    }
    menuSelected--;
    if (menuSelected == -1) {
        menuSelected=texts.size()-1;
        texts.at(menuSelected).setFillColor(sf::Color::White);
    }
    texts.at(menuSelected).setFillColor(sf::Color::Blue);
}

void Menu::moveDown() {
    if (menuSelected + 1 <=texts.size()) {
        texts.at(menuSelected).setFillColor(sf::Color::White);
    }    
    menuSelected++;
    if (menuSelected == texts.size()) {
        menuSelected=0;
    }
    texts.at(menuSelected).setFillColor(sf::Color::Blue);
}

int Menu::menuPressed() {
    print("menu number selected: " + menuSelected);
    return menuSelected;
}

void Menu::clearColouredText() {
    for (sf::Text text : texts) {
        text.setFillColor(sf::Color::White);
    }
}

void Menu::colourMenuSelected() {
    this->texts.at(menuSelected).setFillColor(sf::Color::Blue);
}

void Menu::setMenuSelected(int index) {
    menuSelected = index;
    if (texts.size() > 0) {
        clearColouredText();    
        colourMenuSelected();   
    }
}