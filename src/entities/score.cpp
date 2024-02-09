#include <iostream>
#include <cmath>
#include <score.hpp>

enum digits 
{   
    ten = 10, 
    hundred = 100, 
    thousand = 1000
};

Score::Score(int playerNum, sf::RenderWindow& window) : window(window) {
    loadFont();

    this->playerNum = playerNum;
    this->score=0;

    this->text.setFont(this->font); 
    this->text.setString(std::to_string(this->score));
    this->text.setCharacterSize(72); 
    this->text.setFillColor(sf::Color::Green);
    this->text.setStyle(sf::Text::Bold);    

    setOrigin();
    setPosition();
}

Score::~Score() {
    std::cout << "Score object destroyed!" << std::endl;

}

void Score::loadFont() {
    if (!this->font.loadFromFile("resources/fonts/arial.ttf")) {
        std::cout << "Error loading font!" << std::endl;
    }
}

/**
 * GAME LOOP
*/

void Score::draw() {
    window.draw(text);
}

void Score::resetScore() {
    this->score=0;
}

void Score::increaseScore() {
    this->score += 1;
    std::string newScore = std::to_string(this->score);
    this->text.setString(newScore);

    if (score == ten || score == hundred || score == thousand) {
        setOrigin();
        setPosition();
    }
}

/**
 * SETTERS
*/

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