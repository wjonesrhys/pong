#ifndef PLAYER_H
#define PLAYER_H

#include "SFML/Graphics.hpp"

class Player {
    private:
        sf::RectangleShape rect;
        sf::RenderWindow &window;

        sf::Vector2f velocity;
        int playerNum;
        float deltaTime;
        float multiplier;
 
    public:
        Player(int playerNum, sf::RenderWindow& renderWindow);
        ~Player();

        void draw();
        void move(float deltaTime, float multiplier);
        void moveVertical(sf::Keyboard::Key up, sf::Keyboard::Key down);

        void setPosition(float x_coord, float y_coord);
        void setStartingPosition();
        void setVelocity(sf::Vector2f newVelocity);

        sf::FloatRect getBounds();
        sf::RectangleShape getRect();
        sf::Vector2f getPosition();
        sf::Vector2f getVelocity();

};

#endif