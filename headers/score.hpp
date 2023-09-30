#pragma once
#include "SFML/Graphics.hpp"

class Score {
    private:
        sf::Text text;
        sf::Font font;
        int score;
        int playerNum;

        sf::RenderWindow &window;

    public:
        Score(int playerNum, sf::RenderWindow &renderWindow);
        ~Score();

        void increaseScore();
        void resetScore();
        void loadFont();
        void setFont(sf::Font font);

        void updatePosition();
        void setOrigin();
        void setPosition();
        sf::Vector2f calculatePosition(); 

        void draw();
};