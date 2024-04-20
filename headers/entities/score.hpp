#ifndef SCORE_H
#define SCORE_H

#include "SFML/Graphics.hpp"

class Score {
    private:
        sf::Vector2u windowSize;

        sf::Text text;
        sf::Font font;
        
        int score;
        int playerNum;

    public:
        Score(int playerNum, sf::Vector2u windowSize);
        ~Score();

        void loadFont();

        void draw(sf::RenderWindow& window);
        void resetScore();
        void increaseScore();

        void setOrigin();
        void setPosition();        
        
};

#endif