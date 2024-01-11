#pragma once
#include "SFML/Graphics.hpp"
// #include "collision.hpp"

class Player {
    private:
        sf::Sprite sprite;
        sf::Texture texture;

        sf::RectangleShape rect;
        
        sf::RenderWindow &window;
        // Collision collision;

        sf::Vector2f velocity;
        int playerNum;
        float deltaTime;
        float multiplier;
 
    public:

        Player(int playerNum, std::string imgPath, sf::RenderWindow &renderWindow);
        Player(int playerNum, sf::RenderWindow& renderWindow);

        ~Player();

        void move(float deltaTime, float multiplier);
        void draw();

        void moveVertical(sf::Keyboard::Key up, sf::Keyboard::Key down);

        sf::FloatRect getBounds();
        sf::RectangleShape getRect();
        
        void setPosition(float x_coord, float y_coord);
        sf::Vector2f getPosition();
        void setStartingPosition();

        sf::Vector2f getVelocity();

};