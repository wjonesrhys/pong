#ifndef SCORE_H
#define SCORE_H

#include "SFML/Graphics.hpp"

class Score {
    private:
        sf::RenderWindow& window;

        sf::Text text;
        sf::Font font;
        
        int score;
        int playerNum;

    public:
        Score(int playerNum, sf::RenderWindow& window);
        ~Score();

        void loadFont();

        void draw();
        void resetScore();
        void increaseScore();

        void setOrigin();
        void setPosition();

};

#endif