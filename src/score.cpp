#include <iostream>
#include <cmath>

#include <score.hpp>
#include <util.hpp>

enum digits 
{   
    ten = 10, 
    hundred = 100, 
    thousand = 1000
};

//create a score with a playernumber
//when creating set origin to the 

Score::Score(int playerNum, sf::RenderWindow& renderWindow) : window(renderWindow) {
    this->playerNum = playerNum;

    loadFont();

    float xCoord = window.getSize().x/2;
    this->score=0;

    this->text.setFont(font); 
    this->text.setString("0");
    this->text.setCharacterSize(72); 
    this->text.setFillColor(sf::Color::Green);
    this->text.setStyle(sf::Text::Bold);    

    setOrigin();
    setPosition();

}

Score::~Score() {
    std::cout << "Score object destroyed!" << std::endl;

}

void Score::updatePosition() {
    this->text.setPosition(calculatePosition());
}

sf::Vector2f Score::calculatePosition() {
    sf::FloatRect textRect = text.getGlobalBounds();
    float halfTextX = textRect.getSize().x/2;
    float windowX = window.getSize().x/2;

    playerNum == 1 ? windowX -= 20 : windowX += 20;
    return sf::Vector2f(windowX, floor(textRect.getPosition().y));
}

void Score::resetScore() {
    this->score=0;
}

void Score::increaseScore() {
    switch(score) {
        case (ten):
            setOrigin();
            setPosition();
            break;
        case (hundred):
            setOrigin();
            setPosition();
            break;
        case (thousand):
            setOrigin();
            setPosition();
            break;
    }
    this->score += 1;
    std::string newScore = std::to_string(this->score);
    this->text.setString(newScore);
}

void Score::setFont(sf::Font font) {
    this->font=font;
}

void Score::setOrigin() {
    sf::FloatRect textRect = this->text.getGlobalBounds();
    float xCoord;
    this->playerNum == 1 ? xCoord = textRect.width : xCoord = 0;
    this->text.setOrigin(xCoord, textRect.height/2);
}

void Score::setPosition() {
    sf::FloatRect textRect = this->text.getGlobalBounds();
    float windowX = window.getSize().x/2;
    playerNum == 1 ? this->text.setPosition(windowX - 20, textRect.height) : this->text.setPosition(windowX + 20,textRect.height);
}

void Score::draw() {
    window.draw(text);
}

void Score::loadFont() {
    if (!this->font.loadFromFile("fonts/arial.ttf")) {
        std::cout << "Error loading font!" << std::endl;
    }
}