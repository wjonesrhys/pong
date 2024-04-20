#ifndef PLAYER_H
#define PLAYER_H

#include "SFML/Graphics.hpp"

class Player {
    private:
        sf::RectangleShape shape;

        sf::Vector2u windowSize;
        sf::Vector2f velocity;
        float speed;

        int playerNum;
 
    public:
        Player(int playerNum, sf::Vector2u windowSize);
        ~Player();

        void draw(sf::RenderWindow& window);
        void move(float deltaTime);
        void moveVertical(sf::Keyboard::Key up, sf::Keyboard::Key down, float deltaTime);

        void setPosition(float x_coord, float y_coord);
        void setStartingPosition();
        void setVelocity(sf::Vector2f newVelocity);

        sf::Vector2f getPosition();
        sf::Vector2f getVelocity();

        float getHighestPoint();
        float getLowestPoint();

        float getWidth();
        float getHeight();
        int getPlayerNum();
};

#endif