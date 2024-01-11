#include <menu.hpp>
#include <util.hpp>

Menu::Menu() {
    if (!font.loadFromFile("resources/fonts/arial.ttf")) {
        std::cout << "not loaded";
    }
    setMenuSelected(0);
}

Menu::~Menu() {
    for (sf::Shape* shape : shapes) {
        shape->~Shape();
    }
}

std::vector<sf::Shape*> Menu::getShapes() {
    return this->shapes;
}

std::vector<sf::Text> Menu::getOptionTexts() {
    return this->optionTexts;
}

std::vector<sf::Text> Menu::getStaticTexts() {
    return this->staticTexts;
}

void Menu::addText(std::string text, sf::Vector2f position, std::string vectorName) {
    sf::Text textItem;
    textItem.setFont(font);
    textItem.setString(text);
    textItem.setCharacterSize(70);
    textItem.setPosition(position);

    if (vectorName == "option") {
        optionTexts.push_back(textItem);
    } else if (vectorName == "static") {
        staticTexts.push_back(textItem);
    } else {
        print("not a valid vector name to add to.");
    }
}

void Menu::addShape(sf::Shape* shape) {
    this->shapes.push_back(shape);
}
void Menu::moveUp() {
    if (menuSelected - 1 >=-1) {
        optionTexts.at(menuSelected).setFillColor(sf::Color::White);
    }
    menuSelected--;
    if (menuSelected == -1) {
        menuSelected=optionTexts.size()-1;
        optionTexts.at(menuSelected).setFillColor(sf::Color::White);
    }
    optionTexts.at(menuSelected).setFillColor(sf::Color::Blue);
}

void Menu::moveDown() {
    if (menuSelected + 1 <=optionTexts.size()) {
        optionTexts.at(menuSelected).setFillColor(sf::Color::White);
    }    
    menuSelected++;
    if (menuSelected == optionTexts.size()) {
        menuSelected=0;
    }
    optionTexts.at(menuSelected).setFillColor(sf::Color::Blue);
}

int Menu::menuPressed() {
    print("menu number selected: ");
    print(menuSelected);
    return menuSelected;
}

void Menu::clearColouredText() {
    for (sf::Text text : optionTexts) {
        text.setFillColor(sf::Color::White);
    }
}

void Menu::colourMenuSelected() {
    this->optionTexts.at(menuSelected).setFillColor(sf::Color::Blue);
}

void Menu::setMenuSelected(int index) {
    menuSelected = index;
    if (optionTexts.size() > 0) {
        clearColouredText();    
        colourMenuSelected();   
    }
}