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

        void increaseScore();
        void resetScore();

        void loadFont();
        void setFont(sf::Font font);

        void setOrigin();
        void setPosition();

        void draw();
};

#endif