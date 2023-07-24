#pragma once
#include "SFML/Graphics.hpp"
#include "collision.hpp"

class Player {
    private:
        sf::Sprite sprite;
        sf::Texture texture;
        sf::RenderWindow &window;
        Collision collision;

        int playerNum;
        sf::Vector2f velocity;
        float deltaTime;
        float multiplier;
 
    public:
        Player();
        Player(int playerNum, std::string imgPath, sf::RenderWindow &renderWindow);

        ~Player();

        sf::Sprite getSprite();

        void move(float deltaTime, float multiplier);
        void draw();

        void moveVertical(sf::Keyboard::Key up, sf::Keyboard::Key down);
        void moveHorizontal(sf::Keyboard::Key left, sf::Keyboard::Key right);

        void setStartingPosition();
        void correctVerticalPosition();
        bool isCollidingWithWall();
};