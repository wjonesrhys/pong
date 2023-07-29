#pragma once
#include "SFML/Graphics.hpp"
#include "collision.hpp"

class Player {
    private:
        sf::Sprite sprite;
        sf::Texture texture;

        sf::RectangleShape rect;
        
        sf::RenderWindow &window;
        Collision collision;

        sf::Vector2f velocity;
        int playerNum;
        float deltaTime;
        float multiplier;
 
    public:
        Player();
        ~Player();

        Player(int playerNum, std::string imgPath, sf::RenderWindow &renderWindow);
        Player(int playerNum, sf::RenderWindow& renderWindow);

        void move(float deltaTime, float multiplier);
        void draw();

        void moveVertical(sf::Keyboard::Key up, sf::Keyboard::Key down);
        void moveHorizontal(sf::Keyboard::Key left, sf::Keyboard::Key right);

        void setStartingPosition();
        void correctVerticalPosition();
        bool isCollidingWithWall();
};