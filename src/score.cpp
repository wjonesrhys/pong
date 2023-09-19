#include <iostream>

#include <score.hpp>
#include <util.hpp>

enum digits 
{   
    ten = 1, 
    hundred = 10, 
    thousand = 100
};

Score::Score(int playerNum, sf::RenderWindow& renderWindow) : window(renderWindow) {
    this->playerNum = playerNum;

    loadFont();
    sf::FloatRect textRect = text.getGlobalBounds();

    this->text.setFont(font); 
    this->text.setString("0");
    this->text.setCharacterSize(72); 
    this->text.setFillColor(sf::Color::Green);
    this->text.setStyle(sf::Text::Bold);
    playerNum == 1 ? 
        this->text.setOrigin(sf::Vector2f(textRect.left + textRect.width, textRect.height/2)) :
        this->text.setOrigin(sf::Vector2f(textRect.left, textRect.height/2));
    this->text.setPosition(calculatePosition());
}

Score::~Score() {
    std::cout << "Score object destroyed!" << std::endl;
}

void Score::updatePosition() {
    this->text.setPosition(calculatePosition());
}

sf::Vector2f Score::calculatePosition() {
    float xCoord = window.getSize().x/2;
    printCoords(window.getSize());
    playerNum == 1 ? xCoord -= text.getGlobalBounds().width/2 + 10 : xCoord += text.getGlobalBounds().width/2 + 10;
    return sf::Vector2f(xCoord, text.getGlobalBounds().height);

    // sf::Vector2f coords;
    // coords = playerNum == 1 ? sf::Vector2f(200, 500) : sf::Vector2f(500, 200);
    // return coords;
}

void Score::resetScore() {
    this->score=0;
}

void Score::increaseScore() {
    switch(score) {
        case (ten):
            this->text.setPosition(calculatePosition());
            break;
        case (hundred):
            this->text.setPosition(calculatePosition());
            break;
        case (thousand):
            this->text.setPosition(calculatePosition());
            break;
    }
    this->score += 1;
    std::string newScore = std::to_string(this->score);
    this->text.setString(newScore);
}

void Score::setFont(sf::Font font) {
    this->font=font;
}

void Score::draw() {
    window.draw(text);
}

void Score::loadFont() {
    if (!this->font.loadFromFile("fonts/arial.ttf")) {
        std::cout << "Error loading font!" << std::endl;
    }
}